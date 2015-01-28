/*
描述：编写一个函数，判断链表是否是回文链表；
解法：
    1- 建立快慢指针faster , slower ,faster以两步前进，slower以一步前进，且把slower压入stack中；
    2- 直到faster== NULL || faster->next == NULL 退出；
    3- 若链表是奇数个元素，则用slower = slower->next ;跳过中间的元素；
    4- 依次把stack pop出来的元素 和slower 做比较;
*/
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
    struct Node
    {
        int data ;
        struct Node * next ;
        Node(int value) :data(value),next(NULL) {}
    };
protected:
    Node *Head;
public:
    Solution()
    {
        cout<<"Constructor is begin---"<<endl;
        Head = new Node(-1) ;
    }
    bool  Judge_List_Palindorme(Solution so);
    void Tail_Insert(Solution so ,int item);
    void Head_Insert(Solution so ,int item);
    void Display_List(Solution so);
};
void Solution::Tail_Insert(Solution so ,int item) //尾插法
{
    Node * Rear , * Current ;
    Rear = Head ;
    while (Rear->next != NULL) //找到最后的
    {
        Rear = Rear->next;
    }
    Current = new Node(item); //新建节点
    Current->next = Rear->next;
    Rear->next = Current ;
    Rear = Rear->next;


    Rear->next = NULL ;
#if 0 //for test !
    cout<<Current->data<<endl;
#endif
}

void Solution::Head_Insert(Solution so ,int item)
{
    Node *Tmp ;
    Tmp = new Node(item);
    Tmp->next = Head->next;
    Head->next =  Tmp ;
#if 0 //for test !
    cout<<Tmp->data<<endl;
#endif // 0
}
void Solution::Display_List(Solution so)
{
    Node *Tmp ;
    Tmp = Head->next ;
    while(Tmp != NULL)
    {
        cout<<Tmp->data<<"->";
        Tmp = Tmp->next;
    }
    cout<<"NULL"<<endl;
}
bool  Solution::Judge_List_Palindorme(Solution so)
{
    Node *faster , *slower ;
    faster = Head->next ;
    slower = Head->next ;
    stack<int> St ;
    while(faster != NULL && faster->next != NULL) //faster->2step , slower-> 1 step
    {
        St.push(slower->data); //入栈
        slower = slower->next ;
        faster = faster->next->next ;
    }
    if(faster != NULL) //如果是奇数，跳过中间那位
        slower = slower->next ;
    while(slower != NULL)
    {
        int Tmp ;
        Tmp = St.top(); //取栈顶元素
        St.pop(); //弹栈
        if (Tmp == slower->data)
            slower = slower->next;
        else
            return false;
    }
    return true ;
}

int main()
{
    Solution A ;
    for(int i = 0 ; i < 4 ; i++)
        A.Tail_Insert(A,i);
    for(int i = 3 ; i >= 0 ; i--)
        A.Tail_Insert(A,i);
    cout<<"Inital the list---> "<<endl;
    A.Display_List(A);

    cout<<"It is result:"<<A.Judge_List_Palindorme(A)<<endl;


    return true;
}
/*
The Answer as follow ----->
Constructor is begin---
Inital the list--->
0->1->2->3->3->2->1->0->NULL
It is result:1

Process returned 1 (0x1)   execution time : 0.020 s
Press any key to continue.
*/
