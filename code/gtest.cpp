#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <cmath>
#include <gtest/gtest.h>

#include "MonteCarloIntegration.h"

bool compareEstimationResults(double a, double b, double eps){
	return (fabs(a - b) < eps);
}

double integrand(std::vector<double> parameters){

    double res = sin(parameters[0] * parameters[0]* parameters[0]);
    return res;

}

TEST(IntegrationTest, HandelsCorrectInputs ){	
	std::vector<double> upper_limit;
	upper_limit.push_back(2);
	std::vector<double> lower_limit;
	lower_limit.push_back(0);
	EXPECT_TRUE(compareEstimationResults(0.452, Monte_Carlo_Integration::integrate(1, upper_limit, lower_limit, integrand), 1));
}
