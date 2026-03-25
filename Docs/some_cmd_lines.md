# IGN

### List all ign plugins compile file .so

```bash
ls /usr/lib/x86_64-linux-gnu/ign-gazebo-*/plugins/
```

### Get info about a specific plugin

```bash
ign plugin -i -p /usr/lib/x86_64-linux-gnu/ign-gazebo-6/plugins/<name-of-your-plugin>.so
```

* [X]  Rviz2

create a graph for /tf and /tf_static

```bash
ros2 run tf2_tools view_frames
```

# URDF

To check urdf:

```bash
sudo apt install ros-humble-urdfdom-tools
```

```bash
check_urdf path/to/your/urdf/file.urdf
```

```bash
urdf_to_graphiz path/to/your/urdf/file.urdf
```

# XML

For checking if all the tags of your sdf or urdf files match you can use:

```bash
xmllint --format /path/to/your/file.xml
```
