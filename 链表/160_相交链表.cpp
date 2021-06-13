/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // 两个指针走到交点 或者空结点（没有交点）
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        auto tailA = headA;
        auto tailB = headB;
        while (tailA != tailB)
        {
            tailA = !tailA ? headB : tailA->next;
            tailB = !tailB ? headA : tailB->next;
        }

        return tailA;
    }
};