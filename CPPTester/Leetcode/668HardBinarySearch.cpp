class Solution {
public:
    int numSmaller(int col, int row, int num){
        num=num-1;
        int sum  = 0;
        for(int i=1;i<=row;i++){
            sum+=min(num/i,col);
        }
        cout << "col: " << col << "row : "<<row << "num: "<<num<<"sum: "<<sum<<endl;
        return sum;
    }
    int findKthNumber(int m, int n, int k) {//m=row, n=col
        int targ = m*n;
        int step = m*n;
        int numLess;
        int temp;
        do{
            step=(step+1)/2;
            numLess = numSmaller(n,m,targ);
            if(numLess+1==k){
                temp = numSmaller(n,m,targ+1)+1;
                if(temp>k)return targ;
                else targ = min(targ+step,m*n);
            }else if(numLess+1<k){
                temp = numSmaller(n,m,targ+1)+1;
                if(temp==k){
                     targ=targ+1;
                }
                else if(temp>k) {
                    return targ;
                }
                
                else targ=min(targ+step, m*n);
            }else{
                targ=max(0,targ-step);
            }
        }while(1);
    }
};