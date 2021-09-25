#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

class Color
{
public:
    int R, G, B;
    Color() {}
    void set(int r, int g, int b)
    {
        R = r;
        G = g;
        B = b;
    }
};

class ProcessImage
{
public:
    ProcessImage()
    {
        // Subscribe to camera/rgb/image_raw topic to read the image data inside the process_image_callback function
        sub1_ = n_.subscribe("camera/rgb/image_raw", 10, &ProcessImage::process_image_callback, this);

        // Define a client service capable of requesting services from command_robot
        client_ = n_.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

        pixel_color_.set(255, 255, 255);
        ROS_INFO("Looking for R: %d G: %d B: %d", pixel_color_.R, pixel_color_.G, pixel_color_.B);
    }

    // This function calls the command_robot service to drive the robot in the specified direction
    void drive_robot(float lin_x, float ang_z)
    {
        // Request a service and pass the velocities to it to drive the robot
        ball_chaser::DriveToTarget srv;
        srv.request.linear_x = lin_x;
        srv.request.angular_z = ang_z;

        if (!client_.call(srv))
            ROS_ERROR("Failed to call service drive_bot");
    }

    // This callback function continuously executes and reads the image data
    void process_image_callback(const sensor_msgs::Image &img)
    {
        enum Position
        {
            left,
            mid,
            right,
            none
        };
        Position ball_position = none;

        // Loop through each pixel (which is comprised of three color channels - r, g, b)
        // in the image and check if there's a completely bright white one
        // Then, identify if this pixel falls in the left, mid, or right side of the image

        for (int i = 0; i < img.height * img.step; i += 3)
        {
            if (
                img.data[i] == pixel_color_.R &&
                img.data[i + 1] == pixel_color_.G &&
                img.data[i + 2] == pixel_color_.B)
            {
                int horizontal_pos = i % img.step;
                int chunk = (int)img.step / 3;

                if (horizontal_pos < chunk)
                {
                    ball_position = left;
                }
                else if (horizontal_pos >= chunk * 2)
                {
                    ball_position = right;
                }
                else
                {
                    ball_position = mid;
                }

                // break out of the img for loop cause we found what we need
                break;
            }
        }

        // Depending on the white ball position, call the drive_bot function and pass velocities to it
        // Request a stop when there's no white ball seen by the camera
        // If the image is uniform and the arm is not moving, move the arm to the center
        switch (ball_position)
        {
        case left:
            ROS_INFO("Driving Left");
            drive_robot(0.0, 0.5);
            break;
        case right:
            ROS_INFO("Driving Right");
            drive_robot(0.0, -0.5);
            break;
        case mid:
            ROS_INFO("Driving Forward");
            drive_robot(0.5, 0.0);
            break;
        default:
            // Default state is to stop and not move at all
            drive_robot(0.0, 0.0);
        }
    }

private:
    ros::NodeHandle n_;
    ros::ServiceClient client_;
    ros::Subscriber sub1_;
    // what color pixel we're looking for in RGB
    Color pixel_color_;
};

int main(int argc, char **argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");

    ProcessImage ProcessImageObject;

    ROS_INFO("Ready to process images");

    // Handle ROS communication events
    ros::spin();

    return 0;
}