// Homework_Problem_4.cpp : Defines the entry point for the application.
//

#include "Homework_Problem_4.h"

#include <iostream>
#include <vector>

using namespace std;

// Dot product function
double dot_product(const vector<double>& w, const vector<double>& x) {

    // Initialing the result
    double result = 0.0; 
    for (size_t i = 0; i < w.size(); ++i) {

        // Computing the dot product
        result += w[i] * x[i]; 
    }

    return result; 
}

int main() {

    // Vector w 
    vector<double> w = { 0.0001, 0.0001, 0.0001 }; 

    // Vector x
    vector<double> x = { 124, 31.89, 20.945 };    

    // Calculating dot product using the dot_product function
    double z = dot_product(w, x); 

    // Printing
    cout << "Dot product result: " << z << endl; 

    return 0;
}
