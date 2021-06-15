//参考答案 遍历 + 位运算
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 0; i < 32 && n > 0; i ++)
        {
            res += (n & 1) << (31 - i);
          //res |= (n & 1) << (31 - i); 和上面的式子等同， 或运算 后赋值；
            n >>= 1; // 右移一位后赋值
        }

        return res;
    }
};

// 分治替换
/*
32位无符号整数，如 1111 1111 1111 1111 1111 1111 1111 1111 
表示成16进制        f    f    f    f    f    f    f   f
一个16进制的f代表二进制的4位
ffff ffff右移16位，变成 0000 ffff
ffff ffff左移16位，变成 ffff 0000
它们俩相或，就可以完成低16位与高16位的交换

之后的每次分治，都要先与上一个掩码，再进行交换
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16); //低16位与高16位交换
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8); //每16位中低8位和高8位交换; 1111是f
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4); //每8位中低4位和高4位交换;
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2); //每4位中低2位和高2位交换; 1100是c,0011是3
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1); //每2位中低1位和高1位交换; 1010是a,0101是5
        return n;
    }
};
