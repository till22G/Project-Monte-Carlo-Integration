import _monteCarloIntegration
import numpy as np
import math

def compareEstimationResults(a, b, eps):
	return (abs(a - b) < eps)

def integrand1(parameters):
	return math.sin(parameters[0]) * math.sin(parameters[1]) * math.sin(parameters[2]) 


upper_limits = np.array(2)
lower_limits = np.array(0)
res =  0.451948

print(_monteCarloIntegration.MonteCarloIntegration.test())

print(_monteCarloIntegration.MonteCarloIntegration.integrate(upper_limits, lower_limits, integrand1))



