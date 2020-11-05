//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans;
        int nsize=numbers.size();
        int dif=0;

        for(int i=0;i<nsize;i++)
        {
            dif=target-numbers[i];
            
            int left=0;
            int right=nsize-1;
            int mid=(left+right)/2;
            while(left<=right)
            {
                if(numbers[mid]==dif)
                {
                    if(mid==i)
                    {
                        break;
                    }

                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    if(ans[0]>ans[1])
                    {
                        int tmp=ans[0];
                        ans[0]=ans[1];
                        ans[1]=tmp;
                    }
                    return ans;
                }
                else if(numbers[mid]>dif)
                {
                    right=mid-1;
                    mid=(left+right)/2;
                    continue;
                }
                else
                {
                    left=mid+1;
                    mid=(left+right)/2;
                    continue;
                }
            }
        }

        return ans;
    }
};