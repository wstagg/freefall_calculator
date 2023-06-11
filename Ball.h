#pragma once

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>


class Ball
{

private:
    sf::CircleShape ball;
    sf::Vector2f ball_pos;
    sf::Color outline_colour;
    sf::Texture texture;
    
    float outline_thickness;
    float radius;


public:
    Ball(sf::Vector2f _ball_pos, sf::Color _outline_colour, sf::Texture _texture, float _outline_thickness, float _radius);

    void draw(sf::RenderWindow& window);

    void setOutlineThickness(float thickness);

    void setPosition(sf::Vector2f pos);

    void setRadius(float rad);

    void menu_drop(float velocity, float y_res);
};