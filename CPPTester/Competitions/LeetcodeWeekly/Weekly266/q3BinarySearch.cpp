
class Solution {
public:

    bool canDo(int n, int mid, vector<int>& quantities){
        int tot =0;
        for(int i=0;i<quantities.size();i++){
            tot+=quantities[i]/mid+(quantities[i]%mid!=0);
        }
        return tot<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        unsigned long sum = 0;
        int mx=100000;
        int ans = 0;
        /*
        for(int i=0;i<quantities.size();i++){
            //sum+=quantities[i];
            mx = max(quantities[i],mx);
        }*/
        //int mn = (int)((double)sum/n+1-0.000001);
        int mn = 1;
        int l = mn, r = mx, mid;
        while(l<=r){
            mid = (l+r)/2;
            if(canDo(n,mid,quantities)){
                r = mid-1;
                ans = mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    
};