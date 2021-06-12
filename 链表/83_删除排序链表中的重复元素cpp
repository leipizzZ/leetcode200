// 自己写的， 未简化
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        else
        {
            auto l = head;
            auto r = l->next;

            while(r != nullptr)
            {
                if (l->val < r->val)
                {
                    l->next = r;
                    l = r;
                    r = r->next;
                }
                else 
                {
                    if (r->next == nullptr) l->next = nullptr;
                    r = r->next;
                }
            }

            return head;
        }

    }
};

// 答案简化
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        else
        {
            auto l = head;

            while(l->next) //每次循环前后相等就删后，不相等就往后走
            {
                if (l->val == l->next->val) l->next = l->next->next;
                else l = l->next;
            }

            return head;
        }

    }
};
