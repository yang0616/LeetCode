#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <iterator>
#include <time.h>
#include <string>
#include <math.h>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*表现良好的最长时间段*/

//解法1：动态规划，这种时间最快为最优解
int longestWPI1(vector<int>& hours) 
{
	int maxlen = 0;
	unordered_map<int, int> ma;
	vector<int> flag(hours.size()+1, 0);
	
	for (unsigned int i = 0; i < hours.size(); i++)
	{
		flag[i + 1] = flag[i] + (hours[i] > 8 ? 1 : -1);

		if (flag[i + 1] > 0)
			maxlen = max(maxlen, int(i+1)); //maxlen = i + 1;

		else if (ma.count(flag[i + 1] - 1))
			maxlen = max(maxlen, int(i - ma[flag[i + 1] - 1]));

		if (!ma.count(flag[i + 1]))
			ma.insert(make_pair(flag[i + 1], i));
	}
	return maxlen;
}

//解法2：动态规划，这种超出时间限制了，但是逻辑上没有错误
int longestWPI2(vector<int>& hours) 
{
	int oldlen = 0, newlen = 0, sum = 0;
	vector<int> flag(hours.size(), 0);

	for (unsigned int i = 0; i < hours.size(); i++)//把hourse里面的工作时间转换为-1和1
	{
		hours[i] = hours[i] > 8 ? 1 : -1;
		sum += hours[i];
	}

	if (hours.size() + sum == 0) //判断全为负数的情况
		return newlen;

	unsigned int  i = 0, j = 0;
	for (i = 0; i < hours.size(); i++)
	{
		flag[i] = hours[i];
		newlen = flag[i] >= 1 ? 1 : 0;

		for (j = i + 1; j < hours.size(); j++)
		{
			flag[j] = flag[j - 1] + hours[j] ;
			if (flag[j] >= 1)
				newlen = max(newlen, int(j - i + 1));
		}

		oldlen = max(oldlen, newlen);

		if (oldlen >= int(j - i))
			break;	
	}
	return oldlen;
}

//解法3：二分查找，这种没有超时，但是没有第一种快
int longestWPI3(vector<int>& hours) 
{
	int n = hours.size();
	int res = 0;
	vector<int> sum(n + 1, 0);
	vector<int> prefix(n + 1, 0);

	for (int i = 0; i < n; ++i)
	{
		sum[i + 1] = sum[i] + (hours[i] > 8 ? 1 : (-1));
	}

	/*intial*/
	int mx = 0;
	for (int i = 1; i <= n; ++i)
	{
		mx = min(sum[i], mx);
		prefix[i] = mx;
	}

	for (int i = 1; i <= n; ++i)
	{
		int l = 0;
		int r = i - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;

			if (prefix[mid] >= sum[i])
				l = mid + 1;
			else
				r = mid - 1;
		}
		res = max(res, i - (r + 1));
	}

	return res;
}

int main()
{
	vector<int> f = {6,6,9};
	cout << longestWPI1(f) << endl;
	return 0;
}
