long long binPow(long long a, int b){
    long long ans = 1;
    for(long long i = 1, val = a; i <= b; i *= 2, val *= val){
        if(b & i) ans *= val;
    }
    return ans;
}
