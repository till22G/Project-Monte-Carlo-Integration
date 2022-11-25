bin=monte_carlo_integration
CODEDIRS=.
INCLUDEDIRS=.

CC=g++
OPT=

DEPFLAGS=-MP -MD
CCFLAGS=-Wall -Wextra -g -std=c++17 $(foreach D, $(INCLUDEDIRS), -I$(D)) $(OPT) $(DEPFLAGS)

CPPFILES=$(foreach D, $(CODEDIRS),$(wildcard $(D)/*.cpp))

OBJECTS=$(patsubst %.cpp, %.o, $(CPPFILES))
DEPFILES=$(patsubst %.cpp, %.d, $(CPPFILES))


all: $(bin)

$(bin):$(OBJECTS)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) $(CCFLAGS) -c -o $@ $^

test: $(bin)
	./$(bin)

clean:
	rm -rf $(bin) $(OBJECTS) $(DEPFILES)
