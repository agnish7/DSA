class Solution {
public:
    bool isValid(string s) {
        stack<int> store;
        for(auto i = s.begin(); i != s.end(); i++) {
            if(*i == '(' || *i == '{' || *i == '[') {
                store.push(*i);
            } else if (*i == ')' || *i == '}' || *i == ']') {
                if(store.empty())
                    return false;
                
                char top = store.top();
                store.pop();
                if(top == '(' && *i != ')')
                    return false;
                else if(top == '{' && *i != '}')
                    return false;
                else if(top == '[' && *i != ']')
                    return false;
            } else {
                return false;
            }
        }
        if(!store.empty())
            return false;
        return true;
    }
};
