#include<math.h>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = *std::max_element(piles.begin(), piles.end());
        int res = r;
        while(l <= r) {
            int k = (l + r) / 2;
            if(k == 0) { // if k has reduced to 0 it will cause a div by 0 error.
                return res;
            }
            int time = 0;

            // calculate total time taken to finish all piles
            for(auto i = piles.begin(); i != piles.end(); i++) {
                //cout << ceil(*i/k) << endl;
                time += ceil(double(*i)/double(k));
            }

            printf("%d, %d, %d, %d", l, k, r, time); cout << endl;
            if(time > h) {
                l = k + 1;
            } else {
                res = std::min(res, k);
                r = k - 1;
            }
        }
        return res;
    }
};
