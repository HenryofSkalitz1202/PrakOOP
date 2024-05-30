#include "RestoranRamen.hpp"

void RestoranRamen::tambahOrder(int n, int p){
    // map<int,int>::iterator itr = daftarMeja.begin();
    // itr = daftarMeja.find(n);
    if (daftarMeja.find(n) != daftarMeja.end()){
        daftarMeja[n] += p;
    } 
    else {
        daftarMeja[n] = p;
    }
}

int RestoranRamen::tutupOrder(int n){
    // map<int,int>::iterator itr = daftarMeja.begin();
    // itr = daftarMeja.find(n);
    if (daftarMeja.find(n) != daftarMeja.end()){
        int harga = daftarMeja[n];
        daftarMeja.erase(n);
        return harga;
    } 
    else {
        return 0;
    }

}

int RestoranRamen::cekTotal(int n){
    // map<int,int>::iterator itr = daftarMeja.begin();
    // itr = daftarMeja.find(n);
    if (daftarMeja.find(n) != daftarMeja.end()){
        int harga = daftarMeja[n];
        return harga;
    } 
    else {
        return 0;
    }
}

int RestoranRamen::totalMeja(){
    // map<int,int>::iterator itr = daftarMeja.begin();
    // int count = 0;
    // while (itr != daftarMeja.end()){
    //     count++;
    // }
    // return count;
    return daftarMeja.size();
}

void RestoranRamen::cetakMeja(){
    // map<int,int>::iterator itr = daftarMeja.begin();
    // int count = 0;
    // while (itr != daftarMeja.end()){
    //     cout << "Meja " << itr->first <<" = "<<itr->second<<endl;
    //     count++;
    // }
    // if (count == 0){
    //     cout << "Restoran kosong" << endl;
    // }
    if (daftarMeja.empty()){
        cout << "Restoran kosong" << endl;
    } 
    else {
        for (auto i = daftarMeja.begin(); i != daftarMeja.end(); i++){
            cout << "Meja " << i->first <<" = "<<i->second<<endl;
        }
    }
}