#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    string input;
    cout << "junyu os [版本 1.3.5]" << endl;
    cout << "(c) juyu Corporation。保留所有权利。" << endl;
    
    while (true) {
        cout << ">>";
        getline(cin, input);
        
        // 处理用户输入exit命令退出
        if (input == "exit") {
            break;
        }
        
        // 执行系统命令
        system(input);
        
    }
}


