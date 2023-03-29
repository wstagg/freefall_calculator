#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string_view>
#include <string>
#include <vector>
#include "inputs.h"
#include "ball_drop.h" 



int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Freefall Calculator");
    
    /* Creates text  */
    sf::Font arial;
    if (!arial.loadFromFile("C:\\Users\\wesleystagg\\source\\repos\\SFMLsquare\\arial.ttf"))
    {
        std::cout << "Cannot load text file.";
    }

    sf::Text welcome;
    welcome.setFont(arial);

    std::vector <std::string> welcome_text;
    welcome_text.push_back("Welcome to Freefall Calculator!");
    welcome_text.push_back("Please choose the object you would like to drop....");

    int welcome_vec_size = welcome_text.size()-1;
    
 
    /* Creates menu objects */
    sf::CircleShape menu_ball;
    menu_ball.setRadius(75);
    menu_ball.setPosition(600, 300);
    menu_ball.setFillColor(sf::Color::Blue);
    menu_ball.setOutlineColor(sf::Color::White);
    menu_ball.setOutlineThickness(0.0);




    sf::RectangleShape menu_square;
    menu_square.setSize(sf::Vector2f(150.f, 150.f));
    menu_square.setPosition(100, 300);
    menu_square.setFillColor(sf::Color::Red);
    menu_square.setOutlineColor(sf::Color::White);
    menu_square.setOutlineThickness(10.0);
    
    
    int next_text{ 0 };
    //std::cout << "next text before main " << next_text << std::endl;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }   
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    if (next_text < welcome_vec_size)
                    {
                        ++next_text;
                        std::cout << "next text: " << next_text;
                    }  
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    menu_ball.setOutlineThickness(10.0);
                    menu_square.setOutlineThickness(0.0);
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    menu_ball.setOutlineThickness(0.0);
                    menu_square.setOutlineThickness(10.0);
                }
            }
    
        }
        welcome.setString(welcome_text[next_text]);


        window.clear();
        window.draw(welcome);
        
        if (next_text == 1)
        {
            window.draw(menu_ball);
            window.draw(menu_square); 
        }
        window.display();


    }
    


    return 0;
}

/*std::cout << "\nWelcome to the freefall calculator!";
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


    }*/