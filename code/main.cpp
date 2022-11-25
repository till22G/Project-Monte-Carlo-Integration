#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <cmath>


double f1(std::vector<double> parameters){
    
    double res = sin(parameters[0] * parameters[0]* parameters[0]);
    return res;

}

double monte_carlo_integration(size_t num_parameters, double (*f)(std::vector<double> parameters)){

    size_t nsim= 1000000;
    double upper_limit = 2;
    double lower_limit = 0;
    double interval = upper_limit - lower_limit;

    std::vector<double> simulation_res(nsim);

    for(size_t i = 0; i < nsim; i++){
        std::vector<double> parameters;
        for(size_t j = 0 ; j < num_parameters; j++){
            // pseudo random values for a first estimation
            double tmp = 1.0 * rand()/RAND_MAX;
            tmp = tmp * interval + lower_limit;
            parameters.push_back(tmp);
        }
        // geather results        
        simulation_res[i] = f1(parameters);
    }

    double approximation_res;
    for (auto& n : simulation_res){
        approximation_res += n;
    }

    std::cout << interval * (approximation_res/nsim) << std::endl;
    return 0;
}



int main (int argc, char* argv[]){

    srand(time(0));
    monte_carlo_integration(1, f1);

}