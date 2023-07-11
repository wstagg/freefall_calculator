#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>
#include <vector> 

#include "Menu.h"
#include "inputs.h"
#include "Freefall_object.h"
#include "User_input_text.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init()
{
    sf::RectangleShape box({50,50});
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

///////////////////////////////////////////////
    /* User input page */
    int next_text_input{ 0 }; // changes input selection

    User_input_text enter_drop_ht{arial, sf::Vector2f(0.f, 0.f), sf::String("Enter drop height (Meters):")};

    User_input_text enter_ob_mass{arial, sf::Vector2f(0.f, 300.f), sf::String("Enter object mass (KG):")};

    User_input_text user_input_height{arial, sf::Vector2f(400.f, 0.f), sf::String("|")};

    User_input_text user_input_mass{arial, sf::Vector2f(400.f, 300.f), sf::String("")};

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

    /*******************************/
    /*** Create freefall objects ***/
    /*******************************/
   
    Freefall_object menu_ball{ sf::Vector2f(600.f, 300.f), sf::Color::White, concrete ,0.f, 75.f, sf::Vector2f(0.f, 0.f)};

    Freefall_object menu_cube{sf::Vector2f(200.f, 300.f) ,sf::Color::White, crate, 10.f, 0.f, sf::Vector2f(150.f, 150.f) };

    std::vector <float> cube_size(60.f, 60.f);

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
    // double drop_ht {}; // drop ht for maths
    // double obj_mass{}; // object mass for maths

    /*--------------------*/
    /*   Time Objects     */
   /*---------------------*/
    sf::Clock mass_input_clock;
    bool obj_mass_input_clock_start{ false };

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
                    else if ((next_display == 3) && (user_input_height.return_string().length() > 0) && (next_text_input == 0))
                    {
                        next_text_input = 1;
                        user_input_mass.start_text_cursor_clock();
                        user_input_height.setFillColor(sf::Color::Green);
                        user_input_mass.setString("|");
                        ;
                    }
                    else if ((next_text_input == 1) && (user_input_mass.return_string_Lenght() > 0))
                    {
                        mass_input_clock.restart();
                        user_input_mass.setFillColor(sf::Color::Green);
                        obj_mass_input_clock_start = true;
                        if(object_chosen == 0)
                        {
                            menu_cube.get_user_inputs(user_input_height.return_drop_ht(), user_input_mass.return_obj_mass());
                        }
                        if(object_chosen == 1)
                        {
                            menu_ball.get_user_inputs(user_input_height.return_drop_ht(), user_input_mass.return_obj_mass());
                        }
                    }
                }
                /* Alows user to backaspace to delete text inputs */
                if (event.key.code == sf::Keyboard::BackSpace)
                {
                    if (next_text_input == 0)
                    { 
                        user_input_height.erase_text();                     
                    }
                    else if (next_text_input == 1)
                    {
                        user_input_mass.erase_text();
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
                    user_input_height.get_user_input(event, next_text_input);                         
                }
                else if (next_text_input == 1)
                {
                    user_input_mass.get_user_input(event, next_text_input);                       
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
            menu_text.setPosition(250, 0);
            
            if( object_chosen == 0)
            {
                menu_cube.menu_drop(y_res, next_display);
            }
            else 
            {
                menu_ball.menu_drop(y_res, next_display);
            }
            
            user_input_height.start_text_cursor_clock();
            
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
            
            user_input_height.text_cursor();  
            user_input_mass.text_cursor();
        }
        else if (next_display == 4)
        {       
                if(object_chosen == 0) menu_cube.obj_fall_pos(y_res);
                
                if(object_chosen == 1) menu_ball.obj_fall_pos(y_res);

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
            user_input_mass.draw(window);
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
                //window.draw(box);

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
   
}