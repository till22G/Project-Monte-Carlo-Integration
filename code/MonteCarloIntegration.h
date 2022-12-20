# pragma once

# include <vector>
# include <iostream>
# include <random>
# include <chrono>
# include <algorithm>

class Monte_Carlo_Integration{
    private:
    public:
        static double integrate(size_t num_parameters, 
                                std::vector<double> upper_limits, 
                                std::vector<double> lower_limits,
                                double (*integrand)(std::vector<double> parameters),
                                size_t nsim = 100000);
}; 