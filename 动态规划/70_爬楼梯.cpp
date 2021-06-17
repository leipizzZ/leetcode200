//递归 斐波那契数列 超时

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        
        return climbStairs(n - 1) + climbStairs(n - 2); //只能从n-1层和 n-2 层爬上来  
    }
};

//参考答案 迭代 斐波那契数列
class Solution {
public:
    int climbStairs(int n) {
        int res = 1, p = 1, q = 1; 
        for (int i = 1; i < n; i ++)
        {
            p = q;
            q = res;
            res = p + q;
        }

        return res;
    }
};
