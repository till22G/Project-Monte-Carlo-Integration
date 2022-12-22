# pragma once

# include <vector>
# include <iostream>
# include <random>
# include <chrono>
# include <algorithm>

# if buildPythonModule
# include <pybind11/pybind11.h>
# endif

class MonteCarloIntegration{
    private:
    public:
        static double integrate(std::vector<double> upper_limits, 
                                std::vector<double> lower_limits,
                                //double (*integrand)(std::vector<double> parameters),
                                const std::function<double(std::vector<double>)> integrand,
                                size_t nsim = 1000000);
}; 