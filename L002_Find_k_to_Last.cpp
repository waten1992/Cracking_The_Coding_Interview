/*
描述：一个有头结点的链表，求倒数第K个节点；

解法：快慢指针法!
        1--p1、p2 都指向头结点，p1第一指针先走K步，p2和p1以相同的数度走，直到P1走到末尾
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
    void Tail_Insert(Solution so ,int item);
    void Display_List(Solution so);
    Solution::Node*  Find_K_to_Last(Solution so , int k);
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
Solution::Node* Solution::Find_K_to_Last(Solution so , int k) //第一个指针先走K步，在两个指针用相同的速度走，直到一个指针走到末尾
{
    Node *p1 ,*p2 ; p1= Head; p2 = Head ;
    if ( k <= 0 )
        return NULL;
    while(k--)
    {
        p1 = p1->next;
    }
    while(p1 != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

int main()
{
    Solution A ;
    for(int i = 0 ; i < 4 ; i++)
        A.Tail_Insert(A,i);
    cout<<"Inital the list---> "<<endl;
    A.Display_List(A);
    cout<<"The last k of list->"<<A.Find_K_to_Last(A,2)->data<<endl;;
    return true;
}
/*
The Answer as follow ----->

Constructor is begin---
Inital the list--->
0->1->2->3->NULL
The last k of list->2

Process returned 1 (0x1)   execution time : 0.016 s
Press any key to continue.
*/
