bin=monte_carlo_integration
CODEDIRS=.
INCLUDEDIRS=. /usr/local/include

CC=g++
OPT=

GTESTFLAGS= -pthread -lgtest_main -lgtest -lpthread
LD_FLAGS= -L /usr/local/lib -l gtest -l pthread
DEPFLAGS=-MP -MD
CCFLAGS=-Wall -Wextra -g -std=c++17 $(foreach D, $(INCLUDEDIRS), -I$(D)) $(OPT) $(DEPFLAGS) $(GTESTFLAGS)

CPPFILES=$(foreach D, $(CODEDIRS),$(wildcard $(D)/*.cpp))

OBJECTS=$(patsubst %.cpp, %.o, $(CPPFILES))
DEPFILES=$(patsubst %.cpp, %.d, $(CPPFILES))


all: $(bin)

$(bin):$(OBJECTS)
	$(CC) -o $@ $^ $(LD_FLAGS)

%.o:%.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^

test: $(bin)
	./$(bin)

clean:
	rm -rf $(bin) $(OBJECTS) $(DEPFILES)
