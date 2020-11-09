//https://leetcode.com/problems/sqrtx

#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        if(x<2)
        {
            return x;
        }

        int left=1;
        int right=x;

        while(left<right)
        {
            int mid=left+floor((right-left)/2); //smiliar with (left+right)/2

            if(mid==x/mid)
            {
                return mid;
            }

            if(mid<x/mid)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }

        return left-1;
    }
};