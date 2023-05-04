# Estimation Theory and Kalman Filtering Final Project ###

Name: Peter Kohler\
email: pmkohler@gmail.com\
OS: Ubuntu 20.04\
ROS Version: ROS2 Galactic\
CMake Version: 3.22.1

This repo serves as a storage site for all of the modified ROS packages that are used to run the simulation setup alongside the code written to perform the measurement and state estimation

The directory structure is managed in a way that is conducive to the colcon build tool. Running the command ```colcon build``` at the top level of this repo will build all of the packages located in the `src` directory. 

## Repo Contents ##
### MATLAB ###
Contains all of the scripts used in MATLAB to pull data from the ROS2 environment in which the simulation is running. Also contains a series of `.mat` files which contain data recordings from the simulation and the state estimations from the running Kalman filters.

### Writeups ###
Images and pdfs of the written reports required for the project over the course of the semester.

### src ###
The source code used to perform the simulation as well as the measurement/observation and the actual kalman filtering. `gazebo_ros_pkgs` and `turtlebot3_simulations` are primarily NOT my work. They are open source packages that contain some modified files by me to suit my needs for the project. `matlab_msg_gen` contains the build files needed by MATLAB's ROS toolbox to pull in data using the custom ROS messages defined in the package `fp_msgs`. `aruco_detector` is what performs the measurement using the ArUco markers in the simulated environment. `state_estimation` contains the source code used to implement both the extended and unscented Kalman filters. 


## Build and Usage Instructions ##
Follow the instructions at https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/ using the "Foxy" installation commands at the top of the page. To install the ROS2 Galactic versions of all these packages, simply swap out the word "Foxy" with "Galactic". I haven't tested any of this on anything but ROS2 Galactic, so ensure your ROS2 installation is ROS2-Galactic.

You'll also need to install the Eigen linear algebra library.

Source your ROS2 installation:\
```$ source /opt/ros/galactic/setup.bash```\
Build the packages in this repo\
```$ colcon build```\
Source the newly built packages\
```$ source install/setup.bash```\
For some reason Gazebo installed via binaries doesn't pick up on libraries that aren't in the standard ROS library location, so copy the file `libgazebo_ros_joint_state_noise_publisher.so` to your local install's library folder(this isn't great I know). For my system this would be:\
```$ sudo cp build/gazebo_plugins/libgazebo_ros_joint_state_noise_publisher.so /opt/ros/galactic/lib```\
Finally, run the simulator and the Kalman Filter launch file:\
```$ ros2 launch turtlebot3_gazebo turtlebot3_SEFinalProj.launch.py```

