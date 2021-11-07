class Solution {
public:
    int countVowelSubstrings(string word) {
        int sum=0;
        if(word.length()<=4)return 0;
        for(int i=0;i<word.length()-4;i++){
            int flag=0;
            int j=i;
            while(word[j]=='a' ||word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u'){
                if(word[j]=='a')flag |= 1;
                else if(word[j]=='e')flag |= 1<<1;
                else if(word[j]=='i')flag |= 1<<2;
                else if(word[j]=='o')flag |= 1<<3;
                else if(word[j]=='u')flag |= 1<<4;
                if(flag==pow(2,5)-1)sum++;
                if(j>word.length()-1)break;
                j++;
            }
            flag = 0;
        }
        return sum;
    }
};