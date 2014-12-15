#include <iostream>
#include <cmath>

using namespace std;

void printPrime(int x, int y) {
	int limit = y;
	bool *isPrime = new bool[limit+1];
	for(int i = x; i < limit+1; ++i) {
		isPrime[i] = false;
	}

	for(int i = 1; i <= sqrt(limit); ++i) {
		for(int j = 1; j <= sqrt(limit); ++j) {
			int n = 0;
			n = 4*i*i + j*j;
			if(n <= limit && (n%12==1 || n%12==5))
				isPrime[n] = !isPrime[n];

			n = 3*i*i + j*j;
			if(n<=limit && n%12==7)
				isPrime[n] = !isPrime[n];

			n = 3*i*i - j*j;
			if(i > j && n<=limit && n%12==11)
				isPrime[n] = !isPrime[n];

		}
	}
	for(int i = 5; i<=sqrt(limit); ++i) {
		if(isPrime[i]) {
			for(int k = i*i; k <= limit; k+=i*i)
				isPrime[k]=false;
		}
	}
	isPrime[1] = false;
	isPrime[2] = true;
	isPrime[3] = true;
	isPrime[4] = false;
	for(int j = x; j <= y; ++j) {
		if(isPrime[j])
			cout << j << endl;
	}
	cout << endl;
}

int main() {

	int T;
	cin >> T;
	for(int i = 0; i < T; ++i) {
		int x, y;
		cin >> x >> y;
		
	}
}
