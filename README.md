# Odyssey_Project

A plug in play source code for Génération Robot Kit R&amp;D ROS2 mounting Scout Mini robot from Agilex.


Ros-env.py version. Base on a script I have created. You can find it in my repo as ros_env git.

## Usage


Generating environment files needed only once at the first usage:

```bash
ros-env.py create_from -f .ros_env_param.yaml
```


Start the environment:

```bash
ros-env.py start
```

nota: Take time for the first time to initiate the environment.


Stop the environment:

```bash
exit
ros-env.py stop
```

Delete the environment:

```bash
ros-env.py delete
```
