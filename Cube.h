#pragma once

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>


class Cube
{
private:
    sf::RectangleShape cube;
    sf::Vector2f cube_position;
    sf::Vector2f cube_size;
    sf::Color outline_colour;
    sf::Texture texture;
    float outline_thickness;

public:
    Cube(sf::Vector2f _cube_position, sf::Vector2f _cube_size, sf::Color _outline_colour, sf::Texture _texture, float _outline_thickness);

    void draw(sf::RenderWindow& window);

    void setOutlineThickness(float thickness);

    void setPosition(sf::Vector2f pos);

    void setSize(sf::Vector2f size);

    void menu_drop(float y_res, int &next_display);
};