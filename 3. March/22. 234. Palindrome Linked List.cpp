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
    bool ifPalindrome(vector<int> &nums)
    {
        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            if (nums[i] != nums[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    bool isPalindrome(ListNode *head)
    {
        vector<int> nums;

        ListNode *temp = head;

        while (temp != NULL)
        {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        return ifPalindrome(nums);
    }
};