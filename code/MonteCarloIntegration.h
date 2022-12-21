# pragma once

# include <vector>
# include <iostream>
# include <random>
# include <chrono>
# include <algorithm>

class MonteCarloIntegration{
    private:
    public:
        static double integrate(std::vector<double> upper_limits, 
                                std::vector<double> lower_limits,
                                double (*integrand)(std::vector<double> parameters),
                                size_t nsim = 1000000);
}; 