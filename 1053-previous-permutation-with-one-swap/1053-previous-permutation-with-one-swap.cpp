class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int last[10001];
        memset(last, -1, sizeof(last));
        // Traverse from right to left
        for(int i=n-1; i>0; i--) {
            last[arr[i]] = i;
            if(arr[i-1]<=arr[i]) continue;
            // Find the largest number smaller than arr[i-1] on its right
            for(int j=arr[i-1]-1; j>=0; j--) {
                if(last[j]==-1) continue;
                swap(arr[i-1], arr[last[j]]);
                break;
            }
            break;
        }
        return arr;
    }
};