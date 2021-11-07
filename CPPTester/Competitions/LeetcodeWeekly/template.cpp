class Solution {
public:
    
    void FastIO()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
}
    int trap(vector<int>& height) {
        int ret =0;
        stack<pair<int,int>> entry;
        entry.push({0,height[0]});
        for(int i=1;i<height.size();i++){
            while(!entry.empty() && entry.top().second<height[i]){
                pair<int,int> tp =entry.top();
                //if last element break
                if(entry.size()==1){
                    entry.pop();
                    break;
                }
                //if larger than top
                entry.pop();
                ret+=(i-entry.top().first-1)*(min(height[i],entry.top().second)-tp.second);
            }
            entry.push({i,height[i]});
        }
        return ret;
    }
};