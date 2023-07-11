#include "User_input_text.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Window/Event.hpp"
#include <string>
#include "inputs.h"
#include <iostream>



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
void User_input_text::get_user_input(sf::Event event, int next_text)
{
    if (event.text.unicode >= 48 && event.text.unicode <= 57)
    {
        stop_text_cursor_clock();
        text.setFillColor(sf::Color::White);
        input += event.text.unicode;
        text.setString(input); 

        if (next_text == 0)
        {
            drop_ht = stod(input);
        }
        if (next_text == 1)
        {
            obj_mass = stod(input);
        }
    }
    
}

/* Returns the input string */
std::string User_input_text::return_string()
{
    return input;
}

/* This handles the text cursor pulsating from white to black. Pulse */
/* frequency can be changed by editted "text_cursor_pulse_seconds"  */
void User_input_text::text_cursor()
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
void User_input_text::erase_text()
{
    if (input.length() > 0)
    {
        input = input.erase(input.length()-1, 1);
        std::cout << input.length() << std::endl;
        text.setString(input);
    }

}

void User_input_text::start_text_cursor_clock()
{
    text_cursor_clock_start = true;
}

void User_input_text::stop_text_cursor_clock()
{
    text_cursor_clock_start = false;
}

void User_input_text::setString(std::string input_text)
{
    text.setString(input_text);
}

void User_input_text::setFillColor(sf::Color colour)
{
    text.setFillColor(colour);
}

int User_input_text::return_string_Lenght()
{
    return input.length();
}

double User_input_text::return_drop_ht()
{
    std::cout << "User_input_text::return_drop_ht: " << drop_ht << std::endl;
    return drop_ht;
}

double User_input_text::return_obj_mass()
{
    std::cout << "User_input_text::return_obj_mass: " << obj_mass << std::endl;
    return obj_mass;
}