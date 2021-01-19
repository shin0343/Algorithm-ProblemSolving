class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ans = 0;
        int ansCnt = 0;

        sort(nums.begin(), nums.end());

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ansCnt > nums.size() / 2)
            {
                return ans;
            }

            if (i == 0)
            {
                cnt = 1;
                ans = nums[i];
                continue;
            }
            else
            {
                if (nums[i] != nums[i - 1])
                {
                    cnt = 1;
                }
                else if (nums[i] == nums[i - 1])
                {
                    cnt++;
                }
            }

            if (cnt >= ansCnt)
            {
                ansCnt = cnt;
                ans = nums[i];
            }
        }

        return ans;
    }
};