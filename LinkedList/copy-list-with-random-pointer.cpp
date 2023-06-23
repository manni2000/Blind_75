#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;

        // Step 1:
        // Create a copy of each node
        // keep next ptr and random ptr of new node equal to random ptr of equivalenmt old node

        Node *newhead = NULL;
        Node *cur = head;
        Node *cur1 = head;

        while (cur != NULL)
        {
            Node *temp = new Node(cur->val);
            temp->random = cur->random;
            temp->next = cur->random;
            cur->random = temp;
            if (newhead == NULL)
            {
                newhead = temp;
            }
            cur = cur->next;
        }

        // Step 2:
        // Change the value of random ptr of new node with the equivalent newly created nodes ptr

        cur = head;
        while (cur != NULL)
        {
            if (cur->random->random != NULL)
                cur->random->random = cur->random->random->random;
            cur = cur->next;
        }

        // Step 3:
        // Till now new linked list are isolated and are not linked
        // Random ptr of old LL contains the address of new head
        // Next ptr of new node contains the actual random ptr of old LL
        // Now, traverse old LL and restoore the random ptr from new LL and link the new LL whose next address is present in the random ptr of next node of old LL

        cur = head;
        cur1 = newhead;

        while (cur->next != NULL)
        {
            Node *temp = cur->next->random;
            cur->random = cur1->next;
            cur1->next = temp;
            cur = cur->next;
            cur1 = cur1->next;
        }

        cur->random = cur1->next;
        cur1->next = NULL;

        return newhead;
    }
};

int main()
{
    Node *head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);

    Solution obj;
    Node *result = obj.copyRandomList(head);

    // Print all Nodes
    Node *current = result;
    while (current != NULL)
    {
        std::cout << current->val << " ";
        current = current->next;
    }

    // After print all nodes delete nodes
    current = result;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}

// TC-O(N)
// SC-O(1)