# Odyssey_Project

A plug in play source code for Génération Robot Kit R&amp;D ROS2 mounting Scout Mini robot from Agilex.

Containerised version.

## Table of Contents

* [Features](#features)
* [Installation](#installation)
* [Build](#build)
* [Usage](#usage)

## Features

* **feature1**: feature1 description.

## Installation

### Prerequisites

* docker installed
*

##### Linux:

Install Docker and docker compose

1. Clone the git repository

```bash
git clone --branch gazebo-fortress https://github.com/T0r0t0/Odyssey.git
```

```bash
cd Odyssey
```

2. Setup Environment variable:
   First of all you have to setup the environment variable of your container
   Add execution right to some_script/setup_config_file.sh

```bash
chmod +x some_script/setup_config_file.sh
```

After that execute the script:

```bash
./some_script/setup_config_file.sh
```

3. Build and run container:
   Build:

```bash
docker compose build
```

Run:

```bash
docker compose up -d
```

4. Acces to the terminal of the container:
   Before accessing to the container you have to allow it to display Graphical User Intarface (useful for Gazebo, Rvyz2, ...)

```bash
xhost +
```

Now you can connect to the container with :

```bash
docker exec -it ros-fortress-scout bash
```

5. When you have finish quit the docker using : exit \n
   And run :
   ```bash
   xhost -
   ```

## Build

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

## Usage

#### Launch Gazebo

When your are in the Docker, you have already build and source install/setup.bash, you can launch rviz2 and Gazebo simulation by using the following command:

```bash
ros2 launch odyssey main.launch.py sim:=True
```
