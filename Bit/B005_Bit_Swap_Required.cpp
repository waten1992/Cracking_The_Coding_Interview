/*
描述： 写一个函数，将整数A转成B，需要改变几个位
解题思路：两个数 异或之后中位为‘1’，就表示两个不同的位；

*/

int Bit_Swap_Required(int a , int b)
{
	int Tmp , count = 0 ;
	for(Tmp = a^b ; Tmp != 0 ; Tmp = Tmp >> 1)
		count += Tmp & 1 ;
	return count ;
}