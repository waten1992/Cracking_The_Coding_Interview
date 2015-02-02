#栈和队列专题


----------
## Stack002_Find_Min.cpp ##
[Stack002_Find_Min.cpp][1]

![Stack002_Find_Min_xmind][2]

![Stack002_Find_Min_code][3]


----------
## Stack003_SetOfStacks.cpp ##
[Stack003_SetOfStacks.cpp][4]

![Solution_pic][5]


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


----------
## stack005_Myqueue.cpp ##

[stack005_Myqueue.cpp][6]

![stack005_Myqueue_solution][7]

![stack005_Myqueue_code][8]


----------
## stack006_Sort.cpp ##
[stack006_Sort.cpp][9]

![stack006_Sort_solution][10]

![stack006_Sort_code][11]


  [1]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Stack002_Find_Min.cpp
  [2]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Image/Stack002_Find_Min_Xmind.JPG
  [3]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Image/Stack002_Find_Min_code.JPG
  [4]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Stack003_SetOfStacks.cpp
  [5]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Image/Stack003_SetOfStacks_Solution.JPG
  [6]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/stack005_Myqueue.cpp
  [7]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Image/stack005_Myqueue_solution.JPG
  [8]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Image/stack005_Myqueue_code.JPG
  [9]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/stack006_Sort.cpp
  [10]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Image/stack006_Sort_solution.JPG
  [11]: https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/Stack_Queue/Image/stack006_Sort_code.JPG
