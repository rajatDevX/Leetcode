class Solution {
public:
bool dfs(int node,vector<vector<int>>&graph,vector<int>&state){
    if(state[node]==1){
        return true;
    }
    if(state[node]==2){
        return false;
    }
    state[node]=1;
    for(int neigh:graph[node]){
        if(dfs(neigh,graph,state))
                return true;
    }
    state[node]=2;

        return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto &p:prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        vector<int>state(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(dfs(i,graph,state)){
                return false;
            }
        }
        return true;

        
    }
};