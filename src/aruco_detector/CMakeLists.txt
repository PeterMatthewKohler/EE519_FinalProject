cmake_minimum_required(VERSION 3.8)
project(aruco_detector)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_auto REQUIRED)
find_package(rclcpp REQUIRED)
find_package(image_transport REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(fp_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
  include/aruco_detector
  ${OpenCV_INCLUDE_DIRS}
)

# Create tf_utils shared (.so) library
# Create a shared (.so) library
ament_auto_add_library(TF_Utils_lib
    "include/aruco_detector/tf_utils.hpp"
    "src/tf_utils.cpp"
)

# Link extra headers to the library
#target_include_directories(TF_Utils_lib PUBLIC #UNFINISHED)

# List sources
set(ArucoDetectorNode_SRC
    src/arucoDetector.cpp
    src/tf_utils.cpp
)

# Generate executable for ros1-style standalone nodes
add_executable(arucoDetectorNode
    ${ArucoDetectorNode_SRC}
)

ament_target_dependencies(arucoDetectorNode   rclcpp 
                                              image_transport
                                              sensor_msgs
                                              fp_msgs
                                              cv_bridge
                                              OpenCV
                                              Eigen3)

install(TARGETS
arucoDetectorNode
DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

install(DIRECTORY include/
  DESTINATION include/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
