class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int i = 0;
        int n = asteroids.size();
        long long curmass=mass;
        while (i < n) {

            if (curmass >= asteroids[i]) {
                curmass += asteroids[i];
                i++;
            }
            else {
                int j = i + 1;

                while (j < n && asteroids[j] > curmass) {
                    j++;
                }

                if (j == n)
                    return false;

                swap(asteroids[i], asteroids[j]);

                curmass += asteroids[i];
                i++;
            }
        }

        return true;
    }
};
/*class Solution {
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
};*/
