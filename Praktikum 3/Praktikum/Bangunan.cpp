#include "Exception.hpp"
#include "Bangunan.hpp"
#include <iostream>
using namespace std;

Bangunan::Bangunan(){}

Bangunan::Bangunan(string namaBangunan){
    this->namaBangunan = namaBangunan;
}

string Bangunan::getNamaBangunan(){
    return this->namaBangunan;
}