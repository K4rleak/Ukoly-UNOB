#include <stdlib.h>
#include <iostream>  
#include <string>   
#include <time.h> 

using namespace std;

struct Matice{
int ** matrix;
int radky;
int sloupce;
};

void Zadani(int* rad1, int* sloup1, int* rad2, int* sloup2);
Matice Random(int rad, int sloup);
void Tisk(Matice matice, int rad, int sloup);
void Soucet(Matice mat1,Matice mat2);
void Soucin(Matice mat1,Matice mat2);

int main(){
srand (time(NULL));
Matice mat1,mat2,mat3,mat4;
int rad1, rad2, sloup1, sloup2;
Zadani(&rad1, &sloup1, &rad2, &sloup2);
mat1=Random(rad1, sloup1);
mat2=Random(rad2, sloup2);
cout<<"1.Matice\n";
Tisk(mat1, rad1, sloup1);
cout<<"2.Matice\n";
Tisk(mat2, rad2, sloup2);
Soucet(mat1,mat2);
Soucin(mat1,mat2);
getchar();
getchar();
return 0;
}

void Zadani(int* rad1, int* sloup1, int* rad2, int* sloup2){
    cout<<"Zadej 1. radek: "; cin>>*rad1;
    cout<<"Zadej 1. sloupec: "; cin>>*sloup1;
    cout<<"Zadej 2. radek: "; cin>>*rad2;
    cout<<"Zadej 2. sloupec: "; cin>>*sloup2;
}

Matice Random(int rad, int sloup){
    Matice matice;
    matice.radky=rad;
    matice.sloupce=sloup;
    int** pole = new int* [rad];
        for(int i=0; i<rad; i++)
    {
        pole[i] = new int[sloup];
    }
    for (int o=0; o<rad; o++)
    {
        for (int j=0; j<sloup; j++)
        {
           pole[o][j]=rand() % 10;
        }
    }
    matice.matrix=pole;
    return matice;
}

void Tisk(Matice matice, int rad, int sloup){
    for(int i=0;i<rad;i++){
        cout<<"{";
    for(int o=0;o<sloup;o++){
        cout<<matice.matrix[i][o]<<" ";
    }
    cout<<"}";
    cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

void Soucet(Matice mat1,Matice mat2){
    if(mat1.radky==mat2.radky && mat1.sloupce==mat2.sloupce){
    Matice vysl=Random(mat1.radky,mat1.sloupce);
    for(int i=0;i<mat1.radky;i++){
    for(int o=0;o<mat1.sloupce;o++){
       vysl.matrix[i][o]=mat1.matrix[i][o]+mat2.matrix[i][o];
    }
    }
    cout<<"Soucet matic je: \n";
    Tisk(vysl,vysl.radky,vysl.sloupce);
    }
    else{
        cout<<"Soucet matic je: \n";
        cout<<"Pocet radku a sloupcu neni stejny\n\n";
    }
}

void Soucin(Matice mat1,Matice mat2){
    if(mat1.sloupce==mat2.radky){
    Matice vysl=Random(mat1.radky,mat2.sloupce);
    for(int i=0;i<mat1.radky;i++){
    for(int j=0;j<mat2.sloupce;j++){
        vysl.matrix[i][j]=0;
        for(int k=0;k<mat2.sloupce;k++){
            vysl.matrix[i][j] += mat1.matrix[i][k] * mat2.matrix[k][j];
            }
    }
    }
    cout<<"Soucin matic je: \n";
    Tisk(vysl,vysl.radky,vysl.sloupce);
}
    else{
        cout<<"Soucin matic je: \n";
        cout<<"Počet sloupců 1.matice není roven počtu řádků 2. matice!!"<<endl;
    }

}