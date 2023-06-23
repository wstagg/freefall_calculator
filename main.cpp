#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "SFML/Graphics/Color.hpp"
#include "SFML/System/String.hpp"
#include "SFML/System/Vector2.hpp"
#include "inputs.h"
#include "calculations.h"
#include "Freefall_object.h"
#include "Cube.h"
#include "User_input_text.h"


int main()
{
    double x_res{ 1000.f };
    double y_res{ 800.f };
    sf::RenderWindow window(sf::VideoMode(x_res, y_res), "Freefall Calculator");
    window.setFramerateLimit(60);

    double x_middle{ x_res / 2.0 };
    double y_midlle{ y_res / 2.0 };

    /*------------------------------------*/
    /* Create text to display on screen   */
    /*------------------------------------*/
    sf::Font arial;
    if (!arial.loadFromFile("fonts//arial.ttf"))
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
    // sf::Text user_text;
    // user_text.setFont(arial);
    // sf::String user_input;

///////////////////////////////////////////////
    /* User input page */
    int next_text_input{ 0 }; // changes input selection

    User_input_text enter_drop_ht{arial, sf::Vector2f(0.f, 0.f), sf::String("Enter drop height (Meters):")};

    User_input_text enter_ob_mass{arial, sf::Vector2f(0.f, 300.f), sf::String("Enter object mass (KG):")};

    // sf::Text input_drop_ht;
    // input_drop_ht.setFont(arial);
    // input_drop_ht.setPosition(400, 0);
    // input_drop_ht.setString("I");
    // std::string drop_ht_string;

    User_input_text user_input_height{arial, sf::Vector2f(400.f, 0.f), sf::String("|")};

    sf::Text input_obj_mass;
    input_obj_mass.setFont(arial);
    input_obj_mass.setPosition(400, 300);
    std::string obj_mass_string;


///////////////////////////////////////////////
    
    sf::Text freefall_ht_txt;
    freefall_ht_txt.setFont(arial);
    //freefall_ht_txt.setString("test");
    sf::Vector2f ff_text_pos(0.f, 0.0f);
    freefall_ht_txt.setPosition(ff_text_pos);


    /*----------------------------------*/
    /* Load in textures for objects     */
    /*----------------------------------*/
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    
    sf::Texture concrete;
    if (!concrete.loadFromFile("textures//concrete_texture.jpg"))
    {
        std::cout << "Cannot load concrete texture\n";
    }

    sf::Texture crate;
    if (!crate.loadFromFile("textures//crate_texture.jpg"))
    {
        std::cout << "Cannot load crate texture\n";
    }

    sf::Texture backgorund_texture;
    if (!backgorund_texture.loadFromFile("textures//sky_bg.png"))
    {
        std::cout << "Cannot load background texture\n";
    }

    sf::Texture cloud_texture;
    if (!cloud_texture.loadFromFile("textures//cloud.png"))
    {
        std::cout << "Cannot load cloud texture\n";
    }

    /*----------------------*/
    /* Create menu objects  */
    /*----------------------*/
   
    Freefall_object menu_ball{ sf::Vector2f(600.f, 300.f), sf::Color::White, concrete, 0.f, 75.f, sf::Vector2f(0.f, 0.f)};

    sf::Vector2f ff_ball_pos(x_middle, 0);

    Freefall_object menu_cube{sf::Vector2f(200.f, 300.f) ,sf::Color::White, crate,10.f, 0.f, sf::Vector2f(150.f, 150.f) };
    
    sf::Vector2f ff_cube_pos(x_middle, 0);

    std::vector <float> cube_size(60.f, 60.f);
    float ball_rad{ 30.f };

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
    static int object_chosen {0};
    double drop_ht {}; // drop ht for maths
    double obj_mass{}; // object mass for maths

    double fall_velocity{};
    double rel_screen_drop_ht{};
    double fall_time{};

    //const float time_delta{ 0.5 };

    /*--------------------*/
    /*   Time Objects     */
   /*---------------------*/
    sf::Clock mass_input_clock;
    bool obj_mass_input_clock_start{ false };

    //sf::Clock text_cursor_clock;
    bool text_cursor_clock_start{ false };
    //int switch_text_cursor_colour{ 0 };

    sf::Clock freefall_clock;
    bool freefall_clock_start{ false };


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
                    else if ((next_display == 3) && (user_input_height.get_drop_ht_str().length() > 0) && (next_text_input == 0))
                    {
                        next_text_input = 1;
                        //input_drop_ht.setFillColor(sf::Color::Green);
                        input_obj_mass.setString("|");
                        text_cursor_clock_start = true;
                    }
                    else if ((next_text_input == 1) && (obj_mass_string.length() > 0))
                    {
                        mass_input_clock.restart();
                        input_obj_mass.setFillColor(sf::Color::Green);
                        obj_mass_input_clock_start = true;

                        menu_ball.setPosition(ff_ball_pos);
                        menu_cube.setPosition(ff_cube_pos);

                        menu_ball.setRadius(ball_rad);
                        menu_cube.setSize(sf::Vector2f(60,60));
                        
                        //debug use of calculation functions
                        fall_time = calculate_free_fall_time(obj_mass, drop_ht);
                        
                        //calculate_distance_fallen(drop_ht, fall_time);                       
                        
                        fall_velocity = obj_fall_velocity(fall_time, drop_ht, y_res);

                        std::cout << "fall velocity (pix per second) = " << fall_velocity << std::endl;
                        std::cout << "drop height = " << drop_ht << std::endl;
                        std::cout << "fall time = " << fall_time << std::endl;
                    }
                }
                /* Alows user to backaspace to delete text inputs */
                if (event.key.code == sf::Keyboard::BackSpace)
                {
                    if (next_text_input == 0)
                    { 
                        user_input_height.erase();                     
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
                    //if (event.text.unicode >= 48 && event.text.unicode <= 57)
                    //{
                        //std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl; 
                        //text_cursor_clock_start = false;
                        // input_drop_ht.setFillColor(sf::Color::White);
                        // drop_ht_string += event.text.unicode;                     
                        // input_drop_ht.setString(drop_ht_string);
                        user_input_height.get_user_input(event);
                        drop_ht = std::stod(user_input_height.get_drop_ht_str());                       
                    //}
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
            float menu_drop_velocity{ 10 };
            menu_text.setPosition(250, 0);
            
           
            if( object_chosen == 0)
            {
                menu_cube.menu_drop(y_res, next_display);
            }
            else 
            {
                menu_ball.menu_drop(y_res, next_display);
            }
            
            text_cursor_clock_start = true;
            
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
                    freefall_clock_start = true;
                    freefall_clock.restart();
                }
            }
            user_input_height.text_cursor(text_cursor_clock_start);
            // This handles the text cursor pulsating from white to black. Pulse //
            // frequency can be changed by editted "text_cursor_pulse_seconds"  //
            // if (text_cursor_clock_start)
            // {
            //     sf::Time cursor_time_passed = text_cursor_clock.getElapsedTime();
            //     sf::Time text_cursor_pulse_seconds = sf::seconds(0.5f);
               
            //     if ((cursor_time_passed > text_cursor_pulse_seconds) && (switch_text_cursor_colour == 0))
            //     {
            //         switch_text_cursor_colour = 1;
                    
            //         if (next_text_input == 0)
            //         {
            //             input_drop_ht.setFillColor(sf::Color::Black);
            //         }
            //         else if (next_text_input == 1)
            //         {
            //             input_obj_mass.setFillColor(sf::Color::Black);
            //         }
            //         text_cursor_clock.restart();
            //     }
            //     else if ((cursor_time_passed > text_cursor_pulse_seconds) && (switch_text_cursor_colour == 1))
            //     {
            //         switch_text_cursor_colour = 0;
                    
            //         if (next_text_input == 0)
            //         {
            //             input_drop_ht.setFillColor(sf::Color::White);
            //         }
            //         else if (next_text_input == 1)
            //         {
            //             input_obj_mass.setFillColor(sf::Color::White);
            //         }
            //         text_cursor_clock.restart();
            //     }
            //     //std::cout << cursor_time_passed.asSeconds() << std::endl;
            //     //std::cout << "switch colour: " << switch_text_cursor_colour << std::endl;
            // }
            
        }
        else if (next_display == 4)
        {
            if (freefall_clock_start == true)
            {
                sf::Time ff_timer = freefall_clock.getElapsedTime();
                sf::Time delta_time = sf::seconds(1);
                sf::Time total_fall_time = sf::seconds(fall_time);
                //static double drop_ht_n1 = drop_ht;

                //std::cout << ff_timer.asSeconds() << std::endl; // debug
                //std::cout << object_chosen << std::endl;
                if (ff_timer > delta_time)
                {
                    ff_cube_pos.y += fall_velocity;
                    menu_cube.setPosition(ff_cube_pos);

                    ff_ball_pos.y += fall_velocity;
                    menu_ball.setPosition(ff_ball_pos);

                    float mps = calculate_meters_per_second(drop_ht, fall_time);

                    drop_ht -= mps ;

                    freefall_clock.restart();

                    //std::cout << ff_cube_pos.y<< std::endl;
                    if (object_chosen == 0)
                    {
                        ff_text_pos.y = ff_cube_pos.y;
                        freefall_ht_txt.setString(std::to_string(drop_ht));
                    }
                    if (object_chosen == 1)
                    {
                        ff_text_pos.y = ff_ball_pos.y;
                        freefall_ht_txt.setString(std::to_string(drop_ht));
                    }

                    freefall_ht_txt.setPosition(ff_text_pos);
                }
                                   
                if ((ff_ball_pos.y == (y_res - (ball_rad *2))) || (ff_cube_pos.y > (y_res - cube_size[0])))
                {
                    freefall_clock_start = false;
                    //freefall_clock.restart();                  
                }
            }       
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
            //window.draw(menu_ball);
            menu_ball.draw(window);
            //window.draw(menu_cube);
            menu_cube.draw(window);

            window.draw(object_text); 
            window.draw(press_space);
        }
        /* Object selected page */
        else if (next_display == 2)
        {
            window.draw(menu_text);
            if (object_chosen == 0)
            {
                //window.draw(menu_cube);
                menu_cube.draw(window);

            }
            else
            {
                //window.draw(menu_ball);
                menu_ball.draw(window);
            }
        }
        /* User input page */
        else if (next_display == 3)
        {
            window.draw(press_space);
            enter_drop_ht.draw(window);
            enter_ob_mass.draw(window);
            user_input_height.draw(window);
            window.draw(input_obj_mass);
            //window.draw(text_cursor);
        } 
        else if (next_display == 4)
        {                        
            //window.draw(background_image);
            //window.draw(cloud);
            if (object_chosen == 0)
            {
                //window.draw(menu_cube);
                menu_cube.draw(window);

            }
            else if (object_chosen == 1)
            {
                //window.draw(menu_ball);
                menu_ball.draw(window);



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


