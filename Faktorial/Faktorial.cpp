#include <iostream>

using namespace std;

int main(){
    int zadani;
    int vysledek = 1;
    cout<<"Zadej faktorial: ";
    cin>>zadani;
    for(int i =1;i<=zadani;i++ ){
        vysledek*=i;
    }
    cout<<"Faktorial "<<zadani<<" je roven "<<vysledek;

}