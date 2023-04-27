#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "inputs.h"
#include "ball_drop.h" 
#include "calculations.h"


int main()
{
    int x_res{ 1000 };
    int y_res{ 800 };
    sf::RenderWindow window(sf::VideoMode(x_res, y_res), "Freefall Calculator");
    window.setFramerateLimit(60);
    
    /*------------------------------------*/
    /* Create text to display on screen   */
    /*------------------------------------*/
    sf::Font arial;
    if (!arial.loadFromFile("fonts\\arial.ttf"))
    {
        std::cout << "Cannot load font file.";
    }

    sf::Text menu_text;
    menu_text.setFont(arial);
    //menu_text.setFillColor(sf::Color::Black);
    menu_text.setOutlineThickness(0.5);

    std::vector <std::string> welcome_text;
    welcome_text.push_back("Welcome to Freefall Calculator!");
    welcome_text.push_back("Please choose the object you would like to drop....");

    std::vector <std::string> obj_selection_txt;
    obj_selection_txt.push_back("Cube selected!");
    obj_selection_txt.push_back("Ball selected!");

    int welcome_vec_size = welcome_text.size()-1; 
    
    /* Used to iterate through different pages of the application */
    int next_display{ 0 };   

    /* Text for object selection */
    sf::Vector2f cube_text_pos(230.0, 500.0);
    sf::Vector2f ball_text_pos(640.0, 500.0);
    sf::Text object_text;
    object_text.setFont(arial);
    //object_text.setFillColor(sf::Color::Black);
    object_text.setString("Cube");
    object_text.setPosition(cube_text_pos);
    
    /* Text for pressing space bar */
    sf::Text press_space;
    press_space.setFont(arial);
    //press_space.setFillColor(sf::Color::Black);
    press_space.setString("Push space to continue...");
    press_space.setPosition(320, 700);

    /* User input text */
    sf::Text user_text;
    user_text.setFont(arial);
    sf::String user_input;

    /* User input page */
    int next_text_input{ 0 }; // changes input selection

    sf::Text get_drop_ht;
    get_drop_ht.setFont(arial);
    //get_drop_ht.setFillColor(sf::Color::Black);
    get_drop_ht.setPosition(0, 0);
    get_drop_ht.setString("Enter drop height (Meters):");

    sf::Text input_drop_ht;
    input_drop_ht.setFont(arial);
    input_drop_ht.setPosition(400, 0);
    input_drop_ht.setString("I");
    std::string drop_ht_string;

    sf::Text get_obj_mass;
    get_obj_mass.setFont(arial);
    //get_obj_mass.setFillColor(sf::Color::Black);
    get_obj_mass.setPosition(0, 300);
    get_obj_mass.setString("Enter object mass (KG):");

    sf::Text input_obj_mass;
    input_obj_mass.setFont(arial);
    input_obj_mass.setPosition(400, 300);
    std::string obj_mass_string;

    
    /*----------------------------------*/
    /* Load in textures for objects     */
    /*----------------------------------*/
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::Texture concrete;
    if (!concrete.loadFromFile("textures\\concrete_texture.jpg"));
    {
        std::cout << "Cannot load concrete texture\n";
    }

    sf::Texture crate;
    if (!crate.loadFromFile("textures\\crate_texture.jpg"))
    {
        std::cout << "Cannot load crate texture\n";
    }

    sf::Texture backgorund_texture;
    if (!backgorund_texture.loadFromFile("textures\\sky_bg.png"))
    {
        std::cout << "Cannot load background texture\n";
    }
    
    sf::Texture cloud_texture;
    if (!cloud_texture.loadFromFile("textures\\cloud.png"))
    {
        std::cout << "Cannot load clout texture\n";
    }
    
    /*----------------------*/
    /* Create menu objects  */
    /*----------------------*/
    sf::CircleShape menu_ball;
    menu_ball.setRadius(75);
    sf::Vector2f menu_ball_pos(600, 300);
    menu_ball.setPosition(menu_ball_pos);
    menu_ball.setOutlineColor(sf::Color::White);
    menu_ball.setOutlineThickness(0.0);
    menu_ball.setTexture(&concrete);

    sf::RectangleShape menu_cube;
    menu_cube.setSize(sf::Vector2f(150.f, 150.f));
    sf::Vector2f menu_cube_pos(200, 300);
    menu_cube.setPosition(menu_cube_pos);
    menu_cube.setOutlineColor(sf::Color::White);
    menu_cube.setOutlineThickness(10.0);
    menu_cube.setTexture(&crate);

    /*-------------------------*/
    /* Creates menu background */
    /*-------------------------*/
    sf::Sprite background_image;
    background_image.setScale(1,1);
    background_image.setTexture(backgorund_texture);
    //background_image.setColor(sf::Color::Blue);

    sf::Sprite cloud;
    cloud.setTexture(cloud_texture);
    cloud.setScale(0.1, 0.1);
    
    /*---------------------*/
    /*   Main Objects      */
    /*---------------------*/
    int object_chosen {0};
    double drop_ht {}; // drop ht for maths
    double obj_mass{}; // object mass for maths


    /*--------------------*/
    /*   Time Objects     */
   /*---------------------*/
    sf::Clock mass_input_clock;
    bool obj_mass_input_clock_start{ false };

    sf::Clock text_cursor_clock;
    bool text_cursor_clock_start{ false };
    int switch_text_cursor_colour{ 0 };

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
                    /* This changes to the object selection menu */
                    if (next_display < 1) 
                    {
                        next_display = 1;
                    }
                    /* Cube chosen */ 
                    else if (object_chosen == 0 && next_display == 1)
                    {
                            menu_text.setString(obj_selection_txt[0]);
                            menu_text.setCharacterSize(75);                            
                            menu_cube.setOutlineThickness(0);
                            next_display = 2;
                    }
                    /* Ball Chosen */
                    else if (object_chosen == 1 && next_display == 1)
                    {
                        menu_text.setString(obj_selection_txt[1]);
                        menu_text.setCharacterSize(75);                   
                        menu_ball.setOutlineThickness(0);
                        next_display = 2;
                    }
                    /* Goes to next text input when drop_ht string length is > 0 */
                    else if ((next_display == 3) && (drop_ht_string.length() > 0) && (next_text_input == 0))
                    {
                        next_text_input = 1;
                        input_drop_ht.setFillColor(sf::Color::Green);
                        input_obj_mass.setString("I");
                        text_cursor_clock_start = true;
                    }
                    else if ((next_text_input == 1) && (obj_mass_string.length() > 0))
                    {
                        mass_input_clock.restart();
                        input_obj_mass.setFillColor(sf::Color::Green);
                        obj_mass_input_clock_start = true;
                        
                        //debug use of calculation functions
                        double fall_time{ calculate_free_fall_time(obj_mass, drop_ht) };
                        calculate_distance_fallen(drop_ht, fall_time);
                    }
                }
                /* Alows user to backaspace to delete text inputs */
                if (event.key.code == sf::Keyboard::BackSpace)
                {
                    if (next_text_input == 0)
                    { 
                        input_drop_ht.setString(erase_text(drop_ht_string));
                    }
                    else if (next_text_input == 1)
                    {
                        input_obj_mass.setString(erase_text(obj_mass_string));
                    }
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    if (next_display == 1)
                    {
                        menu_ball.setOutlineThickness(10.0);
                        menu_cube.setOutlineThickness(0.0);
                        object_text.setString("Ball");
                        object_text.setPosition(ball_text_pos);
                        object_chosen = 1;
                            std::cout << "ball chosen\n";
                    }
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    if (next_display == 1)
                    {
                        menu_ball.setOutlineThickness(0.0);
                        menu_cube.setOutlineThickness(10.0);
                        object_text.setString("Cube");
                        object_text.setPosition(cube_text_pos);
                        object_chosen = 0;
                            std::cout << "cube chosen\n";
                    }
                }
            }
            if ((event.type == sf::Event::TextEntered) && (next_display == 3))
            {
                if (next_text_input == 0)
                {
                    if (event.text.unicode >= 48 && event.text.unicode <= 57)
                    {
                        //std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl; 
                        text_cursor_clock_start = false;
                        input_drop_ht.setFillColor(sf::Color::White);
                        drop_ht_string += event.text.unicode;                     
                        input_drop_ht.setString(drop_ht_string);
                        drop_ht = std::stod(drop_ht_string);                       
                    }
                }
                else if (next_text_input == 1)
                {
                    if (event.text.unicode >= 48 && event.text.unicode <= 57)
                    {
                        //std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
                        text_cursor_clock_start = false;
                        input_obj_mass.setFillColor(sf::Color::White);
                        obj_mass_string += event.text.unicode;
                        input_obj_mass.setString(obj_mass_string);
                        obj_mass = std::stod(obj_mass_string);
                    }
                }
            }
        }
        
        /*************************************/
        /****** Display specific events ******/
        /*************************************/
        
        /* Changes the font size and text position for menu text */
        if (next_display == 0)
        {
            menu_text.setPosition(165, 300);
            menu_text.setCharacterSize(50);
            menu_text.setString(welcome_text[0]);
        }
        else if (next_display == 1)
        {
            menu_text.setPosition(165, 0);
            menu_text.setCharacterSize(30);
            menu_text.setString(welcome_text[1]);
        }

        /* Changes the y pos of object when it has been selected to make 
           it drop from the screen */
        else if (next_display == 2)
        {
            float fall_velocity{ 10 };
            menu_text.setPosition(250, 0);
            menu_cube_pos.y += fall_velocity;
            menu_ball_pos.y += fall_velocity;
            menu_cube.setPosition(menu_cube_pos);
            menu_ball.setPosition(menu_ball_pos);
            //std::cout << menu_ball_pos.y << std::endl;
            if ((menu_ball_pos.y  > y_res) || (menu_cube_pos.y > y_res))
            {
                next_display = 3;
                text_cursor_clock_start = true;
            }
        }
        else if (next_display == 3)
        {
            
            /*************************/
            /****** Time Events ******/
            /*************************/
            
            // This handles the delay when the object mass has been inputted to //
            // allow the text enough time to go green before changing to the    //
            // object drop animation.                                          //
            if (obj_mass_input_clock_start)
            {
                sf::Time obj_seconds_passed = mass_input_clock.getElapsedTime();
                sf::Time obj_seconds = sf::seconds(1.f);
                if (obj_seconds_passed > obj_seconds)
                {
                    next_display = 4;
                }
            }
            
            // This handles the text cursor pulsating from white to black. Pulse //
            // frequency can be changed by editting "text_cursor_pulse_seconds"  //
            if (text_cursor_clock_start)
            {
                sf::Time cursor_time_passed = text_cursor_clock.getElapsedTime();
                sf::Time text_cursor_pulse_seconds = sf::seconds(0.5f);
               
                if ((cursor_time_passed > text_cursor_pulse_seconds) && (switch_text_cursor_colour == 0))
                {
                    switch_text_cursor_colour = 1;
                    
                    if (next_text_input == 0)
                    {
                        input_drop_ht.setFillColor(sf::Color::Black);
                    }
                    else if (next_text_input == 1)
                    {
                        input_obj_mass.setFillColor(sf::Color::Black);
                    }
                    text_cursor_clock.restart();
                }
                else if ((cursor_time_passed > text_cursor_pulse_seconds) && (switch_text_cursor_colour == 1))
                {
                    switch_text_cursor_colour = 0;
                    
                    if (next_text_input == 0)
                    {
                        input_drop_ht.setFillColor(sf::Color::White);
                    }
                    else if (next_text_input == 1)
                    {
                        input_obj_mass.setFillColor(sf::Color::White);
                    }
                    text_cursor_clock.restart();
                }
                //std::cout << cursor_time_passed.asSeconds() << std::endl;
                //std::cout << "switch colour: " << switch_colour << std::endl;   
            }
            
        }
        else if (next_display == 4)
        {
            menu_ball.setPosition(0, 0);
            menu_cube.setPosition(0, 0);
        }   
        /*******************************/
        
        /*---------------------*/
        /*   Main draw block   */
        /*---------------------*/
        window.clear();
        //window.draw(background_image);
        
        /* Application welcoms page */
        if (next_display == 0)
        {
            //window.draw(cloud);
            window.draw(menu_text);
            window.draw(press_space);   
        }
        // Object selection page
        else if (next_display == 1)
        {
            window.draw(menu_text);
            window.draw(menu_ball);
            window.draw(menu_cube);
            window.draw(object_text); 
            window.draw(press_space);
        }
        /* Object selected page */
        else if (next_display == 2)
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
        /* User input page */
        else if (next_display == 3)
        {
            window.draw(press_space);
            window.draw(get_drop_ht);
            window.draw(get_obj_mass);
            window.draw(input_drop_ht);
            window.draw(input_obj_mass);
            //window.draw(text_cursor);
        } 
        else if (next_display == 4)
        {                        
            window.draw(background_image);
            //window.draw(cloud);
            if (object_chosen == 0)
            {
                window.draw(menu_cube);
            }
            else if (object_chosen == 1)
            {
                window.draw(menu_ball);

            }
        }
        window.display();
       
        /* debug cout */

        //std::cout << "next text: " << next_text << std::endl;
        //std::cout << drop_ht << std::endl;
        //std::cout << obj_mass << std::endl;
    }
    return 0;
}


