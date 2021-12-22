namespace Fenwick_2D_tree
{
    int tree[mx][mx];
    void update(int x, int y, int val) {
          int y1;
          while (x <= n) {
            y1 = y;
            while (y1 <= m) {
              tree[x][y1] += val;
              y1 += (y1 & -y1);
            }
            x += (x & -x);
          }
    }
    int query(int x, int y) {
          int y1;
          int sum = 0;
          while (x>0) {
            y1 = y;
            while (y1>0) {
              sum+=tree[x][y1];
              y1 -= (y1 & -y1);
            }
            x -= (x & -x);
          }
          return sum;
    }
    // cout << query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1) << "\n";
};


namespace Fenwick_1D_Tree
{
    int tree[mx];
    void update(int pos)
    {
        if(pos<=0)
            return;
        //tem[pos]++;
        while(pos<=n){
            tree[pos]++;
            pos+=(pos & -pos);
        }
    }

    void remove(int pos)
    {
        if(pos <= 0)
            return;
        //tem[pos]++;
        while(pos<=n){
            tree[pos]--;
            pos+=(pos & -pos);
        }
    }

    int query(int pos)
    {
        int sum = 0;
        while(pos>0){
            sum+=tree[pos];
            pos-=(pos & -pos);
        }
        return sum;
    }

    int res(int l, int r)
    {
        int a1 = query(r) - query(l-1);
        return a1;
    }
};
