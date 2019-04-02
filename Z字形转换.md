## Z字形变换 ##
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下（.代表空格）：

LeetCode/picture2/Z字形转换1.png

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);

示例 1:

> 输入: s = "LEETCODEISHIRING", numRows = 3
> 
> 输出: "LCIRETOESIIGEDHN"

示例 2:

> 输入: s = "LEETCODEISHIRING", numRows = 4
> 
> 输出: "LDREOEIIECIHNTSG"

解释:
LeetCode/picture2/Z字形转换2.png
## 代码演示 ##
	//方法一
	string convert1(string s, int numRows)
	{
		if (numRows == 1)
		{
			return s;
		}

		int len = s.size();
		int interval = 2 * numRows - 2;//计算列间隔
		int column = len % numRows == 0 ? len / numRows : len / numRows + 1; //计算列数
		
		vector<int> sub;//存放下标
		for (int i = 0; i < numRows; i++)
		{
			sub.push_back(i);
			int j;
			for (j = interval; j < len ; j += interval)
			{	
				if (i != numRows - 1 && i != 0)
				{
					sub.push_back(j - i);
				}
								
				if (j + i < len)
				{
					sub.push_back(j + i);
				}
				
			}
			if (j - i < len && i != numRows - 1 && i != 0)
			{
				sub.push_back(j - i);
			}
		}

		string result;
		vector<int> ::iterator it = sub.begin();
		for(it; it != sub.end(); it++)
		{
			result.push_back(s[*it]);
		}		
		return result;
	}

	//方法二
	string convert2(string s, int numRows) 
	{
		if (numRows == 1)
		{
			return s;
		}

		string result;
		int len = s.size();
		int interval = 2 * numRows - 2;

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j + i < len; j += interval)
			{
				result += s[j + i];
				if (i != 0 && i != numRows - 1 && j + interval - i < len)
				{
					result += s[j + interval - i];
				}					
			}
		}
		return result;
	}
