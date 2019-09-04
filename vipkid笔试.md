## vipkid笔试 ##

输入一列数字，空格隔开；再输入一个k，求在数列中每k个数的平均数构成的新数列；

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
    #include <set>
    #include <map>
    #include <iomanip>
    using namespace std;
    
    void get(string str, int k, vector<double>& res)
    {
    	vector<int> ve;
    	int val = 0;
    	unsigned int i = 0;
    
    	while(i < str.size())
    	{
    		if (isdigit(str[i]))
    			val = val * 10 + str[i] - '0';		
    		else
    		{
    			ve.push_back(val);
    			val = 0;
    		}	
    		i++;
    	}
    	ve.push_back(val);
    
    	int len = ve.size() - k + 1;
    
    	for (int i = 0; i < len; i++)
    	{
    		double tmp = 0;
    		for (int j = i; j < k+i; j++)
    		{
    			tmp += ve[j];
    		}
    		res.push_back(tmp / k);
    	}
    		
    }
    
    int main()
    {
    	string str;
    vector<double> res;
    	getline(cin, str);
    	int k; cin >> k;
    	get(str, k, res);
    	for (unsigned int i = 0; i < res.size(); i++)
    		cout << setiosflags(ios::fixed) << setprecision(2) << res[i] << " ";
    	cout << endl;
    	return 0;
    }
    