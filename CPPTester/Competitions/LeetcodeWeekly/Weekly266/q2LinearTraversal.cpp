class Solution {
public:
    void FastIO()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
}
    long long countVowels(string word) {
        long long ret = 0;
        for(long long i=0;i<word.length();i++){
            if(word[i]=='a' || word[i]=='e' ||word[i]=='i' ||word[i]=='o' ||word[i]=='u'){
                ret+= (i+1)*(word.length()-i);
            }
        }
        return ret;
    }
};