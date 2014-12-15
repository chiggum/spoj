#include <iostream>

using namespace std;

int main() {
	int x;
	while(1) {
		cin >> x;
		if(x == -1)
			break;
		int *y = new int[x];
		int sum = 0;
		for(int i = 0; i < x; ++i) {
			int z;
			cin >> z;
			sum+=z;
			y[i] = z;
		}
		int count = 0;
		if((1.0*sum)/x != sum/x) {
			cout << -1 << endl;
			continue;
		}
		int avg = sum/x;
		for(int i = 0; i < x; ++i) {
			if(y[i] < avg)
				count += avg-y[i];
		}
		cout << count << endl;
	}
}