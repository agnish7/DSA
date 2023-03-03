#include<stack>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<std::pair<int, int>> pos_speed;
        for(int i = 0; i < size(position); i++) {
            pos_speed.push_back(std::pair<int, int>(position[i], speed[i]));
        }
        std::sort(pos_speed.begin(), pos_speed.end(), [](const std::pair<int, int> a, const std::pair<int, int> b){
            return a.first > b.first;
        });

        // for(int i = 0; i < size(position); i++) {
        //     cout << pos_speed[i].first << " " << pos_speed[i].second << endl;
        // }

        std::stack<std::pair<int, int>> car_stack;

        car_stack.push(pos_speed[0]);

        for(int i = 1; i < size(pos_speed); i++) {
            float curr_time = float(float(target - pos_speed[i].first) / float(pos_speed[i].second));
            float last_time = float(float(target - car_stack.top().first) / float(car_stack.top().second));

            if(curr_time > last_time) {
                car_stack.push(pos_speed[i]);
            }
        }

        return size(car_stack);
    }
};
