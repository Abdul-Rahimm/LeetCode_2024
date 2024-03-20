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
public:
    ListNode *mergeInBetween(ListNode *head, int a, int b, ListNode *list2)
    {
        ListNode *start = head;
        ListNode *end = head;

        a--;

        while (a--)
        {
            start = start->next;
        }
        while (b--)
        {
            end = end->next;
        }

        start->next = list2;

        ListNode *temp = list2;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = end->next;

        return head;
    }
};