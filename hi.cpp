#include <iostream>;
using namespace std;
void axaddb (int a, int b){
    float x;
    x = (float) -b/ a;
    if(a == 0){
        cout << "Phuong trinh ax+b = 0 vo nghiem";
    }
    else{
        cout << "Phuong trinh co nghiem la:" << x;
}
}
int main(){
    axaddb(6,1);
    return 0;
}