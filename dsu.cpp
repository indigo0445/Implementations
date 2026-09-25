class DSU {
private:
    std::vector<int> data;
public:
    DSU(int n) { data = std::vector(n, -1); }
    int leader(int x){ return (data[x] < 0) ? x : (data[x] = leader(data[x])); }
    int set_size(int x) { return -data[leader(x)]; }
    bool same_set(int a, int b) { return (leader(a) == leader(b)); }
    void merge(int a, int b) {
        if (a = leader(a), b = leader(b); a != b) {
            if (set_size(a) < set_size(b)) std::swap(a, b);
            data[a] += data[b];
            data[b] = a;
        }
    }
};
