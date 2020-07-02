all: move query reorder swap insert delete

move: move.cpp DAbidirectional.cpp DAbidirectional.h \
	DAstatic.cpp DAstatic.h \
	../../../HeaderFiles/DAnolimit.cpp ../../../HeaderFiles/DAnolimit.h
	g++ -std=c++11 ../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DAnolimit.cpp \
                   	../../../HeaderFiles/Stree.cpp move.cpp -o move

query: query.cpp DAbidirectional.cpp DAbidirectional.h \
       DAstatic.cpp DAstatic.h \
       ../../../HeaderFiles/DAnolimit.cpp ../../../HeaderFiles/DAnolimit.h
	g++ -std=c++11 ../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DAnolimit.cpp \
                   	../../../HeaderFiles/Stree.cpp query.cpp -o query

reorder: reorder.cpp DAbidirectional.cpp DAbidirectional.h \
         DAstatic.cpp DAstatic.h \
         ../../../HeaderFiles/DAnolimit.cpp ../../../HeaderFiles/DAnolimit.h
	g++ -std=c++11 ../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DAnolimit.cpp \
                   	../../../HeaderFiles/Stree.cpp reorder.cpp -o reorder

swap: swap.cpp DAbidirectional.cpp DAbidirectional.h \
               	DAstatic.cpp DAstatic.h \
               	../../../HeaderFiles/DAnolimit.cpp ../../../HeaderFiles/DAnolimit.h
	g++ -std=c++11 ../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DAnolimit.cpp \
                   	../../../HeaderFiles/Stree.cpp swap.cpp -o swap


insert: insert.cpp DAbidirectional.cpp DAbidirectional.h \
                   	DAstatic.cpp DAstatic.h \
                   	../../../HeaderFiles/DAnolimit.cpp ../../../HeaderFiles/DAnolimit.h
	g++ -std=c++11 ../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DAnolimit.cpp \
                   	../../../HeaderFiles/Stree.cpp insert.cpp -o insert

delete: delete.cpp DAbidirectional.cpp DAbidirectional.h \
                   	DAstatic.cpp DAstatic.h \
                   	../../../HeaderFiles/DAnolimit.cpp ../../../HeaderFiles/DAnolimit.h
	g++ -std=c++11 ../../../HeaderFiles/DynamicArray.cpp ../../../HeaderFiles/DAnolimit.cpp \
	../../../HeaderFiles/Stree.cpp delete.cpp -o delete