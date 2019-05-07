## 旋转数组的最小值 ##
**题目描述：**把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
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
    	static int orderFind(vector<int> ve, int head, int tail)
    	{
    		int ans = ve[head];
    		for (int i = head + 1; i <= tail; i++)
    		{
    			if (ans > ve[i])
    				ans = ve[i];
    		}
    		return ans;
    	}
    
    	int minNumberInRotateArray(vector<int> rotateArray)
    	{
    		if (rotateArray.size() == 0) //判断参数
    			return 0;
    		int head = 0, tail = rotateArray.size() - 1, mid = head;//将mid初始化为头的好处是，实参如果为原来的数组，可以直接返回第一个最小数
    		while (rotateArray[head] >= rotateArray[tail])
    		{
    			if (tail - head == 1)
    			{
    				mid = tail;
    				break;
    			}
    			mid = (head + tail) / 2;
    			if (rotateArray[head] == rotateArray[mid]
    				&& rotateArray[mid] == rotateArray[tail]) //特殊情况：如果头、尾、中间的数都是相同的，就不能采用二分法查找了。只能顺序遍历找最小值
    				return orderFind(rotateArray, head, tail);
    			if (rotateArray[mid] >= rotateArray[head])
    				head = mid;
    			if (rotateArray[mid] <= rotateArray[tail])
    				tail = mid;
    		}
    		return rotateArray[mid];
    	}
    };