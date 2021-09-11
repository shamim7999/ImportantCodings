int fac[N], inv[N];
 
void calc()
{
        fact[0] = 1;
        for(int i = 1; i < N; i++)
            fac[i] = fac[i - 1] * 1ll * i % mod;
        
        inv[N - 1] = pw(fac[N - 1], mod - 2);
        
        for(int i = N - 2; i >= 0; i--)
            inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
