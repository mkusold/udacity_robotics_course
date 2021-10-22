# Project 3

This is the directory for the "Where AM I" Project. It includes a 4 wheel skid steer robot modeled after the kickstarter [Scout robot](https://www.kickstarter.com/projects/moorebot/scout-the-tiny-ai-powered-autonomous-mobile-robot-for-home/description). It also includes a model of my apartment.

## Setup

Run `source ./setup.sh` once per session in order to properly connect Gazebo with any local models I'm using.


## Dependencies

- `sudo apt-get install libignition-math2-dev protobuf-compiler`

### Creating PGM Map
- `git clone https://github.com/udacity/pgm_map_creator.git`
- `cp <YOUR GAZEBO WORLD FILE> src/pgm_map_creator/world/<YOUR GAZEBO WORLD FILE>`
-  Add this to the bottom of that world file before `</world>`: `<plugin filename="libcollision_map_creator.so" name="collision_map_creator"/>`
- Run `gzserver src/pgm_map_creator/world/<YOUR GAZEBO WORLD FILE>`
- Then run `roslaunch pgm_map_creator request_publisher.launch`
- Now a map will be created in the `map` folder of the `pgm_map_creator`

### Getting AMCL Configs
- `wget https://s3-us-west-1.amazonaws.com/udacity-robotics/Resource/where_am_i/config.zip`
- `unzip config.zip`
- `rm config.zip`

### Telop
- `git clone https://github.com/ros-teleop/teleop_twist_keyboard`

## Running

Run `make run` to start the world

To see other options, run `make help`

## Repo

https://github.com/mkusold/udacity_robotics_course

## Credits

I sourced many models for the `apartment.world` file from: https://data.nvision2.eecs.yorku.ca/3DGEMS/
