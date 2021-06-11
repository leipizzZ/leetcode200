// 所有递增 分段区域 都要计算
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0, buy = prices[0];
        for (int i = 1; i < prices.size(); i ++ )
        {
            if (prices[i] < prices[i - 1])
            {
                pro += (prices[i - 1] - buy);
                buy = prices[i];
            }
            else if (i == prices.size() - 1)
                pro += (prices[i] - buy);
        }
        return pro;
    }
};


// 参考答案 贪心 等于每两点间上升相加
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        for (int i = 0; i < prices.size() - 1; i ++)
            pro += max(0, prices[i + 1] - prices[i]);
        
        return pro;
    }
};

// 动态规划有缘再补