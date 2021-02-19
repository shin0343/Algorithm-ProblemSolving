class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = INT_MAX, ans = INT_MIN;
        int a = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] <= min)
            {
                min = prices[i];
            }
            else
            {
                a = prices[i] - min;
                ans = max(ans, a);
            }
        }

        if (a <= 0)
            return 0;
        else
            return ans;
    }
};