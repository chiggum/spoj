#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int r,g,b,m;
		cin >> r >> g >> b >> m;
		int R=0, G=0, B=0;
		int x;
		for(int i = 0; i < r; ++i) {
			cin >> x;
			if(x > R)
				R = x;
		}
		for(int i = 0; i < g; ++i) {
			cin >> x;
			if(x > G)
				G = x;
		}
		for(int i = 0; i < b; ++i) {
			cin >> x;
			if(x > B)
				B = x;
		}
		bool already = false;
		for(int i = 0; i < m; ++i) {
			if(R>G) {
				if(R>B)
					R/=2;
				else
					B/=2;
			} else {
				if(G>B)
					G/=2;
				else
					B/=2;
			}
		}
		int ans;
		if(R>G) {
			if(R>B)
				ans=R;
			else
				ans=B;
		} else {
			if(G>B)
				ans=G;
			else
				ans=B;
		}
		cout << ans << endl;
	}
}