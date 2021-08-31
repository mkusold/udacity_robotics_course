# Project1

This is the Udacity Robotics Submission for Project 1.

Most of the Models in the World have been imported from online.

However, the hand-built model specified in the requirements that needs joints, has been made by me, and is present twice in the world, is called `Scout`' in the `models` directory. (`/models/Scout`)

The model of my apartment is in `/models/Apartment`. It was built based off of a reference floorplan shown in `/resources/apartment_floorplan_1m_scale.png`

# Dev Instructions

## Build Plugins

`cd build && cmake ../ && make`
(as a reminder you also have to add plugins to your world file)

## Running The World

Connect Plugins and Models to Gazebo
Run this once per session:
`source ./setup.sh`

Opening World:

`gazebo world/apartment.world`

## Credits

I sourced many models for the `apartment.world` file from: https://data.nvision2.eecs.yorku.ca/3DGEMS/
