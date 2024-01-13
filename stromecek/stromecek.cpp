#include <iostream>
using namespace std;

int main(){
    int vetve, kmen;

    cout<<"Zadej vysku vetvi: ";
    cin>>vetve;
    cout<<"Zadej vysku kmene: ";
    cin>>kmen;

    for(int i=1;i<=vetve;i++){
        for(int o=0;o<vetve-i;o++)
        cout<<" ";
        for(int a=0;a<i*2-1;a++)
        cout<<"*";
    cout<<endl;
    }

    for(int i=0;i<kmen;i++){
        for(int o=0;o<vetve-1;o++)
        cout<<" ";
        cout<<"#"<<endl;
    }

    getchar();
    getchar();

}
