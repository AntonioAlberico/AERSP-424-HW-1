// Homework_Problem_6.cpp : Defines the entry point for the application.
//

#include "Homework_Problem_6.h"

using namespace std;

// Function to compute cost function 
double gradient_cost(double predicted, double actual) {
    // Calculating Cost
    double dC = 2.0 * (predicted - actual); 
    return dC; 
}

int main() {
    double y = 1.0;
    double y_predicted = 0.504421;

    // Calculating gradient cost function
    double dC = gradient_cost(y_predicted, y);

    cout << "Gradient Cost: " << dC << endl;

    return 0;
}

