#include "User_input_text.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Window/Event.hpp"
#include <string>
#include "inputs.h"


/* Constructor */
User_input_text::User_input_text(sf::Font _font, sf::Vector2f _text_position, sf::String _string):
font(_font),
text_position(_text_position),
string(_string)
{
    text.setFont(font);
    text.setPosition(text_position);
    text.setString(string);
}

/* Draws object to render window */
void User_input_text::draw(sf::RenderWindow& window)
{
    window.draw(text);
}

/* Takes tyoed user input sets it to the text */
void User_input_text::get_user_input(sf::Event event)
{
    if (event.text.unicode >= 48 && event.text.unicode <= 57)
    {
        text.setFillColor(sf::Color::White);
        input += event.text.unicode;
        text.setString(input); 
    }
}

/* Returns the input string */
std::string User_input_text::get_drop_ht_str()
{
    return input;
}

/* This handles the text cursor pulsating from white to black. Pulse */
/* frequency can be changed by editted "text_cursor_pulse_seconds"  */
void User_input_text::text_cursor(bool text_cursor_clock_start)
{
    if (text_cursor_clock_start)
    {
        sf::Time cursor_time_passed = text_cursor_clock.getElapsedTime();
        sf::Time text_cursor_pulse_seconds = sf::seconds(0.5f);
        
        if ((cursor_time_passed > text_cursor_pulse_seconds) && (switch_text_cursor_colour == 0))
        {
            switch_text_cursor_colour = 1;
            text.setFillColor(sf::Color::Black);
            text_cursor_clock.restart();
        }
        else if ((cursor_time_passed > text_cursor_pulse_seconds) && (switch_text_cursor_colour == 1))
        {
            switch_text_cursor_colour = 0;
            text.setFillColor(sf::Color::White);
            text_cursor_clock.restart();
        }
    }
}
 /* Erases the input text */
void User_input_text::erase()
{
    text.setString(erase_text(input));
}

