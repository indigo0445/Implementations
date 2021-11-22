class DSU{
private:
    vector<int> data;
public:
    DSU(int n){
        data.resize(n);
        fill(data.begin(), data.end(), -1);
    }
    int leader(int x){
        if(data[x] < 0){
            return x;
        } else{
            data[x] = leader(data[x]);
            return data[x];
        }
    }
    int sz(int x){
        return -data[leader(x)];
    }
    bool same_set(int a, int b){
        return (leader(a) == leader(b));
    }
    void merge(int a, int b){
        int l1 = leader(a), l2 = leader(b);
        if(sz(l1) > sz(l2)) swap(l1, l2);
        data[l2] += data[l1];
        data[l1] = l2;
    }
};
