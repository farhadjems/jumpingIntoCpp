#include <iostream>

using namespace std;

struct binaryTree
{
    int value;
    binaryTree *biggerNode;
    binaryTree *smallerNode; 
};

binaryTree *insertNode(binaryTree *tree, int value); // this function adds node to the given tree
binaryTree *searchTree(binaryTree *tree, int value); // this function finds the considered node in the given tree by value
binaryTree *removeNode(binaryTree *tree, int value); // this function removes the node which its value is given 
binaryTree *findMaxNode(binaryTree *tree); // this function finds the maximum node in the tree
binaryTree *removeMaxNode(binaryTree *tree); // this function removes the maximum node in the given tree
void deleteTree(binaryTree *tree); // this function removes the given tree
void printTree(binaryTree *tree); // this function prints the given tree in sorted order 
void printTreeReverse(binaryTree *tree); // this function prints the given tree in sorted order 
int numberOfNodes(binaryTree *tree); // this function counts the number of nodes in the given tree
bool isTreeBalanced(binaryTree *tree); // This function checks if the given tree is balanced or not

int main()
{
    binaryTree *tree = NULL;
    int value = 1;
    while (value)
    {
        cout << " enter value: ";
        cin >> value;
        if (value)
        {
            tree = insertNode(tree, value);
        }
    }
    cout << "----------BINARY TREE-------------\n";
    printTree(tree);
    cout << "---------END--------------\n";
    
   bool balanced = isTreeBalanced(tree);
   cout << balanced;
}

