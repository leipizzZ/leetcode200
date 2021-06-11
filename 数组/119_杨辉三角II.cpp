// 递归求
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<int> res(rowIndex + 1);
        res[0] = res[rowIndex] = 1;
        vector<int> res1 = getRow(rowIndex - 1);
        for (int i = 1; i < rowIndex; i ++)
            res[i] = res1[i - 1] + res1[i];
        
        return res;
    }
};


// 修改了一下， 不太行 倒顺求每行的值，只与上一行当前索引和当前索引-1有关，只用一个数组，但是由于递归，多次定义数组，内存占用很高
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<int> res = getRow(rowIndex - 1);
        res.resize(rowIndex + 1);
        for (int i = rowIndex; i >= 1; i --)
            res[i] += res[i - 1];
        
        return res;
    }
};

// 参考答案 内存 O(1)， 倒序，使用循环
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;

        for (int i = 1; i <= rowIndex; i ++)
            for (int j = i; j >= 1; j --)
                res[j] += res[j - 1];
        
        return res;
    }
};