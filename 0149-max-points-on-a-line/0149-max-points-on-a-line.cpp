class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2){
            return n;
        }
        int answer=0;
        for(int i=0;i<n;i++){
            map<pair<int,int>,int>mp;
            for(int j=i+1;j<n;j++){
                int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];
                int g=gcd(dy,dx);
                dy /=g;
                dx /=g;
                if(dx<0){
                    dx=-dx;
                    dy=-dy;

                }
                if(dx==0){
                    dy=1;
                }
                if(dy==0){
                    dx=1;
                }
                mp[{dy,dx}]++;
                 answer = max(answer, mp[{dy, dx}] + 1);
            }
        }
        return answer;
    }
};