import _monteCarloIntegration as mci
import numpy as np
import math

def compareEstimationResults(a, b, eps):
	return (abs(a - b) < eps)

def integrand1(parameters):
	return math.sin(parameters[0] *parameters[0] * parameters[0])

def integrand2(parameters):
	x = parameters[0]
	res = math.sin(math.sqrt(x)) * math.exp(math.sqrt(x)) / math.sqrt(x)
	return res


def test_integrad1_correct_inputs():

	upper_limits = np.array([2],  dtype="float64")
	lower_limits = np.array([0],  dtype="float64")
	correct_res = 0.451948
	sim_res = mci.MonteCarloIntegration.integrate(upper_limits, lower_limits, integrand1, 100000)
	assert compareEstimationResults(correct_res, sim_res, 0.01)  

def test_integrad2_correct_inputs():

	upper_limits = np.array([10],  dtype="float64")
	lower_limits = np.array([1],  dtype="float64")
	correct_res = 22.312
	sim_res = mci.MonteCarloIntegration.integrate(upper_limits, lower_limits, integrand2, 10000000)
	assert compareEstimationResults(correct_res, sim_res, 0.01) 
