#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Iterative Method -> TC-O(N) & SC-O(1)
// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *prev = NULL;
//         ListNode *cur = head;

//         while (cur != NULL)
//         {
//             ListNode *temp = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = temp;
//         }
//         return prev;
//     }
// };

// Recursion Method -> TC-O(N) & SC-O(N)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *h2 = reverseList(head->next);
        head->next->next = head;
        head->next = prev;
        return h2;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode *reversedHead = solution.reverseList(head);

    // Print the reversed list
    ListNode *current = reversedHead;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }

    // Clean up the memory
    current = reversedHead;
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
