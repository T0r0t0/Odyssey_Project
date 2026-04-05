# Odyssey_Project

A plug in play source code for Génération Robot Kit R&amp;D ROS2 mounting Scout Mini robot from Agilex. This code is based on a modified "description package for the ros2" you can find [here](github.com/T0r0t0/gr_description_ros2_R-D_kit). The objectives of this robot is to deliver an object to a specific gps location without any previous information. It doesn't know thetopilogy of the environment and have to make his own map of its surrounding.

## Table of Contents

* [Features](#features)
* [Dependencies](#Dependencies)
* [Installation](#installation)
* [Usage](#usage)

## Features

* Generate a map in 2D
* Trajectory planning with obtacles avoidance

## Dependencies

- nav2
- Slam toolbox

## Installation

You can download the source directly from this branch "main", by cloning the repository:

```bash
git clone git@github.com:T0r0t0/gr_description_ros2_R-D_kit.git
```

Warning: this source code was developed on ROS Humble. The last ubuntu version for ROS Humble is Ubuntu 22.04.

Nota: You can install a containerized version by install the branch "ros_env_odyssey" or "docker_odyssey".

## Usage
