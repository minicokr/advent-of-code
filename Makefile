# compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# detect platform
UNAME_S := $(shell uname -s)
OS_NAME := $(UNAME_S)

ifeq ($(OS), Windows_NT)
    OS_NAME := Windows
endif

# platform specific settings
ifeq ($(OS_NAME), Darwin)  # macOS
    OPENSSL_PREFIX := $(shell brew --prefix openssl)
    LDFLAGS = -L$(OPENSSL_PREFIX)/lib -lssl -lcrypto
    CPPFLAGS = -I$(OPENSSL_PREFIX)/include
else ifeq ($(OS_NAME), Windows)  # Windows Native
    # Adjust for OpenSSL Windows paths
    OPENSSL_PREFIX := C:/OpenSSL-Win64
    LDFLAGS = -L$(OPENSSL_PREFIX)/lib -lssl -lcrypto
    CPPFLAGS = -I$(OPENSSL_PREFIX)/include
else ifeq ($(OS_NAME), Linux)  # WSL or Linux
    OPENSSL_PREFIX := /usr
    LDFLAGS = -L$(OPENSSL_PREFIX)/lib -lssl -lcrypto
    CPPFLAGS = -I$(OPENSSL_PREFIX)/include
else
    $(error Unsupported platform)
endif

# source files
SRC := $(shell find 20[0-9][0-9]/day* -name 'day*_1.cpp') \
       $(shell find 20[0-9][0-9]/day* -name 'day*_2.cpp')
# object files
OBJ := $(SRC:.cpp=.o)

all: $(OBJ)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $< $(LDFLAGS)
