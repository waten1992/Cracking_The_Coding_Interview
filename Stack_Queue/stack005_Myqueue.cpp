/*
描述：用两个栈来模拟队列；

解题方案：
        1-申请2个栈，new_stack -->作为队尾, old_stack--->作为队头；
        2-push() 就把元素压入new_stack ;
        3-pop() 把old_stack的栈顶pop出去；当old_stack为空时调用shif_stack();
        4-shif_stack()= 当old_stack为空时，把new_stack中的所有元素pop出，且压入old_stack中；
        5-top()=先调用shif_stack(), 保证old_stack.top()不为空；
*/
#include <iostream>
#include <stack>
using namespace std;

class Myqueue
{
    stack<int> new_stack , old_stack ;
    void shif_stack()
    {
        if(old_stack.empty()) //当old_stack 为空的时候
        {
            cout<<"called shif_stack---( pop new_stack to old_stack)"<<endl;
            while(!new_stack.empty())//把new_stack说有的元素都pop出去，且压入old_stack中
            {
                int Tmp = new_stack.top();
                old_stack.push(Tmp);
                new_stack.pop();
            }
        }
    }
public:
    void push(int item)
    {
        new_stack.push(item);
        cout<<"Add a new element-->"<<new_stack.top()<<endl;
    }
    void pop()
    {
        shif_stack(); //要保证old_stack 不为空
        old_stack.pop();
    }
    int top()
    {
        shif_stack();//要保证old_stack 不为空
        return old_stack.top();
    }
};
int main()
{
    Myqueue S;
    for(int i ; i < 4 ; i++)
        S.push(i);
    for(int i = 0 ; i < 2 ; i++)
    {
        cout<<"The current of the old_stack -->"<<S.top()<<endl;
        S.pop();
    }
    return 0;
}
/*
The answer as follow ---->
Add a new element-->0
Add a new element-->1
Add a new element-->2
Add a new element-->3
called shif_stack---( pop new_stack to old_stack)
The current of the old_stack -->0
The current of the old_stack -->1

Process returned 0 (0x0)   execution time : 0.030 s
Press any key to continue.
*/
