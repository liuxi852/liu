#include <iostream>
using namespace std;
void BubbleSort(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
    int arr[10] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};
    int temp;
	for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
	for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}
