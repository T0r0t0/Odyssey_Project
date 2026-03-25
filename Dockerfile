FROM osrf/ros:humble-desktop

RUN apt-get update && apt-get install -y \
    git \
    make \
    cmake \
    build-essential \
    python3 \

    libglib2.0-0 \
    libsm6 \
    libxext6 \
    libxrender-dev \
    libopencv-dev \
    ffmpeg \
    python3-pip \

    ignition-fortress \
    ros-humble-ros-ign-interfaces \
    ros-humble-ros-ign-bridge \

    ros-humble-ros-gz-sim \
    ros-humble-gz-ros2-control \
    ros-humble-ros-gz-bridge \
    ros-humble-ros-gz-image \

    ros-humble-ros2-control \
    ros-humble-ros2-controllers \
    ros-humble-joint-state-publisher \
    ros-humble-diagnostic-updater \
    ros-humble-pcl-ros \

    ros-humble-xacro \
    ros-humble-navigation2 \
    ros-humble-nav2-bringup \
    ros-humble-slam-toolbox \
    
    ros-humble-gazebo-ros-pkgs \
    ros-humble-gazebo-ros \
    
    python3-rosdep \
    xterm \

    && rm -rf /var/lib/apt/lists/*


RUN pip install --no-cache-dir \
    networkx \
    matplotlib \
    xacro


# Setting up the user of the docker
ARG UID
ARG GID
ARG USER
ARG GROUP

RUN echo "$USER ALL=(ALL) NOPASSWD:ALL" >>/etc/sudoers
RUN groupadd -g $GID $GROUP

RUN useradd -ms /bin/bash -u $UID -g $GID $USER
RUN adduser $USER dialout
RUN addgroup $USER dialout
RUN adduser $USER video
RUN usermod -a -G video $USER

USER $USER	

# Installing Dynamic World Generator for Gazebo world generation
RUN cd /
RUN sudo git clone https://github.com/ali-pahlevani/Dynamic_World_Generator.git 
RUN pip3 install PyQt5 lxml
# Remove .py extension to simplify the use
RUN sudo mv /Dynamic_World_Generator/code/dwg_wizard.py /Dynamic_World_Generator/code/dwg_wizard
# Add the source command to .bashrc
RUN echo "export PATH=$PATH:/Dynamic_World_Generator/code/" >> /home/${USER}/.bashrc

#the follwing part in comment is useless
# RUN cd Dynamic_World_Generator/code/
# RUN echo '#!/usr/bin/env python3' > ./temp_file && \
#     cat /Dynamic_World_Generator/code/dwg_wizard.py >> ./temp_file && \
#     mv ./temp_file /Dynamic_World_Generator/code/dwg_wizard.py
# RUN mv /Dynamic_World_Generator/code/dwg_wizard.py /usr/local/bin/dwg_wizard

# Add the source command to .bashrc
RUN echo "source /opt/ros/humble/setup.sh" >> /home/${USER}/.bashrc

COPY ./aliases/.ros_aliases /home/${USER}/.ros_aliases
RUN echo "source /home/${USER}/.ros_aliases" >> /home/${USER}/.bashrc


# Copy your workspace into the container
COPY ./ros2_ws /ros2_ws
WORKDIR /ros2_ws

    # && \
#    colcon build --symlink-install

CMD ["/bin/bash"]
