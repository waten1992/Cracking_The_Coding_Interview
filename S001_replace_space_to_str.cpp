
/*
描述：编写一个方法把字符串 str中的空格 用%20代替；
假定str的长度足够长；

解题方案一：传入的参数是char str[] 类型; 如：replace_space_to_str(char str[]  ,int len )
        1-先遍历一遍str 统计出空格的个数Num；
        2-在统计出len = str.length() + 2*Num 长度,因为空格也占一个字符，所以乘以2
        3-再从原来的str的后面向前扫描赋值给新的长度str，当遇到空格时候用%20代替 ；很像memcpy【1】 从后向前赋值；

【1】https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/memcpy.cpp

解题方案二：传入的参数是string str 类型; 如：replace_space_to_str_V2(string str)
        1-先遍历一遍str 统计出空格的个数Num；
        2-在统计出len = str.length() + 2*Num 长度,因为空格也占一个字符，所以乘以2
        3-重置str的长度 str.resize(len);
        4-再从原来的str的后面向前扫描赋值给新的长度str，当遇到空格时候用%20代替 ；

方案比较：
        方案一要事先要知道str的长度，要比空格换%20 后的长度都要长；
        方案二则不需要；只需要重置长度；
        而题目给的是假定str足够长；
*/
#include <iostream>
#include <cstring>
using namespace std ;

class Solution
{
public:
    char * replace_space_to_str(char str[]  ,int len ) //方案一
    {
        int i = 0 , new_len = 0 , Num = 0 ; //i->临时变量； new_len->替换后的长度 ；Num->空格数
        for( ; i< len ; i++) //统计空格数
        {
            if (str[i] == ' ')
                Num++;
        }
        new_len = len + Num*2 ; //计算新长度
        str[new_len] = '\0'; //给新的str添加结束符
        for(i = len-1 ; i > 0 ; i-- )
        {
            if (str[i] != ' ')
                str[--new_len] = str[i] ;
            else
            {
                str[--new_len] = '0';
                str[--new_len] = '2';
                str[--new_len] = '%';
            }
        }
        return str;
    }

    string  replace_space_to_str_V2(string str) //方案二
    {
        int Num = 0 , len = 0 , i = 0, new_len = 0;//len->是原str的长度，其他含义如上
        while(str[i++] != '\0')
        {
            if (str[i] == ' ')
                Num++;
        }
        len = str.length();
        new_len = len + 2*Num ;
        str.resize(new_len); //重置str的容量
        for(i = len-1 ; i >= 0 ; i--)
        {
            if(str[i] != ' ' )
                str[--new_len] = str[i] ;
            else
            {
                str[--new_len] = '0';
                str[--new_len] = '2';
                str[--new_len] = '%';
            }
        }
        return str;
    }
};

int main()
{
    char str[40] = "waten is a man!";
    string str_V2("waten is a man!");

    Solution A ;
    cout<< A.replace_space_to_str(str , strlen(str))<<endl;;
    cout<<A.replace_space_to_str_V2(str_V2)<<endl;

    return true;
}
/*
The answer as follow ----->

waten%20is%20a%20man!
waten%20is%20a%20man!

Process returned 1 (0x1)   execution time : 0.020 s
Press any key to continue.

*/
