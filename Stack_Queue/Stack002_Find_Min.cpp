/*
描述：编写一个类包含push , pop , min ，要求时间复杂度为O(1);

方案：1- 申请两个栈，其中ST1存储当前所压入的栈， ST2存储到目前为止最小元素；
      2- push() 如果当前的元素小于 ST2栈顶储存的元素，则压入ST2栈;
      3- POP() 当ST1 和 ST2的栈顶相等时，都弹出栈，否者只是弹ST1;
      4- Min_ST() 返回ST2的栈顶元素；
*/

#include <iostream>
#include <stack>
using namespace std;
const int Wrong_Num = 999999 ;
class Solution
{
private:
    stack<int> ST1 , ST2 ;
public:
    Solution()
    {
        ST2.push(Wrong_Num);
    }
    void push(int item)
    {
        ST1.push(item);
        if(item < ST2.top())
            ST2.push(item);
    }
    int pop()
    {
        if (ST1.top() == ST2.top())
            ST2.pop();
        cout<<"The current stack-->"<<ST1.top()<<endl;
        ST1.pop();
    }
    int Min_ST()
    {
        if(ST2.empty())
            return Wrong_Num;
        return ST2.top();
    }
};
int main()
{
    Solution S ;
    int a[] = {9,7,12,5,13,5};
    for(int i = 0 ; i < sizeof(a)/sizeof(a[0]) ; i++)
        S.push(a[i]);
    for(int i = 0 ; i < sizeof(a)/sizeof(a[0]) ; i++)
    {
        cout<<"MIN-->"<<S.Min_ST()<<endl;
        S.pop();
    }
    return true;
}

/*
The answer as follow ---->

MIN-->5
The current stack-->5
MIN-->7
The current stack-->13
MIN-->7
The current stack-->5
MIN-->7
The current stack-->12
MIN-->7
The current stack-->7
MIN-->9
The current stack-->9

Process returned 1 (0x1)   execution time : 0.020 s
Press any key to continue.

*/
