/**
 * Title: Binary Search Trees
 * Author : Muhammed Huseyin AYDIN
 * ID: 22203683
 * Section : 1
 * Homework : 1
 * Description : A BST class
 */

#include "BST.h"
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * Construct a binary search tree by inserting values in the array one by one from the beginning.
 *
 * Duplicate keys are omitted.
 *
 * Entering size <= 0 will construct a null BST
 *
 * Entering a size less than the actual array size will construct with first n (n = size) values in the array
 *
 * Do not enter a size greater than the actual array size
 *
 * @param keys an array of integers to be inserted in BST
 * @param size of the array
 *
 * @return A BST object with the given size and values
 *
 */
BST::BST(int keys[], int size){
        rootValue = nullptr;
        leftSubtree = nullptr;
        rightSubtree = nullptr;
        for (int i = 0; i < size; i++) {
                insertKeyHelper(keys[i], false);
        }

        cout << "BST with size " << size << " is created." << endl;
}

/**
 * Construct a null BST which can be filled later
 *
 * @return A null BST object
 *
 */
BST::BST(){
        rootValue = nullptr;
        leftSubtree = nullptr;
        rightSubtree = nullptr;
}

/**
 * Deep copy a BST object
 *
 * @param A BST object to copy values from
 * @return A BST object which is a copy of the given BST
 *
 */
BST::BST(const BST& copyBST){
        if (copyBST.rootValue == nullptr) rootValue = nullptr;
        else rootValue = new int(*copyBST.rootValue);

        if (copyBST.leftSubtree == nullptr) leftSubtree = nullptr;
        else leftSubtree = new BST(*copyBST.leftSubtree);

        if (copyBST.rightSubtree == nullptr) rightSubtree = nullptr;
        else rightSubtree = new BST(*copyBST.rightSubtree);

}

/**
 * Recursively delete a BST object with its left and right subtrees.
 *
 * Set left and right subtrees to nullptr to prevent recursive deletion
 */
BST::~BST(){
        if (rootValue != nullptr) delete rootValue;
        if (leftSubtree != nullptr) delete leftSubtree;
        if (rightSubtree != nullptr) delete rightSubtree;
}

/**
 * Delete the current tree and deep copy the given one into this.
 *
 * @param A BST object to copy from.
 * @return Copied BST object.
 *
 */
BST& BST::operator= (const BST& copyBST){
        if (&copyBST == this) return *this;

        if (rootValue != nullptr) delete rootValue;
        if (leftSubtree != nullptr) delete leftSubtree;
        if (rightSubtree != nullptr) delete rightSubtree;

        if (copyBST.rootValue == nullptr) rootValue = nullptr;
        else rootValue = new int(*copyBST.rootValue);

        if (copyBST.leftSubtree == nullptr) leftSubtree = nullptr;
        else leftSubtree = new BST(*copyBST.leftSubtree);

        if (copyBST.rightSubtree == nullptr) rightSubtree = nullptr;
        else rightSubtree = new BST(*copyBST.rightSubtree);

        return *this;
}

/**
 * Insert a key to the BST and display a message whether the insertion was successfull or not
 *
 * Duplicate keys cannot be inserted
 *
 * @param key integer value to be inserted.
 *
 */
void BST::insertKey(int key){
        insertKeyHelper(key, true);
}

/**
 * Recursive helper function for insertKey() function
 *
 * Duplicate keys cannot be inserted
 *
 * @param key integer value to be inserted.
 * @param displayMessage if true, write a message to the console whether the insertion was successfull or not
 *
 */
void BST::insertKeyHelper(int key, bool displayMessage){
        // Insert value as the root of the correct position
        if (rootValue == nullptr) {
                rootValue = new int(key);
                if (displayMessage) cout << "Key " << key << " is added." << endl;
                return;
        }

        // Direct to left
        if (*rootValue > key) {
                // Duplicate found. Cannot insert
                if (leftSubtree != nullptr && *leftSubtree->rootValue == key) {
                        if (displayMessage) cout << "Key " << key << " is not added. It exists!" << endl;
                        return;
                }

                // Create new subtree and insert
                if (leftSubtree == nullptr) leftSubtree = new BST();
                leftSubtree->insertKeyHelper(key, displayMessage);
                return;
        }

        // Direct to right
        // Duplicate found. Cannot insert
        if (rightSubtree != nullptr && *rightSubtree->rootValue == key){
                if (displayMessage) cout << "Key " << key << " is not added. It exists!" << endl;
                return;
        }

        // Create new subtree and insert
        if (rightSubtree == nullptr) rightSubtree = new BST();
        rightSubtree->insertKeyHelper(key, displayMessage);

}

/**
 * Delete a key from the tree and display a message whether the deletion was successfull or not
 *
 * If node has only a single child, that subtree will be copied into this
 *
 * If node has both children, delete its inorder successor and copy that value into this
 *
 * @param key integer value to be deleted.
 */
void BST::deleteKey(int key){
        deleteKeyHelper(key, true);
}

/**
 * Recursive helper function for deleteKey() function
 *
 * If node has only a single child, that subtree will be copied into this
 *
 * If node has both children, delete its inorder successor and copy that value into this
 *
 * @param key integer value to be deleted.
 * @param displayMessage if true, write a message to the console whether the deletion was successfull or not
 */
void BST::deleteKeyHelper(int key, bool displayMessage){
        // Tree is empty
        if (rootValue == nullptr) {
                if (displayMessage) cout << "Key " << key << " is not deleted. It does not exist!" << endl;
                return;
        }

        if (*rootValue == key) {
                if (displayMessage) cout << "Key " << key << " is deleted." << endl;

                // Only has right child
                if (leftSubtree == nullptr && rightSubtree != nullptr) {

                        BST *temp = rightSubtree;

                        // Copy right child into this
                        delete rootValue;
                        rootValue = new int(*rightSubtree->rootValue);

                        leftSubtree = rightSubtree->leftSubtree;
                        rightSubtree = rightSubtree->rightSubtree;

                        // Delete old right child node
                        temp->rightSubtree = nullptr;
                        temp->leftSubtree = nullptr;
                        delete temp;
                        return;
                }

                // Only has left child
                if (leftSubtree != nullptr && rightSubtree == nullptr) {

                        BST *temp = leftSubtree;

                        // Copy left child into this
                        delete rootValue;
                        rootValue = new int(*leftSubtree->rootValue);

                        rightSubtree = leftSubtree->rightSubtree;
                        leftSubtree = leftSubtree->leftSubtree;

                        // Delete old left child node
                        temp->rightSubtree = nullptr;
                        temp->leftSubtree = nullptr;
                        delete temp;
                        return;
                }

                // Delete a leaf node
                if (leftSubtree == nullptr && rightSubtree == nullptr){
                        BST *parent = getParent(*rootValue);
                        if (parent == nullptr) {
                                delete rootValue;
                                rootValue = nullptr;
                        }
                        else {
                                if (parent->leftSubtree != nullptr && key == *parent->leftSubtree->rootValue) delete parent->leftSubtree;
                                else delete parent->rightSubtree;
                        }

                        return;
                }

                // Has both children
                int inorderSuccessor = getInorderSuccessor(key);
                deleteKeyHelper(inorderSuccessor, false);

                delete rootValue;
                rootValue = new int(inorderSuccessor);
                return;
        }

        // Continue from left
        if (*rootValue > key) {

                // Key does not exist
                if (leftSubtree == nullptr){
                        if (displayMessage) cout << "Key " << key << " is not deleted. It does not exist!" << endl;
                        return;
                }

                leftSubtree->deleteKeyHelper(key, displayMessage);
                return;
        }

        // Continue from right
        // Key does not exist
        if (rightSubtree == nullptr){
                if (displayMessage) cout << "Key " << key << " is not deleted. It does not exist!" << endl;
                return;
        }

        rightSubtree->deleteKeyHelper(key, displayMessage);

}

/**
 * Displays tree with inorder traversal
 */
void BST::displayInorder(){
        cout << "Inorder display is: ";
        bool *displayedFirst = new bool(false);
        displayInorderHelper(displayedFirst);
        delete displayedFirst;
        cout << endl;
}

/**
 * Recursive helper function for displayInorder() function
 *
 * Prints commas between values
 *
 * @param displayedFirst whether the first value has been displayed or not. (In order to prevent printing a leading comma.)
 *
 */
void BST::displayInorderHelper(bool *displayedFirst) const{
        if (rootValue == nullptr) return;

        if (leftSubtree != nullptr) leftSubtree->displayInorderHelper(displayedFirst);

        if (*displayedFirst) cout << ", ";
        cout << *rootValue;
        *displayedFirst = true;

        if (rightSubtree != nullptr) rightSubtree->displayInorderHelper(displayedFirst);
}


/**
 * Finds the maximum level at which the tree is a full binary tree, and displays the level number.
 *
 * Assume that root is level 1.
 */
void BST::findFullBTLevel(){
        int result;

        if (rootValue == nullptr) result = 0;

        result = fullBTLevelHelper(1);

        cout << "Full binary tree level is: " << result << endl;
}

/**
 * Recursive helper function for findFullBTLevel() function.
 *
 *
 * @param currentLevel Full Binary Tree level upto this step
 * @return full binary tree level after traversing both subtrees of that node
 *
 */
int BST::fullBTLevelHelper(int currentLevel) const{
        if (leftSubtree == nullptr || rightSubtree == nullptr) return currentLevel;
        currentLevel++;
        return min(leftSubtree->fullBTLevelHelper(currentLevel), rightSubtree->fullBTLevelHelper(currentLevel));
}


/**
 * Print lowest common ancestor of two nodes, a node is an ancestor of itself.
 *
 * Does not check if the keys exist.
 * Do not execute with non existant keys.
 *
 * @param A First Node.
 * @param B Second Node.
 */
void BST::lowestCommonAncestor(int A, int B){
        cout << "Lowest common ancestor of " << A << " and " << B << " is: " << lowestCommonAncestorHelper(A, B) << endl;
}

/**
 * Recursive helper of lowestCommonAncestor() function.
 *
 * Does not checck if the keys exist.
 *
 * @param A First Node.
 * @param B Second Node.
 */
int BST::lowestCommonAncestorHelper(int A, int B){
        if (A > *rootValue && B > *rootValue) {
                return rightSubtree->lowestCommonAncestorHelper(A, B);
        }

        if (A < *rootValue && B < *rootValue) {
                return leftSubtree->lowestCommonAncestorHelper(A, B);
        }

        return *rootValue;
}

/**
 * Finds the path from root to a leaf node which has the maximum sum of the keys
 * included in the path, and displays the keys of the path from its root to the leaf.
 *
 */
void BST::maximumSumPath(){
        cout << "Maximum sum path is: ";
        if (rootValue == nullptr) {
                cout << endl;
                return;
        }

        // This part is written in order to prevent printing leading comma
        cout << *rootValue;

        if (leftSubtree == nullptr && rightSubtree == nullptr) {
                cout << endl;
                return;
        }
        else if (leftSubtree == nullptr) rightSubtree->maximumSumPathHelper();
        else if (rightSubtree == nullptr) leftSubtree->maximumSumPathHelper();
        else if (leftSubtree->maxSum() > rightSubtree->maxSum()) leftSubtree->maximumSumPathHelper();
        else rightSubtree->maximumSumPathHelper();

        cout << endl;
}


/**
 * Recursive helper for maximumSumPath() function.
 */
void BST::maximumSumPathHelper(){
        cout << ", " << *rootValue;

        if (leftSubtree == nullptr && rightSubtree == nullptr) {
                return;
        }
        else if (leftSubtree == nullptr) rightSubtree->maximumSumPathHelper();
        else if (rightSubtree == nullptr) leftSubtree->maximumSumPathHelper();
        else if (leftSubtree->maxSum() > rightSubtree->maxSum()) leftSubtree->maximumSumPathHelper();
        else rightSubtree->maximumSumPathHelper();

}

/**
 * Finds the max sum from root to a leaf node for that tree or subtree
 *
 * @return max sum from root to a leaf node
 */
int BST::maxSum(){

        if (leftSubtree == nullptr && rightSubtree == nullptr) return *rootValue;

        if (leftSubtree == nullptr) return *rootValue + rightSubtree->maxSum();
        if (rightSubtree == nullptr) return *rootValue + leftSubtree->maxSum();

        return *rootValue + max(leftSubtree->maxSum(), rightSubtree->maxSum());
}


/**
 * Find the level with max number of nodes and displays its keys from left to right.
 * In case of multiple maximum widths select the lowest level. (Closest to the root.)
 */
void BST::maximumWidth(){
        cout << "Maximum level is: ";
        if (rootValue == nullptr) {
                cout << endl;
                return;
        }

        int *arr = new int[1];
        int *size = new int(1);
        maximumWidthHelper(1, size, arr);

        int currentMaxWidthLevel = 1;
        for (int i = 1; i < *size; i++) {
                if (currentMaxWidthLevel < arr[i]) currentMaxWidthLevel = i - 1;
        }

       delete[] arr;
        delete size;

        bool *printedFirst = new bool(false);
        printLevel(currentMaxWidthLevel, printedFirst);
        delete printedFirst;

        cout << endl;
}

/**
 * Recursive helper function for maximumWidth() function
 *
 * Uses preorder traversal when counting
 *
 * @param currentLevel level of the current node that is being traversed
 * @param currentArrSize size of the array that stores the widths of levels
 * @param levelWidths an array that stores widths of levels up to now
 *
 */
void BST::maximumWidthHelper(int currentLevel, int *currentArrSize, int* &levelWidths) const{
        // If array size is less than current level
        if (*currentArrSize == currentLevel - 1 ){
                int *newArr = new int[currentLevel];
                for (int i = 0; i < *currentArrSize; i++) {
                        newArr[i] = levelWidths[i];
                }
                newArr[*currentArrSize] = 0;
                *currentArrSize = *currentArrSize + 1;

                delete[] levelWidths;
                levelWidths = newArr;
        }

        levelWidths[currentLevel - 1] = levelWidths[currentLevel - 1] + 1;

        if (leftSubtree != nullptr) leftSubtree->maximumWidthHelper(currentLevel + 1, currentArrSize, levelWidths);
        if (rightSubtree != nullptr) rightSubtree->maximumWidthHelper(currentLevel + 1, currentArrSize, levelWidths);
}

/**
 * Recursively goes in deep until finding the node to print.
 * Root node is level 0.
 *
 * @param currentLevel height difference from the depth that is wanted to be printed (Entering 0 will print root)
 * @param printedFirst whether the first value is printed or not. (To prevent printing leading comma.)
 *
 */
void BST::printLevel(int currentLevel, bool *printedFirst){
        if (currentLevel > 0) {
                if (leftSubtree != nullptr) leftSubtree->printLevel(currentLevel - 1, printedFirst);
                if (rightSubtree != nullptr) rightSubtree->printLevel(currentLevel - 1, printedFirst);
                return;
        }

        if (*printedFirst) cout << ", ";
        cout << *rootValue;

        *printedFirst = true;
}

/**
 * Finds the path from key A to key B, and displays the keys included in the path.
 *
 * Utilizes printFromAToAncestor() and printFromAncestorToB() functions.
 *
 * @param A First Node
 * @param B Second Node
 *
 */
void BST::pathFromAtoB(int A, int B){
        cout << "Path from " << A << " to " << B << " is: ";

        BST *ancestorNode = getNode(lowestCommonAncestorHelper(A, B));

        if (*ancestorNode->rootValue != A) printFromAToAncestor(A, ancestorNode);

        // In order to prevent double writing lowest common ancestor
        if (*ancestorNode->rootValue > B) {
                printFromAncestorToB(B, ancestorNode->leftSubtree);
        }
        else {
                printFromAncestorToB(B, ancestorNode->rightSubtree);
        }

        cout << endl;
}

/**
 * Creates the mirror of the BST (swap left/right subtrees recursively).
 * Then prints the preorder traversal of the mirror tree.
 * Does not change the original tree.
 *
 */
void BST::mirror(){
        cout << "Preorder mirror is: ";

        BST *copyBST = new BST(*this);
        copyBST->mirrorHelper();
        copyBST->displayPreorder();

        delete copyBST;
        cout << endl;
}

/**
 * Recursive helper function for the mirror() function.
 */
void BST::mirrorHelper(){
        if (leftSubtree != nullptr) leftSubtree->mirrorHelper();
        if (rightSubtree != nullptr) rightSubtree->mirrorHelper();

        // If not a leaf node swap subtrees
        if (leftSubtree != rightSubtree){
                BST *temp = rightSubtree;
                rightSubtree = leftSubtree;
                leftSubtree = temp;
        }
}

int BST::height() const{
        if (rootValue == nullptr) return 0;

        if (leftSubtree != nullptr && rightSubtree != nullptr) return 1 + max(leftSubtree->height(), rightSubtree->height());

        if (leftSubtree != nullptr) return 1 + leftSubtree->height();

        if (rightSubtree != nullptr) return 1 + rightSubtree->height();

        return 1;
}

int BST::size() const{
        if (rootValue == nullptr) return 0;

        if (leftSubtree != nullptr && rightSubtree != nullptr) return 1 + leftSubtree->size() + rightSubtree->size();

        if (leftSubtree != nullptr) return 1 + leftSubtree->size();

        if (rightSubtree != nullptr) return 1 + rightSubtree->size();

        return 1;
}

void BST::printFromAToAncestor(int A, BST *ancestor) const{
        if (*ancestor->rootValue > A) {
                printFromAToAncestor(A, ancestor->leftSubtree);
                cout << ", " << *ancestor->rootValue;
                return;
        }

        if (*ancestor->rootValue < A) {
                printFromAToAncestor(A, ancestor->rightSubtree);
                cout << ", " << *ancestor->rootValue;
                return;
        }

        cout << A;
}

void BST::printFromAncestorToB(int B, BST *ancestor) const{
        cout << ", " << *ancestor->rootValue;

        if (*ancestor->rootValue > B) {
                printFromAncestorToB(B, ancestor->leftSubtree);
                return;
        }

        if (*ancestor->rootValue < B) {
                printFromAncestorToB(B, ancestor->rightSubtree);
                return;
        }
}

void BST::displayPreorder(){
        if (rootValue != nullptr) cout << *rootValue;

        if (leftSubtree != nullptr) leftSubtree->displayPreorderHelper();
        if (rightSubtree != nullptr) rightSubtree->displayPreorderHelper();
}

// Helper is not to put a comma before the first node
void BST::displayPreorderHelper(){

        cout << ", ";
        cout << *rootValue;

        if (leftSubtree != nullptr) leftSubtree->displayPreorderHelper();
        if (rightSubtree != nullptr) rightSubtree->displayPreorderHelper();
}

// Should only be used to delete inorder successor of a node which has right subtree
int BST::getInorderSuccessor(int nodeValue){
        return getNode(nodeValue)->rightSubtree->getInorderSuccessorHelper();

}

int BST::getInorderSuccessorHelper(){
        if (leftSubtree != nullptr) return leftSubtree->getInorderSuccessorHelper();

        return *rootValue;

        if (rightSubtree != nullptr) return rightSubtree->getInorderSuccessorHelper();
}

BST* BST::getParent(int key){
        // If key is the root or the tree is null
        if (rootValue == nullptr && key == *rootValue)return nullptr;

        if (key > *rootValue){
                if (rightSubtree == nullptr) return nullptr; // Key does not exist
                if (*rightSubtree->rootValue == key) return this;
                return rightSubtree->getParent(key);
        }

        if (leftSubtree == nullptr) return nullptr; // Key does not exist
        if (*leftSubtree->rootValue == key) return this;
        return leftSubtree->getParent(key);

}

BST* BST::getNode(int key){

        // If the tree is null
        if (rootValue == nullptr) return nullptr;

        // If key is the root
        if (key == *rootValue) return this;

        if (key > *rootValue){
                if (rightSubtree == nullptr) return nullptr; // Key does not exist
                if (*rightSubtree->rootValue == key) return rightSubtree;
                return rightSubtree->getNode(key);
        }

        if (leftSubtree == nullptr) return nullptr; // Key does not exist
        if (*leftSubtree->rootValue == key) return leftSubtree;
        return leftSubtree->getNode(key);
}
