#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <int> lh, rh;
	int n;
	cin >> n;
	int *x = new int[n];
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				lh.push_back(x[i]*x[j]+x[k]);
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				if(x[k] != 0)
					rh.push_back((x[i]+x[j])*x[k]);
			}
		}
	}

	int count = 0;
	sort(lh.begin(), lh.end());
	sort(rh.begin(), rh.end());
	for(int i = 0; i < lh.size(); ++i) {
		int lo = lower_bound(rh.begin(), rh.end(), lh[i])-rh.begin();
		int hi = upper_bound(rh.begin(), rh.end(), lh[i])-rh.begin();
		count+=(hi-lo);
	}
	cout << count << endl;
	return 0;
}