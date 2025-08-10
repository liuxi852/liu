#include <iostream>
#include <string>
using namespace std;
string pojie(){
	string a;
	int b = -1,c = 0;
	cin >> a;
	while(true){
		b++;
		if(b == a[c]){
			c++;
			b = -1;
			if(c == a.length()){
				break;
			}
		}
	}
	return a;
}
int main(){
	cout << pojie();
}
