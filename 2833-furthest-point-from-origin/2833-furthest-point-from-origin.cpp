class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos=0;
        for(int i=0; i<moves.size(); i++){
            if(moves[i]=='L'){
                pos--;
            }
            else if(pos<=0 && moves[i]=='_'){
                pos--;
            }
            else if(moves[i]=='R'|| moves[i]=='_'){
                pos++;
            }
        }
        pos=abs(pos);
    return pos;
    }
};