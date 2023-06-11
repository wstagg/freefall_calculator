#ifndef calculations_h
#define calculations_h

double calculate_terminal_velocity(double mass, double area);
double calculate_free_fall_time(double mass, double height);
double calculate_meters_per_second(double height, double fall_time);
double calculate_projected_area(double diameter);
double obj_fall_velocity(double fall_time, double drop_ht, double screen_ht);

#endif
