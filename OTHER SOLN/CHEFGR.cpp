#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int n, m;
		cin >> n >> m;
		int *a = new int[n];
		int max = -1;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			if(max < a[i])
				max = a[i];
		}
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			sum += max - a[i];
		}
		if((sum==m)||(m>sum&&((m-sum)%n==0)))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}