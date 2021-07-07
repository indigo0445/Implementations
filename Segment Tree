template <class T = int, T initial = 0, class functor = plus<T>>
class segtree{
	public:
	functor op;
	//node i has parents i/2
	//node i has children 2i, 2i+1
	//original array starts at nodes[size]
	vector<T> nodes;
	int size;
	segtree(vector<T> v){
		int s = v.size();
		int N = ceil(log2(s));
		size = 1 << N;
		nodes.resize(2*size);
		for(int i = 0; i < s; i++) nodes[size + i] = v[i];
		//fill in gaps from resizing array
		for(int i = size+s; i < 2*size; i++) nodes[i] = initial;
		for(int i = size-1; i >= 1; i--){
			nodes[i] = op(nodes[2*i], nodes[2*i+1]);
		}
	}
	T q(int a, int b){
		T ans = initial;
		for(a+=size, b+=size; a <= b; a/=2, b/=2){
			if(a%2 == 1) ans = op(ans, nodes[a++]);
			if(b%2 == 0) ans = op(ans, nodes[b--]);
		}
		return ans;
	}
	void replace(int i, T val){
		int node = size + i;
		nodes[node] = val;
		for(node/=2; node > 0; node/=2){
			nodes[node] = op(nodes[2*node], nodes[2*node+1]);
		}
	}
	void update(int i, T val){
		replace(i, nodes[size + i] + val);
	}
	void print(){
		//debugging purposes
		for(int i = 0; i < 2*size; i++){
			cout << i << " : " << nodes[i] << "\n";
		}
	}
};
