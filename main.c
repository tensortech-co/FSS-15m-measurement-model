#include <stdio.h>
#include "sensor_simulation.h"
#include "sensor_simulation_internal.h"  // Include the internal header for default functions
#define _USE_MATH_DEFINES

int main() {
    // Magnetometer initialization
    double soft_iron[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
    double hard_iron[3] = {0, -0, 0};


    double M0[3] = {1000, 1500, -500};
    double M[3];

    // Sun sensor initialization
    double S0[3] = {0.5, 0.5, 0.7071};
    double S[3];


    // Open the CSV file for writing
    FILE *fp = fopen("sensor_data.csv", "w");
    if (fp == NULL) {
        perror("Unable to open file");
        return 1;
    }

    // Write the CSV header
    fprintf(fp, "Magnetometer_X,Magnetometer_Y,Magnetometer_Z,SunSensor_X,SunSensor_Y,SunSensor_Z\n");

    // Number of simulations
    int num_simulations = 100;

    for (int i = 0; i < num_simulations; i++) {
        // Simulate magnetometer
      simulate_magnetometer(soft_iron, hard_iron, M0, M);
        // Simulate sun sensor
        simulate_sun_sensor(S0, S);

        // Write the results to the CSV file
        fprintf(fp, "%f,%f,%f,%f,%f,%f\n", M[0], M[1], M[2], S[0], S[1], S[2]);
    }

    // Close the CSV file
    fclose(fp);

    printf("Simulation data saved to sensor_data.csv\n");

    return 0;
}
