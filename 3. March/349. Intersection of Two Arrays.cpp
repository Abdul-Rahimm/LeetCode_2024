class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> st; // numbers unique

        // sorting laazmi
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size())
        {

            if (nums1[i] == nums2[j])
            {
                st.insert(nums1[i]); // unique storing
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        vector<int> ans;
        for (int i : st)
        {
            // for all numbers in st

            ans.push_back(i);
        }

        return ans;
    }
};