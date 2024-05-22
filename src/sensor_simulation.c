#include "sensor_simulation.h"

#include "sensor_simulation_internal.h"
#define _USE_MATH_DEFINES

// Simulate the magnetometer measurement
void simulate_magnetometer(double soft_iron[3][3], double hard_iron[3],
                           double M0[3], double M[3]) {

  double noise[3];
  for (int i = 0; i < 3; i++) {
    noise[i] = gaussian_noise(DEFAULT_NOISE_STDDEV_MAG);
  }

  double M_temp[3];
  for (int i = 0; i < 3; i++) {
    M_temp[i] = M0[i] + hard_iron[i] + noise[i];
  }

  for (int i = 0; i < 3; i++) {
    M[i] = 0;
    for (int j = 0; j < 3; j++) {
      M[i] += ((i == j ? 1 : 0) + soft_iron[i][j]) * M_temp[j];
    }
  }
}

// Simulate the sun sensor measurement
void simulate_sun_sensor(double S0[3], double S[3]) {

  double noise[3];
  for (int i = 0; i < 3; i++) {
    noise[i] = gaussian_noise(DEFAULT_NOISE_STDDEV_SUN);
    S[i] = S0[i] + noise[i];
  }
  normalize_vector(S);
}

// Generate Gaussian noise with given standard deviation
double gaussian_noise(double stddev) {
  srand( time(NULL) );
  double u1 = ((double)rand() / RAND_MAX);
  double u2 = ((double)rand() / RAND_MAX);
  double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
  return z0 * stddev;
}

// Normalize a 3D vector
void normalize_vector(double vec[3]) {
  double norm = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
  for (int i = 0; i < 3; i++) {
    vec[i] /= norm;
  }
}
