class Solution {
public:
    string minRemoveToMakeValid(string s) {


        string str = s;

        int cnt=0;

        
        //for forward direction

        for(auto &it:str){

             if(it == '(')
             {
                  cnt++;
             }
             else if(it == ')')
             {
                  if(cnt >0){
                     cnt--;
                  }
                  else it = '*';
             }
        }

        //for backward direction

        cnt = 0;

         for(int i=str.size()-1;i>=0;i--){

             if(str[i] == ')')
             {
                  cnt++;
             }
             else if(str[i] == '(')
             {
                  if(cnt >0){
                     cnt--;
                  }
                  else str[i] = '*';
             }
        }

        string ans="";

        for(auto &it:str){

             if(it == '*') continue;
             ans += it;
        }

        return ans;


       
    }
};