class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a(numRows);
        for (int i = 0; i < numRows; i ++)
        {   
            a[i].resize(i + 1);  //
            a[i][0] = a[i][i] = 1; 
            for(int j = 1; j < i; j ++) 
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
        return a;

    }
};

//构造函数
vector():创建一个空vector
vector(int nSize):创建一个vector,元素个数为nSize
vector(int nSize,const t& t):创建一个vector，元素个数为nSize,且值均为t
vector(const vector&):复制构造函数
vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中