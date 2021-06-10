//暴力解法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i ++)
            if (nums[i] >= target) return i;
        return nums.size();    
    }
};


// 二分法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        else{
            int l = 0, r = nums.size() - 1;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (nums[mid] >= target) r = mid;
                else l = mid + 1;
            }

            return l;
        }   
    }
};