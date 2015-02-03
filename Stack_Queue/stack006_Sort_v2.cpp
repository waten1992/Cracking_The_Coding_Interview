/*
描述：请给一个栈排序，只用一个辅助栈，不能用其他的数据结构（比如数组）。

解题方案一：
        1-申请一个辅助栈作为排序栈Tmp_stack;
        2-开一个循环遍历原始栈，先把原始栈s.top()用临时变量Tmp保存起来，弹出s.pop();
        3-把原始栈的栈顶和比较Tmp_stack的栈顶比较，看是否大于排序栈顶；
        4-若是，则直接Tmp_stack.push(Tmp);否者，则插入有序栈；
        5-插入具体操作是Tmp_stack 把栈顶大于 都压到原始栈里面，在Tmp_stack.push(Tmp);
        6-循环一直到原始栈为空。在把临时栈的内容pop过来；

方案二：
        1-建立优先队列，把原始栈都压入进去，优先队列是内部拍好序的；
        2-在从优先队列弹出来压入原始栈
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
    stack<int> s;
public:
    void Sort_V1()
    {
        stack<int> Tmp_stack ; //利用临时栈来排序
        while(!s.empty())
        {
            int Tmp = s.top();
            s.pop();
            while(!Tmp_stack.empty() && Tmp_stack.top() > Tmp) //即是原始栈弹出来的元素比临时栈的元素都小，就要插入排序栈
            {
                s.push(Tmp_stack.top());
                Tmp_stack.pop();
            }
            Tmp_stack.push(Tmp);
        }
        while(!Tmp_stack.empty()) //把临时栈赋值给原始栈
        {
            s.push(Tmp_stack.top());
            Tmp_stack.pop();
        }
    }

    void Sort_V2()
    {
        priority_queue<int> Myqueue; //建立优先队列
        while(!s.empty())
        {
            Myqueue.push(s.top()); //压入优先队列
            s.pop();
        }
        while(!Myqueue.empty())
        {
            s.push(Myqueue.top()); //压入原始栈
            Myqueue.pop();
        }
    }
    void push(int item)
    {
        s.push(item);
    }
    void Display()
    {
        while(!s.empty())
        {
            cout<<s.top()<<"\t";
            s.pop();
        }
    }
};
int main()
{
    Solution A;
    int a[] = {4,6,9,2,3,8};
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        A.push(a[i]);
    cout<<"The origin stack--->"<<endl;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        cout<<a[i]<<"\t";
#if 0
    cout<<endl<<"Called Sort_v1-->"<<endl;
    A.Sort_V1();
#endif // 0
    cout<<endl<<"Called Sort_v2-->"<<endl;
    A.Sort_V2();
    A.Display();
    return 0;
}
/*
The answer as follow--->
The origin stack--->
4       6       9       2       3       8
Called Sort_v2-->
2       3       4       6       8       9
Process returned 0 (0x0)   execution time : 0.031 s
Press any key to continue.
*/
