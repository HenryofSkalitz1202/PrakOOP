#include <iostream>
using namespace std;



template <class T>
void func(T a, T b){
    cout << "Masukan Anda: "<< a <<" dan "<< b <<", memiliki tipe yang sama" << endl;
}

template <class T1, class T2>
void func(T1 a, T2 b){
    cout << "Masukan Anda: "<< a <<" dan "<< b <<", mungkin memiliki tipe yang berbeda" << endl;
}

template <>
void func<char,int>(char a, int b){
    for (int i = 0; i < b; i++){
        cout << a << endl;
    }
}