/**
* Title: Binary Search Trees
* Author : Muhammed Huseyin AYDIN
* ID: 22203683
* Section : 1
* Homework : 1
* Description : A BST class
*/

#ifndef BST_H
#define BST_H

class BST{
public:
BST();
    BST(int keys[], int size);
    BST(const BST& copyBST);
    ~BST();
    BST& operator= (const BST& copyBST);

    void insertKey(int key);
    void deleteKey(int key);
    void displayInorder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A, int B);
    void maximumSumPath();
    void maximumWidth();
    void pathFromAtoB(int A, int B);
    void mirror();

    void insertKeyHelper(int key, bool displayMessage);
    int height() const;
    int size() const;
private:
    int *rootValue;
    BST *leftSubtree;
    BST *rightSubtree;

    void deleteKeyHelper(int key, bool displayMessage);

    void displayInorderHelper(bool *displayedFirst) const;
    int fullBTLevelHelper(int currentLevel) const;

    int maxSum();
    void maximumSumPathHelper();

    int lowestCommonAncestorHelper(int A, int B);
    void maximumWidthHelper(int currentLevel, int *levelCount, int*& levelWidths) const;

    void displayPreorder();
    void displayPreorderHelper();

    void printFromAToAncestor(int A, BST *ancestor) const;
    void printFromAncestorToB(int B, BST *ancestor) const;

    void printLevel(int currentLevel, bool *printedFirst);
    void mirrorHelper();

    BST* getParent(int key);
    BST* getNode(int key);

    int getInorderSuccessor(int nodeValue);
    int getInorderSuccessorHelper();
};

#endif
