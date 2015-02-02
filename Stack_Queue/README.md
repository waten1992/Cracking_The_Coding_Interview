#栈和队列专题


----------
## Stack002_Find_Min.cpp ##
[Stack002_Find_Min.cpp][1]

![Stack002_Find_Min_code][2]


----------
## Stack003_SetOfStacks.cpp ##
[Stack003_SetOfStacks.cpp][3]

![Solution_pic][4]


```c++
class Solution
{
private:
    int Record = 0; //控制栈内部的元素移动
    int index = 0 ; //控制栈的移动
    int Capacity = Size;
    stack<int> ST[Size];
public :
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
```


  [1]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Stack002_Find_Min.cpp
  [2]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Image/Stack002_Find_Min_code.JPG
  [3]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Stack003_SetOfStacks.cpp
  [4]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Image/Stack003_SetOfStacks_Solution.JPG
