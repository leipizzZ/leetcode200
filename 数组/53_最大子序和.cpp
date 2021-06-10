// 自己写的，不是很好
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = -INT_MAX - 1;
        int j = -1;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (j == -1) 
            {
                res = max(res, nums[i]);
                if (nums[i] > 0) 
                {
                    j = i;
                    sum = nums[i];
                }
            }
            else
            {
                if (nums[i] <= 0)
                    sum += nums[i];
                else 
                {
                    if (sum > 0)
                        sum += nums[i];
                    else 
                    {
                        sum = nums[i];
                        j = i;
                    }

                    res = max(res, sum);
                }
            }
             
        }

        return res;
    }
};


//贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = nums[0];
        for (int i = 0; i < nums.size(); i ++)
        {
            sum = max(sum + nums[i], nums[i]);
            res = max(res, sum);
        }

        return res;
    }
};

// 动态规划 有缘再补
