// class Solution
// {
// public:
//     void moveZeroes(vector<int> &nums)
//     {
//         vector<int> ans;
//         int zeroCnt = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == 0)
//             {
//                 zeroCnt += 1;
//             }
//         }

//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == 0)
//             {
//                 continue;
//             }

//             ans.push_back(nums[i]);
//         }

//         for (int i = 0; i < zeroCnt; i++)
//         {
//             ans.push_back(0);
//         }

//         for (int i = 0; i < nums.size(); i++)
//         {
//             nums[i] = ans[i];
//         }
//     }
// };

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> ans;
        int zeroCnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeroCnt += 1;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }

            ans.push_back(nums[i]);
        }

        for (int i = 0; i < zeroCnt; i++)
        {
            ans.push_back(0);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = ans[i];
        }
    }
};

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int lastNonZeroIdx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[lastNonZeroIdx] = nums[i];
                lastNonZeroIdx++;
            }
        }

        for (int i = lastNonZeroIdx; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};