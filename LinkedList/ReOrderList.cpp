#include <bits/stdc++.h>
using namespace std;

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode *l1 = head;
        ListNode *l2 = reverse(slow);
        merge(l1, l2);
    }

private:
    ListNode *reverse(ListNode *l2)
    {
        if (l2 == nullptr)
            return nullptr;

        ListNode *prev = nullptr;
        ListNode *curr = l2;
        ListNode *next = l2->next;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void merge(ListNode *l1, ListNode *l2)
    {
        while (l2 != nullptr)
        {
            ListNode *next = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = next;
        }
    }
};

int main()
{
    // Usage example
    Solution solution;

    // Create a sample linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Call the reorderList method
    solution.reorderList(head);

    // Output the modified linked list
    ListNode *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    // Clean up memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

//TC-O(N)
//SC-O(1)
