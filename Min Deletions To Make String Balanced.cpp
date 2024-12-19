
class Solution {
public:
    int minimumDeletions(string s){
       stack<char> stack;
        int deletions = 0;
        for(auto&c : s){
            if(c == 'b'){
                stack.push(c);
            }else if(c == 'a'){
                if (!stack.empty()) {
                    stack.pop();
                    deletions++;
                }
            }
        }
        return deletions;
    }
};