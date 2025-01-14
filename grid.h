#include <stdlib.h>
#include <math.h>

// default values to be setup
#define START             0 
#define NUM_CRIMES        0
#define NORMALIZATION     0.0
#define BUFFER_ZONE       0.0
#define DECAY_G           0.0
#define DECAY_F           0.0

typedef struct 
{
    float lon[NUM_CRIMES];            // longitude
    float lat[NUM_CRIMES];            // latitude
    int T;                            // total past crimes
    float k;                          // normalization constant
    float P;                          // probability at this point
    float B;                          // buffer zone radius (static value by default)
    float g,f;                        // decay constants

} Rossmos_Formula;

Rossmos_Formula *init_variables(float lon[], float lat[], int T, float k, float B, float g, float f, int n);
float summation(Rossmos_Formula *rossmos, int n, int T);
float manhattan_distance(float x_i, float x_n, float y_j, float y_n);
float indicator_function(float distance, float B, float f, float g);
float first_term(float distance, float f);
float second_term(float B, float g, float f);

