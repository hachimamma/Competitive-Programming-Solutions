class Solution {
public:
    int reverse(int x) {
        int t;
        long long rev=0;
        while(x!=0){
            t=x%10;
            rev=rev*10+t;
            x=x/10;
        }
        if(rev<INT_MIN || rev> INT_MAX){
            return 0;
        }
        return (int)rev;        
    }
};