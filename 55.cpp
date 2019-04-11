#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static bool canJump(vector<int>& nums)
    {
        int Max=0,n=nums.size();
        for(int i=0;i<n&&i<=Max;i++)
        {
            Max=max(Max,i+nums[i]);
            if(Max>=n-1)
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}
