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
    double obj_mass;
    sf::Clock text_cursor_clock;
    bool text_cursor_clock_start{ false };
    int switch_text_cursor_colour{ 0 };

    
    
public:
    
    User_input_text(sf::Font _font, sf::Vector2f _text_position, sf::String _string);

    void draw(sf::RenderWindow& window);

    void get_user_input(sf::Event event, int next_text);

    std::string return_string();

    void text_cursor();

    void erase_text();

    void start_text_cursor_clock();
    
    void stop_text_cursor_clock();

    void setString(std::string input_text);

    void setFillColor(sf::Color colur);

    int return_string_Lenght();

    double return_drop_ht();

    double return_obj_mass();

};