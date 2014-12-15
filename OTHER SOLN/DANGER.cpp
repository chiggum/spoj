#include <iostream>
#include <cmath>

using namespace std;

int getSafe(int num, int pos, int inc) {
	if(num == 2)
		return pos;
	else if(num == 1)
		return pos ;
	else if(num%2==1)
		return getSafe((num-1)/2, pos+inc, inc*2);
	else 
		return getSafe(num/2, pos, inc*2);
}

int main() {
	string x;
	while(getline(cin, x)) {
		if(x == "00e0")
			break;
		int t;
		t = pow(10, x[3]-'0');
		t *= (10*(x[0]-'0') + x[1]-'0');
		cout << getSafe(t, 1, 2) << endl;
	}
	return 0;
}