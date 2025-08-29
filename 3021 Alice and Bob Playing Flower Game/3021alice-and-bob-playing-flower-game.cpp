class Solution {
public:
    long long flowerGame(int n, int m) {
        long long res=0;
        // O(m*n)
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if((i+j)%2==1)res++;
        //     }
        // }
        //O(n);
        // long long m_e=m/2;
        // long long m_o=(m+1)/2;
        // for(int i=1;i<=n;i++){
        //     if(i%2==1)res+=m_e;
        //     else res+=m_o;
        // }
        //O(1)
        long long n_e=n/2;
        long long n_o=(n+1)/2;
        long long m_e=m/2;
        long long m_o=(m+1)/2;
        res=(n_e*m_o)+(n_o*m_e);
        return res;
    }
};