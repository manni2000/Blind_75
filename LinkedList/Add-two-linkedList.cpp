#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;        // The value of the node
    ListNode *next; // Pointer to the next node in the list

    // Constructors for the ListNode struct
    ListNode() : val(0), next(nullptr) {}                   // Default constructor
    ListNode(int x) : val(x), next(nullptr) {}              // Constructor with value
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value and next node pointer
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;

    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;                               // 2+6=8, 4+6=10, 3+4=7
        carry = sum / 10;                           // 8/10=0, 10/10=1, 7/10=0
        ListNode *newnode = new ListNode(sum % 10); // 8%10=8, 10%10=0, 7%10=7
        temp->next = newnode;
        temp = temp->next; // 8, 0, 7
    }
    return dummy->next; // 8, 0, 7
}

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(6);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *result = addTwoNumbers(l1, l2);

    ListNode *curr = result;
    while (curr != NULL)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }

    delete l1;
    delete l2;
    delete result;

    return 0;
}

// TC-O(N)
// SC-O(1)