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



题目三：二维数组中查找（用时25min）
在一个二维数组中，每一行都按照从左到右递增的顺序排列，每一列都按照从上到下递增的顺序排序，请完成输入一个二维数组和一个整数，判断数组中是否含有该整数。
思路：比较右上角或者左下角的数值。

bool FindNumInMatrix(int *Matrix, int iRows, int iCols, int iNumber)
{
	int iRow, iCol;
	iRow = 0;
	iCol = iCols - 1;/*指向没行中的最后一列*/
	
	while(iRow < iRows && iCol > 0)
	{
		if (Matrix[iRow * iCols + iCol] > iNumber)
		{
			iCol--;
		}
		else if (Matrix[iRow * iCols + iCol] < iNumber)
			iRow--;
		else
		{
			return ture;
			break;
		}
	}
	return false;
}

字符串：每个字符串都是以‘\0’ 作为结尾的，这样很容易找到字符串的结尾，但是会有一个额外的开销，
一不小心就会造成字符串的越界。

题目四：替换空格（用时35min）
请实现一个函数，把字符串中的每个空格替换成“%20”。 例如，we are happy. -> we%20are%20happy.
思路：在原理字符串上进行替换。当合并两个数组或者字符串的时候，如果从前向后合并会有成员移动
多次的话，应该考虑从后向前合并。

int ReplacBlank(char *string)
{
	int i;
	int iBlankNum;
	int iLength;
	char *strOriginalEnd;
	char *strReplacedEnd;
	
	if (NULL == string || iLength < 0)
		return -1;
	/*计算空格数量*/
	/*
	for (i=0; i<iLength; i++)
	{
		if (string[i] == ' ')
			iBlankNum++;
	}
	*/  这种方式通过参数给定字符串的长度，但是这样不确定是否是计算了‘\0’ 的大小
	
	while (string++ != '\0')
	{
		iLength++;
		if (string[i] == ' ')
			iBlankNum++;
	}
	
	strOriginalEnd = string + iLength + 1;
	strReplacedEnd = strOriginalEnd + iBlankNum * 2;
	
	while (iBlankNum)
	{
		if (strOriginalEnd-- == ' ')
		{
			strReplacedEnd-- = '0';
			strReplacedEnd-- = '2';
			strReplacedEnd-- = '%';
			iBlankNum--;
		}
		else
			strReplacedEnd-- = strOriginalEnd--;
	}
	
}


华为测试1
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000];
    char c[2];
    int i = 0;
    int iLength;
    int iCount = 0;
    gets(str);
    gets(c);        //防止是回车后再输入单个字符
   // printf("%s\n", c[0]);
    while (str[i] != '\0')
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    
    iLength = strlen(str);
    /*在一行中将所有内容输入*/
    if (NULL == c[0])
    {
        c[0] = str[iLength-1];
        for (i=0; i<iLength-3; i++)
        {
            if (str[i] == c[0])
                iCount++;
        }
    }
    /*在第二行输入单个字符*/
    else
    {
        if (c[0] >= 'A' && c[0] <= 'Z')
            c[0] += 32;
        
        for (i=0; i<iLength; i++)
        {
            if (str[i] == c[0])
                iCount++;
        }
        
    }
    printf("%d\n",iCount);
    return 0;
}















