#include "Ball.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"

/* Ball class constructor */
Ball::Ball(sf::Vector2f _ball_position, sf::Color _outline_colour, sf::Texture _texture, float _outline_thickness, float _radius):
ball_position(_ball_position),
outline_colour(_outline_colour),
texture(_texture),
outline_thickness(_outline_thickness),
radius(_radius)
{
    ball.setRadius(radius);
    ball.setPosition(ball_position);
    ball.setOutlineColor(outline_colour);
    ball.setOutlineThickness(outline_thickness);
    ball.setTexture(&texture);   
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(ball);
}

void Ball::setOutlineThickness (float thickness)
{
    ball.setOutlineThickness(thickness);
}

void Ball::setPosition(sf::Vector2f pos)
{
    ball.setPosition(pos);
}

void Ball::setRadius(float rad)
{
    ball.setRadius(rad);
}

void Ball::menu_drop(float y_res, int &next_display)
{
    float velocity {10.f};
    ball_position.y += velocity;
    setPosition(ball_position);

    if (ball_position.y > y_res)
    {
        next_display = 3;
    }
}

