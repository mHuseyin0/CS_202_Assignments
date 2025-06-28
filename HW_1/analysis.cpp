/**
* Title: Binary Search Trees
* Author : Muhammed Huseyin AYDIN
* ID: 22203683
* Section : 1
* Homework : 1
* Description : Part 3
*/

#include "analysis.h"
using namespace std;

typedef std::chrono::system_clock sysclock;
typedef std::chrono::time_point<sysclock>  timepoint;
typedef std::chrono::duration< double, std::micro > duration;

void timeAnalysis(){
        srand(std::time(0));

        int *arr = new int[10000];
        // Generate 10 thousand values between 0 and 1 billion
        // 1 billion is chosen in order to prevent duplicates (Even 100 million produces around 5 duplicates in 10 thousand numbers)
        for (int i = 0; i < 10000; i++) {
                arr[i] = rand() % 1000000001;
        }

        BST *bst = new BST(); // Default constructor returns an empty tree

        timepoint startTime, endTime;
        duration time;

        int *heightArr = new int[10];
        for (int i = 0; i < 10; i++) {
                startTime = sysclock::now();

                for (int j = 0; j < 1000; j++) {
                        bst->insertKeyHelper(arr[1000 * i + j], false);
                }

                endTime = sysclock::now();
                time = endTime - startTime;
                heightArr[i] = bst->height();

                cout << "Node: " << 1000 * (i + 1) << "\tHeight: " << heightArr[i] << "\tTime: " << time.count() << "\tms" << endl;
        }
        cout << "Size: " << bst->size() << endl;

	delete[] arr;
	delete[] heightArr;
	delete bst;
}
