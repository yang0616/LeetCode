## 找出最大和 ##
定义一个字符串常量，字符串中只出现大小写字母和整数，输出字符串中的出现最多的数字的和？

例如：
> 输入：“9fi3dj11P0jAsf11j”
> 
> 输出：22
> 
> 因为字符串中出现最多的是两次11
> 
## 代码演示 ##
	//第一种方式，常规做法
	int getSum(const char* str, int len)
	{
		vector<int> data;
		int sum = 0;
		int cur = 0;
		for (int i = 0; i < len; i++)
		{			
			if (str[i] >= '0' && str[i] <= '9')
			{
				cur = str[i] - '0';
				sum = sum * 10 + cur;
				cur = 0;
				continue;
			}

			if (sum)
			{
				data.push_back(sum);
				sum = 0;
			}			
		}
		if (sum) data.push_back(sum);

		sort(data.begin(), data.end());
		vector<int> ::iterator it = data.begin();
		
		int max_count = 0, cur_count = 1, eax_data = 0, old_data = *it; 
		if (++it == data.end())
		{
			return old_data;
		}

		for (it; it != data.end(); it++)
		{
			if (*it == old_data)
			{
				cur_count++;
			}
			else
			{
				old_data = *it;
				cur_count = 1;
			}

			if (max_count <= cur_count)
			{
				max_count = cur_count;
				eax_data = old_data;				
			}	
		}

		int return_sum = 0;
		while (max_count > 0)
		{
			return_sum += eax_data;
			max_count--;
		}
		return return_sum;
	}

	//第二种用哈希表，因为哈希还没有学，待续。。。。。
