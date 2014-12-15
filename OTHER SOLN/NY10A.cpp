#include <iostream>
#include <map>

using namespace std;

int main() {
	int T;
	string targ[] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
	cin >> T;
	for(int i = 0; i < T; ++i) {
		int n;
		cin >> n;
		cout << n << " ";
		string x;
		cin >> x;
		map<string, int> myMap;
		for(int j = 0; j < 8; ++j) {
			myMap[targ[j]] = 0;
		}
		for(int j = 0; j < x.length()-2; ++j) {
			myMap[x.substr(j, 3)]+=1;
		}
		for(int j = 0; j < 8; ++j) {
			if(j != 7)
				cout << myMap[targ[j]] << " ";
			else
				cout << myMap[targ[j]] << endl;
		}
	}
	return 0;
}