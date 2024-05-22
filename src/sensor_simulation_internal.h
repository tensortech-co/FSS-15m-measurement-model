#ifndef SENSOR_SIMULATION_INTERNAL_H
#define SENSOR_SIMULATION_INTERNAL_H
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Default noise standard deviation
static const double DEFAULT_NOISE_STDDEV_MAG = 5.0;
static const double DEFAULT_NOISE_STDDEV_SUN = 0.003;


// Utility functions
double gaussian_noise(double stddev);
void normalize_vector(double vec[3]);

#endif  // SENSOR_SIMULATION_INTERNAL_H
