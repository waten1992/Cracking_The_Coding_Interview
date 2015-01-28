/*
描述：编写一个函数，给定的一个值X为基准将链表分割成两个部分，小于X的节点排在大于或等于X节点之前；
解法：
    1- 建立新的头节点new_head , 遍历原有的链表把大于等于X的值放在new_head上；
    2- 对于大于X的用尾插法，等于X用头插法；
    3- 直到原链表到达NULL
    4- 把尾节点的指针指向new_head->next;
*/
#include <iostream>

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
    void Partition_x(Solution so ,int x);
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
void Solution::Partition_x(Solution so ,int x)
{

    Node *Current = Head;
    Solution new_head ; //新建的链表
    while(Current->next != NULL)
    {
        int value =  Current->next->data;
        if (value > x)
        {
            new_head.Tail_Insert(new_head , value ) ; //调用尾插法
            Current->next = Current->next->next; //原链表跳过后面的节点
        }
        else if(value  == x)
        {
            new_head.Head_Insert(new_head , value ) ; //调用头插法
            Current->next = Current->next->next;//原链表跳过后面的节点
        }
        else
            Current = Current->next;
    }

    Current->next = new_head.Head->next; //原链表链接现在新建的链表
    delete new_head.Head; //防止内存泄漏
}

int main()
{
    Solution A ;
    for(int i = 0 ; i < 4 ; i++)
        A.Tail_Insert(A,i);
    for(int i = 0 ; i < 4 ; i++)
        A.Tail_Insert(A,i);
    cout<<"Inital the list---> "<<endl;
    A.Display_List(A);

    A.Partition_x(A ,2); //
    cout<<"Called Partition_x-->"<<endl;
    A.Display_List(A);

    return true;
}
/*
The Answer as follow ----->

Constructor is begin---
Inital the list--->
0->1->2->3->0->1->2->3->NULL
Constructor is begin---
Called Partition_x-->
0->1->0->1->2->2->3->3->NULL

Process returned 1 (0x1)   execution time : 0.031 s
Press any key to continue.
*/
