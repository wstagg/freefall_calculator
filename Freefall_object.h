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
    float outline_thickness;
    float radius;


public:
    Freefall_object(sf::Vector2f _object_position, sf::Color _outline_colour, sf::Texture _texture, float _outline_thickness, float _radius, sf::Vector2f _cube_size);

    void draw(sf::RenderWindow& window);

    void setOutlineThickness(float thickness);

    void setPosition(sf::Vector2f pos);

    void setRadius(float rad);

    void setSize(sf::Vector2f size);

    void menu_drop(float y_res, int &next_display);

    int object_chosen {};

};