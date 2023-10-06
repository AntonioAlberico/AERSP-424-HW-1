// HW1Problem8.cpp : Defines the entry point for the application.
//

#include "HW1Problem8.h"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Computing the sigmoid function
double sigmoid(double z) {
    // Calculating sigmoid using the exp
    double sig_z = 1.0 / (1.0 + exp(-z));
    return sig_z;
}

// Computing the gradient of the sigmoid function 
double gradient_sigmoid(double z) {
    // Calculating sigmoid
    double sig_z = sigmoid(z);
    // Calculating the gradient using sigmoid output
    return sig_z * (1.0 - sig_z);
}

// Computing gradient of the weights
vector<double> gradient_weights(const vector<double>& w, const vector<double>& x, double y) {
    vector<double> dW(w.size(), 0.0);

    double w_raisedT_x = 0.0;
    for (size_t i = 0; i < w.size(); ++i) {
        // Computing dot product
        w_raisedT_x += w[i] * x[i];
    }

    // Calculate the sigmoid of w_raisedT_x
    double sig_wTx = sigmoid(w_raisedT_x);
    // Calculating the gradient of the cost
    double dC = 2.0 * (sig_wTx - y);
    // Calculating gradient of the sigmoid
    double dSigmoid_wTx = gradient_sigmoid(w_raisedT_x);

    for (size_t i = 0; i < w.size(); ++i) {
        // Calculating gradient for each i
        dW[i] = dC * dSigmoid_wTx * x[i];
    }

    return dW;
}

// Updating the weights
void update_weights(vector<double>& w, const vector<double>& dW, double alpha) {
    for (size_t i = 0; i < w.size(); ++i) {
        // Updating using learning rate and gradient
        w[i] -= alpha * dW[i];
        // If it returns a 1 or a -1 there is big problem my friend. Big, big problem. Maybe just cry?
        if (w[i] > 1.0) {
            w[i] = 1.0;
        }
        else if (w[i] < -1.0) {
            w[i] = -1.0;
        }
    }
}

int main() {
    // Givens
    vector<vector<double>> aircraft_data = {
        // Each row is data_point throught the iterations
        {124, 31.89, 20.945, 1},
        {74, 51.08, 9.170, 0},
        {103, 34.67, 8.300, 1},
        {77, 52.00, 9.400, 0},
        {104, 35.63, 13.000, 1},
        {92, 56.00, 12.500, 0},
        {130, 31.29, 17.637, 1},
        {73, 52.00, 9.600, 0}
    };

    // Initialized variables
    vector<double> w = { 0.0001, 0.0001, 0.0001 };
    double alpha = 0.001;
    int max_iterations = 1000;

    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        // Looping through data
        // Referencing each row in aircraft_data (i think?)
        for (const vector<double>& data_point : aircraft_data) {
            // Engine type
            double y = data_point.back(); 
            // Extracting approach speed, wingspan, and MTOW (assgined to x)
            vector<double> x(data_point.begin(), data_point.end() - 1); 

            // Computing gradient of the weights
            vector<double> dW = gradient_weights(w, x, y);

            // Updating weights (Added)
            update_weights(w, dW, alpha);

            // If this loop outputs a 1 or -1 in your output, you may have an issue. Big issue. 
            // Means something is wrong in code (maybe inputs too?)
            for (size_t i = 0; i < w.size(); ++i) {
                if (w[i] > 1.0) {
                    w[i] = 1.0;
                }
                else if (w[i] < -1.0) {
                    w[i] = -1.0;
                }
            }
        }
    }

    // Output updated weights
    cout << "Updated weights (w_vector): [";
    for (size_t i = 0; i < w.size(); ++i) {
        cout << w[i];
        if (i < w.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

