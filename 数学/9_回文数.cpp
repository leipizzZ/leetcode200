// 自己写的，遍历的整数x中的所有数字
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        else
        {   
            long y = x;
            long res = 0;
            while (x != 0)
            {
               res = res * 10 + x % 10;
               x = x / 10; 
            }

            if (y == res) return true;
            else return false;
			
			// return y == res; 可以再return 判断
        }
    }
};

// 参考答案， 只需要反转一半的数据，并和另一半比较（注意区分数字为奇数位和偶数位的不同情况）
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || !(x % 10) && x != 0) return false;
        else
        {   
            int res = 0;
            while (x > res)
            {
               res = res * 10 + x % 10;
               x = x / 10; 
            }

            return res == x || res / 10 == x;
        }
    }
};