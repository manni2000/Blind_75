#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy, *cur = head, *nex;

        int cnt = 0;
        while (cur)
        {
            cnt++;
            cur = cur->next;
        }

        while (cnt >= k)
        {
            cur = pre->next;
            nex = cur->next;

            for (int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            cnt -= k;
        }
        return dummy->next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode *result = obj.reverseKGroup(head, 2);

    // Print the reversed list
    ListNode *curr = result;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }

    // Delete list from memory
    curr = result;
    while (curr != NULL)
    {
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
