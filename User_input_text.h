#pragma once 

#include <SFML/Graphics.hpp>
#include <string>
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/String.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

class User_input_text
{
private:
    sf::Text text;
    sf::Font font;
    sf::Vector2f text_position;
    sf::String string;
    std::string input;
    sf::Color text_colour;
    double drop_ht;
    sf::Clock text_cursor_clock;
    //bool text_cursor_clock_start{ false };
    int switch_text_cursor_colour{ 0 };

    
    
public:
    
    User_input_text(sf::Font _font, sf::Vector2f _text_position, sf::String _string);

    void draw(sf::RenderWindow& window);

    void setPosition(sf::Vector2f pos);

    void get_user_input(sf::Event event);

    std::string get_drop_ht_str();

    void text_cursor(bool text_cursor_clock_start);

    void erase();


};