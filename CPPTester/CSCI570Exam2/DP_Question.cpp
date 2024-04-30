//Given an integer array nums and an integer m, find k non-overlapping subarrays of length m with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
// If tie, return lexicographically smallest one, e.g. [0,1,2] instead of [1,2,3
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int m=k; //length of subarray
        k=3; //number of subarrays
        

        int n= nums.size();
        //cumulative sum
        int sum[20000+1]= {0}; //initialization
        for(int i=0;i<n;i++){
            sum[i+1]=sum[i]+nums[i];
        }

        //initialization of OPT
        int OPT[20001][4]; // OPT[i][j]=Max possible sum of numbers, nums[x-1], in intervals in range i<=x<=n, with j more subarrays to be formed
        for (int j=0;j<=k;j++) OPT[n+1][j]=0;
        for (int i=1;i<=n+1;i++) OPT[i][0]=0;

        //DP Loops
        for(int i=n;i>=1;i--){
            for(int j=1;j<=k;j++){
                if(i+m>n) OPT[i][j]=OPT[i+1][j];
                else{
                    OPT[i][j]=max(OPT[i+1][j],OPT[i+m][j-1]+sum[i+m-1]-sum[i-1]);
                    //if updated, print
                    if(OPT[i][j]==OPT[i+1][j]) cout << "Not Updated "<< "OPT["<<i<<"]["<<j<<"]="<<OPT[i+1][j]<<endl;
                    else cout << "Updated "<< "OPT["<<i<<"]["<<j<<"]="<<OPT[i+m][j-1]+sum[i+m-1]-sum[i-1]<<endl;
                }
            }
        }
        cout << OPT[1][k]<<endl;




        //backtracking (Not part of CSCI-570 exam)
        //find the max value of the total sum
        // int maxSum=OPT[1][k];
        // //starting from the lowest index, if the maxSum = OPT[i+m][j-1]+sum[i+m-1]-sum[i-1], then add the index to the answer
        // vector<int> ans;
        // for(int i=1,j=k;i<=n && j>0;){
        //     if(i>n)break;
        //     if(maxSum==OPT[i+m][j-1]+sum[i+m-1]-sum[i-1]){
        //         ans.push_back(i-1);
        //         maxSum-=sum[i+m-1]-sum[i-1];
        //         i+=m;
        //         j--;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // //decrease every element in the answer by 1
        // for(int i=0;i<ans.size();i++){
        //     ans[i]--;
        // }
        
        //backtracking (Not part of CSCI-570 exam)
//find the max value of the total sum
int maxSum=OPT[1][k];
//starting from the lowest index, if the maxSum = OPT[i+m][j-1]+sum[i+m-1]-sum[i-1], then add the index to the answer
vector<int> ans;
for(int i=1,j=k;i<=n && j>0;){
    if(i>n)break;
    if(maxSum==OPT[i+m][j-1]+sum[i+m-1]-sum[i-1]){
        ans.push_back(i); // add i to the answer, not i-1
        maxSum-=sum[i+m-1]-sum[i-1];
        i+=m;
        j--;
    }
    else{
        i++;
    }
}
//decrease every element in the answer by 1
for(int i=0;i<ans.size();i++){
    ans[i]--;
}


        return ans;
    }
};