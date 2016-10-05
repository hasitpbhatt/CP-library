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

#define MAX 1000000

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

// keeps maximum prime divisor in largestPrime, 
// if prime == largestPrime, it is prime
void modifiedSieve(vector<int>& largestPrime, vector<int>& primes,int val) {
	primes.clear();
	largestPrime.clear();
	primes.push_back(0);
	largestPrime.resize(val+1);
	for(ll i=2;i<=val;i++) {
		if(!largestPrime[i]) {
			primes.push_back(i);
			for(ll j=i;j<=val;j+=i) {
				largestPrime[j] = i;
			}
		}
	}
}

int main() {
	fastin;
	vector<int> largestPrime;
	vector<int> primes;
	vector<int> modPrimes;
	vector<bool> isVisited;
	sieve(isVisited,primes,MAX);
	modifiedSieve(largestPrime,modPrimes,MAX);
	//cout << (primes == modPrimes) << endl;
	cout << "Prime numbers by sieve are :" << endl;
	for(int i=2;i<=MAX;i++) {
		if(!isVisited[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	cout << "Prime numbers by modified sieve are :" << endl;
	for(int i=990000;i<=MAX;i++) {
		if(largestPrime[i]==i) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}