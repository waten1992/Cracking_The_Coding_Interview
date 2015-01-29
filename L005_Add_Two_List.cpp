/*
描述：给定2个链表，反向储存整数，编写一个函数计算2个数相加之和；

例如：A: Head->3->2->1->NULL;
      B: Head->2->9->9->NULL;
      ------------------------ +
      C: Head->5->1->2->NULL
即是：123 + 992 = 1115
解法：
    1- 从个位相加起，申请carry保存进位，设立一个循环直到A B 链表其中有一个变为空；
    2- carry = (A->data + B->data)/10 , Bit = (A->data + B->data)%10  ；
    3- 若有进位即carry =1，则也把进位加起来 ,即是Bit = Bit + carry ；
    4- 若退出循环，判断是那个链表为空，在把另一个链表和carry相加，若有进位则新建一个节点储存;
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
    Solution Add_Two_List(Solution s1 , Solution s2);
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
Solution Solution::Add_Two_List(Solution S1 , Solution S2)
{
    Node *LA , *LB ;
    LA = S1.Head->next ;
    LB = S2.Head->next ;
    Solution CC;
    int Carry = 0 , Bit = 0 ;
    while(LA != NULL || LB != NULL)
    {
        Bit =  ( LA->data + LB->data + Carry ) % 10 ;
        Carry = ( LA->data + LB->data + Carry ) / 10 ;

        CC.Head_Insert(CC,Bit);
        if(LA != NULL)
            LA = LA->next ;
        if(LB != NULL)
            LB = LB->next ;
    }
    if (Carry == 1) //最高位产生了进位，需要新建节点新插入
        CC.Head_Insert(CC,Carry);
    return CC ;
}

int main()
{
    Solution A ,B,C;
    int a[] = {3,2,1};
    int b[] = {2,9,9};
    int i = 0 ;
    for( i = 0 ; i < sizeof(a)/sizeof(a[0]) ; i++)
        A.Tail_Insert(A,a[i]);
    for( i = 0 ; i < sizeof(b)/sizeof(b[0]) ; i++)
        B.Tail_Insert(B,b[i]);

    cout<<"Inital the list of A---> "<<endl;
    A.Display_List(A);
    cout<<"Inital the list of B---> "<<endl;
    B.Display_List(B);
    cout<<"Called Add_Two_List-->"<<endl;
    C = C.Add_Two_List(A , B);
    C.Display_List(C);
    return true;
}
/*
The Answer as follow ----->
Constructor is begin---
Constructor is begin---
Constructor is begin---
Inital the list of A--->
3->2->1->NULL
Inital the list of B--->
9->9->2->NULL
Called Add_Two_List-->
Constructor is begin---
4->2->2->NULL

Process returned 1 (0x1)   execution time : 0.016 s
Press any key to continue.
*/
