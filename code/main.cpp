#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <cmath>

#include "Monte_Carlo_Integration.h"

double integrand(std::vector<double> parameters){
    
    double res = sin(parameters[0] * parameters[0]* parameters[0]);
    return res;

}

int main (int argc, char* argv[]){

    srand(time(0));
    std::vector<double> upper_limit;
    upper_limit.push_back(0);
    std::vector<double> lower_limit;
    lower_limit.push_back(0);

    double approx = Monte_Carlo_Integration::integrate(1, upper_limit, lower_limit, integrand);
    std::cout << approx << std::endl;
}