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
    ListNode *deleteMiddle(ListNode *head)
    {
        int count = 0;

        if (head->next == NULL)
            return NULL;

        ListNode *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        count = count / 2;
        temp = head;

        for (int i = 0; i < count - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        cout << temp->val << endl;
        return head;
    }
};