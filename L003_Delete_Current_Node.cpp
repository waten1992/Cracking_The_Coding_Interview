#include <iostream>
using namespace std;

typedef map<int , int> int_int_map;
int_int_map hash_int;
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
    void Delete_Dups_hash_ver(Solution so);
    void Delete_Current_Node(Solution so , int k) ;
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

void Solution::Delete_Current_Node(Solution so , int k)
{
   Node * Current = Head->next;
   Node *Temp = NULL;
    while(k--) //模拟只提供指向要删除的元素
    {
        Current = Current->next;
    }
    if( Current == NULL ||Current->next == NULL) // 要删除的节点不能是最后一个
        ;
    else //把后面值赋给当前的值，再将当前的指针指向下一个的一下个；
    {
        Current->data = Current->next->data;
        Temp = Current->next; //delete temp 防止内存泄漏
        Current->next = Current->next->next;
        delete Temp ;
        Temp = NULL;
    }
}

int main()
{
    Solution A ;
    int i ;
    for( i = 0 ; i < 4 ; i++)
        A.Tail_Insert(A,i);
    cout<<"Inital the list---> "<<endl;
    A.Display_List(A);
    
    cout<<"Called Delete_Current_Node ---->"<<endl;
    A.Delete_Current_Node(A,2); //删除A中的第2个元素，用K个模拟
    A.Display_List(A);
    return true;
}
/*
The answer as follow ----->
Constructor is begin---
Inital the list--->
0->1->2->3->NULL
Called Delete_Current_Node ---->
0->1->3->NULL

Process returned 1 (0x1)   execution time : 0.746 s
Press any key to continue.
*/
