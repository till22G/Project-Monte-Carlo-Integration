import _monteCarloIntegration as mci
import numpy as np
import math

def compareEstimationResults(a, b, eps):
	return (abs(a - b) < eps)

def integrand1(parameters):
	return math.sin(parameters[0] *parameters[0] * parameters[0])


upper_limits = np.array([2],  dtype="float64")
lower_limits = np.array([0],  dtype="float64")
correct_res = 0.451948

res_monte_carlo = mci.MonteCarloIntegration.integrate(upper_limits, lower_limits, integrand1, 100000)
print("The correct result is: " + str(correct_res))
print("The simulaition results is: " + str(res_monte_carlo))


