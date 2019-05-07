## 矩形覆盖 ##
**题目描述：**我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个 2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
## 代码演示 ##
此题为变相的斐波那契数列

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
    	int rectCover(int number)
    	{
    		if (number == 0)
    			return 0;
    		if (number == 1)
    			return 1;
    		if (number == 2)
    			return 2;
    		int sum = 3, f1 = 1, f2 = 2;
    		for (int i = 3; i < number; i++)
    		{
    			f1 = f2;
    			f2 = sum;
    			sum = f1 + f2;
    		}
    		return sum;
    	}
    };