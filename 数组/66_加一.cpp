// 自己写的

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i --)
        {
            if (digits[i] != 9)
            {
                digits[i] += 1;
                return digits;
            }
            else
            {
                digits[i] = 0;
                if (!i) 
                {
                    digits.insert(digits.begin(), 1);
                    return digits;
                }
            }
        }
        return digits;
    }
};



//参考一下 别人的答案 好像也没太多不同
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i --)
        {
            digits[i] ++;
            digits[i] %= 10;
            if (digits[i] != 0)
                break;
            else
                if (!i) 
                {
                    digits.insert(digits.begin(), 1);
                    break;
                }
        }
        return digits;
    }
};