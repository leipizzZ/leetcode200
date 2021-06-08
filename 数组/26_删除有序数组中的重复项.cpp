class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
           if(nums[i]!=nums[j])
            {
                if (i - j > 1)
                    nums[++ j] = nums[i];
                else j ++; 
            }
               
        }

        return ++ j;
    }
};