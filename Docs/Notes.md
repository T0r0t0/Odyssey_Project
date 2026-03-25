# SDF vs URDF

### Tags

- The following tags have the same names but a different sintax:
  - SDF

    ```xml
    <parent>base_link</parent>
    <child>right_rear_wheel_link</child>
    <axis><xyz>0 0 -1</xyz></axis>

    <-- ---------------------------------------------------------------------- -->
    <-- In Visual and Collision -->
    <box><size>0.01 0.01 0.004</size></box>
    <cylinder><length>0.08</length><radius>0.04</radius></cylinder>

    <-- ---- -->
    <mesh>
      <scale>1 1 1</scale>
      <uri>file:///ros2_ws/install/gr_description/share/gr_description/meshes/agilex/scout/wheel.dae</uri>
    </mesh>

    <-- ---------------------------------------------------------------------- -->
    <-- In inertial tags -->
    <inertial>

      ...

      <mass>62.904</mass>
        <inertia>
          <ixx>5.55936</ixx>
          <ixy>-0.00212481</ixy>
          <ixz>-0.0130841</ixz>
          <iyy>5.70812</iyy>
          <iyz>-0.00151496</iyz>
          <izz>3.74187</izz>
        </inertia>
    </inertial>
    ```
  - URDF

    ```xml
    <parent link="base_link"/>
    <child link="right_rear_wheel_link"/>
    <axis xyz="0 0 -1"/>

    <box size="0.01 0.01 0.004"/>
    <cylinder length="0.08" radius="0.04"/>

    <mesh scale="1 1 1" filename="file:///ros2_ws/install/gr_description/share/gr_description/meshes/agilex/scout/scout_mini_base_link.dae"/>

    <mass value="62.904"/>
    <inertia ixx="5.55936" ixy="-0.00212481" ixz="-0.0130841" iyy="5.70812" iyz="-0.00151496" izz="3.74187"/>
    ```
- Some times the names of the tag is completly different:
  - SDF

    ```xml
    <pose>0.00172 0.000157 -0.015991 0 -0 0</pose>
    ```
  - URDF

    ```xml
    <origin xyz="0.00172 0.000157 -0.015991" rpy="0 -0 0"/>
    ```
- Others

### SDF :

```xml
<material>
  <ambient>0.5 0.5 0.5 1</ambient>   <!-- RGBA -->
  <diffuse>0.8 0.2 0.2 1</diffuse>   <!-- Red color -->
  <specular>0.1 0.1 0.1 1</specular>
</material>

```

### URDF:

In URDF, you typically only define the diffuse color using the `<color>` tag. URDF does not support separate ambient, diffuse, and specular components like SDF does. Here's how you can define it:

```xml
<material name="red_material">
  <color rgba="0.8 0.2 0.2 1"/>  <!-- RGBA: Red color -->
</material>

```

# Gazebo Sensor

### Lidar

To simulate a 3D-lidar in Ignitio Fortress you have to use the the sensor's type "gpu_lidar. There is some points to be aware of:

- This sensor publish in two ign topics: /model/gr_robot/lidar [ignition.msgs.LaserScan] and an other /model/gr_robot/lidar/points [ignition.msgs.PointCloudPacked]. If you want to visualize the point cloud you have to define in the bridge the link between the types [ignition.msgs.PointCloudPacked] and [sensor_msgs/msg/PointCloud2]
- You probably have to modify the frame_id attribut of the ignition.msgs.PointCloudPacked and ignition.msgs.LaserScan messages to make it work in the rviz. To do it you have to use the following tag:

  ```xml
  <ignition_frame_id>RS16_link</ignition_frame_id>
  ```

# Generating World for Ignition Fortress

A really good project for generating world for you ros humble application is the following github repository:

[https://github.com/ali-pahlevani/Dynamic_World_Generator.git](https://)

* [ ]  This project coded in python provi****ded a GUi application for generating a world by drawing map or even add model with simple trajectory.
