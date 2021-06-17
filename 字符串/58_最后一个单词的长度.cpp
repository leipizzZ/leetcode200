// 自己写的， 感觉判断很辣鸡
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int i, j;
        for ( i = 0, j = 0; j < s.size(); j ++)
        {
            while (s[j] == ' ' && j + 1 < s.size()) 
            {
                j ++;
                if (s[j] != ' ') i = j;
            }
            
        }

        while (j - 1 >= 0 && s[j - 1] == ' ') j --;
        return j - i;
    }
};

//参考答案 stream 
class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        istringstream in(s); //字符串输入输出流自动过滤空格
        string res;
        while(in>>res); //读取到最后一个单词
        return res.size();
    }
};

//参考答案 从后往前数
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, i = s.size() - 1;

        while (i >= 0 && s[i] == ' ') i --;
        while (i >= 0 && s[i --] != ' ') res ++;
        return res;
    }
};
