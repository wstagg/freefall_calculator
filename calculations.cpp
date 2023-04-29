#include <iostream>
#include "calculations.h"
#include <cmath>
#include <iomanip>

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

// Calculate free fall time
double calculate_free_fall_time(double mass, double height)
{
    double freefall_time{ (sqrt(mass / (g * k))) * (acosh(pow(e,(height * k) / mass))) };
    return freefall_time;
}

// Calculate distance fallen
void calculate_distance_fallen(double height, double fall_time)
{
    const double fall_velcocity{ height / fall_time };
    double i{ 0 };
    for (; i < fall_time; ++i)
    {
        std::cout << std::setprecision(4);
        std::cout << "At " << i << " seconds the ball height is " << height << "m\n";
        height -= fall_velcocity;
    }
    std::cout << "At " << fall_time << " seconds the ball has hit the ground\n";
}

// Calculate area of sphere
double calculate_projected_area(double diameter)
{
    double radius{ diameter / 2 };
    return pi * pow(radius, 2.0);
}

