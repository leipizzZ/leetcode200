
// 参考答案 翻转后， 从低位到高位一步步计算a 和 b 的每一位， 和进位 carry
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());  //翻转string字符串
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size());
        int carry = 0;
        for (int i = 0; i < n; i ++)
        {
            carry += i < a.size() ? (a.at(i) == '1') : 0;  // 判断正确，返回(int)1 true, 判断错误, 返回 int(0) false;
			//carry += i < a.size() ? (a[i] == '1') : 0;  结果一样
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            res += (carry % 2) ? '1' : '0'; //res.push_back((carry % 2) ? '1' : '0'); 结果一样

            carry /= 2;
        }

        if (carry) res += '1';

        reverse(res.begin(), res.end());

        return res;
    }
};


