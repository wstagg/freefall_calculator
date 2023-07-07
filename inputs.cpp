#include <iostream>
#include "inputs.h"
#include <SFML/Graphics.hpp>

/* This deletes the last charater in a string */
std::string erase_text(std::string &text)
{
    if (text.length() > 0)
    {
        std::cout << text.length() << std::endl;
        text = text.erase(text.size() - 1, 1);
    }
    return text;
}

