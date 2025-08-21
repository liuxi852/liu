#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
using namespace std;
void windows(){
	system("chcp 936 > nul");
    
    string currentDir = "C:\\Users\\Administrator";
    
    cout << "Microsoft Windows [版本 10.0.22631.2715]" << endl;
    cout << "(c) Microsoft Corporation。保留所有权利。" << endl;
    cout << " " << endl; 
    system("title 命令提示符");  // 这里添加了分号
    while (true) {
        cout << currentDir << ">";
        
        string input;
        getline(cin, input);
        
        if (input == "exit") {
            break;
        }
        
        if (input.substr(0, 2) == "cd") {
            string newDir = input.substr(3);
            if (newDir.empty()) {
                cout << "请指定目录" << endl;
                continue;
            }
            
            if (newDir == "..") {
                size_t pos = currentDir.find_last_of("\\");
                if (pos != string::npos) {
                    currentDir = currentDir.substr(0, pos);
                }
            } else {
                currentDir += "\\" + newDir;
            }
            continue;
        }
        
        int result = system(input.c_str());
        cout << endl;
    }
}

