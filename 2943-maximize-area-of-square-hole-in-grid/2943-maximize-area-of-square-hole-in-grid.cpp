class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int max_hbar = 1;
        int max_vbar = 1;

        int current = 1;
        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i] - hBars[i-1] == 1){
                current++;
            }else{
                current = 1;
            }
            if(current > max_hbar) max_hbar = current;
        }

        current = 1;
        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i] - vBars[i-1] == 1){
                current++;
            }else{
                current = 1;
            }
            if(current > max_vbar) max_vbar = current;
        }

        int side = min(max_hbar, max_vbar) + 1;
        return side*side;
    }
};