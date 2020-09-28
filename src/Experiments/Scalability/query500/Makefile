all: query1K query10K query100K query1M 

query1K: query1K.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
            	../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DynamicArray.h \
            	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
            	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h \
            	../../../HeaderFiles/tiered-vector.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp query1K.cpp -o query1K

query10K: query10K.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
             	../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DynamicArray.h \
             	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
             	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h \
             	../../../HeaderFiles/tiered-vector.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp query10K.cpp -o query10K


query100K: query100K.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
               	../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DynamicArray.h \
               	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
               	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h \
               	../../../HeaderFiles/tiered-vector.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp query100K.cpp -o query100K

query1M: query1M.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
      	../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DynamicArray.h \
      	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
      	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h \
      	../../../HeaderFiles/tiered-vector.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp query1M.cpp -o query1M


