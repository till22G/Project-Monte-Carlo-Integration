#include "Monte_Carlo_Integration.h"


// currently this function does not work for improper integrals (one or more limits are infinity)
double Monte_Carlo_Integration::integrate(  size_t num_parameters, 
                                            std::vector<double> upper_limits, 
                                            std::vector<double> lower_limits,
                                            double (*integrand)(std::vector<double> parameters),
                                            size_t nsim){

    //check if upper and lower are equal


    //calculate the size of the intervals between upper and lower limit    
    std::vector<double> intervals;                                      
    for(size_t i = 0; i < upper_limits.size();i++){
        intervals.push_back(upper_limits[i] - lower_limits[i]); 
    }

    std::vector<double> simulation_res(nsim);
    //std::cout << "sim" << std::endl;

    for(size_t i = 0; i < nsim; i++){
        std::vector<double> parameters;
        for(size_t j = 0 ; j < num_parameters; j++){
            //std::cout << "sample parameters" << std::endl;
            // pseudo random values for a first estimation
            // need to implement a better random generator
            double tmp = lower_limits[j] + (float(rand())/RAND_MAX) * intervals[j]; 
            //std::cout << "tmp: " << tmp << std::endl;
            parameters.push_back(tmp);
            
        }

        // gather results        
        simulation_res[i] = integrand(parameters);
        //std::cout << "sim res: " << simulation_res[i] << std::endl;

    }

    // multiply the dimensions used for the multidimensional integral
    // e.g. for two dimensin x1 * x2 (area) which gets multiplied with
    // the integrands result
    double dim_intervals = 1;
    for (auto& n : intervals){
        dim_intervals *= n;
    }
    std::cout << "dim intervals: " << dim_intervals << std::endl;

    double cum_res = 0;
    for (auto& n : simulation_res){
        cum_res += n;
    }

    std::cout << "cum res" << cum_res << std::endl;

    // ap
    double approximation_res = dim_intervals * cum_res/nsim;

    return approximation_res;
}
