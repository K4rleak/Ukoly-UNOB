#include <iostream>
using namespace std;

void prohozeni(int* a, int* b){
    int temp=*b;
    *b=*a;
    *a=temp;
}

int main(){
    int a=1;
    int b=2;
    prohozeni(&a,&b);
}