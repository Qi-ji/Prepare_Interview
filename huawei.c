#if 0

#include <stdio.h>
int main(void)
{

  
    while(scanf("%f", &num) != EOF)
    {
		
    }
    
    return 0;
}





#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	char aFirstIP[20]= {0};
	char aBinaryFirstIP[5][50]= {0};
	int ainteger[20] = {0};
	char aTemp[5] = {0};
	char aSecondIP[20]= {0};
	char aBinarySecondIP[50]= {0};
	char aMask[20]= {0};
	char aBinaryMask[50]= {0};
	char *token;
	char c = '.';
	int i, j;
	int iLength = 0;
	int a;
	int num = 4;
	while (scanf("%s", aFirstIP) != EOF)
	{
		
		//scanf("%d", aSecondIP);
		//scanf("%d", aMask);

		iLength = strlen(aFirstIP);
/*
		ptr = aFirstIP;
		while(num)
		{
			ptr1 = ptr;
			ptr = strchr(ptr, '.');
			memcpy(aTemp, ptr1, ptr-ptr1);
			ainteger[i++] = atoi(aTemp);
			ptr += 1;
			printf("%d\n", a);
			if (NULL == ptr)
			{
				memcpy(aTemp, ptr1, aFirstIP + iLength - ptr1);
				ainteger[i] = atoi(aTemp);
			}
			num--;
		}
*/

		token = strtok(aFirstIP,&c);
		while(NULL != token)
		{
			ainteger[i] = atoi(token);
			i++;
			token = strtok(NULL, &c);
		}
		printf("%d",ainteger[0]);
	
		for (i=0; i<4;i++)
		{
			itoa(ainteger[i], aBinaryFirstIP[i], 2);
			printf("0x%s", aBinaryFirstIP[i]);
			
		}
	}
	return 0;
	
}




2222.
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组； 
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
#include <stdio.h>
#include <string.h>

int SplitStr(char *str)
{
    int length,times;
    int i,j;
    length = strlen(str);
    times = (length / 8);
    if (length != 0)
    {
        if(length % 8 == 0)
        {
            j = 0;
            for(i=0; i<length; i++)
            {
                printf("%c",str[i]);
                j++;
                if(j / 8)
                {
                    printf("\n");
                    j=0;
                }
                    
            }
        }
        else
        {
            for(i=length; i<((times+1)*8); i++)
            {
                str[i] = '0';
            }
            j = 0;
            for(i=0; i<((times+1)*8); i++)
            {
                printf("%c",str[i]);
                j++;
                if(j / 8)
                {
                    printf("\n");
                    j=0;
                }
            }
         }
      }
}


int main(void)
{
    char str1[200];
    char str2[200];
    
    while(scanf("%s", str1) != EOF)
    {
        scanf("%s", str2);
        SplitStr(str1);
        SplitStr(str2);        
    }
    return 0;
}


33333333333.
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
#include <stdio.h>
#include <string.h>
int main(void)
{
    char strin[100] = {0};
    int length = 0;
    int sum = 0;
    int temp = 0;
    int i;
    
    while(scanf("%s", strin) != EOF)
    {
        sum = 0;					//不要忘记在清零
        length = strlen(strin);
        
        for(i=2; i<length; i++)
        {
            if (strin[i] <= '9')
                temp = strin[i] - '0';
            else 
                temp = strin[i] - 'A' + 10;//不知道为什么大小写字母不用区分
            //printf("%d\n",temp);
            sum = sum*16 + temp;
        }
        printf("%d\n", sum);
    }
    return 0;
}


44444444444.
功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
最后一个数后面也要有空格
好多人没明白这个问题的意思，其实就是让你把输入的整数因式分解，只不过因子必须都是质数
例如：180 = 2 * 2 * 3 * 3 * 5；90 = 2 * 3 * 3 * 5；而不是找出所有的质数因子

#include <stdio.h>

int main(void)
{
    int num;
    int i;
    
    while (scanf("%d", &num) != EOF)
    {
        for (i=2; i<=num; i++)
        {
            while(num % i == 0)
            {
                printf("%d ",i);
                num /= i;
            }
        }
    }

    return 0;
}

55555555555.
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整
#include <stdio.h>

int main(void)
{
    float num;
    
    while(scanf("%f", &num) != EOF)
    {
            printf("%d",(int)(num+0.5)); //一定要int强制类型转换
    }
    
    return 0;
}


66666666666.
数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出


#include <stdio.h>

int main(void)
{
    int Table[1000] = {0};
    int Index,Value;
    int num, i;
    
    while(scanf("%d", &num) != EOF)
    {
        for(i=0; i<num; i++)
        {
            scanf("%d %d",&Index, &Value);
            if (Table[Index] == 0)
            {
                Table[Index] = Value;
            }
            else
                Table[Index] += Value;
        }
        
        for(i=0; i<1000; i++)
        {
            if(Table[i])
                printf("%d %d\n", i, Table[i]);
        }
    }
    
    return 0;
}

以上的这种方法虽然比较简单，但是中间有一个小Bug，在这里虽然可以通过所有测试，但是必须是在相同索引项最后的键值和不为0的情况下才能正确，而这里牛客的测试数据最后的输出结果的键值都是非0值，所以也通过了，但是更严谨地来应该采用一种更为常规的方法，也就是用结构体来设计算法，这样输入的每一项是一种连续存放的数据结构，相对第一种方法来说代码更复杂一点，但是更具有普适性，代码如下
#include<iostream>
using namespace std;
struct Key_Value_Pair
{
    int index;
    int value;
};
int main()
{
    Key_Value_Pair Part[1000];
    int Key_Value_Pairs_Num,i,j,k;
    cin>>Key_Value_Pairs_Num;
    for(i=0;i<Key_Value_Pairs_Num;i++)
        cin>>Part[i].index>>Part[i].value;
    for(i=0;i<Key_Value_Pairs_Num;i++)
    {
        for(j=i+1;j<Key_Value_Pairs_Num;j++)
        {
            if(Part[i].index==Part[j].index)
            {
                Part[i].value+=Part[j].value;//对第二键值求和，累加在第一次出现的键值项上，下一步进行重复索引的删除操作
                for(k=j;k<Key_Value_Pairs_Num-1;k++)
                    Part[k]=Part[k+1];
                j--;
                Key_Value_Pairs_Num--;
            }
        }
    }
    //下面进行排序操作
    Key_Value_Pair Temp;//定义一个结构体，作为交换操作的中间值
    for(i=0;i<Key_Value_Pairs_Num-1;i++)
    {
        for(j=0;j<Key_Value_Pairs_Num-1-i;j++)
        {
            if(Part[j].index>Part[j+1].index)
            {
                Temp=Part[j];
                Part[j]=Part[j+1];
                Part[j+1]=Temp;
            }
        }
    }
    for(i=0;i<Key_Value_Pairs_Num;i++)
        cout<<Part[i].index<<" "<<Part[i].value<<endl;
    return 0;
}

77777777.
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。

#include <stdio.h>
#include <string.h>
int main(void)
{
    char num[100];
    int i,j;
    int index,flag;
    while(scanf("%s", num) != EOF)
    {
        index = strlen(num) - 1;
        for(i=index; i>=0; i--)
        {
            flag = 0;
            for (j=i+1; j<=index; j++)
            {
                if(num[i] == num[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                continue;
            printf("%c", num[i]);
        }
        printf("\n");
    }
    
    return 0;
}

或者是
#include <stdio.h>
  
#define MAX_KEY 10
  
int main (void)
{
    int array[MAX_KEY] = {0};
    int count = 0;
    while (scanf("%d", &count) != EOF)
    {
        while(count)
        {
            if(array[count%10] == 0)
            {
                printf("%d",count%10);
                array[count%10] = 1;
            }
            count /= 10;
        }
    }
    return 0;
}

8888888888888888
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
#include <stdio.h>
#include <string.h>
int main(void)
{
    char array[1000] = {0};
    int num[128] = {0}; 
    int length,i;
    int number = 0;
  
    while(scanf("%s", array) != EOF)
    {
		length = strlen(array);
        for(i=0; i<length; i++)
        {
            if(array[i]>=0 && array[i] <= 127)
                num[ array[i] ] ++;
        }
        
        for(i=0; i<128; i++)
        {
            if (num[i])
                number++;
        }
        printf("%d", number);
    }
    
    return 0;
}


999999999
描述：
输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
#include <stdio.h>
#include <string.h>
int main9(void)
{
    char interge[500]={0};
    int i,index = 0;
  
    while(scanf("%s", interge) != EOF)
    {
		index = strlen(interge) - 1;
        for(i=index; i>=0; i--)
        {
            printf("%c",interge[i]);
        }
        printf("\n");
    }
    
    return 0;
}

方法2
#include <stdio.h>
#include <string.h>
int main9(void)
{
    int number = 0;
  
    while(scanf("%d", &number) != EOF)
    {
        while(number)
        {
            printf("%d",number%10);
            number /= 10;
        }
        printf("\n");
    }
    
    return 0;
}


给定n个字符串，请对n个字符串按照字典序排列。
输入描述:
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
#include <stdio.h>
#include <string.h>

int main11(void)
{
    int num = 0;
    int i,j;
    scanf("%d", &num);
    char str[num][100];
    char Temp[100];
  
    for(i=0; i<num; i++)
    {
        scanf("%s", str[i]);
    }
    for(i=0; i<num; i++)
    {
        for(j=i+1;j<num;j++)
        {
            if(strcmp(str[i],str[j]) > 0)
            {
                strcpy(Temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], Temp);
            }
        }
    }
    for(i=0; i<num; i++)
        printf("%s\n", str[i]);
    
    return 0;
}
strcpy和memcpy主要有以下3方面的区别。
1、复制的内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。
2、复制的方法不同。strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，所以容易溢出。memcpy则是根据其第3个参数决定复制的长度。
3、用途不同。通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy

整形转为二进制
#include <stdio.h>
int main10(void)
{
    int binary[100]={0};
    int num = 0; 
    int i=0,j;
    while(scanf("%d", &num) != EOF)
    {
		while(num)
        {
            binary[i] = num % 2;
            i++;
            num = (int)num / 2;
        }
        for(j=0; j<=i-1; j++)
        {
             printf("%d",binary[j]);   
        }
    }
    
    return 0;
}



将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

#include <stdio.h>
#include <string.h>
int main11(void)
{
	char sentence[2000];
	int len,i;
	int count = 0;
	char *p;
	char word[20];
	
	gets(sentence);
	len = strlen(sentence);
	
	p = sentence + len - 1;
	
	
	while(len--)
	{
		count++;
		if(*p == ' ')
		{
			//printf("%s ", (p+1));
			sprintf(word, "%.*s", count-1, (p+1));
			printf("%s ", word);
			count = 0;
		}
		p--;
	}
	for(i=0; i<strlen(sentence); i++)
	{
		if(sentence[i] == ' ')
			break;
		printf("%c",sentence[i]);
	}
	
    return 0;
}



开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。
输入：
合法坐标为A(或者D或者W或者S) + 数字（两位以内）坐标之间以;分隔。非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。


#include <stdio.h>
#include <string.h>

/*返回值： 0 - 有效命令
 *         -1 - 无效命令
 */
int CheckFormat(char *command)
{
	int len;
	len = strlen(command);
	if (len < 2 || len > 3)
		return -1;
	if (command[0] == 'A' || command[0] == 'S' || command[0] == 'D' || command[0] == 'W')
	{
		if(len == 2)
		{
			if(command[1] < '0' || command[1] > '9')
				return -1;
			else 
				return 0;
		}
		if(len == 3)
		{
			if(command[1] < '0' || command[1] > '9' || command[2] < '0' || command[2] > '9')
				return -1;
			else 
				return 0;
		}
	}
	return 0;
}

/*
 * 输入：str 其中str[1], str[2]才开始为数字
 * 返回：-1 -错误
 *		 其他值 - 转化为的整数
 */
int StrToInt(char *str)
{
	if(NULL == str)
		return -1;
	int i = 0, j = 0;
	int intger = 0;
	int len = 0;
	len = strlen(str);
	if (len == 2)
	{
		intger = str[1] - '0';
		return intger;
	}
	if (len == 3)
	{
		i = str[1] - '0';
		j = str[2] - '0';
	    intger = i * 10 + j;
		return intger;
	}
	return -1;
}
int main12(void)
{
	char StrGetIn[10000];
	int len, count;
	
	char *token;
	
	while (gets(StrGetIn))
	{
		int i = 0, x=0, y=0; 			/*要在while中重新初始化为0*/
		len = strlen(StrGetIn);
		char *command[len];	/*储存每个命令*/

		token = strtok(StrGetIn, ";");	/*这里要使用双引号*/
		while(token)
		{
			if ( 0 == CheckFormat(token) )
			{
				command[i] = token;
				i++;
			}
			token = strtok(NULL,";");
		}
		count = i ;/*记录有多少个命令*/
		
		
		for(i=0; i<count; i++)
		{
			//printf("%s\n",command[i]);
			switch (command[i][0])
			{

				case 'A':
				{
					x -= StrToInt(command[i]);
					break;
				}
				case 'S':
				{
					y -= StrToInt(command[i]);
					break;
				}
				case 'W':
				{
					y += StrToInt(command[i]);
					break;
				}
				case 'D':
				{
					x += StrToInt(command[i]);
					break;
				}
						
			}
		}
		printf("%d,%d\n", x,y);  	/*打印时要加上\n*/
	}
	return 0;
}

开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。处理： 1、 记录最多8条错误记录，循环记录，对相同的错误记录（净文件名称和行号完全匹配）只记录一条，错误计数增加；2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；3、 输入的文件可能带路径，记录文件名称不能带路径。
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
E:\V1R2\product\fpgadrive.c   1325

fpgadrive.c 1325 1

#include <stdio.h>
#include <string.h>

int main13(void)
{
	char StrGetIn[100] = {0};
	char record[10][100] = {0,0};
	char count[10] = {1};
	int len,i;
	int flag = 0;
	int DocNum = 0;
	
	char *pTemp;
	char *plen;
	//char *pFile;
	
	while (gets(StrGetIn))
	{
		if (strlen(StrGetIn) != 0)
		{
			/*注意是 ‘\\’*/
			pTemp = strrchr(StrGetIn, '\\') + 1; /*找到字符串中最后一个，并返回指向该点的指针*/
			
			if (DocNum == 8)
			{
				DocNum = 0;
			}
				
			for (i=0; i<8; i++)
			{
				if (!strcmp(record[i], pTemp)) 
				{
					count[i]++;
					flag = 1;
					break;		
				}
			}
			
			if (!flag)
			{
				plen = strchr(pTemp, ' ');
				while (plen - pTemp > 16)
				{
					 pTemp  += 1;
				}
				strcpy(record[DocNum],pTemp);  
				DocNum++;
			}
			else 
				flag = 0;
			
			for (i=0; i<8;i++)
			{
				if(record[i][0] != 0)
				{
					printf("%s %d\n",record[i], count[i]);
				}
				
			}
			
		}	
	}
	return 0;
}


原理：ip地址的每段可以看成是一个0-255 的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成一个长整数。
举例：一个ip地址为10.0.3.193 每段数字相对应的二进制数
10                   00001010
0                    00000000
3                    00000011
193                  11000001
组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。的每段可以看成是一个0-255的整数，需要对IP地址进行校验




#include <stdio.h>
#include <string.h>

int main(void)
{
	unsigned int a,b,c,d;
	a =10;
	b = 0;
	c = 3;
	d = 193;
	printf("%d\n",a<<2);
	printf("%d\n",a<<4);
	printf("%d\n",a<<6);
	printf("%d\n",a<<24);
	//sum=(a<<24)|(b<<16)|(c<<8)|d;
	return 0;
}


密码要求:
1.长度超过8位
2.包括大小写字母.数字.其它符号,以上四种至少三种
3.不能有相同长度超2的子串重复
说明:长度超过2的子串   021Abc9000


#include <stdio.h>
#include <string.h>

int CheckForKinds(char *str)
{
	int i = 0;
	int a = 0, b = 0, c = 0, d = 0;

	
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			a = 1;
		else if (str[i] >= 'a' && str[i] <= 'b')
			b = 1;
		else if (str[i] >= '0' && str[i] <= '9')
			c = 1;
		else 
			d = 1;
		i++;
		
	}
	
	return a+b+c+d;
}
int main15(void)
{
	char StrGetIn[256];
	int len;
	int count = 0;
	int i,j,m,n;	
	int flag = 0;
	
	while (gets(StrGetIn))
	{
		len = strlen(StrGetIn);
		flag = 0;
		if (len > 9)
		{
			if(CheckForKinds(StrGetIn) > 2)
			{
				for(i=0; i<len-4; i++)
				{
					for(j=i+3; j<len-2; j++)
					{
						m = i;
						n = j;
						count = 0;
						
						if(StrGetIn[m] == StrGetIn[n])
						{
							if(StrGetIn[m+1] == StrGetIn[n+1])
							{
								if(StrGetIn[m+2] == StrGetIn[n+2])
									flag = 1;
							}
				
						}		
					}
				}
				
			}
			else
				flag = 1;
		}
		else
			flag = 1;
		
		if (flag)
			printf("NG\n");
		else
			printf("OK\n");

	}
	return 0;
}



他是这么变换的，大家都知道手机上的字母： 1--1， abc--2, def--3, ghi--4, jkl--5, mno--6, pqrs--7, tuv--8 wxyz--9, 0--0,就这么简单，渊子把密码中出现的小写字母都变成对应的数字，数字和其他的符号都不做变换，
声明：密码中没有空格，而密码中出现的大写字母则变成小写之后往后移一位，如：X，先变成小写，再往后移一位，不就是y了嘛，简单吧。记住，z往后移是a哦。




#include <stdio.h>
#include <string.h>

void uppercase(char *captical)
{
	if(*captical == 'Z')
		*captical = 'a';
	else
	    *captical = *captical + 32 + 1;
	
}

void lowercase(char *minuscule)
{
	if (*minuscule >= 'a' && *minuscule <= 'c')
		*minuscule = '2';
	else if (*minuscule >= 'd' && *minuscule <= 'f')
		*minuscule = '3';
	else if (*minuscule >= 'g' && *minuscule <= 'i')
		*minuscule = '4';
	else if (*minuscule >= 'j' && *minuscule <= 'l')
		*minuscule = '5';
	else if (*minuscule >= 'm' && *minuscule <= 'o')
		*minuscule = '6';
	else if (*minuscule >= 'p' && *minuscule <= 's')
		*minuscule = '7';
	else if (*minuscule >= 't' && *minuscule <= 'v')
		*minuscule = '8';
	else if (*minuscule >= 'w' && *minuscule <= 'z')
		*minuscule = '9';
}
int main16(void)
{
	char StrGetIn[256];
	int len;
	int count = 0;
	int i,j,m,n;	

	while (gets(StrGetIn))
	{
		len = strlen(StrGetIn);
		for (i=0; i<len; i++)
		{
			if (StrGetIn[i] >= 'A' && StrGetIn[i] <= 'Z')
				uppercase(&StrGetIn[i]);
			else if (StrGetIn[i] >= 'a' && StrGetIn[i] <= 'z')
				lowercase(&StrGetIn[i]);
		}
		printf("%s\n", StrGetIn);
		
	}
	
	
}


实现删除字符串中出现次数最少的字符，若多个字符出现次数一样，则都删除。输出删除这些单词后的字符串，字符串中其它字符保持原来的顺序


#include <stdio.h>
#include <string.h>

int main17(void)
{
	char StrGetIn[20];
	char bucket[26] = {0};
	int len;
	int min = 0;
	int i,j,m,n;

	while(gets(StrGetIn))
	{
		memset(bucket,0,sizeof(bucket));
		len = strlen(StrGetIn);
		for (i=0; i<len; i++)
			bucket[ StrGetIn[i]-'a' ]++;
		
		min = bucket[ StrGetIn[0]-'a' ];
		for (i=0; i<len; i++)
		{
			if (bucket[ StrGetIn[i]-'a' ] < min )
				min = bucket[ StrGetIn[i]-'a' ];
		}
		for (i=0; i<len; i++)
		{
			if (bucket[ StrGetIn[i]-'a' ] != min)
				printf("%c", StrGetIn[i]);
		}
		printf("\n");
	}
	return 0;
}

编写一个程序，将输入字符串中的字符按如下规则排序。

规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。

       如，输入： Type   输出： epTy

规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。

     如，输入： BabA   输出： aABb

规则 3 ：非英文字母的其它字符保持原来的位置。

     如，输入： By?e   输出： Be?y


//不能通过 不知道什么原因
#include <stdio.h>
#include <string.h>

int main(void)
{
	char StrGetIn[500];
	char bucket[500] = {0};
	int len;
	char k = 0;
	int i,j,m,n;

	while(gets(StrGetIn))
	{
		len = strlen(StrGetIn);
		for(i=0; i<26; i++)
		{
			for (j=0; j<len; j++)
			{
				if (StrGetIn[j] == ('a' + i ) || StrGetIn[j] ==('A' + i))
					bucket[k++] = StrGetIn[j];
			}
		}
		k = 0;
		for (i=0; i<len; i++)
		{
			if (StrGetIn[i] >= 'A' && StrGetIn[i] <= 'Z' || StrGetIn[i] >= 'a' && StrGetIn[i] <= 'z') 
				StrGetIn[i] = bucket[k++];
		}
		printf("%s\n", StrGetIn);
	}
	return 0;
}


按照指定规则对输入的字符串进行处理。

详细描述：

将输入的两个字符串合并。

对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。这里的下标意思是字符在字符串中的位置。

对排序后的字符串进行操作，如果字符为‘0’——‘9’或者‘A’——‘F’或者‘a’——‘f’，则对他们所代表的16进制的数进行BIT倒序的操作，并转换为相应的大写字符。如字符为‘4’，为0100b，则翻转后为0010b，也就是2。转换后的字符为‘2’； 如字符为‘7’，为0111b，则翻转后为1110b，也就是e。转换后的字符为大写‘E’

#include <stdio.h>
#include <string.h>
  
char *pStr;
  
/*
 *功能：字符串处理
 *输入：两个字符串，需要异常处理
 *输出：合并处理后的字符串
 返回：无
 */
void ProcessString(const char *str1,const char *str2,char *strOutput)
{
    if(str1 == NULL || str2 == NULL)
        exit(1);        // exit(1)表示异常退出
    //step1；合并字符串
    pStr = strcat(str1, str2);
    int len = strlen(pStr);
    char tmp;
    //step2；字符串排序：从小到大
    //a.奇数位置字符排序
    for(int i=0; i<len; i += 2)
    {
        for(int j=i+2; j<len; j += 2)
        {
            if(*(pStr + j) < *(pStr + i))
            {
                tmp = *(pStr + j);
                *(pStr + j) = *(pStr + i);
                *(pStr + i) = tmp;
            }
        }
    }
    //偶数位置字符排序
    for(int i=1; i<len; i += 2)
    {
        for(int j=i+2; j<len; j += 2)
        {
            if(*(pStr + j) < *(pStr + i))
            {
                tmp = *(pStr + j);
                *(pStr + j) = *(pStr + i);
                *(pStr + i) = tmp;
            }
        }
    }
    //printf("%s", pStr);    测试OK，可以实现排序
    //step3；字符串处理之转换为十六进制bit倒序
    //思路：0-9字符转换为16进制数字atoi()，并逆序，后来想了下挺麻烦的，于是使用了查表法
    for(int i=0; i<len; i++)
    {
        tmp = *(pStr + i);
        if(tmp == 'a' || tmp == 'A')    tmp = '5';
        else if(tmp == 'b' || tmp == 'B')    tmp = 'D';
        else if(tmp == 'c' || tmp == 'C')    tmp = '3';
        else if(tmp == 'd' || tmp == 'D')    tmp = 'B';
        else if(tmp == 'e' || tmp == 'E')    tmp = '7';
        else if(tmp == 'f' || tmp == 'F')    tmp = 'F';
        else if(tmp == '1')    tmp = '8';
        else if(tmp == '2')    tmp = '4';
        else if(tmp == '3')    tmp = 'C';
        else if(tmp == '4')    tmp = '2';
        else if(tmp == '5')    tmp = 'A';
        else if(tmp == '6')    tmp = '6';
        else if(tmp == '7')    tmp = 'E';
        else if(tmp == '8')    tmp = '1';
        else if(tmp == '9')    tmp = '9';
        *(pStr + i) = tmp;
    }
    printf("%s\n", pStr);        //一定要添加‘\n’，否则会有莫名的错误，比如输出比正确的字符要长
      
}
  
int main()
{
    char str1[1000],str2[1000],str[2000]={0};
  
    while(scanf("%s %s", str1, str2) != EOF)
    {
        ProcessString(str1, str2, str);
    }
    return 0;
}



#endif




#include <stdio.h>
#include <string.h>

int main(void)
{
	int a, b, c, d;
	int ip[4];
	int i = 0;
	unsigned int num,numIn;
	while(scanf("%d.%d.%d.%d", &a,&b,&c,&d) != EOF)
	{
		scanf("%u", &numIn);
		
		num = ((a<<24)|(b<<16)|(c<<8)|d);
		printf ("%u\n",num);
		
		ip[0] = (numIn&0xff000000)>>24;
		ip[1] = (numIn&0x00ff0000)>>16;
		ip[2] = (numIn&0x0000ff00)>>8;
		ip[3] = (numIn&0x000000ff);
		
		printf ("%d.%d.%d.%d\n", ip[0],ip[1],ip[2],ip[3]);
	}
	
	return 0;
}








































