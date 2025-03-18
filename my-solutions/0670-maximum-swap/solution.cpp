class Solution {
public:
    int maximumSwap(int num) {
        int res = 0;
        vector<int> numArray;
        while(num) {
            numArray.push_back(num%10);
            num/=10;
        }

        int max_i = 0;
        int swap_i = -1, swap_j = -1;

        // for(auto& i: numArray) cout << i << " ";
        // cout << endl;

        for(int i = 1; i < numArray.size(); ++i) {
            if(numArray[i] > numArray[max_i]) max_i = i;
            if(numArray[i] < numArray[max_i]) {
                swap_i = max_i;
                swap_j = i;
            }
        }

        //cout << swap_i << " " << swap_j << endl;

        if(swap_i != -1 && swap_j != -1) swap(numArray[swap_i], numArray[swap_j]);
        for(int i = numArray.size()-1; i > -1; --i) res = res * 10 + numArray[i];
        return res;
    }
};
