## 【剑指offer】从头到尾打印链表 ##
**题目描述**

 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

**代码演示**

    #include <iostream>
    #include <vector>
    #include <stack>
    using namespace std;
    
    struct ListNode 
    {
    	int val;
    	struct ListNode *next;
    	ListNode(int x) :
    		val(x), next(NULL) 
    	{}
    };
    
    class  Function
    {
    public:
    	vector<int> printListFromTailToHead(ListNode* head)
    	{
    		stack<int> sta;
    		vector<int> ve;
    		ListNode* p = head->next;
    		while (p != NULL)
    		{
    			sta.push(p->val);
    			p = p->next;
    		}
    
    		while (!sta.empty())
    		{
    			ve.push_back(sta.top());
    			sta.pop();
    		}
    		return ve;
    	}
    };