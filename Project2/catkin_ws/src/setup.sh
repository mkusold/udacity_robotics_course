alias sys-update="sudo apt-get update && sudo apt-get upgrade -y"
echo "For Gazebo, don\'t forget to run sys-update first"

source /home/workspace/catkin_ws/devel/setup.bash
echo "devel/setup.bash sourced"

export PKG_NAME=my_robot
echo "PKG_NAME is set -- for the Makefile commands"

export GAZEBO_PLUGIN_PATH=${CATKIN_WS}/src/${PKG_NAME}/build:$GAZEBO_PLUGIN_PATH
echo $GAZEBO_PLUGIN_PATH
export GAZEBO_MODEL_PATH=${CATKIN_WS}/src/${PKG_NAME}/model:$GAZEBO_MODEL_PATH
echo $GAZEBO_MODEL_PATH