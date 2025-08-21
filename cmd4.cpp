#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	string input; 
	cout << "Microsoft Windows [版本 10.0.22631.2715]" << endl;
    cout << "(c) Microsoft Corporation。保留所有权利。" << endl;
    cout << " " << endl; 
    system("title 命令提示符");
	while(true) {
		cout << ">";
		cin >> input; 
		getline(cin, input);	
        int result = system(input.c_str());
		cout << " " << endl;
		if(input == " ") {
			break;
		}
		if(input == "") {
			continue;
		}
	}
}
