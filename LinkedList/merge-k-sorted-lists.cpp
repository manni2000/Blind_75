#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class mycompare
{
public:
    bool operator()(const ListNode *a, const ListNode *b)
    {
        return (a->val > b->val);
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        priority_queue<ListNode *, vector<ListNode *>, mycompare> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }

        while (!pq.empty())
        {
            auto least = pq.top();
            pq.pop();
            temp->next = least;
            temp = temp->next;
            if (least->next)
            {
                pq.push(least->next);
            }
        }
        return head->next;
    }
};

int main()
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode *head3 = new ListNode(2);
    head3->next = new ListNode(6);

    Solution s;
    vector<ListNode *> lists = {head1, head2, head3};
    ListNode *merged = s.mergeKLists(lists);

    // Printing the merged list
    while (merged != NULL)
    {
        cout << merged->val << " ";
        merged = merged->next;
    }

    return 0;
}
// TC- O(KlogN)
// SC- O(N)
