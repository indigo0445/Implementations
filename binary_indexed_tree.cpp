#include <bits/stdc++.h>
using namespace std;

class binary_indexed_tree{
private:
    int* bit;
    int* vals;
    int N;
    int lsb(int x){
        return x&(-x);
    }
    int prefix(int i){
        //prefix of first i
        int sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= lsb(i);
        }
        return sum;
    }
public:
    binary_indexed_tree(int sz, int* initial){
        N = sz;
        bit = new int[N+1];
        vals = initial;
        for(int i = 1; i <= N; i++){
            bit[i] = accumulate(vals+i-lsb(i), vals+i, 0);
        }
    }
    ~binary_indexed_tree(){
        delete[] bit, delete[] vals;
    }
    int query(int a, int b){
        //[a, b)
        return prefix(b) - prefix(a);
    }
    void set(int i, int k){
        update(i, k-vals[i]);
    }
    void update(int i, int k){
        vals[i++] = k;
        while(i <= N){
            bit[i] += k;
            i += lsb(i);
        }
    }
};
