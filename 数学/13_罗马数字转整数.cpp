//自己写的， 所有情况都用if else 模拟, 有丶辣鸡
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i ++)
        {
            if (s[i] == 'I')
            {
                if (s[i + 1] == 'V') 
                {
                    res += 4;
                    i ++;
                }
                else if (s[i + 1] == 'X')
                {
                    res += 9;
                    i ++;
                }
                else res ++;
            }
            else if (s[i] =='V') res += 5;
            else if (s[i] == 'X')
            {
                if (s[i + 1] == 'L')
                {
                    res += 40;
                    i ++;
                }
                else if (s[i + 1] == 'C')
                {
                    res += 90;
                    i ++;
                }
                else res += 10;
            }
            else if (s[i] == 'L') res += 50;
            else if (s[i] == 'C')
            {
                if (s[i + 1] == 'D')
                {
                    res += 400;
                    i ++;
                }
                else if (s[i + 1] == 'M')
                {
                    res += 900;
                    i ++;
                }
                else res += 100;
            }
            else if (s[i] == 'D') res += 500;
            else res += 1000;
        }

        return res;
    }
};


//罗马数字 如果小的数字在大的数字左边， 等同于减去小的数字。 哈希表保存 罗马数字 和 阿拉伯数字 的转换
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash = 
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;

        for (int i = 0; i < s.size(); i ++)
        {   
            int val = hash[s[i]];
            if (i < s.size() - 1 && val < hash[s[i + 1]]) res -= val;
            else res += val;
        }

        return res;
    }
};