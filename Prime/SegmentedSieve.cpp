#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long ld;

#define endl "\n"
#define DFLAG 0

#define DEBUG(x) if(DFLAG) cout << #x << " " << x << endl;
#define fastin ios::sync_with_stdio(false)

#define REP(i,x) for(int i = 0; i < x; i++)
#define PER(i,x) for(int i = x-1; i >= 0; i--)
#define FOR(i,x,y) for(int i = x; i <= y; i++)
#define ROF(i,x,y) for(int i = y; i >= x; i--)
#define FORn(i,x,y,n) for(int i = x; i <= y; i+=n)

#define mp make_pair

#define MAX 1000

void segmentedSieve(vector<bool>& isVisited,vector<int>& primes,ll low,ll high) {
	int primeSize = primes.size();
	isVisited.resize(high-low+1);
	for(int i=1;(i<primeSize) && (primes[i]*primes[i])<=high;i++) {
		ll start = (low/primes[i]) * primes[i];
		if(start < low)
			start += primes[i];
		if(start == primes[i])
			start += primes[i];
		for(int j=start;j<=high;j+=primes[i]) {
			isVisited[j-low] = true;
		}
	}
}

void sieve(vector<bool>& visited, vector<int>& primes,int val) {
	primes.clear();
	visited.clear();
	primes.push_back(0);
	visited.resize(val+1);
	for(ll i=2;i<=val;i++) {
		if(!visited[i]) {
			primes.push_back(i);
			for(ll j=i*i;j<=val;j+=i) {
				visited[j] = true;
			}
		}
	}
}

int main() {
	fastin;
	vector<int> primes;
	vector<bool> isVisited;
	vector<bool> isComposite;
	sieve(isVisited,primes,MAX);
	ll low = 990000;
	ll high = 1000000;
	segmentedSieve(isComposite,primes,low,high);
	cout << "Prime numbers are :" << endl;
	for(int i=0;i<=high-low;i++) {
		if(!isComposite[i])
			cout << i+low << " ";
	}
	return 0;
}