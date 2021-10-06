# EKF Lab

## Setup
```sh
sudo apt-key del 421C365BD9FF1F717815A3895523BAEEB01FA116
sudo -E apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
sudo apt clean
sudo apt-get update && sudo apt-get upgrade -y
apt-get install ros-kinetic-rqt -y
apt-get install ros-kinetic-rqt-multiplot -y
apt-get install libqwt-dev -y
rm -rf ~/.config/ros.org/rqt_gui.ini
```