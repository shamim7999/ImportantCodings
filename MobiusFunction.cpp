bitset < mx > chk;
vector < int > pr;
int mob[mx];

void sieve(int N)
{
    for(int i=3; i*i<=N; i+=2){
        if(!chk[i]){
            for(int j=i*i; j<=N; j+=2*i){
                chk[j] = 1;
            }
        }
    }

    pr.push_back(2);
    for(int i=3; i<=N; i+=2)
        if(!chk[i]) pr.push_back(i);
    for(int i=1; i<=N; i++)
        mob[i] = 1;
    int sz = pr.size();
    for(int i=0; i<sz && pr[i]*pr[i]<=N; i++){
        int x = pr[i];
        x = x*x;
        for(int j=x; j<=N; j+=x){
            mob[i] = 0;
        }
    }
    for(int i=0; i<sz; i++){
        int x = pr[i];
        for(int j=x; j<=N; j+=x)
            mob[j]*=-1;
    }

}
