//given list of ranges, be able to update range and query element in log(N) time
class segtree{
	public:
	vector<int> nodes;
	int size;
	//node i has parent i/2
	//node i has children 2i, 2i+1
	//original array starts at nodes[size]
	segtree(int s){
		int N = ceil(log2(s));
		size = pow(2, N);
		nodes.resize(2*size);
		//vector filled with 0s
	}
	int q(int i){
		int ans = 0;
		for(int node = i + size; node > 0; node/=2){
			ans += nodes[node];
		}
		return ans;
	}
	void update(int i, int val){
		nodes[size + i] += val;
	}
	void updateRange(int a, int b, int val){
		for(a+=size, b+=size; a <= b; a/=2, b/=2){
			if(a%2 == 1) nodes[a++] += val;
			if(b%2 == 0) nodes[b--] += val;
		}
	}
	void print(){
		for(int i = 0; i < 2*size; i++){
			cout << i << " : " << nodes[i] << "\n";
		}
	}
};
