class Solution {
public:
    double myPow(double x, int n) {
        x = n >= 0 ? x : 1 / x;
        unsigned int n_bar = static_cast<unsigned int>(abs(static_cast<long long>(n)));
        unsigned int pow = 0;
        double res = 1;
        while(pow < n_bar) {
            unsigned int p = 2;
            double num = x;
            while(p < n_bar - pow) {
                num = num * num;
                p = p * 2;
            }
            pow = pow + p / 2;
            res = res * num;
            if(res == 0) {
                break;
            }
        }
        return res;
    }
};
