// 自己写的 ，先排序后遍历
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i ++)
        {
            if (nums[i] != nums[i + 1]) return nums[i];
            i ++;
        }

        return nums[nums.size() - 1];
    }
};

//参考答案 异或
//a 异或 0 = a
// a 异或 a = 0；
//异或具有交换律

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (auto i : nums) res ^= i;

        return res;
    }
};
