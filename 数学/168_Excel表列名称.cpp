// 要把1-26 转变成  0-25，不然Z的情况会出错 需要 - 1
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber != 0)
        {
            res += ('A'  + (columnNumber - 1) % 26);
            columnNumber = (columnNumber - 1) / 26;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};