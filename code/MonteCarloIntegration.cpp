#include "MonteCarloIntegration.h"

std::vector<std::vector<double>> MonteCarloIntegration::uniform_sampling(const std::vector<double> &upper_limits,
                                                                         const std::vector<double> &lower_limits,
                                                                         size_t nsim){

    std::vector<std::vector<double>> samples(nsim);
    
    std::random_device rd;
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    rng = std::mt19937(rd());
    std::uniform_real_distribution<double> dist;

    for(size_t i = 0; i < nsim; i++){
        std::vector<double> variable_values(upper_limits.size());
        for(size_t j = 0; j < upper_limits.size(); j++){
            dist = std::uniform_real_distribution<double>(lower_limits[j], upper_limits[j]);
            double tmp = dist(rng);
            variable_values[j] = tmp;
        }
    samples[i] = variable_values;
    }
    return samples;
}


std::vector<double> MonteCarloIntegration::calculate_intervals(const std::vector<double> &upper_limits,
                                                               const std::vector<double> &lower_limits){

    std::vector<double> intervals; 
    for(size_t i = 0; i < upper_limits.size(); i++){
        // calculate the interval size
        double interval_size = upper_limits[i] - lower_limits[i];
        if(interval_size <= 0){
            throw std::invalid_argument("Zero or negative intervals are not allowed");
        }
        else {
            intervals.push_back(interval_size);
        }
    }
    return intervals;
}

// currently this function does not work for improper integrals (one or more limits are infinity)
// or the integral is infinite
double MonteCarloIntegration::integrate(std::vector<double> upper_limits, 
                                        std::vector<double> lower_limits,
                                        //double (*integrand)(std::vector<double> variable_values),
                                        const std::function<double(std::vector<double>)> integrand,
                                        size_t nsim){


    //calculate the size of the intervals between upper and lower limit    
    std::vector<double> intervals;  
    intervals = calculate_intervals(upper_limits, lower_limits);
    

    std::vector<std::vector<double>> samples = uniform_sampling(upper_limits, lower_limits, nsim);
    std::vector<double> simulation_res(nsim);
    for(size_t i = 0; i < nsim; i++){
        simulation_res[i] = integrand(samples[i]);
    }

    // multiply the dimensions used for the multidimensional integral
    // e.g. for two dimensin x1 * x2 (area) which gets multiplied with
    // the integrands result
    double dim_intervals = 1; 
    for (auto& n : intervals){
        dim_intervals *= n;
    }

    // sum over all samples results
    double cum_res = 0;
    for (auto& n : simulation_res){
        cum_res += n;
    }

    // approximates result
    double approximation_res = dim_intervals * cum_res/nsim;
    return approximation_res;
}


# if buildPythonModule
# include <pybind11/pybind11.h>
# include <pybind11/stl.h>
# include <pybind11/functional.h>

namespace py = pybind11;

PYBIND11_MODULE(_monteCarloIntegration, handle) {
    py::class_<MonteCarloIntegration>(handle, "MonteCarloIntegration")
        .def("integrate", &MonteCarloIntegration::integrate);
}

# endif