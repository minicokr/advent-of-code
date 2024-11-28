CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lssl -lcrypto

SRC := $(wildcard 20[0-9][0-9]/day*/day*_1.cpp) $(wildcard 20[0-9][0-9]/day*/day*_2.cpp)

OBJ := $(SRC:.cpp=.o)

all: $(OBJ)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
