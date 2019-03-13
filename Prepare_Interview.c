#include <stdio.h>

题目一：
在一个长度为n的数组里的所有数字都在0~ n-1 的范围内，数组中某些数字是重复的，但是不知道哪些是重复的，重复了几次，
请找出数组中任意一个重复的数字。
int Duplicate(int number[], int length, int *duplication)
{
	if (NULL == number || length < 0)
		return -1;
	int i = 0;
	int itemp;
	
	for (i=0; i<length; i++)
	{
		while (number[i] != i)
		{
			if (number[i] == number[number[i]])
			{
				duplication = number[i];
				return 0;
			}
			
			itemp = number[i];
			number[i] = number[number[i]];
			number[number[i]] = itemp;
		}				
	}
	return -1;
}

题目二
不修改数组找到重复的数字
在一个长度为n+1 的数组里，里面所有的数字都在1~n 之间，所有数组中至少有一个数字是重复的，请找出数组中
任一重复的数字。
思路：若无重复数字，则1~n 一共有n个数字，而现在有n+1 个数字，说明有重复，
可以按照二分法来进行查找哪个区间内多了数字。需要运算时间。
或者是可以构建一个“辅助数组”，需要空间
注意：找出所有重复？找出任意重复？时间优先？空间优先？
static int CountRange(const int *aNumber, int iLength, int iStart, int iEnd)
{
	int i;
	int iCount = 0;
	for (i=0; i<iLength; i++)
	{
		if (iStart <= aNumber[i] <= iEnd)
			iCount++;
	}
	return iCount;
}
int GetDuplication(const int *aNumber, int iLength) 
{
	if (NULL == aNumber || iLength == 0)
		return -1;
	int iStart, iEnd, iMiddle;
	int iCount;
	
	iStart = 1;
	iEnd = iLength - 1;
	while (iEnd >= iStart)
	{
		iMiddle = (iEnd - iStart) >> 1 + iStart;
	
		iCount = CountRange(aNumber, iLength, iStart, iMiddle);		/*计算两段直接数字的个数*/
		if (iEnd == iStart)
		{
			if (iCount > 1)
				return iStart;
			
			else
				break;
		}
		
		
		if (iCount > (iMiddle - iStart + 1))
		{
			iEnd = iMiddle;	
		}
		else 
			iStart = iMiddle + 1;	/*前半部分相等时，去检测后半部分*/				
	}
	
	return -1;
	
}



题目三：二维数组中查找















