#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    string mc[10] = {"����", "�ҽ�", "��ë", "������", "����ʯ", "�ݿ�", "ʯͷ", "ľͷ", "TNT", "����"};
    int x = 0;
    int y = 0;
    int p, e, r = 0, w, q;

    while (true) {
        if (r != 1) {
            cout << "�Ƿ�������Ա��������ԱҲ������1.Yes 2.No" << endl;
            cin >> r;
            if (r == 1) {
                cout << "����Ա����" << endl;
                cin >> r;
                if (r == 114514) {
                    cout << "�ѿ���" << endl;
                    r = 1;
                } else {
                    cout << "�������δ������" << endl;
                    r = 0;
                }
            }
        }

        if (r == 1) {
            cout << "ɾ�����飿" << endl;
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
            cout << "��ǰ����: " << mc[x] << endl;
        } else {
            cout << "��ǰ���飺�ݿ�" << endl;
        }

        if (x == 3) {
            cout << "�����ˣ���Ϊ�������ƴ����ˡ��������룺mc_Cactus" << endl;
            return 0;
        }

        if (x == 1) {
            cout << "�����ˣ���Ϊ�������ҽ����������룺mc_Magma" << endl;
            return 0;
        }

        if (x == 9) {
            cout << "�Ƿ��ȼTNT? 1.Yes 2.No" << endl;
            cin >> e;
        }

        switch (e) {
            case 1:
                cout << "�������ߵ�ȼ��TNT" << endl;
                cout << "������������......" << endl;
                Sleep(1000);
                cout << "�㱻TNTը���ˣ��������룺mc_TNT" << endl;
                return 0;
        }

        cout << "1.x++\n2.x--\n3.y++\n4.y--\n����.��ѡ��" << endl;
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
