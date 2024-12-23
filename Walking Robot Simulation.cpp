class Solution {
    int x, y, dist;
    set<pair<int, int>> obs;
private:
    void moveX(int k, int dirn) {
        int newX = x;
        for (int i = 1; i <= k; i++) {
            newX = x + i * dirn;
            if (obs.find({newX, y}) != obs.end()){
                newX -= 1*dirn;
                break;
            }
        }
        x = newX;
    }
    void moveY(int k, int dirn) {
        int newY = y;
        for (int i = 1; i <= k; i++) {
            newY = y + i * dirn;
            if (obs.find({x, newY}) != obs.end()){
                newY -= 1*dirn;
                break;
            }
        }
        y = newY;
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        x = 0, y = 0, dist = 0;
        obs.clear();
        for (auto& it : obstacles) {
            obs.insert({it[0], it[1]});
        }

        int isY = 1, isX = 0, dirn = 1;
        int maxi = 0;

        for (auto it : commands) {
            if (it == -1) {
                if (isY == 1) isX = 1, isY = 0;
                else if (isY == -1) isX = -1, isY = 0;
                else if (isX == 1) isY = -1, isX = 0;
                else if (isX == -1) isY = 1, isX = 0;
            }
            else if (it == -2) {
                if (isY == 1) isX = -1, isY = 0;
                else if (isY == -1) isX = 1, isY = 0;
                else if (isX == 1) isY = 1, isX = 0;
                else if (isX == -1) isY = -1, isX = 0;
            }
            else {
                if (isX == 0) moveY(it, isY);
                if (isY == 0) moveX(it, isX);
                maxi = max(maxi, x*x + y*y);
            }
        }

        return maxi;
    }
};