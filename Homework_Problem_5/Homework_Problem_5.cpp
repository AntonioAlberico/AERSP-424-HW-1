// Homework_Problem_5.cpp : Defines the entry point for the application.
//

#include "Homework_Problem_5.h"
#include <iostream>
#include <cmath>

using namespace std;

// Sigmoid function
double sigmoid(double z) {
    double sig_z = 1.0 / (1.0 + exp(-z)); 
    return sig_z; 
}

// Gradient of the sigmoid function
double gradient_sigmoid(double z) {
    double sig_z = sigmoid(z); 
    double gradient = sig_z * (1.0 - sig_z); 
    return gradient; 
}

int main() {
    double z = 0.0176835;

    // Calculating sigmoid(z)
    double sig_z = sigmoid(z);

    // Calculating the gradient of sigmoid(z)
    double grad_sig_z = gradient_sigmoid(z);

    cout << "Sigmoid(" << z << ") = " << sig_z << endl;
    cout << "Gradient of Sigmoid(" << z << ") = " << grad_sig_z << endl;

    return 0;
}