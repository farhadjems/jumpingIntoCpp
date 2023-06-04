#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *p_next;
};
int main()
{
    int val;
    //! you need to assign a space to the below pointer from the heap
    Node *p_head;
    // Node *p_head = new Node;
    //! since the above pointer is at the end of the list,
    //! it must point to NULL, closing the end of the list
    p_head->p_next = NULL;
    while (1)
    {
        cout << "Enter a value, 0 to replay: " << endl;
        cin >> val;
        if (val = 0 /*val == 0*/) //! check the condition, it doesnt work at all! it's not comapring, it's assigning!
        {
            break;
        }
        Node *p_temp = new Node;
        p_temp = p_head;
        p_temp->val = val;
        p_head = p_temp;
        // ! In above lines, new pointer will not add to the list
        // p_temp->val = val;
        // p_temp->p_next = p_head;
        // p_head = p_temp;
    }
    Node *p_itr = p_head;
    while (p_itr != NULL)
    {
        cout << p_itr->val << endl;
        // ! you are deleting the next element, not the current!
        p_itr = p_itr->p_next;
        delete p_itr;
        // p_itr = p_head->p_next;
        // delete p_head;
        // p_head = p_itr;
    }
}