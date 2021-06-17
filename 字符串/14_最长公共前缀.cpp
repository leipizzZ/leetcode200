// 参考答案 先排序， 比较字符串组第一个和最后一个字符串 相同的前缀即可
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        sort(strs.begin(), strs.end());
        string st = strs.front(), en = strs.back();

        int num = max(st.size(), en.size());
        int i = 0;
        while(i < num && st[i] == en[i])
            i ++;

        return string(st, 0, i); // i 长度
    }
};

// 参考答案 横向遍历 对比每一个字符串并保存
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string str = strs[0];
        for(string s : strs)
        {
            str = twoCommonPrefix(str, s);
            if (!str.size()) return "";
        }

        return str;
    }

    string twoCommonPrefix(string& str1, string& str2)
    {
        int num = max(str1.size(), str2.size());
        int i = 0;
        while (i < num && str1[i] == str2[i]) i ++;

        return str1.substr(0, i); //i 长度
    }
};


// 自己写的 纵向遍历， 有丶辣鸡
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string str;
        int j = 0, num0 = strs[0].size();
        while (j < num0)
        {
            int i = 1;
            while (i < strs.size())
            {
                if (j < strs[i].size() && strs[0][j] == strs[i][j]) i ++;
                else return str;
            }

            str += strs[0][j];
            j ++; 
        }

        return str;
    }
};

//参考答案 两重for循环，一重字符串索引，一重字符串组索引

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int i = 0; i < strs[0].size(); i ++)
        {
            for (int j = 1; j < strs.size(); j ++)
                if (i >= strs[j].size() ||strs[0][i] != strs[j][i] )
                    return strs[0].substr(0, i);
        }

        return strs[0];
    }
};
