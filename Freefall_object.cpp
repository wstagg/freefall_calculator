#include "Freefall_object.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include <cmath>
#include <iostream>

/* Freefall_object class constructor */
Freefall_object::Freefall_object(sf::Vector2f _object_position, sf::Color _outline_colour, sf::Texture _texture, float _outline_thickness, float _radius, sf::Vector2f _cube_size):
object_position(_object_position),
outline_colour(_outline_colour),
texture(_texture),
outline_thickness(_outline_thickness),
radius(_radius),
cube_size(_cube_size)
{
    if(radius)
    {
        ball.setRadius(radius);
        ball.setPosition(object_position);
        ball.setOutlineColor(outline_colour);
        ball.setOutlineThickness(outline_thickness);
        ball.setTexture(&texture);  
        object_chosen = 1; 
    }
    else
    {
        cube.setSize(cube_size);
        cube.setPosition(object_position);
        cube.setOutlineColor(outline_colour);
        cube.setOutlineThickness(outline_thickness);
        cube.setTexture(&texture);
        object_chosen = 0; 

    }
    
}

void Freefall_object::draw(sf::RenderWindow& window)
{
    if (object_chosen == 0)
    {
        window.draw(cube);
    }
    else
    {
        window.draw(ball);
    }
}

void Freefall_object::setOutlineThickness (float thickness)
{
    if (object_chosen == 0)
    {
        cube.setOutlineThickness(thickness);
    }
    else
    {
        ball.setOutlineThickness(thickness);
    }
}

void Freefall_object::setPosition(sf::Vector2f pos)
{
    if (object_chosen == 0)
    {
        cube.setPosition(pos);
    }
    else
    {
        ball.setPosition(pos);
    }
}

void Freefall_object::setRadius(float rad)
{
    ball.setRadius(rad);
}

void Freefall_object::setSize(sf::Vector2f size)
{
    cube.setSize(size);
}

void Freefall_object::menu_drop(float y_res, int &next_display)
{
    float velocity {10.f};
    object_position.y += velocity;
    setPosition(object_position);

    if (object_position.y > y_res)
    {
        next_display = 3;
    }
}

void Freefall_object::get_user_inputs(double drop_ht, double object_mass)
{
    in_drop_ht = drop_ht;
    std::cout << "drop height is: "<< in_drop_ht << std::endl;
    in_obj_mass = object_mass;
    std::cout << "obj mass is: " << in_obj_mass << std::endl;

}

void Freefall_object::object_freefall()
{

}


// Calculate terminal velocity of sphere
double Freefall_object::calculate_terminal_velocity(double mass, double area)
{
    double cd{ 0.47 };    // Coefficient of drag of sphere
    double terminal_velocity{ sqrt((2 * (mass * g)) / (cd * p * area)) };
    return terminal_velocity;
}

/* Calculate free fall time */
double Freefall_object::calculate_free_fall_time(double mass, double height)
{
    double freefall_time{ (sqrt(mass / (g * k))) * (acosh(pow(e,(height * k) / mass))) };
    return freefall_time;
}

/* Calculate meters per second */
double Freefall_object::calculate_meters_per_second(double height, double fall_time)
{
    double fall_velcocity_mps{ height / fall_time };
    return fall_velcocity_mps;
}

// Calculate area of sphere
double Freefall_object::calculate_projected_area(double diameter)
{
    double radius{ diameter / 2 };
    return pi * pow(radius, 2.0);
}

// Calculate object fall velocity on screen
double Freefall_object::obj_fall_velocity(double fall_time, double drop_ht, double screen_ht)
{
    double meters_per_second{ calculate_meters_per_second(drop_ht, fall_time)};
    double pix_per_meter = screen_ht / drop_ht;

    return pix_per_meter * meters_per_second ;
}

double Freefall_object::calculate_Distance_Travelled_In_Time(double fall_time, double mass)
{
    double height = mass/k*log(cosh(fall_time/sqrt(mass/g/k)));
    return height;
}

double Freefall_object::calculate_velocity(double fall_time, double mass)
{
    double vel = (sqrt(mass*g/k)*tanh(fall_time/sqrt(mass/g/k)));
    return vel;
}

// Calculate object fall velocity on screen
//lets assume object dropped from top to bottom of screen. This function will calculate the y
//max screen = screen ht
//max distance = calculate_Distance_Travelled_In_Time();
//we combine the two to get a percentage = screen/distance
//multiply it by current distance made.
void Freefall_object::obj_fall_pos(double screen_ht)
{
    static int first_pass{0};
    sf::Vector2f ff_pos(500.f, 0.f);
    float ball_rad{ 30.f };
    sf::Vector2f cube_size(60.f, 60.f);

    if (!first_pass)
    {
        ball.setPosition(ff_pos);
        cube.setPosition(ff_pos);

        ball.setRadius(ball_rad);
        cube.setSize(cube_size);
        
        ff_clock.restart();
        first_pass = 1;
    }
    
    double fall_time = ff_clock.getElapsedTime().asMilliseconds()/1000.0;
    double maxFallTime = calculate_free_fall_time(in_obj_mass, in_drop_ht);
    double maxDistance = calculate_Distance_Travelled_In_Time(maxFallTime, in_obj_mass);
    double maxVelocity = calculate_velocity(maxFallTime, in_obj_mass);
    
    if (fall_time > maxFallTime)
    {
        fall_time = maxFallTime;
    
    } 
    double currentDistance = calculate_Distance_Travelled_In_Time(fall_time, in_obj_mass);
    double currentVelocity = calculate_velocity(fall_time,in_obj_mass);
    double y = currentDistance / maxDistance * screen_ht;
    //std::cout << currentVelocity << std::endl;
    cube.setPosition(cube.getPosition().x, y);
    ball.setPosition(ball.getPosition().x, y);

    if ((ball.getPosition().y == (screen_ht - (radius *2))) || (cube.getPosition().y > (screen_ht - cube_size.x)))
    {
        fall_time = 0;                
    }   
    //std::cout << fall_time << std::endl;

    // std::cout << "MaxFallTime: " << maxFallTime << std::endl;
    // std::cout << "MaxDistance: " << maxDistance << std::endl;
    // std::cout << "Ma xVelocity: " << maxVelocity << std::endl;
    // std::cout << "CurrentDistance: " << currentDistance << std::endl;
    // std::cout << "CurrentVelocity: " << currentVelocity << std::endl;
    // std::cout << "yPos: " << y << std::endl;

    
}
