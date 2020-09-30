all: prefetching

prefetching: prefetching.cpp ../../../HeaderFiles/AdaptiveDynamicArray.cpp ../../../HeaderFiles/AdaptiveDynamicArray.h
#	g++ -std=c++11 ../../../HeaderFiles/StandardArray.cpp ../../../HeaderFiles/DynamicArray.cpp \
	../../../HeaderFiles/LinkedList.cpp ../../../HeaderFiles/CountedBtree.cpp insert.cpp -o insert \
	-L/usr/include/mysql -lmysqlclient -I/usr/include/mysql
	g++ -std=c++11 -Wall -g ../../../HeaderFiles/AdaptiveDynamicArray.cpp prefetching.cpp \
    -I/usr/include/cppconn -o prefetching -pthread -L/usr/lib -lmysqlcppconn

