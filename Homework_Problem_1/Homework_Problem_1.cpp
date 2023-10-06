// Homework_Problem_1.cpp : Defines the entry point for the application.
//

#include "Homework_Problem_1.h"
#include <iostream>

using namespace std;


int main() {

    // Defining the parameters

    // Roll damping coefficient
    const double Lp = 0.6;   
    // Aileron effectiveness
    const double Ldelta = 0.8;  

    // Initial conditions

    // Initial roll rate in rad/s
    const double initial_roll_rate = 1.0; 
    // Time step size
    const double time_step = 0.01; 
    // Total simulating time
    const double tspan = 5.0; 

    // Initializing the variables
    double p = initial_roll_rate;
    double t = 0.0;

    // Simulating roll rate over time
    while (t <= tspan) {
        // Aileron deflection Applied for the first 2 seconds only (AD = 1)
        if (t <= 2.0) {
            p += (Lp * p + Ldelta * 1.0) * time_step;
        }
        // Aileron deflection gone after 2 seconds
        else {
            p += (Lp * p) * time_step;
        }

        // Printing time and roll rate
        cout << "Time: " << t << " s, Roll Rate: " << p << " rad/s" << endl;

        // Increment time
        t += time_step;
    }

    return 0;
}
