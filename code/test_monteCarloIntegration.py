import _monteCarloIntegration as mci
import pytest
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

def integrand3(parameters):
	a = parameters[0]
	b = parameters[1]
	res = math.sin(a) + math.sin(b)
	return res

def integrand4(parameters):
	a = parameters[0]
	b = parameters[1]
	c = parameters[2]
	res = math.sin(a) * math.sin(b) * math.sin(c)
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
	sim_res = mci.MonteCarloIntegration.integrate(upper_limits, lower_limits, integrand2, 1000000)
	assert compareEstimationResults(correct_res, sim_res, 0.1) 

def test_integrad3_correct_inputs():

	upper_limits = np.array([5, 5],  dtype="float64")
	lower_limits = np.array([0, 0],  dtype="float64")
	correct_res = 7.163
	sim_res = mci.MonteCarloIntegration.integrate(upper_limits, lower_limits, integrand3, 1000000)
	assert compareEstimationResults(correct_res, sim_res, 0.1)

def test_integrad4_correct_inputs():

	upper_limits = np.array([5, 5, 5],  dtype="float64")
	lower_limits = np.array([0, 0, 0],  dtype="float64")
	correct_res = 0.367
	sim_res = mci.MonteCarloIntegration.integrate(upper_limits, lower_limits, integrand4, 1000000)
	assert compareEstimationResults(correct_res, sim_res, 0.1) 

def test_handle_zero_input():
	upper_limits = np.array([0],  dtype="float64")
	lower_limits = np.array([0],  dtype="float64")
	with pytest.raises(ValueError) as excinfo:
		mci.MonteCarloIntegration.integrate(upper_limits, lower_limits, integrand1, 1000000)
	assert "Zero or negative intervals are not allowed" in str(excinfo.value)

	
	
