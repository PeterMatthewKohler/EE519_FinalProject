cmake_minimum_required(VERSION 3.8)
project(state_estimation)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

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
find_package(rclcpp_components REQUIRED)
find_package(fp_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(Eigen3 REQUIRED)

# List sources
set(EKF_Node_SRC
  src/ekf_impl.cpp
  src/ekf_main.cpp)

set(UKF_Node_SRC
  src/ukf_impl.cpp
  src/ukf_main.cpp)

# List headers
set(EKF_HEADERS
  include/state_estimation/ekf_impl.hpp)

set(UKF_HEADERS
  include/state_estimation/ukf_impl.hpp)

# Require that dependencies from package.xml be available
ament_auto_find_build_dependencies(REQUIRED
  ${${PROJECT_NAME}_BUILD_DEPENDS}
  ${${PROJECT_NAME}_BUILDTOOL_DEPENDS}
)

# Generate executable for ros1-style standalone nodes
ament_auto_add_executable(ekfNode
    ${EKF_Node_SRC}
)

ament_auto_add_executable(ukfNode
    ${UKF_Node_SRC}
)

install(TARGETS
ekfNode
ukfNode
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
