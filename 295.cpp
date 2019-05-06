#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
    int median;
    bool empty;//indicate whether median is empty
public:
    MedianFinder()
    {
        empty = true;
    }

    void addNum(const int& num)
    {
        if (empty)
        {
            empty = false;
            size_t ls=left.size(),rs=right.size();
            int lt,rt;
            if(ls==0)
            {
                median=num;
                return;
            }
            lt=left.top();
            rt=right.top();
            if(num>right.top())
            {
                median=rt;
                right.pop();
                right.push(num);
            }
            else if(num<left.top())
            {
                median=lt;
                left.pop();
                left.push(num);
            }
            else
            {
                median=num;
            }
        }
        else
        {
            left.push(min(num, median));
            right.push(max(num,median));
            empty = true;
        }
    }

    double findMedian()
    {
        if (empty)
        {
            return (left.top() + right.top()) / 2.0;
        }
        return median;
    }
};
int main()
{
    MedianFinder MF;
    MF.addNum(1);
    MF.addNum(2);
    cout<<MF.findMedian()<<endl;
    MF.addNum(3);
    cout<<MF.findMedian()<<endl;
    MF.addNum(4);
    cout<<MF.findMedian()<<endl;
    for(int i=5;i<10;i++)
    {
        MF.addNum(i);
        cout<<MF.findMedian()<<endl;
    }
    return 0;
}
