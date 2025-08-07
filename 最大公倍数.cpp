#include <iostream>
using namespace std;
long long a,b,c;
int main(){
  cin >> a >> b;
  while(true){
    c++;
    if(c = a * b){
      break;
    }
  }
  cout << c;
}
