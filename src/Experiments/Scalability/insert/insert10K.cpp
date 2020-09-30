#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>
#include "../../../HeaderFiles/CountedBtree.h"
#include "../../../HeaderFiles/StandardArray.h"
#include "../../../HeaderFiles/AdaptiveDynamicArray.h"
#include "../../../HeaderFiles/LinkedList.h"
#include "../../../HeaderFiles/tiered-vector.h"
using namespace std;
using namespace Seq;
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
    //random_shuffle(&n[0], &n[num]);
    return n;
}


int main(int argc, char** argv) {
    string filepath[3] = {"insert10K.csv", "insert10KLog.txt"};
    ofstream finstant, flog, ffinal;
    finstant.open(filepath[0], ios::out | ios::in | ios::trunc);
    flog.open(filepath[1], ios::out | ios::in | ios::trunc);


    finstant<<" ,DA,SA,LL,CBT,TV"<<endl;
    long long Tsa = 0, Tda = 0, Tll = 0, Tcbt = 0, Ttv=0;
    int iniNum = 10000;
    int danodesize = 20;
    int CbtOrder = 20;
    int m = 500;  //for linked list
    int NumOfOutput = 10;
    int operations = 1000000;
    int InsertActions = operations * 25 / 100;
    int DeleteActions = operations * 25 / 100;
    int ReorderActions = operations * 25 / 100;
    int SwapActions = operations * 25 / 100;
    int TotalActions = DeleteActions + InsertActions + ReorderActions+SwapActions;
    printf("%d, %d, %d, %d\n", InsertActions, DeleteActions, ReorderActions, SwapActions);
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
    bool flag1 = false, flag2 = false, flag3 = false;
    int NowTotalNum = iniNum;
    int ToInsert = iniNum + 1;
    int * array = new int[iniNum];
    for (int i = 0; i < iniNum; ++i) {
        array[i] = i+1;
    }
    DynamicArray *da = NewDynamicArray(array, iniNum, danodesize);
    StandardArray *sa = NewStandardArray(array, iniNum);
    CountedBtree * cbt = NewCBTreeForArray(CbtOrder, iniNum);
    LinkedList * ll = NewLinkedListForArray(m, array, iniNum);
    Seq::Tiered<int, LayerItr<LayerEnd, Layer<22, Layer<22, Layer<22>>>>> tiered;
    tiered.initialize(array, iniNum);
    delete []array;
    int NumSA, NumDA, Numll, NumCBT;
    cout<<"da depth = "<<da->Depth() << endl;
    int depth = 1;
    int numUpdate = 0;
    for (int lt = 0; lt < operations; lt++) {
        if (lt % 5000 == 0) {
            cout<<"lt = "<<lt;
            cout<<"da depth = "<<da->Depth() << endl;
            flog<<"lt = "<<lt<<endl;
            flog<<"da depth = "<<da->Depth() << endl;
        }
        if (da->Depth() > depth) {
            depth++;
            flog<<"numUpdate = "<<numUpdate<<" da depth = "<<depth<<endl;
        }
        switch (a[lt]) {

            case 2: //insert
            {
                int pos = RandomInt(1, NowTotalNum);
                sa->Insert(ToInsert, pos);
                da->Insert(ToInsert, pos);
                cbt->Insert(ToInsert, pos);
                ll->Insert(ToInsert, pos);
                tiered.insert(pos, ToInsert);
                ToInsert++;
                NowTotalNum++;
                break;
            }
            case 3: //delete
            {
                int pos = RandomInt(1, NowTotalNum);
                sa->Delete(pos);
                da->Delete(pos);
                cbt->Delete(pos);
                ll->Delete(pos);
                tiered.remove(pos);
                NowTotalNum--;
                break;
            }

            case 4: //reorder
            {
                int len = reorderrange[ir];
                if (len == 0) {
                    len = 1;
                }
                ir++;
                if (len >= NowTotalNum) {
                    len = NowTotalNum-1;
                }
                int start = RandomInt(1, NowTotalNum - len);
                int end = start + len - 1;
                if (end >= NowTotalNum) {
                    end = NowTotalNum - 1;
                }
                int * oldArray = sa->RangeQuery(start, end, &NumSA);
                int * newArray = new int[len];
                for (int j = 0; j < len; ++j) {
                    newArray[j] = oldArray[len-j-1];
                }

                sa->Reorder(start, end, newArray);
                da->Reorder(start, end, newArray);
                cbt->Reorder(start, end, newArray);
                ll->Reorder(start, end, newArray);
                tiered.Reorder(start, end, newArray);
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
                sa->Swap(start1, end1, start2, end2);
                da->Swap(start1, end1, start2, end2);
                cbt->Swap(start1, end1, start2, end2);
                ll->Swap(start1, end1, start2, end2);
                tiered.Swap(start1, end1, start2, end2);
                break;
            }
        }

        if ((lt+1)%100000 == 0)
        {
            numUpdate ++;

            CurOutputNum ++;
            int pos = RandomInt(1, NowTotalNum);

            time1 = timeNow();
            sa->Insert(ToInsert, pos);
            time2 = timeNow();
            Tsa += duration(time2-time1);

            time1 = timeNow();
            da->Insert(ToInsert, pos);
            time2 = timeNow();
            Tda += duration(time2-time1);

            time1 = timeNow();
            ll->Insert(ToInsert, pos);
            time2 = timeNow();
            Tll += duration(time2 - time1);

            time1 = timeNow();
            cbt->Insert(ToInsert, pos);
            time2 = timeNow();
            Tcbt += duration(time2 - time1);

            time1 = timeNow();
            tiered.insert(pos, ToInsert);//->Insert(ToInsert, pos);
            time2 = timeNow();
            Ttv += duration(time2 - time1);

            ToInsert++;
            NowTotalNum++;
            cout<<"lt = "<< lt <<" da depth = "<<da->Depth()<<endl;
            flog<<"lt= "<<lt<<" ll length = "<<ll->NumItem<<endl;
        }
        numUpdate++;
    } //for lt <= loopTime

    finstant <<Tda/10 << ","<< Tsa/10<<","<<Tll/10<<","<<Tcbt/10<<","<<Ttv/10<<endl;
    flog<<"da depth = "<<da->Depth() << endl;
    delete []reorderrange;
    delete []a;
    flog.close();
    finstant.close();
    return 0;
}

