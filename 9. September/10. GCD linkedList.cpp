// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

ListNode *insertGreatestCommonDivisors(ListNode *head)
{
    if (!head->next)
        return head;

    ListNode *prev = head;
    ListNode *curr = head->next;

    while (curr != NULL)
    {
        int first = prev->val;
        int second = curr->val;

        int GCD = __gcd(first, second);
        ListNode *newNode = new ListNode(GCD, curr);

        prev->next = newNode;

        prev = curr;
        curr = curr->next;
    }

    return head;
}