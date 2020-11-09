//https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <map>
#include <iostream>
using namespace std;


class Solution {
public:

    map<char,int> m;

    int romanToInt(string s) {

        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;

        int ans=0;
        int sLen=s.length();

        for(int i=0;i<sLen;)
        {
            int tmpSum=0;
            int curNum=m[s[i]];
            int prevNum;
            char curChar = s[i];
            char prevChar;

            if(curNum==1)
            {
                tmpSum+=curNum;
            }

            if(curNum==5)
            {
                if(prevNum==1)
                {
                    tmpSum=5-tmpSum;
                }
                else
                {
                    tmpSum+=curNum;
                }
            }

            prevNum=curNum;
            prevChar=curChar;
        }
    }
};