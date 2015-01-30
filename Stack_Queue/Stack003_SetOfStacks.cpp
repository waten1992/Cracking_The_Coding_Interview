#include <iostream>
#include <stack>
using namespace std;
const int Size = 4  ;
class Solution
{
private:
    int Record ;
    int index  ;
    int Capacity ;
    stack<int> ST[Size];
public :
    Solution()
    {
         Record = 0;
         index = 0 ;
         Capacity = Size;
    }
    void push(int item)
    {
        if(Record < Capacity )//当小于阈值 ，压入当前栈Record 取 1 2 3 4 ；压入Capacity-1个
        {
            ST[index].push(item);//先压栈
            Record++;//在前进
            cout<<"reord---->"<<Record<<endl;//测试用
        }
        else //当大于等于 阈值 ，则压入到下一个栈中 ;压入1个
        {
            index++;
            Record = 0 ; //置为初值
            ST[index].push(item); //压入最高位
            Record++;
            cout<<"plus one"<<endl; //测试用
        }
    }

    void pop()
    {
        cout<<"index:"<<index<<endl; //测试用
        #if 1
        if(Record >= 2 ) //
        {
            ST[index].pop();
            Record--;
        }
        else //处于最小值时，先弹出去，在回到前一个栈
        {
            Record = Capacity;//置为Capacity
            cout<<"pop()-->"<< ST[index].top()<<endl;
            ST[index].pop();//先弹出去
            index--;//在回到前一个栈
        }
        #endif
    }
};
int main()
{
    Solution A;
    for(int i = 0; i < 9 ;i++)
        A.push(i);
    for(int i = 0; i < 9;i++)
        A.pop();
    return 0;
}
/*
The answer as follow ---->
reord---->1
reord---->2
reord---->3
reord---->4
plus one
reord---->2
reord---->3
reord---->4
plus one
index:2
pop()-->8
index:1
index:1
index:1
index:1
pop()-->4
index:0
index:0
index:0
index:0
pop()-->0

Process returned 0 (0x0)   execution time : 0.078 s
Press any key to continue.
*/
