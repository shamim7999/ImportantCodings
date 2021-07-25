int nck[100005][4]
// Function to find the nCr
int printNcR(int n, int r)
{
    int p = 1, k = 1;

    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            int m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;
    return p;
}

void calc()
{
    for(int i=1; i<=100000; i++){
        for(int j=1; j<=min(i, 3LL); j++){
            nck[i][j] = printNcR(i, j);
        }
    }
}
