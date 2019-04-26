#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Function
{
public:
	/*
	*��Ŀ������
	*    ��һЩ�˱�����һ���˵��ϣ���Ҫ����ͧ������ǡ���i���˵�����Ϊpeople[i],ÿһ�Ҿ���ͧ���Գ���
	*���������Ϊlimit��ÿһ�Ҿ���ͧ�����Գ��������ˣ������������������˵�����֮�����Ϊlimit����
	*��������Ҫ�����پ���ͧ������֤ÿ���˶����Ա��ȣ�����1 <= people[i] <=limit <= 3000��
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
	*��Ŀ������
	*    ����һ�����������ҳ��������ȡ������������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
	*˵����Ҷ�ӽ����ָû���ӽڵ�Ľڵ㣻
	*���룺������������{3, 9��20��NULL��NULL��15, 7}
	*����������ȣ�3
	 
	int maxDepth(TreeNode* root)
	{
		if (root == NULL) return 0;
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		return ((leftDepth > rightDepth) ? leftDepth : rightDepth) + 1;
	}
   */
	/*
	*��Ŀ������
	*    ����һ������ͷ���head�ķǿյ���������������м�ڵ㡣����������м�ڵ㣬�򷵻صڶ�����
	*ʾ��1��
	*	���룺{1, 2, 3, 4, 5}
	*	�����3
	*ʾ��2��
	*	���룺{1, 2, 3, 4, 5, 6}
	*   �����4
	*���˼·:
	*    ����ָ��
	*/

	/*
	*��Ŀ������
	*    ����һ��λ��ˮƽ���ϵķ��ݺ�����·������λ�ã��ҵ����Ը������з��ݵ���С�źŰ뾶���������
	*���Ƿ��ݺ�·������λ�ã����������С�źŵķ���뾶
	*
	*˵����
	*	�����ķ��ݺ�·��������Ŀ��Ϊ�Ǹ������Ҳ�����25000��
	*	�����ķ��ݺ�·������λ�þ��ǷǸ������Ҳ��ᳬ��10^9��
	*	ֻҪ����λ��·�����ķ���뾶�ڣ�������Ե�ϣ����Ϳ��Եõ����ǣ�
	*	���е�·��������ѭ��İ뾶��׼������뾶Ҳһ����
	*
	*ʾ��1��
	*	���룺{1, 2, 3}��{2}
	*	�����1
	*	���ͣ�����λ��2�Ϸ�һ���˰뾶Ϊ2��·����
	*ʾ��2��
	*	���룺{1, 2, 3, 4}��{1, 4}
	*	�����1
	*	���ͣ���λ��1��4�Ű뾶Ϊ1��·����
	*/
	int findRadius(vector<int>& houses, vector<int>& heaters)
	{
		sort(heaters.begin(), heaters.end());
		int ans = 0;
		//˼·��
		//����ÿ�����ӣ���ǰ��������ů��(ֻ��һ����ů������������ж�)��Ѱ������֮��Ľ�С���룬���뵱ǰ���뾶�Ƚϸ��¼���
		for (int i = 0; i<houses.size(); i++)
		{
			int cur = INT_MAX;
			// lower_bound ���ص�һ�����ڵ������Ԫ�صĵ�����
			//��ʱlarger�������������ұߵĹ�ů��
			//ʹ��*larger��ȡֵ,����heaters[larger-heaters.begin()]
			auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
			if (larger != heaters.end())
			{
				//������ڵĻ� ��ô�ͼ�������֮��ľ���
				cur = *larger - houses[i];
			}
			//������Ԫ��û��С���ʼ��Ԫ�� ��ô��ζ�������Ҳ��һ����ů��
			if (larger != heaters.begin())
			{
				//��߹�ů����λ�þ��ǵ�ǰlargerλ��-1
				auto smaller = larger - 1;
				//ʹ��*smaller��ȡ�����ֵ,��������֮��Ľ�Сֵ
				cur = min(cur, houses[i] - *smaller);
			}
			ans = max(cur, ans);
		}
		return ans;
	}
};