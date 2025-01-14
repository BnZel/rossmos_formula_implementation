#include "../include/grid.h"
#include <stdbool.h>
#include <stdio.h>

Rossmos_Formula *init_variables(float lon[], float lat[], int T, float k, float B, float g, float f, int n)
{
    Rossmos_Formula *rf = (Rossmos_Formula *)malloc(sizeof(Rossmos_Formula));
    rf->P = 0.0;

    memcpy(rf->lon, lon , sizeof(float) * NUM_CRIMES);
    memcpy(rf->lat, lat , sizeof(float) * NUM_CRIMES);

    rf->T = T;
    rf->k = k;
    rf->B = B;
    rf->g = g;
    rf->f = f;

    return rf;
}

float summation(Rossmos_Formula *rossmos, int n, int T)
{
    // rossmos->T = T;
    float percentage = 0.0;
    
    for(int i=n; i<T; i++)
    {
         printf("==================================[%d]======================================\n",i);
         // printf("start:\nlon: %f | lat: %f\n\ncalculated:\nlon: %f\nlat: %f\n", rossmos->lon[start], rossmos->lat[start], rossmos->lon[i], rossmos->lat[i]);
         float dist = manhattan_distance(rossmos->lon[n], rossmos->lat[n], 39.904202, 116.407394);
         float phi = indicator_function(dist, rossmos->B, rossmos->f, rossmos->g);
         
         rossmos->P += (rossmos->k * phi);
         percentage = (rossmos->P / T) * 100;
         
        //  if(percentage >= 100.0f)
        //  {
        //      printf("Finished...\n");
        //      return percentage;
        //  }
        
         printf("distance: %.13f | phi: %.13f\n", dist, phi);
         printf("Probability: %.5f\n", percentage);
         printf("========================================================================\n\n");
    }



    printf("Finished...\n");
    return percentage;
}

float manhattan_distance(float x_i, float x_n, float y_j, float y_n)
{
    return fabs(x_i - x_n) + fabs(y_j - y_n);
}

float first_term(float distance, float f)
{
    return 1 / pow(distance,f);   
} 

float second_term(float B, float g, float f)
{
    float numerator_a = 1 - 0;
    float numerator_b = pow(B,g-f);
    float numerator_t = numerator_a * numerator_b;

    float denominator_o = 2*B;    
    float denominator_i = 0;
    float denominator_p = pow(denominator_o - denominator_i, g);

    return numerator_t / denominator_p;
}

float indicator_function(float distance, float B, float f, float g)
{   
    if(distance > B){
        return first_term(distance,f);
    }
    else {
        return second_term(B,g,f);
    }
}