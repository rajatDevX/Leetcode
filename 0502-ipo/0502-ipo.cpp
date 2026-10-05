class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>projects;
        for(int i=0;i<n;i++){
            projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(),projects.end());
        priority_queue<int>available;
        int i=0;
        for(int count=0;count<k;count++){
            while(i<n && projects[i].first<=w){
                available.push(projects[i].second);
                i++;
            }
            if(available.empty()) break;
            w+=available.top();
            available.pop();
        } 
        return w;

    }
};