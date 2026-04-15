class Solution {
public:
    int recursion(int i,int j,string& word1,string& word2,vector<vector<int>>&dp){
        //base case
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
            return word1.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }



        //logic
        if(word1[i]==word2[j]){
            return recursion(i+1,j+1,word1,word2,dp);
        }else{
            int insert=1+recursion(i,j+1,word1,word2,dp);
            int delet=1+recursion(i+1,j,word1,word2,dp);
            int replace=1+recursion(i+1,j+1,word1,word2,dp);
            return dp[i][j]=min(insert,min(delet,replace));

        }
        




        //return 
       
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return recursion(0,0,word1,word2,dp);
    }
};