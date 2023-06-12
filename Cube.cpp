#include "Cube.h"
#include "SFML/System/Vector2.hpp"

/* Cube object condtructor */
Cube::Cube(sf::Vector2f _cube_position, sf::Vector2f _cube_size, sf::Color _outline_colour, sf::Texture _texture, float _outline_thickness):
cube_position(_cube_position),
cube_size(_cube_size),
outline_colour(_outline_colour),
texture(_texture),
outline_thickness(_outline_thickness)
{
    cube.setSize(cube_size);
    cube.setPosition(cube_position);
    cube.setOutlineColor(outline_colour);
    cube.setOutlineThickness(outline_thickness);
    cube.setTexture(&texture);   
}

void Cube::draw(sf::RenderWindow& window)
{
    window.draw(cube);
}

void Cube::setOutlineThickness (float thickness)
{
    cube.setOutlineThickness(thickness);
}

void Cube::setPosition(sf::Vector2f pos)
{
    cube.setPosition(pos);
}

void Cube::setSize(sf::Vector2f size)
{
    cube.setSize(size);
}

void Cube::menu_drop(float y_res, int &next_display)
{
    float velocity {10.f};
    cube_position.y += velocity;
    setPosition(cube_position);

    if (cube_position.y > y_res)
    {
        next_display = 3;
    }
}