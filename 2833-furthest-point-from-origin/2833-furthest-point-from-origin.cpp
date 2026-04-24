class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos=0;int mx=0;
        for(int i=0; i<moves.size(); i++){
            if(moves[i]=='L'){
                pos--;
            }
            else if(moves[i]=='_'){
                mx++;
            }
            else if(moves[i]=='R'){
                pos++;
            }
        }
        if(pos<=0) pos-=mx;
        else pos+=mx;
        pos=abs(pos);
    return pos;
    }
};