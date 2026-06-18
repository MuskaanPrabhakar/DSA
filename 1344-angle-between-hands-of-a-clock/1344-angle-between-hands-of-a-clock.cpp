class Solution {
public:
    double angleClock(int hour, int minutes) {
                double angleclock= abs(30*hour - 5.5*minutes);
                angleclock = min(angleclock, 360-angleclock);
                return angleclock;
    }
};