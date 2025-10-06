class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[j][i],matrix[i][j]);               
            }
        }
        for(int i=0;i<n;i++){
            int j=0;
            int k=n-1;
            while(j<=k){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[i][k];
            matrix[i][k]=temp;
            j++;
            k--;
           }
           cout<<endl;
        }      
    }
};