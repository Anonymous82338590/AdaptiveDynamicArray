all: swap average

swap: swap.cpp 	../../../../HeaderFiles/DAstatic.cpp ../../../../HeaderFiles/DAstatic.h \
                   	../../../../HeaderFiles/DAnolimit.cpp ../../../../HeaderFiles/DAnolimit.h \
                   	../../../../HeaderFiles/DynamicArray.cpp ../../../../HeaderFiles/DynamicArray.h
	g++ -std=c++11 ../../../../HeaderFiles/DynamicArray.cpp ../../../../HeaderFiles/DAnolimit.cpp \
                   	../../../../HeaderFiles/DAstatic.cpp swap.cpp -o swap


average: average.cpp
	g++ -std=c++11 average.cpp -o average
