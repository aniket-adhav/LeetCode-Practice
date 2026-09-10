class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n=nums.size();
        string s = "";

        for(int i=0; i<n; i++){
            s+=to_string(nums[i]);
        }

        

        int count=0;

        for(int i=0; i<s.size(); i++){
            if(s[i]==digit+'0') count++;
        }

        return count;
    }
};