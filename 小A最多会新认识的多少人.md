## 小A最多会新认识的多少人  ##
题目描述：链接：https://www.nowcoder.comquestionTerminal/1fe6c3136d2a45fa8ef555b459b6dd26来源：牛客网
小A参加了一个n人的活动，每个人都有一个唯一编号i(i>=0 & i<n)，其中m对相互认识，在活动中两个人可以通过互相都认识的一个人介绍认识。现在问活动结束后，小A最多会认识多少人？

输入描述:
> 第一行聚会的人数：n（n>=3 & n<10000）；
> 第二行小A的编号: ai（ai >= 0 & ai < n)；
> 第三互相认识的数目: m（m>=1 & m
> < n(n-1)/2）；
> 第4到m+3行为互相认识的对，以','分割的编号。

输出描述:
> 输出小A最多会新认识的多少人？

示例:
> 输入:
> 
> 7
> 
> 5
> 
> 6
> 
> 1,0
> 
> 3,1
> 
> 4,1
> 
> 5,3
> 
> 6,1
> 
> 6,5
> 
> 输出
> 
> 3
## 代码演示1 ##
时间复杂度较大,不建议使用。

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
    using namespace std;
    
    class  Function
    {
    private:
    	bool find_que(int key, queue<int> que)
    	{
    		while (!que.empty())
    		{
    			if (que.front() == key) return false;
    			que.pop();
    		}
    		return true;
    	}
    
    	int find_ve(int key, vector<pair<int, int>>& ve)
    	{
    		int ans = -1;
    		for (auto it = ve.begin(); it != ve.end(); it++)
    		{
    			if (it->first != key && it->second != key)   continue;
    			if (it->first == key)
    				ans = it->second;
    			else
    				ans = it->first;
    			it = ve.erase(it);
    			if (ans) return ans;
    		}
    		return ans;
    	}
    
    	int deal(int a, vector<pair<int, int>> ve, queue<int> f_que)
    	{
    		int ans = 0, count = 0 - f_que.size();
    		queue<int> s_que;
    		while (!f_que.empty())
    		{
    			int cur = f_que.front();
    			while (ans = find_ve(cur, ve) > 0 && find_que(ans, s_que))
    			{
    				f_que.push(ans);
    			}
    			f_que.pop();
    			count++;
    		}
    		return count;
    	}
    
    	bool insert(int n, int a, string str, vector<pair<int, int>>& ve, queue<int>& que)
    	{		
    		int fig = 0,eax = -1;
    		for (unsigned int i = 0; i < str.size(); i++)
    		{
    			char cur = str[i];
    			if (cur >= '0' && cur <= '9')
    			{
    				fig = fig * 10 + cur - '0';
    				continue;
    			}
    
    
    			if (fig < 0 || fig > n)  return false; 	//判断数字是否合法				
    			if (eax == -1)  eax = fig;		
    			else
    			{
    				if (eax == a)
    					que.push(fig);
    				else if (fig == a)
    					que.push(eax);
    				else
    					ve.push_back(make_pair(eax, fig));
    				eax = -1;
    			}			
    			fig = 0;
    		}
    		return true;
    	}
    public:
    	int get()
    	{
    		queue<int> que;
    		int n, a, m;
    		cin >> n >> a >> m;
    		if (n < 3 || n >= 10000 || a < 0 || a > n || m < 1 || m > n / 2 * (n + 1)) return 0;
    		string str;
    		vector<pair<int, int>> ve;
    		while (m-- >= 0)
    		{
    			getline(cin, str);
    			str += " ";
    			if (!insert(n, a, str, ve, que))
    				return 0;
    		}
    		int ans = deal(a, ve, que);
    		return ans;
    	}
    };
    
    int main()
    {
    	Function fun;
    	cout << fun.get() << endl;
    	return 0;
    }

## 代码演示2 ##
待续 >>>>