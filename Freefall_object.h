#pragma once

#include <SFML/Graphics.hpp>

class Freefall_object
{

private:
    sf::CircleShape ball;
    sf::RectangleShape cube;
    sf::Vector2f object_position;
    sf::Color outline_colour;
    sf::Texture texture;
    sf::Vector2f cube_size;
    float outline_thickness{};
    float radius{};
    double in_drop_ht{};
    double in_obj_mass{};
    sf::Clock ff_clock;
    
    /* Freefall calulations */
    double calculate_terminal_velocity(double mass, double area);
    double calculate_free_fall_time(double mass, double height);
    double calculate_meters_per_second(double height, double fall_time);
    double calculate_projected_area(double diameter);
    double obj_fall_velocity(double fall_time, double drop_ht, double screen_ht);
    double calculate_Distance_Travelled_In_Time(double fall_time, double mass);
    double calculate_velocity(double fall_time, double mass);

    const double g{ 9.80665 };   // Gravity (m/s2)
    const double p{ 1.2041 };    // Density of air (kg/m3)
    const double e{ 2.71828 };   // Euler's number (e)
    const double k{ 0.24 };      // Air resistance (kg/m)
    const double pi{ 3.142 };    // Pi
    
public:
    Freefall_object(sf::Vector2f _object_position, sf::Color _outline_colour, sf::Texture _texture ,float _outline_thickness, float _radius, sf::Vector2f _cube_size);

    void draw(sf::RenderWindow& window);

    void setOutlineThickness(float thickness);

    void setPosition(sf::Vector2f pos);

    void setRadius(float rad);

    void setSize(sf::Vector2f size);

    void menu_drop(float y_res, int &next_display);

    void object_freefall();

    void get_user_inputs(double drop_ht, double object_mass);

    int object_chosen {};

    void obj_fall_pos(double screen_ht);


};