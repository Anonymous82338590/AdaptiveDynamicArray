all: pointquery


pointquery: pointquery.cpp ../../../../HeaderFiles/ADAstatic.cpp ../../../../HeaderFiles/ADAstatic.h \
						  ../../../../HeaderFiles/ADAnolimit.cpp ../../../../HeaderFiles/ADAnolimit.h \
						  ../../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../../HeaderFiles/AdaptiveDynamicArray.h
	g++ -std=c++11 ../../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../../HeaderFiles/ADAnolimit.cpp \
                    ../../../../HeaderFiles/ADAstatic.cpp pointquery.cpp -o pointquery



