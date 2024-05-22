# Fss15mModel Usage
## Overview

Fss15mModelTesting is a C project designed to test the FSS (Fine Sun Sensor) model. This project uses CMake for build configuration and management. It includes header files, static libraries, and an example implementation to demonstrate the usage of the functions defined in the header files.

## Project Structure

```
Fss15mModelTesting/
├── include/                # Directory containing header files
│   └── SensorLib.h
├── lib/                    # Directory containing static libraries
│   ├── SensorLib.lib       # Static library for Windows
│   └── libSensorLib.a      # Static library for Linux
├── main.c                  # Example implementation using the header functions
├── CMakeLists.txt          # CMake configuration file
└── README.md               # Project README file
```

## Requirements

- CMake version 3.10 or higher
- A C11 compatible compiler
- Operating system: Windows or Linux

## Building the Project

1. **Clone the repository:**

   ```sh
   git clone <repository_url>
   cd Fss15mModelTesting
   ```

2. **Create a build directory:**

   ```sh
   mkdir build
   cd build
   ```

3. **Generate the build files:**

   ```sh
   cmake ..
   ```

   CMake will detect your operating system and configure the project accordingly.

4. **Build the project:**

   ```sh
   cmake --build .
   ```

   This will compile the source files and link the appropriate static library based on your operating system.

## Running the Example

After building the project, you will have an executable named `MyProject` (or `MyProject.exe` on Windows) in the `build` directory. You can run it using the following command:

```sh
./MyProject
```

## Customizing the Project

- **Include Directory:** The header files are located in the `include` directory. If you need to add more header files, place them in this directory and ensure they are included in your source files.

- **Library Directory:** The static libraries are located in the `lib` directory. If you have additional libraries, place them in this directory and update the `CMakeLists.txt` file accordingly.

- **Source Files:** The main source file is located in the `src` directory. You can add more source files as needed and update the `CMakeLists.txt` file to include them in the build.

## CMakeLists.txt Explanation

```cmake
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
add_executable(MyProject src/main.c)

# Link the static library
# Conditionally link the libraries based on the operating system
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_link_libraries(MyProject SensorLib.lib)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(MyProject libSensorLib.a m)
else()
    message(FATAL_ERROR "Unsupported operating system")
endif()
```

- The project is configured to use C11 standard.
- The include directory is specified to allow the compiler to find header files.
- The library directory is specified to allow the linker to find the static libraries.
- An executable named `MyProject` is created from `main.c`.
- The appropriate static library is linked based on the detected operating system.

## License

Include your license information here.

## Authors

Include the author information here.

## Acknowledgements

Include any acknowledgements or credits here.
