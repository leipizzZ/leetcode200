// 参考答案 Boyer-Moore 投票算法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int condidate = -1;
        int count = 0;

        for (int num : nums)
        {
            if (num == condidate) count ++;
            else
            {
                count --;
                if (count < 0)
                {
                    condidate = num;
                    count = 1;
                }
            }
        }

        return condidate;
    }
};
