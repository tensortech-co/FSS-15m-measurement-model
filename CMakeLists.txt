cmake_minimum_required(VERSION 3.10)
project(Fss15mModel)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)

# Add the source files for the library
set(LIB_SOURCES
    src/sensor_simulation.c
)

# Add the source files for the executable
set(EXE_SOURCES
    main.c
)

# Create the static library
add_library(SensorLib STATIC ${LIB_SOURCES})

# Create the executable
add_executable(SensorSimulation ${EXE_SOURCES})

# Include directories
target_include_directories(SensorLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(SensorSimulation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include src)

# Conditionally link the math library for GCC/MinGW
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_link_libraries(SensorLib m)
endif()

# Link the static library to the executable
target_link_libraries(SensorSimulation SensorLib)
