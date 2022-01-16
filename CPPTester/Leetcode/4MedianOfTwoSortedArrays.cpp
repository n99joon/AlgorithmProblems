class Solution {
public:
    int findIdx(vector<int>& n1, vector<int>& n2,int idx){
        return lower_bound(n2.begin(),n2.end(),n1[idx])-n2.begin() + idx;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int no = nums1.size();
        int nt = nums2.size();
        int targ = (no+nt-1)/2;
        
        int low = 0, high = no-1, mid;
        while(low<=high){
            mid = (low+high)/2;
            int cur = findIdx(nums1,nums2,mid);
            if(cur==targ){
                low=mid;
                break;
                
            }
            else if(cur < targ){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        cout << low << " " << high << " " << mid;
        //if found targ while b search
        if(findIdx(nums1,nums2,low)==targ){
            if((no+nt)%2==1)return nums1[low];
            else{
                int med = nums1[low];
                int n2Idx = lower_bound(nums2.begin(),nums2.end(),nums1[low])-nums2.begin();
                if(low >= no-1)med+=nums2[n2Idx];
                else if(n2Idx == nt)med+=nums1[low+1];
                else med+=min(nums1[low+1],nums2[n2Idx]);
                return (double)med/2;
            }
        }
        //if not found,
       // if(low)
        return 0;
    }
};