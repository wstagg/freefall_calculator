#include "Freefall_object.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"

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

