//https://leetcode.com/problems/count-and-say/

#include <string>
#include <iostream>
using namespace std;

string nMemo[31];
string Ans;

class Solution {
public:
    void dfs(string cas, int cnt, int n)
    {
        if(cnt>=n)
        {
            Ans=cas;
            return;
        }

        string tmp="";
        int numCnt=0;

        for(int i=0;i<cas.length();i++)
        {
            if(i>0 && cas[i]!=cas[i-1])
            {
                tmp+=to_string(numCnt);
                tmp+=cas[i-1];
                numCnt=0;
            }
            
            numCnt+=1;
        }

        tmp+=to_string(numCnt);
        tmp+=cas[cas.length()-1];

        dfs(tmp,cnt+1,n);
    };

    string countAndSay(int n)
    {
        dfs("1",1,n);
        return Ans;
    };
};