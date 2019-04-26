#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Function
{
public:
	/*
	*题目描述：
	*    有一些人被困在一个人岛上，需要救生艇解救它们。第i个人的体重为people[i],每一艘救生艇可以承载
	*的最大重量为limit。每一艘救生艇最多可以承载两个人，但是条件是这两个人的重量之和最多为limit。则
	*返回所需要的最少救生艇数（保证每个人都可以被救，并且1 <= people[i] <=limit <= 3000）
	*/
	int getCount()
	{
		vector<int> ve;
		int limit, people, count = 0; 
		
		cin >> limit;
		while (cin >> people)
		{
			if (people > limit)
			{
				cout << "data error!" << endl;
				continue;
			}

			ve.push_back(people);

			char ch = getchar();
			if (ch == '\n') break;
					
		}	
		sort(ve.begin(), ve.end());
		vector<int> ::iterator it_front = ve.begin(), it_tail = --ve.end();
		while (it_front < it_tail)
		{
			if (*it_front + *it_tail > limit)
			{
			    it_tail--;				
			}
			else
			{
				it_front++;
				it_tail--;
			}
			count++;
		}
		if (it_front == it_tail)
		{
			count++;
		}
		return count;
	}

	/*
	*题目描述：
	*    给定一个二叉树，找出其最大深度。二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
	*说明：叶子结点是指没有子节点的节点；
	*输入：给定二叉树：{3, 9，20，NULL，NULL，15, 7}
	*输出：最大深度：3
	 
	int maxDepth(TreeNode* root)
	{
		if (root == NULL) return 0;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		return ((leftDepth > rightDepth) ? leftDepth : rightDepth) + 1;
	}
   */
	/*
	*题目描述：
	*    给定一个带有头结点head的非空单链表，返回链表的中间节点。如果有两个中间节点，则返回第二个，
	*示例1：
	*	输入：{1, 2, 3, 4, 5}
	*	输出：3
	*示例2：
	*	输入：{1, 2, 3, 4, 5, 6}
	*   输出：4
	*编程思路:
	*    快慢指针
	*/

	/*
	*题目描述：
	*    给出一条位于水平线上的房屋和无线路由器的位置，找到可以覆盖所有房屋的最小信号半径；您输入的
	*将是房屋和路由器的位置，您将输出最小信号的辐射半径
	*
	*说明：
	*	给出的房屋和路由器的数目均为非负整数且不超过25000；
	*	给出的房屋和路由器的位置均是非负整数且不会超过10^9；
	*	只要房屋位于路由器的辐射半径内（包括边缘上），就可以得到覆盖；
	*	所有的路由器都遵循你的半径标准，辐射半径也一样；
	*
	*示例1：
	*	输入：{1, 2, 3}，{2}
	*	输出：1
	*	解释：仅在位置2上放一个人半径为2的路由器
	*示例2：
	*	输入：{1, 2, 3, 4}，{1, 4}
	*	输出：1
	*	解释：在位置1和4放半径为1的路由器
	*/
	int findRadius(vector<int>& houses, vector<int>& heaters)
	{
		sort(heaters.begin(), heaters.end());
		int ans = 0;
		//思路：
		//对于每座房子，有前后两个供暖器(只有一个供暖器的情况另外判断)，寻找它们之间的较小距离，并与当前最大半径比较更新即可
		for (int i = 0; i<houses.size(); i++)
		{
			int cur = INT_MAX;
			// lower_bound 返回第一个大于等于这个元素的迭代器
			//此时larger就是这座房子右边的供暖器
			//使用*larger来取值,或者heaters[larger-heaters.begin()]
			auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
			if (larger != heaters.end())
			{
				//如果存在的话 那么就计算它们之间的距离
				cur = *larger - houses[i];
			}
			//如果这个元素没有小于最开始的元素 那么意味着它左边也有一个供暖器
			if (larger != heaters.begin())
			{
				//左边供暖器的位置就是当前larger位置-1
				auto smaller = larger - 1;
				//使用*smaller来取得这个值,更新它们之间的较小值
				cur = min(cur, houses[i] - *smaller);
			}
			ans = max(cur, ans);
		}
		return ans;
	}
};