#!/bin/bash

echo "DISPLAY=${DISPLAY}
QT_X11_NO_MITSHM=1
ROBOT_ID=9
LIDAR_TYPE=RSHELIOS
CAMERA_TYPE=D435
ROBOT_TYPE=SCOUT_MINI
START_CAMERA=1
RVIZ=1" > .env



echo "UID=$(id -u)" >> .env
echo "GID=$(id -g)" >> .env
echo "USER=$(whoami)" >> .env
echo "GROUP=$(whoami)" >> .env
