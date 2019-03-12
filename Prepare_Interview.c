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