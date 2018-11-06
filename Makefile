CPPS := $(wildcard *.cpp)
OBJS := $(CPPS:.cpp=.o)

SUFFIXES :=

.PHONY: all clean
.SUFFIXES:
.SECONDARY:

all: full_application

%.o: %.cpp
	g++ -std=c++17 -Wall -Wextra -c -o $@ $<

full_application: $(OBJS)
	g++ -std=c++17 -o $@ $^

clean:
	rm -f $(OBJS) full_application

