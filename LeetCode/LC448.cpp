class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            int j = nums[i] - 1;
            while (nums[i] != i + 1 && nums[j] != j + 1)
            {
                swap(nums[i], nums[j]);
                j = nums[i] - 1;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};