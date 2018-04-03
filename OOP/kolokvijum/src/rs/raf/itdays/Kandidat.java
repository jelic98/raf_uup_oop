package rs.raf.itdays;

public class Kandidat implements Comparable, Test {

    private String imeIPrezime, grad;
    private int brojPoena;

    public Kandidat(String imeIPrezime, String grad) {
        this.imeIPrezime = imeIPrezime;
        this.grad = grad;
    }

    public String getImeIPrezime() {
        return imeIPrezime;
    }

    public String getGrad() {
        return grad;
    }

    public int getBrojPoena() {
        return brojPoena;
    }

    @Override
    public void polaganjeTesta() {

    }

    @Override
    public int compareTo(Object o) {
        try {
            return getBrojPoena() - ((Kandidat) o).getBrojPoena();
        }catch(ClassCastException e) {
            return 0;
        }
    }

    @Override
    public String toString() {
        return getClass().getSimpleName() + ": " + getImeIPrezime() + " " + getGrad() + " " + getBrojPoena();
    }
}