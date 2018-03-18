######################

CXX           = g++
LD            = g++

#############################

os = $(shell uname -s)


ifeq ($(os),Linux)
CXXFLAGS      = -O -fPIC -Wall
else
CXXFLAGS      = -O -fPIC -pipe -Wall
endif

ifeq ($(os),Linux)
LDFLAGS       = -g
LDFLAGSS      = -g --shared
else
LDFLAGS       = -O -Xlinker -bind_at_load -flat_namespace
LDFLAGSS      = -dynamiclib -flat_namespace -undefined suppress
endif

HDRS          = vecNd.h matrixMN.h
SRCS          = vecNd.cpp matrixMN.cpp

OBJS          = $(SRCS:.cpp=.o)

SLIB          = libLinearAlgebra.so

$(SLIB): $(OBJS)
	@echo "Linking $(SLIB) for "$(os)
	@echo $(LD) $(LDFLAGSS) $(OBJS) $(LIBS) -o $(SLIB)	
	@$(LD) $(LDFLAGSS) $(OBJS) $(LIBS) -o $(SLIB)
	@echo "done"

##########################################################

%.o: %.cxx
	@echo "Compile" $<
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f *.o $(SLIB)
	@echo "All cleaned-up :-)"
