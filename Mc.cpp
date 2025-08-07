#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    string mc[10] = {"基岩", "岩浆", "羊毛", "仙人掌", "黑曜石", "草块", "石头", "木头", "TNT", "引线"};
    int x = 0;
    int y = 0;
    int p, e, r = 0, w, q;

    while (true) {
        if (r != 1) {
            cout << "是否开启管理员？（管理员也会死）1.Yes 2.No" << endl;
            cin >> r;
            if (r == 1) {
                cout << "管理员密码" << endl;
                cin >> r;
                if (r == 114514) {
                    cout << "已开启" << endl;
                    r = 1;
                } else {
                    cout << "密码错误，未开启。" << endl;
                    r = 0;
                }
            }
        }

        if (r == 1) {
            cout << "删除方块？" << endl;
            cin >> w;
        }
		if (w == 1) {
            cin >> q;
            mc[q - 1] = "";
        }
		while (y != 0 && y > 0) {
            if (y > 50 && y < 80) {
                y -= 2;
            }
            if (y > 0 && y < 50 && y < 80) {
                y--;
            }
            if (y > 80) {
                y -= 3;
            }
            if (y < 1) {
                break;
            }
        }

        if (x >= 0 && x < 10) {
            cout << "当前方块: " << mc[x] << endl;
        } else {
            cout << "当前方块：草块" << endl;
        }

        if (x == 3) {
            cout << "你死了，因为被仙人掌刺死了。死亡代码：mc_Cactus" << endl;
            return 0;
        }

        if (x == 1) {
            cout << "你死了，因为碰到了岩浆。死亡代码：mc_Magma" << endl;
            return 0;
        }

        if (x == 9) {
            cout << "是否点燃TNT? 1.Yes 2.No" << endl;
            cin >> e;
        }

        switch (e) {
            case 1:
                cout << "你用引线点燃了TNT" << endl;
                cout << "呲呲呲呲呲呲......" << endl;
                Sleep(1000);
                cout << "你被TNT炸死了，死亡代码：mc_TNT" << endl;
                return 0;
        }

        cout << "1.x++\n2.x--\n3.y++\n4.y--\n其他.无选择。" << endl;
        if (x == 0 || x == 2 || r == 1) {
            cout << "5.x+2" << endl;
        }

        cin >> p;
        switch (p) {
            case 1: x++; break;
            case 2: x--; break;
            case 3: y++; break;
            case 4: if (y > 0) { y--; } break;
            case 5: if (x == 0 || x == 2) { y++; x += 2; } break;
        }

        cout << "x:" << x << " y:" << y << endl;
    }
}
