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