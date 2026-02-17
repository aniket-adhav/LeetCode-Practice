class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;
        int n = classes.size();
        for(int i = 0;i<n;i++){
            int a = classes[i][0];
            int b = classes[i][1];
            double gain = (double)(a+1)/(b+1) - (double)a/b;
            pq.push({gain,{a,b}});
        }   
        while(extraStudents--){
            auto item = pq.top();
            pq.pop();
            int pass = item.second.first;
            int total = item.second.second;
            pass++;
            total++;
            double gain = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({gain,{pass,total}});
            
        }
        double sum = 0;
        while(!pq.empty()){
            auto item = pq.top();
            pq.pop();
            int pass = item.second.first;
            int total = item.second.second;
            sum += (double)pass/(double(total));
        }
        return sum/n;
    }
};