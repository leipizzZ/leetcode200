// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j)
        {
            if (numbers[i] + numbers[j] > target) j --;
            else if (numbers[i] + numbers[j] < target) i ++;
            else return {i + 1, j + 1};
        }
        return {};
    }
};


// 哈希表 不太行
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); i ++)
        {
            if (hash.count(target - numbers[i])) return {hash[target - numbers[i]] + 1, i + 1};
            hash[numbers[i]] = i;
        }

        return {};
    }
};