#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct BinaryTree
{
    int value;
    BinaryTree *left;
    BinaryTree *right;
};

int randomNumber(int low, int high);
BinaryTree *addNode(BinaryTree *tree, int value);
void printTree(BinaryTree *tree);                          // problem 01
int numberOfNodes(BinaryTree *tree);                       // problem 02
bool isTreeBalanced(BinaryTree *tree);                     // problem 03
bool isTreeSorted(BinaryTree *tree);                       // problem 04
BinaryTree *addNonSortedNode(BinaryTree *tree, int value); // problem 04
void deleteTree(BinaryTree *tree);                         // problem 05
int main()
{
    srand(time(NULL));
    // the root
    BinaryTree *tree = new BinaryTree;
    tree->left = NULL;
    tree->right = NULL;
    tree->value = 5;

    // adding elements - sorted manner - problems 01 to 03
    for (int i = 0; i < 20; i++)
    {
        int number = randomNumber(1, 11);
        cout << "Trying to add " << number << endl;
        addNode(tree, number);
    }

    // adding elements - non-sorted manner - problem 04
    // for (int i = 0; i < 20; i++)
    // {
    //     int number = randomNumber(1, 11);
    //     cout << "Trying to add " << number << endl;
    //     addNonSortedNode(tree, number);
    // }

    // problem 01
    cout << "----Printing Table----" << endl;
    printTree(tree);

    // problem 02
    cout << "--------" << endl
         << "number of nodes: " << numberOfNodes(tree) << endl;

    // problem 03
    if (isTreeBalanced(tree))
    {
        cout << "Tree is balanced" << endl;
    }
    else
    {
        cout << "Tree is not balanced" << endl;
    }

    // problem 04
    if (isTreeSorted(tree))
    {
        cout << "Tree is sorted" << endl;
    }
    else
    {
        cout << "Tree is not sorted" << endl;
    }

    // problem 05
    deleteTree(tree);

    return 0;
}

int randomNumber(int low, int high)
{
    return (random() % (high - low) + low);
}

BinaryTree *addNode(BinaryTree *tree, int value)
{
    if (tree == NULL)
    {
        BinaryTree *newNode = new BinaryTree;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->value = value;
        return newNode;
    }

    if (value == tree->value)
    {
        cout << "Node with value " << value << " already exists" << endl;
        return tree;
    }
    if (value < tree->value)
    {
        tree->left = addNode(tree->left, value);
    }
    if (value > tree->value)
    {
        tree->right = addNode(tree->right, value);
    }
    return tree;
}

void printTree(BinaryTree *tree)
{
    if (tree == NULL) // base case - tree is empty
    {
        return;
    }
    printTree(tree->left);
    cout << tree->value << endl;
    printTree(tree->right);
}

int numberOfNodes(BinaryTree *tree)
{
    if (tree == NULL) // base case - tree is empty
    {
        return 0;
    }
    int number = 1;
    number += numberOfNodes(tree->left);
    number += numberOfNodes(tree->right);
    return number;
}
bool isTreeBalanced(BinaryTree *tree)
{
    int numberOfleftNodes = numberOfNodes(tree->left);
    int numberOfrightNodes = numberOfNodes(tree->right);

    if (numberOfleftNodes == numberOfrightNodes)
    {
        return true;
    }
    return false;
}

bool isTreeSorted(BinaryTree *tree) // problem 04
{
    if (tree == NULL) // base case
    {
        return true;
    }
    if (tree->left != NULL && tree->left->value < tree->value)
    {
        isTreeSorted(tree->left);
    }
    else
    {
        return false;
    }
    if (tree->right != NULL && tree->right->value > tree->value)
    {
        isTreeSorted(tree->right);
    }
    else
    {
        return false;
    }

    return true;
}

BinaryTree *addNonSortedNode(BinaryTree *tree, int value)
{
    if (tree == NULL)
    {
        BinaryTree *newNode = new BinaryTree;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->value = value;
        cout << "Node with value " << value << " added" << endl;
        return newNode;
    }

    if (randomNumber(1, 3) == 2)
    {
        tree->left = addNonSortedNode(tree->left, value);
    }
    else
    {
        tree->right = addNonSortedNode(tree->right, value);
    }

    return tree;
}

struct LinkedList // this list is implemented to store the nodes in the tree, in each level
{
    BinaryTree *node;
    LinkedList *nextNode;
};

void deleteTree(BinaryTree *tree)
{
    cout << "---- DELETE TREE PROGRAM ----" << endl;
    if (tree == NULL) // semi-base case :)
    {
        cout << "tree is already empty" << endl;
    }

    if (tree->left == NULL && tree->right == NULL)
    {
        delete tree;
        return;
    }

    LinkedList *listNode = new LinkedList;
    listNode->nextNode = NULL; // closing the end of the list
    listNode->node = tree;

    // in this loop, each level of tree nodes will be traversed and their left and right nodes
    //  will be added to the new list, then the current level will be deleted and then
    //  left and right nodes will be passsed to the level list.
    while (listNode->node != NULL)
    {
        LinkedList *nextLevelListNode = new LinkedList; // in this list, left and right of each node in the level will be added
        nextLevelListNode->nextNode = NULL;             // closing the end of the list
        nextLevelListNode->node = NULL;
        LinkedList *listNodeTraverse = listNode; // with this variable, we will traverse the list
        // in this loop, eversy left and right node of each level nodes will be added to the new list
        while (listNode != NULL && listNode->node != NULL)
        {
            if (listNode->node->left != NULL)
            {
                LinkedList *leftNode = new LinkedList;
                leftNode->node = listNode->node->left;
                leftNode->nextNode = nextLevelListNode;
                nextLevelListNode = leftNode;
                // delete leftNode;
                // leftNode = NULL;
            }

            if (listNode->node->right != NULL)
            {
                LinkedList *rightNode = new LinkedList;
                rightNode->node = listNode->node->right;
                rightNode->nextNode = nextLevelListNode;
                nextLevelListNode = rightNode;
                // delete rightNode;
                // rightNode = NULL;
            }
            listNodeTraverse = listNode->nextNode;
            cout << "deleting node with value: " << listNode->node->value << endl;

            // deleting current level
            delete listNode->node;
            listNode->node = NULL;

            // and clearing current level list completeley
            listNodeTraverse = listNode->nextNode;
            delete listNode;
            listNode = NULL;
            listNode = listNodeTraverse;
        }

        // left and right nodes are the next level, so they must be passed to the
        // pointer pointing to the current deleted level
        listNode = nextLevelListNode;
    }
    cout << "---- TREE DELETED ----" << endl;

    delete tree;
}