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
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL, *temp = head, *n = head->next;

        while (prev != temp)
        {
            temp->next = prev;

            prev = temp;
            temp = n;
            if (n->next)
                n = n->next;
        }

        return temp;
    }
    void solve(ListNode *head)
    {
        ListNode *temp = head, *lastNode = NULL;
        int carry = 0;

        while (temp != NULL)
        {
            int value = temp->val * 2 + carry;

            temp->val = value % 10;
            carry = value >= 10 ? 1 : 0;

            lastNode = temp;
            temp = temp->next;
        }

        if (carry)
        {
            ListNode *node = new ListNode(1);
            lastNode->next = node;
        }
    }

    ListNode *doubleIt(ListNode *head)
    {
        head = reverse(head);

        solve(head);

        return reverse(head);
    }
};