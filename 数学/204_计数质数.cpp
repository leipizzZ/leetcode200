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

//参考答案 埃氏筛法
//把每次能遍历到的质数 的倍数标记为 非质数，剩下的为质数
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);

        int res = 0;
        for (int i = 2; i < n; i ++)
            if (isPrime[i]) 
            {
                res ++;
                if ((long)i * i < n)
                    for (int j = i * i; j < n; j += i)
                        isPrime[j] = 0;
            }
        
        return res;
        
    }
};

//线性筛 下次一定

