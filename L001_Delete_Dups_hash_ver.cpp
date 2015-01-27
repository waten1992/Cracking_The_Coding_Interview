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
    void Delete_Dups_hash_ver(Solution so);
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
  void Solution::Delete_Dups_hash_ver(Solution so)
  {
    int_int_map::iterator it;
    Node * Current  , *Temp ;
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
            Temp = Current->next ; //delete temp 防止内存泄漏
            Current->next = Current->next->next;
            delete Temp ;
            Temp = NULL;
        }
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

    for(i = 2 ; i < 4 ; i++)
        A.Tail_Insert(A,i);
    cout<<"ADD dups elements---->"<<endl;
    A.Display_List(A);

    cout<<"Called Delete_Dups_hash_ver ---->"<<endl;
    A.Delete_Dups_hash_ver(A);
    A.Display_List(A);
    return true;
}
/*
The answer as follow ----->
Constructor is begin---
Inital the list--->
0->1->2->3->NULL
ADD dups elements---->
0->1->2->3->2->3->NULL
Called Delete_Dups_hash_ver ---->
0->1->2->3->NULL

Process returned 1 (0x1)   execution time : 0.405 s
Press any key to continue.
*/
