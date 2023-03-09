#Student Name: James Truong		CS302 Hybrid
#Programming Assignment #3 Schedule Planner 	Makefile

#Variables
CC = g++
CXXFLAGS = -g -Wall -std=c++17 
SRCS = prog3-main.cpp prog3-table.cpp prog3-menu.cpp prog3-schedule.cpp 
OBJS = $(SRCS:.cpp=.o)
TARGETS = prog3

#Default target
all: $(TARGETS)

.PHONY: clean 

$(TARGETS): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(TARGETS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $(<) -o $(@)

clean:
	rm -f $(TARGETS) $(OBJS)