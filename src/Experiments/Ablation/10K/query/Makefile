all: query

query: query.cpp 	../../../../HeaderFiles/ADAstatic.cpp ../../../../HeaderFiles/ADAstatic.h \
                   	../../../../HeaderFiles/ADAnolimit.cpp ../../../../HeaderFiles/ADAnolimit.h \
                   	../../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../../HeaderFiles/AdaptiveDynamicArray.h
	g++ -std=c++11 ../../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../../HeaderFiles/ADAnolimit.cpp \
                   	../../../../HeaderFiles/ADAstatic.cpp query.cpp -o query

