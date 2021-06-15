// lowbit(x) = x & -x
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n&(-n))
        {
            sum ++ ;
            n -= n&(-n);
        }

        return sum;
    }
};
