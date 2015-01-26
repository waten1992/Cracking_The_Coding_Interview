#include <iostream>
#include <map>
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

  void Solution::Delete_Dups_hash_ver(Solution so)
  {
    int_int_map::iterator it;
    Node * Current ;
    Current = Head;
    int i = 0;
    while( Current->next != NULL )
    {
        it= hash_int.find(Current->next->data);
        if (it == hash_int.end()) //没有找到相同的就添加
        {
            hash_int.insert(map<int, int> :: value_type(Current->next->data, i));
            i++;
            Current = Current->next ;
        }
        else //否则，删除重复的；
        {
            Current->next = Current->next->next;
        }
    }
  }


void Solution::Delete_Current_Node(Solution so , int k)
{
   Node * Current = Head->next;
    while(k--) //模拟只提供指向要删除的元素
    {
        Current = Current->next;
    }
    if(Current->next == NULL) // 要删除的节点不能是最后一个
        ;
    else //把后面值赋给当前的值，再将当前的指针指向下一个的一下个；
    {
        Current->data = Current->next->data;
        Current->next = Current->next->next;
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
    cout<<"The last k of list->"<<A.Find_K_to_Last(A,2)->data<<endl;
    for(i = 2 ; i < 4 ; i++)
        A.Tail_Insert(A,i);
    cout<<"ADD dups elements---->"<<endl;
    A.Display_List(A);
    cout<<"Called Delete_Dups_hash_ver ---->"<<endl;
    A.Delete_Dups_hash_ver(A);

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
The last k of list->2
ADD dups elements---->
0->1->2->3->2->3->NULL
Called Delete_Dups_hash_ver ---->
0->1->2->3->NULL
Called Delete_Current_Node ---->
0->1->3->NULL

Process returned 1 (0x1)   execution time : 0.746 s
Press any key to continue.
*/
