/*
描述：编写一个类，描述当一个栈满时，就要申请另一个新栈向里面添加元素，支持和栈一样的功能push pop

解决方案：
        1-申请一个栈的数组stack<int> ST[Size] ；
        2-用下标index控制栈的移动 ，Record控制栈内部的元素移动;
        3-push()当Capacity == Record时，index向后移动一位，即是表示这栈满了寻找下一个栈，Record=0 ；
        4-pop() 当前栈的元素是当前栈最后的一个，需要index向前移动一位 ，Record = Capacity。

*/
#include <iostream>
#include <stack>
using namespace std;
const int Size = 4  ;
class Solution
{
private:
    int Record ; //控制栈内部的元素移动
    int index  ; //控制栈的移动
    int Capacity ;
    stack<int> ST[Size];
public :
    Solution()
    {
        Record = 0; //控制栈内部的元素移动
        index = 0 ; //控制栈的移动
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
    }
};
int main()
{
    Solution A;
    for(int i = 0; i < 9 ; i++)
        A.push(i);
    for(int i = 0; i < 9; i++)
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
