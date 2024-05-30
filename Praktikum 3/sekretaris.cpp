#include "sekretaris.h"
#include "exception.h"
#include <iostream>
using namespace std;

Sekretaris::Sekretaris(){
    this->energi = ENERGI_MAX;
    this->tinta = TINTA_DEFAULT;
    this->kertas = KERTAS_DEFAULT;
    this->memoLength = 0;
    this->memo = new Memo[500];
}

Sekretaris::Sekretaris(int kertas, int tinta){
    this->energi = ENERGI_MAX;
    this->tinta = tinta;
    this->kertas = kertas;
    this->memoLength = 0;
    this->memo = new Memo[500];
}

Sekretaris::~Sekretaris(){
    delete [] this->memo;
}

void Sekretaris::buatMemo(string pesan, string untuk){
    try {
        pakaiKertas();
        pakaiTinta(pesan.length());
        pakaiEnergi();
        Memo newMemo(pesan, untuk);
        this->memo[memoLength] = newMemo;
        cout << "Memo [" << memoLength+1 <<"] untuk "<< untuk <<" berhasil dibuat" <<endl;
        memoLength++;
    }
    catch (KertasHabisException& e){
        cout << e.what() << ", segera isi kertas" << endl;
    }
    catch (TintaKurangException& e){
        cout << e.what() << ", segera isi tinta" << endl;
        batalPakaiKertas();
    }
    catch (EnergiHabisException& e){
        cout << e.what() << ", segera istirahat" << endl;
        batalPakaiKertas();
        batalPakaiTinta(pesan.length());
    }
    catch (PesanKepanjanganException& e){
        cout << e.what() << ", perpendek pesannya";
        batalPakaiEnergi();
        batalPakaiKertas();
        batalPakaiTinta(pesan.length());
    }
}

void Sekretaris::pakaiKertas(){
    if (kertas <= 0){
        throw KertasHabisException();
    }
    kertas --;
}

void Sekretaris::pakaiTinta(int num){
    if (tinta < num){
        throw TintaKurangException();
    }
    tinta -= num;
}

void Sekretaris::pakaiEnergi(){
    if (energi <= 0){
        throw EnergiHabisException();
    }
    energi --;
}

void Sekretaris::batalPakaiKertas(){
    kertas ++;
}

void Sekretaris::batalPakaiTinta(int num){
    tinta += num;
}

void Sekretaris::batalPakaiEnergi(){
    energi ++;
}

void Sekretaris::isiTinta(int num){
    tinta += num;
}

void Sekretaris::isiKertas(int num){
    kertas += num;
}

void Sekretaris::istirahat(){
    energi = ENERGI_MAX;
}

void Sekretaris::printStatus(){
    cout <<"Status" << endl;
    cout <<"  Energi : "<< energi << endl;
    cout <<"  Tinta : "<< tinta << endl;
    cout <<"  Kertas : "<< kertas << endl;
    cout <<"  Memo : "<< memoLength <<endl;
    for (int i = 0; i < memoLength; i++){
        cout << "    Memo ["<<i+1<<"]"<< endl;
        cout << "      Pesan : "<< memo[i].getPesan() << endl;
        cout << "      Untuk : "<< memo[i].getUntuk() <<endl;
    }
}