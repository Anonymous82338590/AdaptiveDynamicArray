all: asyn


asyn: asyn.cpp ../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.h
#	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp insert.cpp -o insert \
	-L/usr/include/mysql -lmysqlclient -I/usr/include/mysql
	g++ -std=c++11 -Wall -g ../../../HeaderFiles/AdaptiveDynamicArray.cpp asyn.cpp \
    -I/usr/include/cppconn -o asyn -pthread -L/usr/lib -lmysqlcppconn


