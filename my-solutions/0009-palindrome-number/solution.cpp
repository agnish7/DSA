class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long reversed = 0, num = x;
        while(x) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        while(num && reversed) {
            if(num % 10 != reversed % 10) return false;
            num /= 10;
            reversed /= 10;
        }
        if(num || reversed) return false;
        return true;
    }
};
