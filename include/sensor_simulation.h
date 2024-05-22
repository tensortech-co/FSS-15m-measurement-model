#ifndef SENSOR_SIMULATION_H
#define SENSOR_SIMULATION_H

/**
 * @brief Simulate the magnetometer measurement.
 *
 * This function models the magnetometer measurement, where M0 is the true
 * magnetic field vector, and M is the measured magnetic field vector.
 *
 * M = (Identity matrix + soft_iron) * (M0 + gaussian noise + hard_iron)
 *
 * @param soft_iron A 3x3 matrix representing the soft iron distortion
 * coefficients.
 * @param hard_iron A 3-element array representing the hard iron offset
 * coefficients.
 * @param M0 A 3-element array representing the true magnetic field vector.
 * @param M A 3-element array to store the measured magnetic field vector.
 */
void simulate_magnetometer(double soft_iron[3][3], double hard_iron[3],
                           double M0[3], double M[3]);

/**
 * @brief Simulate the sun sensor measurement.
 *
 * This function models the sun sensor measurement, where S0 is the true sun
 * vector, and S is the measured sun vector.
 *
 * S = S0 + gaussian noise
 * S = normalize(S)
 *
 * @param S0 A 3-element array representing the true sun vector.
 * @param S A 3-element array to store the measured sun vector.
 */
void simulate_sun_sensor(double S0[3], double S[3]);

#endif  // SENSOR_SIMULATION_H
