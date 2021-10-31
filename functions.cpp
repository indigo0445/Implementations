//FUNCTIONS ARE COMPLETELY INDEPENDENT

long long binPow(long long a, int b){
    long long ans = 1;
    for(long long i = 1, val = a; i <= b; i *= 2, val *= val){
        if(b & i) ans *= val;
    }
    return ans;
}

using arr2 = array<int, 2>;
const int INF = 1e9;
int* dijkstra(int vertices, vector<vector<arr2>> graph, int source){
    int* minDist = new int[vertices];
    fill(minDist, minDist+vertices, INF);
    minDist[source] = 0;
    bool* visited = new bool[vertices]();
    priority_queue<arr2, vector<arr2>, greater<arr2>> pq;
    pq.push({0, source});
    while(!pq.empty()){
        auto [currentDist, currentV] = pq.top();
        pq.pop();
        if(!visited[currentV]){
            visited[currentV] = true;
            for(auto& [adj, dist] : graph[currentV]){
                if(currentDist + dist < minDist[adj]){
                    minDist[adj] = currentDist + dist;
                    pq.push({minDist[adj], adj});
                }
            }
        }
    }
    delete[] visited;
    return minDist;
}
