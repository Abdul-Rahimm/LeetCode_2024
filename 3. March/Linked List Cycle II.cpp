ListNode *detectCycle(ListNode *head)
{
    if (!head || !head->next)
        return NULL;

    ListNode *slow = head, *fast = head;

    while (fast != NULL)
    {

        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else
            return NULL;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return NULL;

    ListNode *temp = head;
    while (temp != slow)
    {
        temp = temp->next;
        slow = slow->next;
    }

    return temp;
}