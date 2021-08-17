bitset<mx>compo;
vector<int>pr;
int phi[mx],mob[mx];
void seive(int n)
{
    phi[1]=mob[1]=1;
    for(int i=2; i<=n; i++){
        mob[i]=1;
        if(compo[i] == 0){
            pr.push_back(i);
            phi[i]=i-1;
        }
        for(int j=0; j<pr.size() && i*pr[j]<=n; j++){
            compo[i*pr[j]]=1;
            if(i%pr[j]==0){
                phi[i*pr[j]]=phi[i]*pr[j];
                break;
            }
            else
                phi[i*pr[j]]=phi[i]*phi[pr[j]];
        }
    }
    for(auto xx : pr){
        int tem=xx*xx;
        if(tem>n)break;
        for(int j=tem; j<=n; j+=tem)
            mob[j]=0;
    }
    for(auto xx : pr){
        for(int j=xx; j<=n; j+=xx)
            mob[j]*=-1;
    }
}
