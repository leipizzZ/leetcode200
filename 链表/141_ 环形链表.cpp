/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> Nodeset;
        while (head != NULL)
        {
            if (!Nodeset.count(head)) 
            {
                Nodeset.insert(head);
                head = head->next;
            }
            else return true;
        }

        return false;
    }
};


//快慢指针
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if (!head || !head->next) return false;
       auto slow = head;
       auto fast = head->next->next;

       while (slow != fast)
       {
           if (fast == NULL || fast->next == NULL) return false; // 注意这个条件，验证了全部链表有无空
           else 
           {
               slow = slow->next;
               fast = fast->next->next;
           }
       }

       return true;
    }
};