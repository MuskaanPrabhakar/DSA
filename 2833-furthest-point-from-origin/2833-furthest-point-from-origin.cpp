class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos=0;int mx=0;
        for(int i=0; i<moves.size(); i++){
            if(moves[i]=='L'){
                pos--;
            }
            else if(moves[i]=='R'){
                pos++;
            }
            else mx++;
        }
        return abs(pos) + mx;;
    }
};
/*
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos = 0, mx = 0;

        for(char ch : moves) {
            if(ch == 'L') pos--;
            else if(ch == 'R') pos++;
            else mx++;
        }

        return abs(pos) + mx;
    }
};*/
