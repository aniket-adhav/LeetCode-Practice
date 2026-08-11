class Solution {
public:
    int n ; 
    int dp[1001][1001] ;
    
    bool isPred(string& prev_w, string& curr_w){
        int M = prev_w.length() ;
        int N = curr_w.length() ;

        //base-case
        if(M >= N || N-M != 1){
            return false ;
        }

        int i = 0, j = 0 ;

        while(i < M && j < N){
            if(prev_w[i] == curr_w[j]){
                i++ ;
            }
            j++ ;
        }

        return i == M ; //then it is a predecessor

    }
    int LIS(vector<string>& words, int prev_i, int curr_i){
        //1.) handle base case
        if(curr_i == n) return 0 ;

        //2.) check memoization table
        if(prev_i != -1 && dp[prev_i][curr_i] != -1){
            return dp[prev_i][curr_i] ;
        }

        int take = 0 , skip = 0 ;

        if(prev_i == -1 || isPred(words[prev_i], words[curr_i]) ){
            take = 1 + LIS(words, curr_i, curr_i +1) ;
        }

        skip = LIS(words, prev_i, curr_i +1) ; //if not taken move curr by 1
        
        if(prev_i != -1){
            dp[prev_i][curr_i] = max(take, skip) ;
        }
        return max(take, skip) ;



    }
    //comparator defining
    static bool myFunction(const string& word1, const string& word2){
        return word1.length() < word2.length() ;
    }
    int longestStrChain(vector<string>& words) {
        n = words.size() ;

        memset(dp, -1, sizeof(dp)) ;

        //Sort words according the length
        sort(begin(words), end(words), myFunction) ;


        //function call to LIS
        return LIS(words, -1, 0) ;
    }
};