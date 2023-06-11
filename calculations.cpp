//
// Created by Wesley Stagg on 29/05/2023.
//

#include "calculations.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <cmath>
#include <iomanip>
#include <vector>



const double g{ 9.80665 };   // Gravity (m/s2)
const double p{ 1.2041 };    // Density of air (kg/m3)
const double e{ 2.71828 };   // Euler's number (e)
const double k{ 0.24 };      // Air resistance (kg/m)
const double pi{ 3.142 };    // Pi

// Calculate terminal velocity of sphere
double calculate_terminal_velocity(double mass, double area)
{
    double cd{ 0.47 };    // Coefficient of drag of sphere
    double terminal_velocity{ sqrt((2 * (mass * g)) / (cd * p * area)) };
    return terminal_velocity;
}

/* Calculate free fall time */
double calculate_free_fall_time(double mass, double height)
{
    double freefall_time{ (sqrt(mass / (g * k))) * (acosh(pow(e,(height * k) / mass))) };
    return freefall_time;
}

/* Calculate meters per second */
double calculate_meters_per_second(double height, double fall_time)
{
    double fall_velcocity_mps{ height / fall_time };
    return fall_velcocity_mps;
}

// Calculate area of sphere
double calculate_projected_area(double diameter)
{
    double radius{ diameter / 2 };
    return pi * pow(radius, 2.0);
}

// Calculate object fall velocity on screen
double obj_fall_velocity(double fall_time, double drop_ht, double screen_ht)
{
    double meters_per_second{ calculate_meters_per_second(drop_ht, fall_time)};
    double pix_per_meter = screen_ht / drop_ht;

    return pix_per_meter * meters_per_second ;
}




