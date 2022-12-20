#include "MonteCarloIntegration.h"


// currently this function does not work for improper integrals (one or more limits are infinity)
// or the integral is infinite
double Monte_Carlo_Integration::integrate(  size_t num_variables, 
                                            std::vector<double> upper_limits, 
                                            std::vector<double> lower_limits,
                                            double (*integrand)(std::vector<double> variable_values),
                                            size_t nsim){

    // implement importance sampling?
    // 

    //integral over one or two bounds equal to infinity
    // check if there is enough time for proper implementation


    //calculate the size of the intervals between upper and lower limit    
    std::vector<double> intervals;
    std::vector<double> random_points;
    bool integral_is_zero = true;

    
    for(size_t i = 0; i < upper_limits.size(); i++){

        // calculate the interval size
        double interval_size = upper_limits[i] - lower_limits[i];
        intervals.push_back(interval_size);

        // check if interval size is zero
        if(interval_size > 0){
            integral_is_zero = false;
        }
    }
    
    
    // check if integral is 0 and return result 
    if(integral_is_zero) return 0;


    std::vector<double> simulation_res(nsim);
    //std::cout << "sim" << std::endl;

    std::random_device rd;
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    rng = std::mt19937(rd());
    std::uniform_real_distribution<double> dist;

    for(size_t i = 0; i < nsim; i++){
        std::vector<double> variable_values;
        for(size_t j = 0; j < num_variables; j++){
            double upper = upper_limits[j];
            double lower = lower_limits[j];
            //std::cout << "upper: " << upper << " lower: " << lower << std::endl; 
            dist = std::uniform_real_distribution<double>(lower, upper);
            double tmp = dist(rng);
            variable_values.push_back(tmp);
        }
    simulation_res[i] = integrand(variable_values);
    }

    // multiply the dimensions used for the multidimensional integral
    // e.g. for two dimensin x1 * x2 (area) which gets multiplied with
    // the integrands result
    double dim_intervals = 1; 
    for (auto& n : intervals){
        dim_intervals *= n;
    }
    //std::cout << "dim intervals: " << dim_intervals << std::endl;

    double cum_res = 0;
    for (auto& n : simulation_res){
        cum_res += n;
    }

    //std::cout << "cum res " << cum_res << std::endl;

    // approximates result
    double approximation_res = dim_intervals * cum_res/nsim;
    std::cout << approximation_res << std::endl;
    return approximation_res;
}
