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

double integrand1(std::vector<double> parameters){
    double res = sin(parameters[0] * parameters[0]* parameters[0]);
    return res;
}


double integrand2(std::vector<double> parameters){
	double x = parameters[0];
    double res = (sin(sqrt(x)) * exp(sqrt(x))) / sqrt(x);
    return res;
}

double integrand3(std::vector<double> parameters){
	double a = parameters[0];
	double b = parameters[1];
    double res = sin(a) + sin(b);
    return res;
}


TEST(IntegrationTestIntegral1, HandelsCorrectInputs){	
	std::vector<double> upper_limit;
	std::vector<double> lower_limit;
	upper_limit.push_back(2);
	lower_limit.push_back(0);
	double result = 0.451948;
	EXPECT_TRUE(compareEstimationResults(result, Monte_Carlo_Integration::integrate(upper_limit, lower_limit, integrand1), 0.1));
}

TEST(IntegrationTestIntegral2, HandelsCorrectInputs){	
	std::vector<double> upper_limit;
	std::vector<double> lower_limit;
	upper_limit.push_back(10);
	lower_limit.push_back(1);
	double result = 22.312;
	EXPECT_TRUE(compareEstimationResults(result, Monte_Carlo_Integration::integrate(upper_limit, lower_limit, integrand2), 0.1));
}

TEST(IntegrationTestIntegral3, HandelsCorrectInputs){	
	std::vector<double> upper_limit;
	std::vector<double> lower_limit;
	upper_limit.push_back(5);
	lower_limit.push_back(0);
	upper_limit.push_back(5);
	lower_limit.push_back(0);
	double result = 7.163;
	EXPECT_TRUE(compareEstimationResults(result, Monte_Carlo_Integration::integrate(upper_limit, lower_limit, integrand3), 0.1));
}

TEST(IntegrationTest, HandelsZeroInput){	
	std::vector<double> upper_limit;
	upper_limit.push_back(0);
	std::vector<double> lower_limit;
	lower_limit.push_back(0);
	EXPECT_ANY_THROW(Monte_Carlo_Integration::integrate(upper_limit, lower_limit, integrand1));
}