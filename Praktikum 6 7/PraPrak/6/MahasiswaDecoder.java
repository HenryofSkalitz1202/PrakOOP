import java.lang.reflect.*;

public class MahasiswaDecoder {
  private Mahasiswa mahasiswa;

  MahasiswaDecoder(Mahasiswa mahasiswa) {
    this.mahasiswa = mahasiswa;
  }

  public void addMatkul(String name) throws Exception {
    Class<? extends Mahasiswa> studentClass = this.mahasiswa.getClass();

    Method method = studentClass.getDeclaredMethod("addMatkul", String.class);
    method.setAccessible(true);
    method.invoke(this.mahasiswa, name);
  }

  public int getNIM() throws Exception {
    Class<? extends Mahasiswa> studentClass = this.mahasiswa.getClass();

    Field field = studentClass.getDeclaredField("NIM");
    field.setAccessible(true);
    int nim = (Integer) field.get(this.mahasiswa);

    return nim;
  }

  public double getIPK() throws Exception {
    Class<? extends Mahasiswa> studentClass = this.mahasiswa.getClass();

    Field field = studentClass.getDeclaredField("IPK");
    field.setAccessible(true);
    double ipk = (Double) field.get(this.mahasiswa);

    return ipk;
  }
}