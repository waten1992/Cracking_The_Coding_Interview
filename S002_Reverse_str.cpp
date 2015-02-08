/*
--描述：用C++编写自己的写char * reverse(char *str)

解决方案一：1-计算字符长度；
            2-第N元素和第1元素交换，N-1 和 2 ，依次到N/2元素；

解决方案二：1-先把一个指针指向末尾；
            2-把首指针++ 和未指针-- ，依次交换首和未元素；
*/
#include <iostream>
#include <cstring>
using namespace std;
void Reverse_v1(char *Str)
{
    int index = 0 , len = strlen(Str) ; //计算长度
    if(len <= 0)
        return ;
    int Tmp = len/2 ; //计算中间值
    len--;
    for( ; index < Tmp ; index++,len--) //交换首未元素
        swap(Str[len],Str[index]);
}
void Reverse_v2(char *Str)
{
    char *End = Str ;
    char Tmp ;
    if(Str)
    {
        while(*End) //指向str末尾的指针
        {
            ++End;
        }
    }
    --End;//回退一个
    while(Str < End) 
    {
        swap(*Str++,*End--);
    }
}

int main()
{
    char str[] = {"ab"};
    char str1[] = {"abc"};
    cout<<"The origial str--->"<<str<<endl;
    Reverse_v1(str);
    cout<<"Reverse_V1--->"<<str<<endl;
    cout<<"The origial str1--->"<<str1<<endl;
    Reverse_v2(str1);
    cout<<"Reverse_V2--->"<<str1<<endl;
    return 0;
}
/*
THE Answer as follows---->
The origial str--->ab
Reverse_V1--->ba
The origial str1--->abc
Reverse_V2--->cba

Process returned 0 (0x0)   execution time : 0.027 s
Press any key to continue.
*/
