// 枚举 超时
class Solution {
public:
    bool isPrimes(int n){
        for (int i = 2; i * i <= n; i ++)
            if (!(n % i)) return false;

        return true;
    }

    int countPrimes(int n) {
        int res = 0;
        for (int i = 2; i < n; i ++)
            res += isPrimes(i);
        
        return res;
    }
};