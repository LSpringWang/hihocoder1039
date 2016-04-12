/*输出
	对于每一行输入的字符串，输出小Hi最高能得到的分数。

第一组数据：在"ABCBCCCAA"的第2个字符后插入'C'得到"ABCCBCCCAA"，消除后得到"A"，总共消除9个字符(包括插入的'C')。

第二组数据："AAA"插入'A'得到"AAAA"，消除后得到""，总共消除4个字符。

第三组数据：无论是插入字符后得到"AABC","ABBC"还是"ABCC"都最多消除2个字符。*/

#include <iostream>
#include<string>
using namespace std;
int delSameStr(string str);
int main()
{
	string str;
	int t = 0;
	int num = 0;
	int maxnum = 0;
	cin>>t;
	while (t>0)
	{
		cin>>str;
		string str2 = str;
		int strlen = str.length();
		int i = 0;
		for (i=0;i<strlen;i++)
		{
			str2.insert(i,"A");
			num = delSameStr(str2);
			if(num>maxnum)
				maxnum = num;
			str2 = str;
		}
		for (i=0;i<strlen;i++)
		{
			str2 = str2.insert(i,"B");
			num = delSameStr(str2);
			if(num>maxnum)
				maxnum = num;
			str2 = str;
		}
		for (i=0;i<strlen;i++)
		{
			str2 = str2.insert(i,"C");
			num = delSameStr(str2);
			if(num>maxnum)
				maxnum = num;
			str2 = str;
		}
		cout<<maxnum<<endl;
		maxnum = 0;
		t--;
	}

		system("pause");
	return 0;
}
int delSameStr(string str)
{
	int len = str.length();
	int i = 0;
	bool hasDel = false;
	int beginLen = 0;
	int delNum = 0;
	while (beginLen!= len)
	{
		beginLen = len;
		for(i=0;i<len-1;i++)
		{
		
			if(str[i] == str[i+1])
			{
				str.erase(i+1,1);
				delNum++;
				hasDel = true;
				i--;
				len--;
			}else{
				if(hasDel)
				{
					str.erase(i,1);
					delNum++;
					i--;
					len--;
					hasDel = false;
				}
			}  
		}
		if(hasDel &&(i == len-1))
		{
			str.erase(i,1);
			delNum++;
			len--;
			hasDel = false;

		}
	}
	return delNum;
}