// 哈希表， 判断会不会出现重复的数字
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        hash.insert(n);
        
        while (true)
        {   
            int m = 0;
            while(n)
            {
                m += ((n % 10) * (n % 10));
                n /= 10;
            }

            if (m == 1) return true;

            if (hash.count(m)) return false;
            else 
            {
                hash.insert(m);
                n = m;
            }
        }
    }
};


//参考答案，判断有无循环用快慢指针
class Solution {
public:
    int next(int n)
    {
        int m = 0;
        while(n)
        {
            m += ((n % 10) * (n % 10));
            n /= 10;
        }
        return m;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do
        {
            slow = next(slow);
            fast = next(next(fast));
        }while (slow != fast);

        return slow == 1;
    }
};