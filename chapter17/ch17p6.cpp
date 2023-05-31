#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum MenuOptions
{
    exitMenu = 0,
    addItem = 1,
    removeItem = 2,
    updateItem = 3,
    findItem = 4,
    printMap = 5,
};

struct BinaryTree
{
    string key;   // name
    string value; // email
    BinaryTree *left;
    BinaryTree *right;
};

BinaryTree *addNode(BinaryTree *tree, string key, string value);
BinaryTree *findMaxNode(BinaryTree *tree);
BinaryTree *swapMaxNode(BinaryTree *tree, BinaryTree *maxNode);
BinaryTree *removeNode(BinaryTree *tree, string key);
void updateNode(BinaryTree *tree, string key);
BinaryTree *searchNode(BinaryTree *tree, string key);
void printTree(BinaryTree *tree);
void deleteTree(BinaryTree *tree);

int main()
{
    BinaryTree *map;
    string name;
    string email;

    int menu = 1;
    while (menu)
    {
        cout << "Please choose one option:" << endl
             << "0. Exit Program" << endl
             << "1. Add Item" << endl
             << "2. Remove Item" << endl
             << "3. Update Item" << endl
             << "4. Find Item" << endl
             << "5. Print Item List" << endl;
        cin >> menu;
        cin.ignore();
        switch (menu)
        {
        case exitMenu:
            break;
            break;

        case addItem:
            cout << "Please enter name: ";
            getline(cin, name);
            cout << "Please enter" << name << "'s email address: ";
            getline(cin, email);
            map = addNode(map, name, email);
            break;

        case removeItem:
            cout << "Please enter name: ";
            getline(cin, name);
            map = removeNode(map, name);
            break;

        case updateItem:
            cout << "Please enter name: ";
            getline(cin, name);
            updateNode(map, name);
            break;

        case findItem:
            cout << "Please enter name: ";
            getline(cin, name);
            searchNode(map, name);
            break;
        case printMap:
            printTree(map);
            break;
        default:
            cout << "Choosen option does not exist in the menu, try again..." << endl;
            break;
        }
    }
    deleteTree(map);
    return 0;
}

BinaryTree *addNode(BinaryTree *tree, string key, string value)
{
    if (tree == NULL)
    {
        BinaryTree *newNode = new BinaryTree;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->value = value;
        newNode->key = key;
        return newNode;
    }

    if (key == tree->key)
    {
        cout << "Node with key " << tree->key << " already exists" << endl;
        return tree;
    }
    if (key < tree->key)
    {
        tree->left = addNode(tree->left, key, value);
    }
    if (key > tree->key)
    {
        tree->right = addNode(tree->right, key, value);
    }
    return tree;
}

BinaryTree *findMaxNode(BinaryTree *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->right == NULL)
    {
        return tree;
    }
    return findMaxNode(tree->right);
}
BinaryTree *swapMaxNode(BinaryTree *tree, BinaryTree *maxNode)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree == maxNode)
    {
        return maxNode->left;
    }

    tree->right = swapMaxNode(tree->right, maxNode);
    return tree;
}
BinaryTree *removeNode(BinaryTree *tree, string key)
{
    if (tree == NULL) // base case - empty tree
    {
        cout << "could not find the name " << key << endl;
        return NULL;
    }

    if (tree->key == key)
    {
        // no children
        if (tree->left == NULL && tree->right == NULL)
        {
            delete tree;
            return NULL;
        }

        // one child
        if (tree->left == NULL)
        {
            BinaryTree *removedNode = tree;
            tree = tree->right;
            delete removedNode;
            cout << "Item with the name " << key << " removed" << endl;
            return tree;
        }
        if (tree->right == NULL)
        {
            BinaryTree *removedNode = tree;
            tree = tree->left;
            delete removedNode;
            cout << "Item with the name " << key << " removed" << endl;
            return tree;
        }

        // with two children
        BinaryTree *maxNode = findMaxNode(tree->left);
        maxNode->left = swapMaxNode(tree->left, maxNode);
        maxNode->right = tree->right;
        delete tree;
        cout << "Item with the name " << key << " removed" << endl;
        return maxNode;
    }
    else if (key < tree->key)
    {
        tree->left = removeNode(tree->left, key);
    }
    else
    {
        tree->right = removeNode(tree->right, key);
    }
    return tree;
}

void updateNode(BinaryTree *tree, string key)
{
    BinaryTree *editedItem = searchNode(tree, key);
    if (editedItem != NULL)
    {
        cout << "Item with the name " << editedItem->key << " found, please enter new email: ";
        getline(cin, editedItem->value);
        cout << "Item with the name " << editedItem->key << " updated" << endl
             << "new email address: " << editedItem->value << endl;
    }
    else
    {
        cout << "Item with the name " << key << " does not exist" << endl;
    }
}

BinaryTree *searchNode(BinaryTree *tree, string key)
{
    if (tree == NULL)
    {
        cout << "could not find the item with the name: " << key << endl;
        return NULL;
    }
    if (tree->key == key)
    {
        cout << "Item with the key " << tree->key << " exists. Related email address is: " << tree->value << endl;
        return tree;
    }
    else if (key < tree->key)
    {
        return searchNode(tree->left, key);
    }
    else
    {
        return searchNode(tree->right, key);
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
    cout << tree->key << "\t\t" << tree->value << endl;
    printTree(tree->right);
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