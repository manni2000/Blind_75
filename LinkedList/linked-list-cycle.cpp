#include <iostream>

struct ListNode
{
    int val;        // The value of the node
    ListNode *next; // Pointer to the next node in the list

    // Constructors for the ListNode struct
    ListNode() : val(0), next(nullptr) {}                   // Default constructor
    ListNode(int x) : val(x), next(nullptr) {}              // Constructor with value
    ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value and next node pointer
};

bool hasCycle(ListNode *head)
{
    if (head == nullptr)
        return false;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    bool hasCycleResult = hasCycle(head);

    std::cout << "Does the list have a cycle? " << (hasCycleResult ? "Yes" : "No") << std::endl;

    // Clean up the memory
    ListNode *curr = head;
    while (curr != nullptr)
    {
        ListNode *next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}
