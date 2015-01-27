/*
描述：删除一个链表中的重复的元素，是无序的链表？
解决方案一：
            1-建立一个hash_map,遇到重复的就删除

方案二：
            1-用两个指针，一个从链表开始，另一个从一个后面迭代到最后看是否有重复
*/
#include <iostream>
#include <hash_map>
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
    void Delete_Dups_list(Solution so);
    void Tail_Insert(Solution so ,int item);
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

void Solution::Delete_Dups_list(Solution so) //不需要而外的空间，时间复杂度为O(N^2)
{
    Node * Current , * Previous , *Tmp;
    Previous = Head->next;
#if 1
    while(Previous != NULL)
    {
        Current = Previous ;
        while(Current->next != NULL)
        {
            if (Previous->data == Current->next->data)
            {
                Tmp = Current->next; //删除节点，防止内存泄漏
                Current->next = Current->next->next;
                delete Tmp ;
                Tmp = NULL;
            }
            else
                Current = Current->next;
        }
        Previous = Previous->next;
    }
#endif // 0
}
int main()
{
    Solution A ;
    for(int i = 0 ; i < 4 ; i++)
        A.Tail_Insert(A,i);
    for(int i = 2 ; i < 4 ; i++)
        A.Tail_Insert(A,i);
    cout<<"Inital the list---> "<<endl;
    A.Display_List(A);
    A.Delete_Dups_list(A);
    cout<<"called Delete_Dups_list---->"<<endl;
    A.Display_List(A);
    return true;
}
/*
The Answer as follow ----->

Inital the list--->
0->1->2->3->2->3->NULL
called Delete_Dups_list----->
0->1->2->3->NULL

Process returned 1 (0x1)   execution time : 0.031 s
Press any key to continue.
*/
