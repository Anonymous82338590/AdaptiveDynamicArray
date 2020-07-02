all: move query reorder swap insert delete

move: move.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
	../../../HeaderBidirectional ../../../HeaderBidirectional \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp move.cpp -o move

query: query.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
	../../../HeaderBidirectional ../../../HeaderBidirectional \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp query.cpp -o query \
	-L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

reorder: reorder.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
	../../../HeaderBidirectional ../../../HeaderBidirectional \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp reorder.cpp -o reorder

swap: swap.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
	../../../HeaderBidirectional ../../../HeaderBidirectional \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp swap.cpp -o swap


insert: insert.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
	../../../HeaderBidirectional ../../../HeaderBidirectional \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp insert.cpp -o insert \
	-L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

delete: delete.cpp ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/StandardArray.h \
	../../../HeaderBidirectional ../../../HeaderBidirectional \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/LinkedList.h \
	../../../HeaderFiles/CountedBtree.cpp ../../../HeaderFiles/CountedBtree.h
	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp delete.cpp -o delete \
	-L/usr/include/mysql -lmysqlclient -I/usr/include/mysql
