abstract class TempatTinggal{
    protected int luas;
    protected double hargaBahanBangunan;
    public void setLuas(int luas){
        this.luas = luas;
    }

    public void setHargaBahanBangunan(double hargaBahanBangunan){
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public int getLuas(){
        return this.luas;
    }

    public double getHargaBahanBangunan(){
        return this.hargaBahanBangunan;
    }

    public double hitungBiayaBangun(){
        double biayaBangun = this.luas * hargaBahanBangunan;
        return biayaBangun;
    }
}

class Rumah extends TempatTinggal{
    public Rumah(int luas, double hargaBahanBangunan){
        this.luas = luas;
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public Rumah(int lebar, int panjang, double hargaBahanBangunan){
        this.luas = lebar * panjang;
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public void setLuas(int panjang, int lebar){
        this.luas = panjang * lebar;
    }

    public double hitungBiayaBangun(double ormas){
        double biayaBangun = hitungBiayaBangun() + ormas;
        return biayaBangun;
    }
}

interface Kendaraan{
    public float hitungJarakTempuh();
}

class Karavan extends TempatTinggal implements Kendaraan{
    private float bensin;
    private float pemakaianBensin;

    public void setBensin(float bensin){
        this.bensin = bensin;
    }

    public void setPemakaianBensin(float pemakaianBensin){
        this.pemakaianBensin = pemakaianBensin;
    }

    public float getBensin(){
        return this.bensin;
    }

    public float getPemakaianBensin(){
        return this.pemakaianBensin;
    }

    public double hitungBiayaBangun(){
        return this.luas * this.hargaBahanBangunan * 3;
    }

    public float hitungJarakTempuh(){
        float jarakTempuh = this.bensin * this.pemakaianBensin;
        return jarakTempuh;
    }
}