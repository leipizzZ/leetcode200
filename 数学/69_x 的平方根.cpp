// 浮点数的做法套用
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        double l = 0, r = x;

        while(r - l > 1e-6)
        {
            double mid = (r + l) / 2;
            if (mid * mid < x) l = mid;
            else r = mid;
        }

        return r;
    }
};

// e^(0.5 * lnx) = sqrt(x)  但是 指数函数和对数函数的参数和返回值均为浮点数，因此运算过程中会存在误差
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        int res = exp(0.5 * log(x));

        return (long)(res + 1) * (res + 1) <= x ? res + 1 : res; // 判断 res + 1 是结果 还是 res （误差）
    }
};


//整数二分 按照模板写的
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        int l = 0, r = x;
        while (l < r)
        {
            int mid = l + r >> 1;
            if ((long long)mid * mid >= x) r = mid;
            else l = mid + 1;
        } //算出来的结果是 mid * mid 大于等于 x 的结果

        return (long) r * r <= x ? r : r - 1; // 判断一下结果是r还是r - 1
    }
};

// 牛顿迭代法 快速求零点 ，C 的平方根就是函数 y = f(x) = x^2 - C 的零点

// 牛顿迭代法的本质是借助泰勒级数，从初始值开始快速向零点逼近。我们任取一个 x0作为初始值，
// 在每一步的迭代中，我们找到函数图像上的点 (xi, f(xi))，过该点作一条斜率为该点导数 f'(xi)的直线，
//与横轴的交点记为 x{i+1}。 x{i+1}相较于 xi 而言距离零点更近。
//在经过多次迭代后，我们就可以得到一个距离零点非常接近的交点。

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        double x0 = x;
        while (true)
        {
            double x1 = 0.5 * (x0 + x / x0);
            if (fabs(x0 - x1) < 1e-6) break;

            x0 = x1;
        }

        return x0;
    }
};

