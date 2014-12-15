#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		long double P;
		int c;
		cin >> P >> c;
		long double low = 0.0, high = 13.0, mid;
		double log10P = log10(P);
		for(int i = 0; i < 25; ++i) {
			mid = (low + high)*0.5;
			double temp = (c*mid+1)*log10(mid);
			if(temp > log10P)
				high = mid;
			else if(temp < log10P)
				low = mid;
			else
				break;
		}
		printf("%.6LF\n", mid);
	}
	return 0;
}