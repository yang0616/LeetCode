## 二进制中1的个数 ##
**题目描述：**输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
## 代码演示 ##
    #include <iostream>
    #include <vector>
    #include <stack>
    #include <iterator>
    #include <time.h>
    #include <string>
    using namespace std;
    
    class  Function
    {
    public:
    	//第一种方法
    	int NumberOf1_1(int n) //注意，尽量不要改变参数得值
    	{
    		int sum = 0;
    		unsigned int flag = 1;
    		while (flag)
    		{
    			if (n & flag)
    				sum++;
    			flag = flag << 1;
    		}
    		return sum;
    	}
    
    	//第二种方法
    	int NumberOf1_2(int n) 
    	{
    		int sum = 0;
    		while (n)
    		{
    			sum++;
    			n = (n - 1) & n;
    		}
    		return sum;
    	}
    };
