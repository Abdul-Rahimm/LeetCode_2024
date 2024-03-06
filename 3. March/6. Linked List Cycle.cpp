bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {

        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else
            return false;

        if (slow == fast)
            return true;
    }

    return false;
