# Odyssey_Project

A plug in play source code for Génération Robot Kit R&amp;D ROS2 mounting Scout Mini robot from Agilex. This code is based on a modified "description package for the ros2" you can find [here](https://github.com/T0r0t0/gr_description_ros2_R-D_kit). The objectives of this robot is to deliver an object to a specific gps location without any previous information. It doesn't know thetopilogy of the environment and have to make his own map of its surrounding.

## Table of Contents

* [Features](#features)
* [Dependencies](#Dependencies)
* [Installation](#installation)
* [Usage](#usage)

## Features

* Generate a map in 2D
* Trajectory planning with obtacles avoidance

## Dependencies

- git

- make
- cmake
- build-essential
- python3
- python3-pip
- ignition-fortress
- ros-humble-ros-ign-interfaces
- ros-humble-ros-ign-bridge
- ros-humble-ros-gz-sim
- ros-humble-gz-ros2-control
- ros-humble-ros-gz-bridge
- ros-humble-ros-gz-image
- ros-humble-ros2-control
- ros-humble-ros2-controllers
- ros-humble-joint-state-publisher
- ros-humble-diagnostic-updater
- ros-humble-pcl-ros
- ros-humble-xacro
- ros-humble-navigation2
- ros-humble-nav2-bringup
- ros-humble-slam-toolbox
- ros-humble-gazebo-ros-pkgs
- ros-humble-gazebo-ros
- xterm

## Installation

You can download the source directly from this branch "main", by cloning the repository:

```bash
git clone git@github.com:T0r0t0/gr_description_ros2_R-D_kit.git
```

Warning: this source code was developed on ROS Humble. The last ubuntu version for ROS Humble is Ubuntu 22.04.

Nota: You can install a containerized version by install the branch "ros_env_odyssey" or "docker_odyssey".

## Usage

#### Build

When you have create the docker and connected to it. You have to build the code from source using:

```bash
cd /ros2_ws
```

```bash
colcon build
```

After the build you have to source the setup:

```bash
source install/setup.bash
```

or

```bash
. install/setup.bash
```

This operation have to be done every time you connect to the container.

#### Launch Gazebo

When you have already build and source install/setup.bash, you can launch rviz2 and Gazebo simulation by using the following command:

```bash
ros2 launch odyssey main.launch.py sim:=True
```
