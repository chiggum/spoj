#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i) {
		int a;
		string b;
		cin >> a >> b;
		if(a == 0) {
			cout << b << endl;
		} else {
			int rem = 0;
			for(int j = 0; j < b.size(); ++j) {
				rem = rem*10 + (b[j]-'0');
				rem = rem%a;
			}
			cout << gcd(a, rem) << endl;
		}
	}
	return 0;
}