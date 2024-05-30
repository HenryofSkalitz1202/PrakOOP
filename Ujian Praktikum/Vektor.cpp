#include "Vektor.hpp"

/*
set n = 0 dan vektor tetap kosong
*/
Vektor::Vektor(){
    this->n = 0;
}

/*
set n = _n dan vektor berisi _n elemen dengan setiap elemennya bernilai 0
*/
Vektor::Vektor(int _n){
    this->n = _n;
    for (int i = 0; i < _n; i++){
        this->vektor.push_back(0);
    }
}

// cctor
Vektor::Vektor(const Vektor &v){
    this->n = v.n;
    int size = vektor.size();
    for(int i = 0; i < this->vektor.size(); i++){
        this->vektor[i] = v.vektor[i];
    }
}

// dtor
Vektor::~Vektor(){}

/*
Set elemen ke-idx (0<=idx<n) dari vektor menjadi x
idx dijamin valid
*/
void Vektor::setElmt(int idx,int x){
    this->vektor[idx] = x;
}

int Vektor::getN(){
    return this->n;
} // menghasilkan n (ukuran vektor)

/*
operasi penjumlahan 2 vektor yang menghasilkan sebuah objek vektor baru, ukuran kedua vektor dijamin sama
misal
v1 = [1,2,3]
v2 = [3,7,9]
v1 + v2 = [4,9,12]
*/
Vektor operator+(const Vektor &v1,const Vektor &v2){
    Vektor v(v1.n);
    for(int i = 0; i < v1.n; i++){
        v.vektor[i] = v1.vektor[i] + v2.vektor[i];
    }

    return v;
}

/*
operasi pengurangan 2 vektor yang menghasilkan sebuah objek vektor baru, ukuran kedua vektor dijamin sama
misal
v1 = [1,2,3]
v2 = [3,7,9]
v1 - v2 = [-2,-5,-6]
*/
Vektor operator-(const Vektor &v1,const Vektor &v2){
    Vektor v(v1.n);
    for(int i = 0; i < v1.n; i++){
        v.vektor[i] = v1.vektor[i] - v2.vektor[i];
    }

    return v;
}

/*
operasi dot product 2 vektor, ukuran kedua vektor dijamin sama
misal
v1 = [1,2,3]
v2 = [3,7,9]
v1 * v2 = 1*3+2*7+3*9 = 44
*/
int operator*(const Vektor &v1,const Vektor &v2){
    int sum_kali = 0;

    for(int i = 0; i < v1.n; i++){
        sum_kali += v1.vektor[i] * v2.vektor[i];
    }

    return sum_kali;
}

// mengecek apakah kedua vektor memiliki ukuran yang sama dan setiap elemennya bernilai sama
bool operator==(const Vektor &v1,const Vektor &v2){
    bool status = true;

    for(int i = 0; i < v1.n; i++){
        bool temp_status = (v1.vektor[i] == v2.vektor[i]);
        status = status & temp_status;
    }

    return status;
}

/*
menampilkan vektor dalam format <v[0],v[1],...,v[n-1]> dan diakhiri dengan newline
misal v1 = [1,3,5]
hasil print = <1,3,5>
*/
void Vektor::printVektor(){
    cout << "<";
    for(int i = 0; i < this->n; i++){
        cout << this->vektor[i];
        if(i != this->n - 1){
            cout << ",";
        }
    }
    cout << ">" << endl;
}

// int main(){
//     Vektor v1(4);
//     Vektor v2(4);
//     v1.setElmt(1,2);
//     v1.setElmt(0,3);
//     v1.setElmt(2,5);
//     v2.setElmt(1,4);
//     v2.setElmt(2,3);
//     v1.printVektor();
//     v2.printVektor();
//     Vektor v3 = v1 + v2;
//     Vektor v4 = v1 - v2;
//     v3.printVektor();
//     v4.printVektor();
// }