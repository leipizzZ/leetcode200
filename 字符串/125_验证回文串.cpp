//自己写的，好像双指针不需要用for
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0, j = s.size() - 1; i < j; i ++)
        {
            while (i < j && !isalpha(s[i]) && !isdigit(s[i])) i ++;
            while (i < j && !isalpha(s[j]) && !isdigit(s[j])) j --;
            if (i < j && tolower(s[i]) != tolower(s[j])) return false; //tolower(c) 和 toupper(c) 只有c在有相应的小写或者大写才会改变c，否则保持不变
            j --;
        }

        return true;
    }
};
