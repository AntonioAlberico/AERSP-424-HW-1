// Homework_Problem_7.cpp : Defines the entry point for the application.
//

#include "Homework_Problem_7.h"

#include <iostream>
#include <vector>

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
        // Upadating using learning rate and gradient
        w[i] -= alpha * dW[i]; 
    }
}

int main() {
    // Givens
    vector<double> w = { 0.0001, 0.0001, 0.0001 }; 
    vector<double> x = { 124, 31.89, 20.945 }; 
    double y = 1.0; 
    double alpha = 0.001; 

    // Computing gradient of the weights
    vector<double> dW = gradient_weights(w, x, y);

    // Updating weights
    update_weights(w, dW, alpha);

    // Output weights
    cout << " Updated weights (w_vector): [";
    for (size_t i = 0; i < w.size(); ++i) {
        cout << w[i];
        if (i < w.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

