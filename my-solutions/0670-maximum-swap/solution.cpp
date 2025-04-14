class Solution {
public:
    int maximumSwap(int num) {
        string numAsString = to_string(num);
        vector<int> maxRight(numAsString.size(), 0);
        
        int maxR = INT_MIN;
        int maxRIdx = -1;
        for(int i = numAsString.size() - 1; i > -1; --i) {
            maxRight[i] = maxRIdx;
            if(numAsString[i] - '0' > maxR) {
                maxR = numAsString[i] - '0';
                maxRIdx = i;
            }
        }

        for(int i = 0; i < numAsString.size() - 1; ++i) {
            int idx = maxRight[i];
            if(numAsString[idx] - '0' > numAsString[i] - '0') {
                swap(numAsString[idx], numAsString[i]);
                break;
            }
        }

        return stoi(numAsString);
    }
};
