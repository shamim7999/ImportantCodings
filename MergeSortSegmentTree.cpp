namespace Segment_Tree
{
        vector < int > tree[mx*4];
        void init(int node, int b, int e)
        {
                if(b == e){
                        tree[node].push_back(a[b]);
                        return;
                }
                int mid = (b+e)/2;
                int left = node*2;
                int right = left+1;
                init(left, b, mid);
                init(right, mid+1, e);

                merge(tree[left].begin(), tree[left].end(),
                        tree[right].begin(), tree[right].end(),
                        back_inserter(tree[node]));
        }

        int Query(int node, int b, int e, int i, int j)
        {
            
            if(i>e || j<b)return 0;
            if(b>=i && e<=j){
                
                //// write here....
              
              
            }

            int mid=(b+e)/2;
            int left=node*2;
            int right=left+1;
            int p=Query(left,b,mid,i,j);
            int q=Query(right,mid+1,e,i,j);
            return p+q;
        }

}

using namespace Segment_Tree;
