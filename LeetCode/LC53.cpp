class Solution
{
public:
    int dp[100000];
    int maxSubArray(vector<int> &nums)
    {
        int max = -100000;

        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = dp[i - 1] + nums[i] > nums[i] ? dp[i - 1] + nums[i] : nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            max = dp[i] > max ? dp[i] : max;

            // std::cout<<"max="<<max<<endl;
        }

        return max;
    }
};