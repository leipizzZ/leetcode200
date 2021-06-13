// 双指针算法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int res = 0;
        while (i < j)
            res = height[i] <= height[j] ? max(res, height[i ++] * (j - i + 1)) : max(res, height[j --] * (j - i + 1));   
        return res;
    }
};