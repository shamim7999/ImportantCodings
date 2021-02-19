using pair_type = std::pair<int, int>;

struct cmp
{
    bool operator()(const pair_type& v1, const pair_type& v2) const
    {
        if(v1.first >= v2.first){
            if(v1.first > v2.first)
                return 1;
            return (v1.second < v2.second);
        }
        return 0;
    }
};
