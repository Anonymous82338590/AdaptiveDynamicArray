#ifndef INDEXSTRUCTURE_DYNAMICARRAY_H
#define INDEXSTRUCTURE_DYNAMICARRAY_H
#include <cstdio>
#include <iostream>
#include <cmath>
#include <list>
#include <chrono>
//typedef std::chrono::high_resolution_clock::time_point TimeVar;
//#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
//#define timeNow() std::chrono::high_resolution_clock::now()

class NodeDA {
public:
    NodeDA **Pointers;
    int *Keys;
    NodeDA *Parent;
    bool IsLeaf;
    int NumOfKeys;
    NodeDA *Next;
   // NodeDA *Previous;
    explicit NodeDA(int capacity, int numkeys = 0, NodeDA *parent = nullptr);
    ~NodeDA();
};

class DynamicArray {
public:
    int NumItems;
    int Capacity;
    int Min; // Min = ceiling(Capacity / 2)
    NodeDA *Root;

    DynamicArray(int numItems, int capacity) {
        NumItems = numItems;
        Capacity = capacity;
        Min = ceil(Capacity * 1.0 / 2.0);
        Root = nullptr;// new NodeDA(Capacity);
    }

    ~DynamicArray();

    int *RangeQuery(int, int, int *);

    int NumOfItems() const { return NumItems; }

    void PrintTree() const;

    void PrintDA();

    void Insert(int, int);

    int Delete(int);

    int Depth() const;

    NodeDA *findLeaf(int pos, int *preIndexInLeaf, int *preIndexInArray);

    void SimplyAdjustAncestorKeysBy(NodeDA *node, int increase);

    void AdjustAncestorKeysAccordingToCurNode(NodeDA *n);

    NodeDA *CompleteAdjustAncestorNodesAfterDelete(NodeDA *n);

    NodeDA *adjustAfterDeleteKeysInNode(NodeDA *fromLeaf, int numKeysDeleted = -1);

    void insertOneIntoLeaf(NodeDA *leaf, int *righta, int rightlen, int IndexInLeaf);

    void insertIntoParent(NodeDA *left, int sumKetsLeft, NodeDA *right, int sumKeysRight, bool needGoUpwards = true);

    void insertIntoNewRoot(NodeDA *left, int sumKeysLeft, NodeDA *right, int sumKeysRight);

    int getLeftIndex(NodeDA *parent, NodeDA *left);

    int NodeSumKeys(NodeDA *n);

    void
    insertIntoNodeAfterSplitting(NodeDA *n, int leftIndex, int sumKeysRight, NodeDA *right, bool needGoupwards = true);

    int pathToRoot(NodeDA *child) const;

    void deleteEntry(NodeDA *n, int indexInNode);

    NodeDA *removeEntryFromNode(NodeDA *n, int indexInNode);

    void adjustRoot();

    int getLeftNeighborIndex(NodeDA *n);

    NodeDA *coalesceNodes(NodeDA *n, NodeDA *neighbour, int neighbour_index);

    void redistributeNodes(NodeDA *n, NodeDA *neighbour, int neighbour_index);

    void coalesceNodesForDeleteOperation(NodeDA *n, NodeDA *neighbour, int neighbour_index);

    void deleteEntryForDeleteOperatoin(NodeDA *n, int indexInNode);

    void redistributeNodesForDeleteOperation(NodeDA *n, NodeDA *neighbour, int neighbour_index);

    void Reorder(int start, int end, int *neworder);

    void CutArray(int pos);

    void insertOneIntoLeafForCut(NodeDA *leaf, int *newarray, int length, int indexInLeaf);

    void MergeOrRedistributeArrayAfterDelete(NodeDA *leaf, int IndexInLeaf, int IndexInArray);

    void insertOneIntoLeafForDeletion(NodeDA *leaf, int *newa, int length, int indexInLeaf);

    void MergeOrRedistributeArrayAfterDeleteInMiddle(NodeDA *leaf, int IndexInLeaf, int IndexInArray);

    void CheckMinArrayAfterSwap(int s);

    void MergeRedistributeArrayAfterSwap(NodeDA *leaf, int IndexInLeaf);

    void deleteEntryForCheckMinArray(NodeDA *n, int indexInNode);

    void coalesceNodesForCheckMinArray(NodeDA *n, NodeDA *neighbour, int neighbour_index);

    void swapLeaf(NodeDA **inter1, NodeDA **inter2, int numLeaf1, int numLeaf2, int startIndexLeaf1, int endIndexLeaf1,
                  int startIndexLeaf2, int endIndexLeaf2);

    int getIndexInParent(NodeDA *n);

    NodeDA * deleteMulEntry(NodeDA **entryToDelete, int numEntryToDelete);

    void movePointerInNodeForward(NodeDA *node, int startIndex, int endIndex, int toIndex);

    //void PutLeavesIntoUpdateSumKeys(NodeDA **leaves, int numLeaf);

    void UpdateSumKeys(NodeDA **nodes, int numNode);

    NodeDA *movePointerBefore(NodeDA *fromLeaf, int startIndex, int endIndex, NodeDA *toLeaf, int toIndex);

    NodeDA *movePointerAfter(NodeDA *fromLeaf, int startIndex, int endIndex, NodeDA *toLeaf, int toIndex);

    void insertMulLeavesIntoLeafParentAfterSplitting(NodeDA *toParent, int startIndexInParent, NodeDA **leafToInsert,
                                                     int numLeafToInsert);

    void insertMulIntoParent(NodeDA *toParent, NodeDA **parentNewSibling, int parentNewSiblingNum);

    void insertMulIntoNewRoot(NodeDA *toParent, NodeDA **parentNewSibling, int parentNewSiblingNum);

    void insertMulIntoNode(NodeDA *parent, int toIndex, NodeDA **parentNewSibling, int parentNewSiblingNum,
                           int ParentIncrease);

    void insertMulIntoNodeAfterSplitting(NodeDA *parent, int toIndex, NodeDA **pointerToInsert, int pointerToInsertNum);

    void redistributeNodesForCheckMinArray(NodeDA *n, NodeDA *neighbour, int neighbour_index);

    void
    insertLeavesIntoLeafParent(NodeDA *toParent, int startIndexInParent, NodeDA **leafToInsert, int numLeafToInsert);

    void
    insertMulLeavesIntoLeafParent(NodeDA *toParent, int startIndexInParent, NodeDA **leafToInsert, int numLeafToInsert);

    void swapEndPointer(NodeDA *leftLeaf, int indexInLeftLeaf, int endIndexInLeftLeaf, NodeDA *rightLeaf,
                        int indexInRightLeaf, int endIndexInRightLeaf);

    void swapWholeLeafAndGoUpwards(NodeDA **wholeLeaf1, NodeDA **bwholeLeaf2, int w1, int w2);

    void exchangeLeaf(NodeDA *LeftLeaf, NodeDA *LeftParent, NodeDA *RightLeaf, NodeDA *RightParent);

    void RedistributeMergeRecomputeKeysInAncestorsLeftPart(NodeDA *node);

    void adjustAncestorKeysAfterExchangingLeaves(NodeDA **nodeArray, int numNodeInArray);

    void swapHeadTail12(NodeDA *inter1, NodeDA *inter2, int startIndexLeaf1, int endIndexLeaf1, int startIndexLeaf2,
                        int endIndexLeaf2);

    void
    swapHeadTail11(NodeDA *inter1, int startIndexLeaf1, int endIndexLeaf1, int startIndexLeaf2, int endIndexLeaf2);

    void swapHeadTail21(NodeDA *inter1, NodeDA *inter2, int startIndexLeaf1, int endIndexLeaf1, int startIndexLeaf2,
                        int endIndexLeaf2);

    void swapHeadTail22(NodeDA *inter1, NodeDA *inter2, NodeDA *inter3, int startIndexLeaf1, int endIndexLeaf1,
                        int startIndexLeaf2, int endIndexLeaf2);

    void
    swapHeadTailLen1Is1(NodeDA **inter2, int numLeaf2, int startIndexLeaf1, int endIndexLeaf1, int startIndexLeaf2,
                        int endIndexLeaf2);

    void
    swapHeadTailLen2Is1(NodeDA **inter1, int numLeaf1, int startIndexLeaf1, int endIndexLeaf1, int startIndexLeaf2,
                        int endIndexLeaf2);

    void swapHeadTailLen1Is2(NodeDA **inter1, NodeDA **inter2, int numLeaf1, int numLeaf2, int startIndexLeaf1,
                             int endIndexLeaf1, int startIndexLeaf2, int endIndexLeaf2);

    void swapHeadTailLen2Is2(NodeDA **inter1, NodeDA **inter2, int numLeaf1, int numLeaf2, int startIndexLeaf1,
                             int endIndexLeaf1, int startIndexLeaf2, int endIndexLeaf2);

    void SwapRangesAdjacentWhenLensAreBoth2(NodeDA **inter1, NodeDA **inter2, int numLeaf1, int numLeaf2,
                                            int startIndexLeaf1,
                                            int endIndexLeaf1, int startIndexLeaf2, int endIndexLeaf2);

    NodeDA *DeleteMidPartOfTwoAdjacentLeaves(NodeDA *leaf1, int startIndexInLeaf1, NodeDA *leaf2, int endIndexInLeaf2);

    void SwapRangesAdjacentRightIs2(NodeDA **inter1, NodeDA **inter2, int numLeaf1, int numLeaf2, int startIndexLeaf1,
                                    int endIndexLeaf1, int startIndexLeaf2, int endIndexLeaf2);

    void SWapRangesAdjacentWhenLensAre1And2(NodeDA *leftnode, NodeDA *right1, NodeDA *right2, int startIndexLeaf1,
                                            int endIndexLeaf1, int startIndexLeaf2, int endIndexLeaf2);

    void
    SwapRangesAdjacentWhenRightIs1(NodeDA **inter1, int numLeaf1, NodeDA *right, int sartIndexLeaf1, int endIndexLeaf1,
                                   int startIndexLeaf2, int endIndexLeaf2);

    void SwapRangesAdjacent(NodeDA **inter1, NodeDA **inter2, int numLeaf1, int numLeaf2, int sartIndexLeaf1,
                            int endIndexLeaf1,
                            int startIndexLeaf2, int endIndexLeaf2);

    void SwapWhenBothLensAre2(NodeDA *left1, NodeDA *left2, int startIndexLeaf1, int endIndexLeaf1, NodeDA *right1,
                              NodeDA *right2,
                              int startIndexLeaf2, int endIndexLeaf2);

    void SWapRangesAdjacentWhenLensAreBoth1(NodeDA *leftnode, NodeDA *rightnode, int startIndexLeaf1, int endIndexLeaf1,
                                            int startIndexLeaf2, int endIndexLeaf2);

    void
    SwapRangesAdjacentWhenLeftIs1(NodeDA *left, NodeDA **inter2, int numLeaf2, int startIndexLeaf1, int endIndexLeaf1,
                                  int startIndexLeaf2, int endIndexLeaf2);

    void SwapRangesAdjacentLeftIs2(NodeDA **inter1, NodeDA **inter2, int numLeaf1, int numLeaf2, int startIndexLeaf1,
                                   int endIndexLeaf1, int startIndexLeaf2, int endIndexLeaf2);

    void SwapRangesAdjacentWhenLensAre2And1(NodeDA *left1, NodeDA *left2, NodeDA *right, int startIndexLeaf1,
                                            int endIndexLeaf1,
                                            int startIndexLeaf2, int endIndexLeaf2);

    void
    SwapWhenBothLensAre1(NodeDA *leaf1, int startIndex1, int endIndex1, NodeDA *leaf2, int startIndex2, int endIndex2);


    void
    SwapWhenLensAre1And2(NodeDA *leaf1, int startIndex1, int endIndex1, NodeDA *leaf2, int startIndex2, NodeDA *leaf3,
                         int endIndex3);

    NodeDA *coalesceNodesStopAtParent(NodeDA *n, NodeDA *neighbour, int neighbour_index);

    void SwapForTailHead(NodeDA **inter1, NodeDA **inter2, int numLeaf1, int numLeaf2, int startIndexLeaf1,
                         int endIndexLeaf1, int startIndexLeaf2, int endIndexLeaf2);

    void SwapWhenLenIs1(NodeDA *LongLeaf, NodeDA **inter2, int numLeaf2, int startIndexLeaf1, int endIndexLeaf1,
                        int startIndexLeaf2, int endIndexLeaf2);

    NodeDA *swapStartPointer(NodeDA *leftLeaf, int endIndexInLeftLeaf, NodeDA *rightLeaf, int endIndexInRightLeaf);

    int RangePosInLeafPointer(int start, int end, NodeDA ***inter, int *startIndexLeaf, int *endIndexLeaf);

    void Move(int start, int end, int des);

    void RealMove(int startIndexLeaf1, int endIndexLeaf1, NodeDA **inter1, int numLeaf1, NodeDA *toleaf, int toindex);

    void MoveToLeafIsFirstLeaf(NodeDA **inter1, int numLeaf1, int startIndexLeaf1, int endIndexLeaf1, NodeDA *toleaf,
                               int toindex);

    void MoveToLeafIsLastLeaf(NodeDA **inter1, int numLeaf1, int startIndexLeaf1, int endIndexLeaf1, NodeDA *toleaf,
                              int toindex);

    void Move1(NodeDA **inter1, int numLeaf1, int startIndexLeaf1, int endIndexLeaf1, NodeDA *toleaf, int toindex);

    void
    MoveWhenLenIs1(NodeDA **inter1, int numLeaf1, int startIndexLeaf1, int endIndexLeaf1, NodeDA *toleaf, int toindex);

    void
    MoveWhenLenIs2(NodeDA **inter1, int numLeaf1, int startIndexLeaf1, int endIndexLeaf1, NodeDA *toleaf, int toindex);

    NodeDA *CutForDesInMove(int des, int *toIndex);

    NodeDA *insertOneIntoLeafAfterSplittingForMove(NodeDA *leaf, int *newID, int length, int indexInLeaf, int *toIndex);

    // void Swap(int start1, int end1, int start2, int end2, int *CutArrayTime, int *FindLeafTime, int *swapLeafTime,
    //         int *CheckMinTime);

    void Swap(int start1, int end1, int start2, int end2);

    void insertIntoNode(NodeDA *n, int leftIndex, int sumKeysRight, NodeDA *right, bool needGoUpward = true);

    void insertOneIntoLeafAfterSplitting(NodeDA *leaf, int *newPointer, int length, int indexInLeaf,
                                         bool needGoupwards = true);

    void AdjustAncestorKeyForOneNode(NodeDA *c);

    void insertMulLeavesIntoLeafParentSplitOnce(NodeDA *toParent, int startIndexInParent, NodeDA **leafToInsert,
                                                int numLeafToInsert);

    bool
    insertKeysIntoLeaf(int *keysToInsert, NodeDA **pointersToInsert, int numKeysToInsert, NodeDA *toLeaf, int toIndex);

    bool insertMulKeysIntoLeafAfterOneSplitting(int *keysToInsert, NodeDA **pointersToInsert, int numKeysToInsert,
                                                NodeDA *toLeaf,
                                                int toIndex);

    void insertMulKeysIntoLeaf(int *keysToInsert, NodeDA **pointersToInsert, int numKeysToInsert, NodeDA *toLeaf,
                               int toIndex);

    void insertMulKeysIntoLeafAfterMulSplitting(int *keysToInsert, NodeDA **pointersToInsert, int numKeysToInsert,
                                                NodeDA *toLeaf, int toIndex);

    void SwapWhenLeftLenIs2(NodeDA *left1, NodeDA *left2, int startIndexLeaf1, int endIndexLeaf1, NodeDA **inter2,
                            int numLeaf2,
                            int startIndexLeaf2, int endIndexLeaf2);

    void
    ReplaceMidOfTwoAdjacentLeaves(NodeDA *left, NodeDA *right, int startIndexLeft, int endIndexRight, int *keysToInsert,
                                  NodeDA **pointersToInsert, int numToInsert);

    void CheckAndMergeRedistributeNode(NodeDA *n);

    void replaceKeysInLeaf(NodeDA *leaf, int startIdx, int endIdx, int *keysToInsert, NodeDA **pointersToInsert,
                           int numToInsert);

    NodeDA *findPrevious(NodeDA *node);

    void CallRedistributeMergeRecomputeKeysInAncestorsLeftPart(NodeDA *preLeaf, NodeDA **leafToDelete,
                                                               int numLeafToDelete);

    int Query(int start) const;

    void PrintArray();
};

DynamicArray *NewDynamicArray(int * & array, int numItems, int degree);

#endif //INDEXSTRUCTURE_DYNAMICARRAY_H
