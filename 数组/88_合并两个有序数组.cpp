// 自己写的 ，很乱

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) 
        {
            nums1 = nums2;
            return ;
        }
        else if (n != 0)
        {
            int j = n - 1, k = m + n - 1;
             for (int i = m - 1; i >= 0; i --)
            {
                while (j >= 0 && nums1[i] <= nums2[j])
                    nums1[k --] = nums2[j --];
                nums1[k --] = nums1[i];
            }

                while (j >= 0)
                    nums1[k --] = nums2[j --];
        }

        return ;
    }
};

// 参考答案 先写索引为负数的不成立条件，不然使用索引会出错

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 || j >= 0)
        {
            if (i == -1)
                nums1[k --] = nums2[j --];
            else if (j == -1)
                nums1[k --] = nums1[i --];
            else if (nums1[i] <= nums2[j])
                nums1[k --] = nums2[j --];
            else 
                nums1[k --] = nums1[i --];
        }
        return ;
    }
};