#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string_view>
#include "inputs.h"
#include "ball_drop.h"

int main()
{
    
    std::cout << "\nWelcome to the freefall calculator!";
    int running{ 1 };
    while (running)
    {
        std::cout << "\n\nPlease choose the object you would like to drop...\
            \nor enter (q) to quit.\n\n(b) Ball\n(c) Cube\n\nEnter the your choice: " ;
        
        char start{ get_input_c() };

        if (start == 'b')
        {
            ball_drop();
        }
        else
        {
            std::cout << "Goodbye!\n";
            running = 0;
        }


    }


    return 0;
}


/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/