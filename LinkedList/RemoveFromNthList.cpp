#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head, *fast = head;
        while (n--)
        {
            fast = fast->next;
        }
        if (fast == NULL)
            return slow->next;

        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Create a sample linked list
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);
    ListNode *fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    int n = 2; // Remove the 2nd node from the end

    Solution solution;
    ListNode *newHead = solution.removeNthFromEnd(head, n);

    printList(newHead);

    // Free the memory
    ListNode *current = newHead;
    while (current != NULL)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
