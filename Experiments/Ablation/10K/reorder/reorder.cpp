/*
 * # items = 100,000
 * # operations = 100,000
 *
 */
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>
#include "../../../../HeaderFiles/DAnolimit.h"
#include "../../../../HeaderFiles/DAstatic.h"
#include "../../../../HeaderFiles/DynamicArray.h"
using namespace std;
typedef std::chrono::high_resolution_clock::time_point TimeVar;
#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
bool CompareArray(const int *a, const int *b, int len) {
    if (a == nullptr || b == nullptr) {
        cout<<"null pointer error!" << endl;
        return false ;
    }
    for (int i = 0; i < len; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
// A function to return a seeded random number generator.
inline std::mt19937& generator() {
    // the generator will only be seeded once (per thread) since it's static
    static thread_local std::mt19937 gen(std::random_device{}());
    return gen;
}

// A function to generate integers in the range [min, max]
int RandomInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(generator());
}

int* RangeDistributionRandom( int num, int min, int max) {
    int * n = new int[num];
    for (int j = 0; j < num; ++j) {
        n[j] = RandomInt(min, max);
    }
    shuffle(n, n + num, generator());
    return n;
}

int main() {
    //var time1, time2 time.Time
    string filepath[3] = {"reorder.csv", "reorderLog.txt"};
    ofstream finstant, flog, ffinal;
    finstant.open(filepath[0], ios::out | ios::in | ios::trunc);
    flog.open(filepath[1], ios::out | ios::in | ios::trunc);
    //ffinal.open(filepath[2], ios::out | ios::in | ios::trunc);
    finstant<<" ,DA,DANL,ST"<<endl;

    int reorderLength = 100;

    int iniNum = 10000;
    int danodesize = 20;
    int operations = 1000000;
    int InsertActions = operations * 2 / 10;
    int DeleteActions = operations * 2 / 10;
    int ReorderActions = operations * 2 / 10;
    int SwapActions = operations * 2 / 10;
    int MoveActions = operations * 2 / 10;
    int TotalActions = DeleteActions + InsertActions + ReorderActions+SwapActions + MoveActions; // 550 000
    printf("%d, %d, %d, %d, %d\n", InsertActions, DeleteActions, ReorderActions, SwapActions, MoveActions);
    printf("# of operations = %d\n", operations);
    int CurOutputNum = 0;

    int *a = new int[TotalActions];
    int ua = 0;
    for (int y = 0; y < ReorderActions; y++) {
        a[ua] = 4;
        ua++;
    }
    for (int y = 0; y < SwapActions; y++) {
        a[ua] = 5;
        ua++;
    }
    for (int y = 0; y < MoveActions; y++) {
        a[ua] = 6;
        ua++;
    }
    for (int y = 0; y < InsertActions; y++) {
        a[ua] = 2;
        ua++;
    }
    for (int y = 0; y < DeleteActions; y++) {
        a[ua] = 3;
        ua++;
    }

    shuffle(a, a + TotalActions, generator());
    //random_shuffle(&a[DeleteActions+InsertActions], &a[TotalActions]);
    //random_shuffle(&a[0], &a[MoveActions+SwapActions+ReorderActions]);
    //random_shuffle(&a[0], &a[operations]);
    //int * shortqueryrange = RangeDistributionRandom(, 1, 100);
    int * reorderrange = RangeDistributionRandom(ReorderActions, 1, 100);
    int ir = 0;

    TimeVar time1, time2;

    int NowTotalNum = iniNum;
    int ToInsert = iniNum + 1;
    int * array = new int[iniNum];
    for (int i = 0; i < iniNum; ++i) {
        array[i] = i+1;
    }

    DAnolimit * danolimit = NewDAnolimit(array, iniNum, danodesize);
    DAstatic * stree = NewStree(array, iniNum, danodesize);
    DynamicArray * da = NewDynamicArray(array, iniNum, danodesize);
    delete []array;
    int NumDA;
    cout<<"da depth = "<<da->Depth() << endl;
    int DAdepth = 1, DANLdepth = 1, STdepth = stree->Depth();
    int numUpdate = 0;
    for (int lt = 0; lt < TotalActions; lt++) {
        if (lt % 5000 == 0) {
            cout<<"lt = "<<lt;
            cout<<"da depth = "<<da->Depth() << endl;
            flog<<"lt = "<<lt<<endl;
            flog<<"da depth = "<<da->Depth() << endl;
        }
        if (da->Depth() > DAdepth) {
            DAdepth++;
            flog<<"numUpdate = "<<numUpdate<<" da depth = "<<DAdepth<<endl;
        }
        if (danolimit->Depth() > DANLdepth) {
            DANLdepth++;
            flog<<"numUpdate = "<<numUpdate<<" danolimit depth = "<<DANLdepth<<endl;
        }
        if (stree->Depth() > STdepth) {
            STdepth++;
            flog<<"numUpdate = "<<numUpdate<<" stree depth = "<<STdepth<<endl;
        }
        switch (a[lt]) {

            case 2: //insert
            {
                int pos = RandomInt(1, NowTotalNum);
                danolimit->Insert(ToInsert, pos);
                da->Insert(ToInsert, pos);
                stree->Insert(ToInsert, pos);

                ToInsert++;
                NowTotalNum++;
                break;
            }
            case 3: //delete
            {
                int pos = RandomInt(1, NowTotalNum);
                danolimit->Delete(pos);
                da->Delete(pos);
                stree->Delete(pos);

                NowTotalNum--;
                break;
            }

            case 4: //reorder
            {
                int len = reorderrange[ir];
                ir++;
                if (len >= NowTotalNum) {
                    len = NowTotalNum-1;
                }
                int start = RandomInt(1, NowTotalNum - len);
                int end = start + len - 1;
                if (end >= NowTotalNum) {
                    end = NowTotalNum - 1;
                }
                int * oldArray = da->RangeQuery(start, end, &NumDA);
                int * newArray = new int[len];
                for (int j = 0; j < len; ++j) {
                    newArray[j] = oldArray[len-j-1];
                }

                danolimit->Reorder(start, end, newArray);
                da->Reorder(start, end, newArray);
                stree->Reorder(start, end, newArray);

                delete []newArray;
                delete []oldArray;
                break;
            }
            case 5: //swap
            {
                int b[4] = {};
                for (int & j : b) {
                    j = RandomInt(1, NowTotalNum);
                }
                sort(b, b + 4);
                if (b[1] == b[2]) {
                    continue;
                }
                int start1 = b[0];
                int end1 = b[1];
                int start2 = b[2];
                int end2 = b[3];
                danolimit->Swap(start1, end1, start2, end2);
                da->Swap(start1, end1, start2, end2);
                stree->Swap(start1, end1, start2, end2);

                break;
            }
            case 6: //move
            {
                int b[3] = {};
                for (int & j : b) {
                    j = RandomInt(1, NowTotalNum);
                }
                sort(b, b + 3);
                if (b[1] == b[2]) {
                    continue;
                }
                int start1, end1, start2;

                if (RandomInt(1, 10) % 2 == 1) {
                    start1 = b[0];
                    end1 = b[1];
                    start2 = b[2];
                } else {
                    start1 = b[1];
                    end1 = b[2];
                    start2 = b[0];
                }
                danolimit->Move(start1, end1, start2);
                da->Move(start1, end1, start2);
                stree->Move(start1, end1, start2);

                break;
            }
        }
        numUpdate++;

        if ( (lt+1 <= 10) || ((lt+1<=100) && ((lt+1)%10 == 0)) || ((lt+1<=1000) && ((lt+1)%100 == 0))
             || ((lt+1<=10000) && ((lt+1)%1000 == 0)) || ((lt+1<=100000) && ((lt+1)%10000 == 0))
             || ((lt+1<=1000000) && ((lt+1)%100000 == 0))) {
            int num;
            long long Tda = 0, Tdanl = 0, Tst = 0;
            CurOutputNum ++;
            double fl = (lt+1)*1.0/operations ;
            finstant << fl << ",";
            int start1, end1 = NowTotalNum + 2;
            int repeatNum = 10;
            for (int k = 0; k < repeatNum; ++k) {
                while (end1 >= NowTotalNum) {
                    start1 = RandomInt(1, NowTotalNum);
                    end1 = start1 + reorderLength - 1;
                }
                int numOldArray;
                int * oldArray = da->RangeQuery(start1, end1, &numOldArray);
                int * newArray = new int[numOldArray];
                for (int j = 0; j < numOldArray; ++j) {
                    newArray[j] = oldArray[numOldArray-1-j];
                }

                time1 = timeNow();
                danolimit->Reorder(start1, end1, newArray);
                time2 = timeNow();
                Tdanl += duration(time2-time1);

                time1 = timeNow();
                da->Reorder(start1, end1, newArray);
                time2 = timeNow();
                Tda += duration(time2-time1);

                time1 = timeNow();
                stree->Reorder(start1, end1, newArray);
                time2 = timeNow();
                Tst += duration(time2 - time1);

                delete []newArray;
                delete []oldArray;
            }

            finstant <<Tda/repeatNum << ","<< Tdanl/repeatNum <<","<< Tst/repeatNum <<endl;
            cout<<"lt = "<< lt <<" da depth = "<<da->Depth()<<endl;
        }
    } //for lt <= loopTime
    flog<<"da depth = "<<da->Depth() << endl;
    delete []reorderrange;
    delete []a;
    flog.close();
    finstant.close();
    return 0;
}
