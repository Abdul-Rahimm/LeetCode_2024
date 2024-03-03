class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> nodes;

        ListNode *temp = head;

        while (temp != NULL)
        {
            cout << temp->val << " ";
            nodes.push_back(temp); // record all nodes in the vector
            temp = temp->next;
        }

        int size = nodes.size();

        if (size == n)
        {
            head = head->next;
            return head;
        }

        int targetNode = size - n - 1;
        temp = nodes[targetNode];

        temp->next = temp->next->next;

        return head;
    }
};