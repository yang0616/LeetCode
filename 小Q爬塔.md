## 小Q爬塔 ##
题目描述：小Q正在攀登一座宝塔，这座宝塔很特别，一共有n层，但是每两层之间的净高却不相同，所以造成了小Q爬过每层的时间也不相同。如果一层的高度为X，那么爬过这层需要的时间也为X。小Q还会一种魔法，没用一次可以让他向上跳一层或者两层，但是每次跳跃完后小Q后都将用完 魔法力，必须爬过至少一层再次跳跃，跳跃不消耗时间。
问小Q想用最短的时间爬到塔顶，需要多少时间？【求职攻略第一题】

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
    
    int p[10001], t[10001];
    int main()
    {	
    	int n, val;
    	cin >> n;
    	for (int i = 1; i <= n; i++)
    	{
    		cin >> val;
    		p[i] = min(p[i - 1], t[i - 1]) + val;
    		if (i == 1) continue;
    		t[i] = min(p[i - 1], p[i - 2]);
    	}
    	cout << min(p[n], t[n]) << endl;
    	return 0;
    }
