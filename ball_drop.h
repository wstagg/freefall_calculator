#ifndef ball_dop_h
#define ball_dop_h

#include <SFML/Graphics.hpp>
void ball_drop();

class Ball
{
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Ball(float radius, sf::Color color, float x, float y)
    {
        shape.setRadius(radius);
        shape.setFillColor(color);
        shape.setPosition(x, y);
    }

    void update()
    {
        shape.move(velocity);
    }
};


#endif