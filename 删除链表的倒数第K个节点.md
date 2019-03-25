# 删除链表的倒数第K个节点 #
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

> 给定一个链表: 1->2->3->4->5, 和 n = 2.
> 
> 当删除了倒数第二个节点后，链表变为 1->2->3->5.

【说明：给定的 n 保证是有效的】
## 代码演示 ##
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* faster = head;
        ListNode* slow = new ListNode(0);
        slow->next = head;
        head = slow;
        
        while(n > 0)
        {
            faster = faster->next;
            n--;
        }
        
        while(faster != NULL)
        {
            faster = faster->next;
            slow = slow->next;
        }
        
        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next;   
        delete deleteNode;
        return head->next;
    }
