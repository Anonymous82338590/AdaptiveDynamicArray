all: pointquery


pointquery: pointquery.cpp ../../../../HeaderFiles/DAstatic.cpp ../../../../HeaderFiles/DAstatic.h \
						  ../../../../HeaderFiles/DAnolimit.cpp ../../../../HeaderFiles/DAnolimit.h \
						  ../../../../HeaderFiles/DynamicArray.cpp ../../../../HeaderFiles/DynamicArray.h
	g++ -std=c++11 ../../../../HeaderFiles/DynamicArray.cpp ../../../../HeaderFiles/DAnolimit.cpp \
                    ../../../../HeaderFiles/DAstatic.cpp pointquery.cpp -o pointquery



