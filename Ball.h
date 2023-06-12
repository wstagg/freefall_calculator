#pragma once

#include <SFML/Graphics.hpp>

class Ball
{

private:
    sf::CircleShape ball;
    sf::Vector2f ball_position;
    sf::Color outline_colour;
    sf::Texture texture;
    
    float outline_thickness;
    float radius;


public:
    Ball(sf::Vector2f _ball_position, sf::Color _outline_colour, sf::Texture _texture, float _outline_thickness, float _radius);

    void draw(sf::RenderWindow& window);

    void setOutlineThickness(float thickness);

    void setPosition(sf::Vector2f pos);

    void setRadius(float rad);

    void menu_drop(float y_res, int &next_display);
};