class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        if (mass < asteroids[0]) return false;
        long long sum = mass + asteroids[0];
        for (int i=1; i<asteroids.size(); i++) {
            if(sum < asteroids[i])
                return false;
            sum += asteroids[i];
        }
        return true;
    }
};