class Solution {
public:
    void dfs(vector<int>& values,vector<int>& curTaken,int curSum,int leftT,int prevN){
        if(prevN==0)maxS = max(maxS,curSum);
        if(leftT<=0)return;
        for(auto k : edge[prevN]){
            if(leftT-k.second>=0){
                curTaken[k.first]++;
                int nxtS = curTaken[k.first]==1?curSum+values[k.first]:curSum;
                dfs(values,curTaken,nxtS,leftT-k.second,k.first);
                curTaken[k.first]--;
            }
        }
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<int> curTaken(n);
        maxS=0;
        for(int i=0;i<n;i++){
            curTaken[i]=0;
        }
        for(auto k : edges){
            edge[k[0]].push_back({k[1],k[2]});
            edge[k[1]].push_back({k[0],k[2]});
        }
        
        curTaken[0]=1;
        dfs(values,curTaken,values[0],maxTime,0);
        return maxS;
    }
private:
    vector<pair<int,int>> edge[1000];
    int maxS;
};