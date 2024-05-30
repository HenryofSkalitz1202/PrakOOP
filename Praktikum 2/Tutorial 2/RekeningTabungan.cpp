#include "RekeningTabungan.h"

RekeningTabungan::RekeningTabungan(double saldo, double biayaTransaksi) : Rekening(saldo) {
    if (biayaTransaksi < 0) {
        this->biayaTransaksi = 0.0;
    }
    else {
        this->biayaTransaksi = biayaTransaksi;
    }
}

void RekeningTabungan::setBiayaTransaksi(double biayaTransaksi) {
    this->biayaTransaksi = biayaTransaksi;
}

double RekeningTabungan::getBiayaTransaksi() const {
    return this->biayaTransaksi;
}

void RekeningTabungan::simpanUang(double nominal) {
    Rekening::simpanUang(nominal - this->biayaTransaksi);
}

bool RekeningTabungan::tarikUang(double nominal) {
    bool valid = Rekening::tarikUang(nominal);
    if (valid) {
        Rekening::setSaldo(this->getSaldo() - this->biayaTransaksi);
    }
    return valid;
}