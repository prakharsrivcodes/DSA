/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
private:
    ListNode *reverseLinkedList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *newHead = reverseLinkedList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;

        // 1. Middle node dhoondna (slow-fast pointer)
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Second half ko reverse karna
        ListNode *newHead = reverseLinkedList(slow->next);

        // 3. Both halves ko compare karna
        ListNode *first = head;
        ListNode *second = newHead;
        while (second != NULL)
        {
            if (first->val != second->val)
            {
                reverseLinkedList(newHead); // Original list restore karna
                return false;
            }
            first = first->next;
            second = second->next;
        }

        // 4. List ko wapas original state me restore karna
        reverseLinkedList(newHead);

        return true;
    }
};