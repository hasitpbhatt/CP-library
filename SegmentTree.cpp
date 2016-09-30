template <typename T>
void build(vector<T>& segTree, vector<T>& array, int node, int lower, int upper) {
	if(lower>upper)
		return;
	if(lower == upper) {
		segTree[node] = array[lower];
	}
	int mid = (lower+upper)/2;
	build(segTree,array,2*node,lower,mid);
	build(segTree,array,2*node+1,mid+1,upper);

	T sum = segTree[2*node];
	sum += segTree[2*node+1];

	segTree[node] = sum;
}

template <typename T>
T query(vector<T>& segTree, int node, int lower, int upper, int start, int end) {
	if((lower >= start) && (upper <= end))
		return segTree[node];
	else if((start > upper) || (end < lower))
		return 0; // equivalent to invalid
	else {
		int mid = (lower+upper)/2;
		return query(segTree, 2*node, lower, mid, start, end) + query(segTree, 2*node+1, mid+1, upper, start, end);
	}
}
