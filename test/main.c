#include <stdio.h>
#include "sensor_simulation.h"

int main() {
    // Example initialization values
    double soft_iron[3][3] = {{0.01, 0.02, 0.03}, {0.01, 0.01, 0.02}, {0.03, 0.02, 0.01}};
    double hard_iron[3] = {100, -50, 75};
    double M0[3] = {1000, 1500, -500};
    double M[3];

    simulate_magnetometer(soft_iron, hard_iron, M0, M);

    printf("Simulated Magnetometer Measurement: %f, %f, %f\n", M[0], M[1], M[2]);

    double S0[3] = {0.5, 0.5, 0.7071};
    double S[3];

    simulate_sun_sensor(S0, S);

    printf("Simulated Sun Sensor Measurement: %f, %f, %f\n", S[0], S[1], S[2]);

    return 0;
}
