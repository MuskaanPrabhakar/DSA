class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long curMass = mass;

        for (int a : asteroids) {
            if (curMass < a)
                return false;

            curMass += a;
        }

        return true;
    }
};