#define N 200005
int fact[N], inv[N];

int bigmod(int e, int x)
{
    if(!x)return 1;
    int p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}
 
void calc()
{
        fact[0] = 1;
        for(int i = 1; i < N; i++)
            fact[i] = fact[i - 1] * 1ll * i % mod;
        
        inv[N - 1] = bigmod(fact[N - 1], mod - 2);
        
        for(int i = N - 2; i >= 0; i--)
            inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}

int norm(int x)
{
    if(x>=mod)
        x%=mod;
    if(x<0)
        x+=mod;
    return x;
}
