// Homework_Problem_3.cpp : Defines the entry point for the application.
//

#include "Homework_Problem_3.h"
#include <iostream>

using namespace std;

int main() {

    // Defining Aircraft Parameters

    // Roll damping coefficient
    const double Lp = 0.6;       
    // Time step size
    const double time_step = 0.01; 
    // Time to simulate
    const double t_span = 5.0; 
    // Adaptive Rate
    const double alpha = 1.9;

    // Initializing variables

    // Initial roll rate in rad/s
    double p = 1.0; 
    double t = 0.0;
    // Feedback control gain
    double K = 2.8;  

    // Simulating roll rate with feedback control
    while (t <= t_span) {
        // Calculating aileron deflection with feedback control
        // The negative sign in front of K means that the aileron deflection is in the opposite direction of the roll rate. 
        // Hence, if the roll rate is positive (p > 0), the control law will command a negative aileron deflection to counteract the roll, and vice versa.
        double delta_a = -K * p;

        // Aileron deflection for 2 seconds
        if (t <= 2.0) {
            p += (Lp * p + delta_a) * time_step;
        }
        // No aileron deflection
        else {
            p += (Lp * p) * time_step;
        }

        // Update the control gain
        K += alpha * (p * p); 

        // Printing time, roll rate, aileron deflection, and control gain
        cout << "Time: " << t << " s, Roll Rate: " << p << " rad/s, Aileron Deflection: " << delta_a << " rad, Gain K: " << K << endl;

        // Increment time
        t += time_step;
    }

    return 0;
    
}

