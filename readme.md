# Fss15mModel

## Overview

Fss15mModel is a C project that simulates sensor operations and generates a static library `SensorLib` for use in other projects. This project includes an example executable `SensorSimulation` to run analysis and verify that the functions meet the requirements. The project is designed to be built with both GCC and Visual Studio.

## Project Structure

```
Fss15mModel/
├── include/                # Directory containing header files
│   └── sensor_simulation.h
├── src/                    # Directory containing source files for the library
│   ├── sensor_simulation.c
    ├── sensor_simulation_internal.h
├── test/                   # Directory containing the test subproject
├── CMakeLists.txt          # CMake configuration file for the main project
└── README.md               # Project README file
```

## Requirements

- CMake version 3.10 or higher
- A C11 compatible compiler (GCC or Visual Studio)

## Building the Project

### Main Project (Fss15mModel)

1. **Clone the repository:**

   ```sh
   git clone <repository_url>
   cd Fss15mModel
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

   CMake will configure the project and detect your compiler.

4. **Build the project:**

   ```sh
   cmake --build .
   ```

   This will compile the source files and create both the static library `SensorLib` and the executable `SensorSimulation`.

### Test Subproject (Fss15mModelTesting)

1. **Navigate to the test directory:**

   ```sh
   cd ../test
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

4. **Build the test project:**

   ```sh
   cmake --build .
   ```

## Running the Example

After building the main project, you will have an executable named `SensorSimulation` (or `SensorSimulation.exe` on Windows) in the `build` directory. You can run it using the following command:

```sh
./SensorSimulation
```

This will execute the analysis and verify the functions defined in the `SensorLib` library.

# Simulation Report

## Magnetometer Measurement Error

### Mean Error
The mean error of the simulated magnetometer measurements in the XYZ axis is:
\[ [0.45968525, -0.2160204, -0.24310844] \]

### Standard Deviation
The standard deviation of the simulated magnetometer measurements' error in the XYZ axis is:
\[ [5.48219184, 4.68882155, 5.21317614] \]

### Unit
The unit of the magnetometer measurement error is nanotesla (nT).

## Sun Sensor Measurement Error

### Mean Error
The mean error of the simulated sun sensor measurements is:
\[ 0.213396 \]

### Standard Deviation
The standard deviation of the simulated sun sensor measurements' error is:
\[ 0.0999 \]

### Unit
The unit of the sun sensor measurement error is degrees.




## License

Include your license information here.

## Authors

Include the author information here.

## Acknowledgements

Include any acknowledgements or credits here.
