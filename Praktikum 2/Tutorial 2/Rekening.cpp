#include "Rekening.h"

Rekening::Rekening(double saldo) {
    if (saldo < 0) {
        this->saldo = 0.0;
    }
    else {
        this->saldo = saldo;
    }
}

void Rekening::setSaldo(double saldo) {
    this->saldo = saldo;
}

double Rekening::getSaldo() const {
    return this->saldo;
}

void Rekening::simpanUang(double nominal) {
    this->saldo += nominal;
}

bool Rekening::tarikUang(double nominal) {
    if (this->saldo >= nominal) {
        this->saldo -= nominal;
        return true;
    }
    else {
        return false;
    }
}
