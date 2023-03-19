#include "ball_drop.h"
#include <iostream>
#include <iomanip>
#include "inputs.h"
#include "calculations.h"


void ball_drop()
{
    std::cout << "You have chosen to drop a ball\n\n";
    
    std::cout << "Please enter a ball mass in KG: ";
    double ball_mass{ get_input_d() };

    std::cout << "\nPlease enter a drop height in meters: ";
    double drop_height{ get_input_d() };
    double freefall_time{ calculate_free_fall_time(ball_mass, drop_height) };

    std::cout << std::setprecision(4);

    std::cout << "\nA ball weighing " << ball_mass << "kg dropped from " <<
        drop_height << " meters,\n" << "will take " << freefall_time <<
        " seconds to hit the ground.\n\n";

    calculate_distance_fallen(drop_height, freefall_time);
}
