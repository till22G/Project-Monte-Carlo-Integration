bin=monte_carlo_integration
CODEDIRS=.
INCLUDEDIRS=.

I=/usr/include/python3.8 /home/tgalla/anaconda3/lib/python3.9/site-packages/pybind11/include /usr/include/python3.8

CC=g++
OPT=

PCCFLAGS=-O3 -Wall -m64 -shared -std=c++17 -fPIC
PPYINCLUDE=`python3 -m pybind11 --includes`
PSPEC=`python3-config --extension-suffix`


GTESTFLAGS= -pthread -lgtest_main -lgtest -lpthread
LD_FLAGS= -L /usr/local/lib -l gtest -l pthread
DEPFLAGS=-MP -MD
CCFLAGS= -Wall -Wextra -std=c++17 -g $(foreach D, $(INCLUDEDIRS), -I$(D)) $(OPT) $(DEPFLAGS) $(GTESTFLAGS)

CPPFILES=$(foreach D, $(CODEDIRS),$(wildcard $(D)/*.cpp))

OBJECTS=$(patsubst %.cpp, %.o, $(CPPFILES))
DEPFILES=$(patsubst %.cpp, %.d, $(CPPFILES))


all: $(bin) module

$(bin):$(OBJECTS)
	$(CC) -o $@ $^ $(LD_FLAGS) $(PPYINCLUDE)

%.o:%.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^ $(PPYINCLUDE)

module:
	$(CC) $(PCCFLAGS) $(PPYINCLUDE) MonteCarloIntegration.cpp -o _monteCarloIntegration$(PSPEC) -DbuildPythonModule

test: $(bin)
	./$(bin)

test_module: module
	python3 -m pytest -v

test_all: test test_module


clean:
	rm -rf $(bin) $(OBJECTS) $(DEPFILES) *.so __pycache__/
