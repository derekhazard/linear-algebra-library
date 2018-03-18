######################

CXX           = g++
LD            = g++

#############################

os = $(shell uname -s)

#if more debug needed use -g option for CXXFLAGS in addition

ifeq ($(os),Linux)
CXXFLAGS      = -O -Wall -I./lib
else
CXXFLAGS      = -O -fPIC -pipe -Wall -dynamiclib -I./lib
endif

ifeq ($(os),Linux)
LDFLAGS       = -O 
else
LDFLAGS       = -O -Xlinker -bind_at_load -flat_namespace
endif

vec2dLibTest :
	g++ $(CXXFLAGS) -c src/linearAlgebraLibTest.cpp
	g++ $(LDFLAGS) linearAlgebraLibTest.o -L./lib -lLinearAlgebra -o bin/linearAlgebraLibTest
	rm linearAlgebraLibTest.o

clean :
	rm -f *.o 
	@echo "All cleaned-up :-)"


# DO NOT DELETE
