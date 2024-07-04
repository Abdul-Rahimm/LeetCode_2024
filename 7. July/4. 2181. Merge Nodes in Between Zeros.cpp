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
    ListNode *mergeNodes(ListNode *head)
    {

        ListNode *headAns = new ListNode(); // main answer wali linkedList
        ListNode *temp = headAns;

        head = head->next;

        int sum = 0;

        while (head != NULL)
        {
            if (head->val != 0)
            {
                sum += head->val;
            }
            else
            {
                temp->val = sum;

                if (head->next != NULL)
                {
                    temp->next = new ListNode();
                    temp = temp->next;
                }

                sum = 0;
            }

            head = head->next;
        }

        return headAns;
    }
};