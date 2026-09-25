//FUNCTIONS ARE COMPLETELY INDEPENDENT

long long binPow(long long a, int b){
    long long ans = 1;
    for(long long i = 1, val = a; i <= b; i *= 2, val *= val){
        if(b & i) ans *= val;
    }
    return ans;
}

std::vector<long long> dijkstra(std::vector<std::vector<std::array<int, 2>>>& edges, int source) {
    constexpr long long INF = 1e18;
    std::vector<long long> dists(n, INF);
    dists[source] = 0;
    std::priority_queue<std::pair<long long, int>,
                        std::vector<std::pair<long long, int>>,
                        std::greater<>> pq; // {len, x}
    pq.push({0, source});

    while (!pq.empty()) {
        auto [len, x] = pq.top();
        pq.pop();
        if (len != dists[x]) continue;

        for (auto [c, b] : edges[x]) {
            long long new_len = len + c;
            if (new_len < dists[b]) {
                dists[b] = new_len;
                pq.push({new_len, b});
            }
        }
    }

    return dists;
}
