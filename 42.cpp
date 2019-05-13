#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int ans=0,pos=0;
        int n=height.size();
        vector<int>temp;
        for(int i=0;i<n;i++)
            pos=height[i]>height[pos]?i:pos;

        for(int i=0;i<=pos;i++)
        {
            if(temp.empty()||height[i]<temp[0])
                temp.push_back(height[i]);
            else
            {
                int size=temp.size();
                for(int j=1;j<size;j++)
                {
                    ans+=temp[0]-temp[j];
                }
                temp.clear();
                temp.push_back(height[i]);
            }
        }
        temp.clear();
        for(int i=n-1;i>=pos;i--)
        {
            if(temp.empty()||height[i]<temp[0])
                temp.push_back(height[i]);
            else
            {
                int size=temp.size();
                for(int j=1;j<size;j++)
                {
                    ans+=temp[0]-temp[j];
                }
                temp.clear();
                temp.push_back(height[i]);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int>vec={5,2,1,2,1,5};
    Solution S;
    cout<<S.trap(vec)<<endl;
    return 0;
}
