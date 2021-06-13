/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        while (head->next) //  空节点 没有 next 节点。 先确定 head 存在，才能调用 head->next， 会报错
        {
            if (head->next->val == val)
                head->next = head->next->next;
            else 
                head = head->next;
        }
        if (dummy->next->val == val) dummy->next = dummy->next->next; 

        return dummy->next;
    }
};


// 参考答案， 重新创一个移动的节点，表示确定 不需要删除的节点，用于删除之后的 val节点

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(-1, head);
        auto tail = dummy;
        while (tail->next)
        {
            if (tail->next->val == val)
                tail->next = tail->next->next;
                
            else 
                tail= tail->next;
        }


        return dummy->next;
    }
};