all: pointquery1K pointquery10K pointquery100K pointquery1M 

pointquery1K: pointquery1K.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
            	../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.h \
            	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
            	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h \
            	../../../HeaderFiles/tiered-vector.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp pointquery1K.cpp -o pointquery1K

pointquery10K: pointquery10K.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
             	../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.h \
             	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
             	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h \
             	../../../HeaderFiles/tiered-vector.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp pointquery10K.cpp -o pointquery10K


pointquery100K: pointquery100K.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
               	../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.h \
               	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
               	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h \
               	../../../HeaderFiles/tiered-vector.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp pointquery100K.cpp -o pointquery100K

pointquery1M: pointquery1M.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
      	../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.h \
      	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
      	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h \
      	../../../HeaderFiles/tiered-vector.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp pointquery1M.cpp -o pointquery1M


