#include "Base.hpp"

class Pakaian : public Base {
protected:
  std::string pemilik;
  float ukuran;

public:
  Pakaian(){}
  Pakaian(std::string pemilik, float ukuran){
    this->pemilik = pemilik;
    this->ukuran = ukuran;
  }

  ~Pakaian(){
    std::cout << "[D] Pakaian milik '" << this->pemilik << "' hancur" << std::endl;
  }

  virtual void pakai() = 0;

protected:
  std::ostream &status() {
    std::cout << "Pakaian milik '" << this->pemilik << "' dengan ukuran " << this->ukuran;
    return std::cout;
  }
};

class Baju : public Pakaian {
public:
  static int defaultTahun;
  static int defaultUkuran;

protected:
  //const int tahun;
  int tahun;

public:
  Baju(){
    this->ukuran = defaultUkuran;
    this->tahun = defaultTahun;
    this->pemilik = "anonim";
  }

  Baju(std::string pemilik, float ukuran, int tahun){
    this->pemilik = pemilik;
    this->ukuran = ukuran;
    this->tahun = tahun;
  }

  void pakai(){
    std::cout << this->pemilik << " pake baju dari atas" << std::endl;
  }

  virtual ~Baju(){
    std::cout << "[D] Baju milik '" << this->pemilik << "' hancur" << std::endl;
  }

protected:
  std::ostream &status() {
    std::cout << "Pakaian milik '" << this->pemilik << "' dengan ukuran " << this->ukuran << " tahun " << this->tahun;
    return std::cout;
  }
};

class BajuPolo : public Baju {
private:
  static int jumlah;

protected:
  double panjangKerah = 0.5;
  int keluaranKe;

public:
  BajuPolo(std::string pemilik, int tahun){
    this->pemilik = pemilik;
    this->tahun = tahun;
    //jumlah++;
  }

  BajuPolo(std::string pemilik, int tahun, double panjangKerah){
    this->pemilik = pemilik;
    this->tahun = tahun;
    this->panjangKerah = panjangKerah;
    //jumlah++;
  }

  BajuPolo(BajuPolo &other){
    this->pemilik = other.pemilik;
    this->ukuran = other.ukuran;
    this->tahun = other.tahun;
    this->panjangKerah = other.panjangKerah;
    this->keluaranKe = other.keluaranKe;
    //jumlah++;
  }

  //lengkap 7 10 10 10
  //ilang pemilik_tahun 5 8 8 8
  //ilang panjangkerah 7 9 9 9
  //ilang other 7 10 10 10
  //status aja 6 7 8 9


  ~BajuPolo(){
    std::cout << "[D] Baju Polo milik '" << this->pemilik << "' hancur" << std::endl;
  }

protected:
  std::ostream &status(){
    jumlah++;
    std::cout << "Pakaian milik '" << this->pemilik << "' dengan ukuran " << this->ukuran << " tahun " << this->tahun << " dengan panjang kerah " << this->panjangKerah << " keluaran ke-" << jumlah;
    return std::cout;
  }
};

class Celana : public Pakaian {
private:
  bool pakeSabuk;

public:
  Celana(std::string pemilik, float ukuran, bool pakeSabuk){
    this->pemilik = pemilik;
    this->ukuran = ukuran;
    this->pakeSabuk = pakeSabuk;
  }

  Celana(Celana &other, std::string pemilikBaru){
    this->pemilik = pemilikBaru;
    this->ukuran = other.ukuran;
    this->pakeSabuk = other.pakeSabuk;
  }

  void pakai(){
    std::cout << this->pemilik << " pake celana dari bawah";

    if(this->pakeSabuk){
      std::cout << " dengan sabuk";
    }

    std::cout << std::endl;
  }

  ~Celana(){
    std::cout << "[D] Celana milik '" << this->pemilik << "' hancur" << std::endl;
  }

protected:
  std::ostream &status(){
    std::cout << "Pakaian milik '" << this->pemilik << "' dengan ukuran " << this->ukuran;

    if(this->pakeSabuk){
      std::cout << " dengan sabuk";
    }
    return std::cout;
  }
};
