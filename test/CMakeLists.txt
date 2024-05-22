cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Fss15mModelTesting)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the library directory
link_directories(${PROJECT_SOURCE_DIR}/lib)

# Add the executable
add_executable(MyProject main.c)

# Link the static library
# Conditionally link the libraries based on the operating system
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(MyProject SensorLib.lib)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(MyProject libSensorLib.a m)
else()
    message(FATAL_ERROR "Unsupported operating system")
endif()
