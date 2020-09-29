# AdaptiveDynamicArray
Adaptive Dynamic Array: Keeping Data in Order from Exploration to Manipulation

## Introduction
Adaptive Dynamic Array is an index structure which maintains a rank-to-row mapping to enable order awareness in relational databases.

### Extended Report
An extended report can be found [here](https://github.com/Anonymous82338590/AdaptiveDynamicArray/blob/master/extended_report.pdf).

## About this repo
This repository contains all the algorithms and texting files in our experiments, as shown in the following table.

| Algorithms (src/HeaderFiles)     | Description                             |
| ------------------------- | ---------------------------------------- |
| Adaptive Dynamic Array (ADA)    |  Index structure. |
| Standard Array (SA)  | Basic data structure array a[...]. |
| Counted Btree (CBT), aka Ordered Statistic Tree | [This](https://www.chiark.greenend.org.uk/~sgtatham/algorithms/cbtree.html) and [this](https://en.wikipedia.org/wiki/Order_statistic_tree) give definitions of CBT.|
| Indexed Linked List (LL) | [A linked list with an auxiliary array.](https://patents.google.com/patent/US5950191A/en) |
| Tiered Vector (TV)       |  [A data structure for maintaining a sequence allowing query and udpate.](https://arxiv.org/pdf/1711.00275.pdf)


| Experiments | Location |
|-----------------|---------------|
| Framework Validation| src/Experiments/Framework |
| Index Structure Comparison | src/Experiments/IndexStructureComparison |
| Ablation Study | src/Experiments/Ablation |

### Requirements
- g++ 
- MySQL Connector/C++ is needed for framework validation. Installation guide can be found [here](https://dev.mysql.com/doc/connector-cpp/8.0/en/connector-cpp-downloading.html).

### How to build
Every single program is put into a separate folder with a Makefile and run.sh.
Please go to the directory and use the following commands to build and run.
 ```
make
bash run.sh
 ```
For example, go to directory src/Experiments/Ablation/1M/delete, use 'make' to get the executable file and then 'bash run.sh' to run it.
Final results are recorded in 'avg.csv': average response time after running 'delete.cpp' for 10 times.