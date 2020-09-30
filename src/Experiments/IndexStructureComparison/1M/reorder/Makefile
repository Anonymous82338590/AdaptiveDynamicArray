all: reorder

reorder: reorder.cpp ../../../../HeaderFiles/StandardArray.cpp ../../../../HeaderFiles/StandardArray.h \
        	../../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../../HeaderFiles/AdaptiveDynamicArray.h \
        	../../../../HeaderFiles/LinkedList.cpp ../../../../HeaderFiles/LinkedList.h \
        	../../../../HeaderFiles/CountedBtree.cpp ../../../../HeaderFiles/CountedBtree.h \
        	../../../../HeaderFiles/tiered-vector.h
	g++ -std=c++11 ../../../../HeaderFiles/StandardArray.cpp ../../../../HeaderFiles/AdaptiveDynamicArray.cpp \
	../../../../HeaderFiles/LinkedList.cpp ../../../../HeaderFiles/CountedBtree.cpp reorder.cpp -o reorder



