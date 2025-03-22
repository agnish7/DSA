class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x) {
            res = res * 10 + x%10;
            if(res > INT_MAX || res < INT_MIN) return 0;
            x/=10;
        }
        return static_cast<int>(res);
    }
};
