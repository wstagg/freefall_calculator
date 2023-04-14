#include <iostream>
#include "inputs.h"
#include <SFML/Graphics.hpp>

// Gets input from user (double)
double get_input_d()
{
    double input_num {};
    
    std:: cin >> input_num;
    
    return input_num;
}

// Gets input from user (char)
char get_input_c()
{
    char input_char {};
    
    std:: cin >> input_char;
    
    return input_char;
}


