from pathlib import Path
# These modules must be imported to use this script as a launch file
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory

PACKAGE = 'state_estimation'

def generate_launch_description():

    # ----------- Generate Launch Actions for Extended Kalman Filter node -----------
    share_dir = get_package_share_directory(PACKAGE)

    # Each node call is a new object in the Launch Description array.
    ekf_node = Node(                      # Node 1 object init
        package=PACKAGE,                      # Package name
        executable="ekfNode",               # Exe name, as declared in CMakeLists.txt
        name="ekf_node",                  # Node name, must be unique
        arguments=['--ros-args', '--log-level', "WARN"] # Sets verbosity
    )

    ld = LaunchDescription()

    ld.add_action(ekf_node)
    return ld