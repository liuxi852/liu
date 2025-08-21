#include <iostream>
using namespace std;

int main() {
	int num,unitsDigit,tensDigit,hundredsDigit,sum;
	
	cin >> num;
	hundredsDigit = num / 100;
	tensDigit = num % 100 / 10;
	unitsDigit = num % 10;
	sum = hundredsDigit +tensDigit + unitsDigit;
	printf("%d + %d + %d = %d",hundredsDigit,tensDigit,unitsDigit,sum);
	
	return 0;
}
