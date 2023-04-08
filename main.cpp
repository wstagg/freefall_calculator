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
    
    /*------------------------------------*/
    /* Creating text to display on screen */
    /*------------------------------------*/
    sf::Font arial;
    if (!arial.loadFromFile("C:\\Users\\wesleystagg\\source\\repos\\SFMLsquare\\arial.ttf"))
    {
        std::cout << "Cannot load font file.";
    }
    sf::Text menu_text;
    menu_text.setFont(arial);

    std::vector <std::string> welcome_text;
    welcome_text.push_back("Welcome to Freefall Calculator!");
    welcome_text.push_back("Please choose the object you would like to drop....");

    std::vector <std::string> obj_selection_txt;
    obj_selection_txt.push_back("Cube selected!");
    obj_selection_txt.push_back("Ball selected!");

   

    int welcome_vec_size = welcome_text.size()-1; 
    int next_text{ 0 }; // Used to iterate through the welcome text vector

    // Text for object selection 
    sf::Vector2f cube_text_pos(230.0, 500.0);
    sf::Vector2f ball_text_pos(640.0, 500.0);

    sf::Text object_text;
    object_text.setFont(arial);
    object_text.setString("CUBE");
    object_text.setPosition(cube_text_pos);
   

    /*----------------------------------*/
    /* Loading in textures for objects  */
    /*----------------------------------*/
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::Texture concrete;
    if (!concrete.loadFromFile("C:\\Users\\wesleystagg\\textures\\concrete_texture.jpg"));
    {
        std::cout << "Cannot load concrete texture\n";
    }

    sf::Texture crate;
    if (!crate.loadFromFile("C:\\Users\\wesleystagg\\textures\\crate_texture.jpg"))
    {
        std::cout << "Cannot load concrete texture\n";
    }

    sf::Texture backgorund;
    if (!backgorund.loadFromFile("C:\\Users\\wesleystagg\\textures\\sky_bg.png"))
    {
        std::cout << "Cannot load background texture\n";
    }
    
    /*----------------------*/
    /* Creates menu objects */
    /*----------------------*/
    sf::CircleShape menu_ball;
    menu_ball.setRadius(75);
    menu_ball.setPosition(600, 300);
    menu_ball.setOutlineColor(sf::Color::White);
    menu_ball.setOutlineThickness(0.0);
    menu_ball.setTexture(&concrete);

    sf::RectangleShape menu_cube;
    menu_cube.setSize(sf::Vector2f(150.f, 150.f));
    menu_cube.setPosition(200, 300);
    menu_cube.setOutlineColor(sf::Color::White);
    menu_cube.setOutlineThickness(10.0);
    menu_cube.setTexture(&crate);

    /*---------------------*/
    /*   Main Objects      */
    /*---------------------*/
    int object_chosen {0};

    
    /*---------------------*/
    /*   main event loop   */
    /*---------------------*/
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
                    // This goes up to the object selection menu 
                    if (next_text < 1) 
                    {
                        ++next_text;
                        std::cout << "next text: " << next_text;
                    }
                    // Cube chosen
                    else if (object_chosen == 0 && next_text == 1)
                    {
                            menu_text.setString(obj_selection_txt[0]);
                            menu_text.setCharacterSize(75);
                            menu_text.setPosition(250, 0);
                            menu_cube.setPosition(320, 300);
                            menu_cube.setScale(2, 2);
                            menu_cube.setOutlineThickness(0);
                            ++next_text;
                    }
                    // Ball Chosen
                    else if (object_chosen == 1 && next_text == 1)
                    {
                        menu_text.setString(obj_selection_txt[1]);
                        menu_text.setCharacterSize(75);
                        menu_text.setPosition(250, 0);
                        menu_ball.setPosition(320, 300);
                        menu_ball.setScale(2, 2);
                        menu_ball.setOutlineThickness(0);
                        ++next_text;
                    }
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    menu_ball.setOutlineThickness(10.0);
                    menu_cube.setOutlineThickness(0.0);
                    object_text.setString("BALL");
                    object_text.setPosition(ball_text_pos);
                    object_chosen = 1;

                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    menu_ball.setOutlineThickness(0.0);
                    menu_cube.setOutlineThickness(10.0);
                    object_text.setString("CUBE");
                    object_text.setPosition(cube_text_pos);
                    object_chosen = 0;
                }
            }
        }
        if (next_text == 0)
        {
            menu_text.setPosition(165, 300);
            menu_text.setCharacterSize(50);
            menu_text.setString(welcome_text[0]);
        }
        else if (next_text == 1)
        {
            menu_text.setPosition(165, 0);
            menu_text.setCharacterSize(30);
            menu_text.setString(welcome_text[1]);
        }
        
        //menu_text.setString(welcome_text[next_text]);
        /*---------------------*/
        /*   Main draw block   */
        /*---------------------*/
        window.clear();
        if (next_text == 0)
        {
            window.draw(menu_text);
        }
        else if (next_text == 1)
        {
            window.draw(menu_text);
            window.draw(menu_ball);
            window.draw(menu_cube);
            window.draw(object_text);   
        }
        else if (next_text == 2)
        {
            window.draw(menu_text);
            if (object_chosen == 0)
            {
                window.draw(menu_cube);
            }
            else
            {
                window.draw(menu_ball);
            }
        }
        window.display();

    }
    return 0;
}
