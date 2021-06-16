// 自己手写一个栈
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) return false; //奇数必然没有成对括号

        char stk[10000];
        int tt = -1;

        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                stk[++ tt] = c;
            else if (tt < 0) return false;
            else if (c == ')')
            {
                if (stk[tt --] == '(') continue;
                else return false; 
            }
            else if (c == '}')
            {
                if (stk[tt --] == '{') continue;
                else return false; 
            }
            else 
            {
                if (stk[tt --] == '[') continue;
                else return false; 
            }
        }

        return tt == -1;
        
    }
};

// 参考答案 直接用栈
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) return false;

        stack<char> stk;

        unordered_map<char, char> pairs =
        {
            {'}', '{'},
            {']', '['},
            {')', '('}
        }; // 用hash表 存对照关系，学一下

        for (auto c : s)
        {
            if (pairs.count(c))
            {
                if (stk.empty() || stk.top() != pairs[c])
                    return false;
                else stk.pop();
            }
            else stk.push(c);
        }

        return stk.empty();
        
    }
};
