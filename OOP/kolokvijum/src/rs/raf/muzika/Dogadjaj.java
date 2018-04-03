package rs.raf.muzika;

import java.util.Calendar;
import java.util.Date;

public abstract class Dogadjaj implements Comparable {

    private String naziv;
    private Date vremePocetka;

    public Dogadjaj(String naziv, Date vremePocetka) {
        this.naziv = naziv;
        this.vremePocetka = vremePocetka;
    }

    public String getNaziv() {
        return naziv;
    }

    public Date getVremePocetka() {
        return vremePocetka;
    }

    @Override
    public int compareTo(Object o) {
        try {
            return getVremePocetka().compareTo(((Dogadjaj) o).getVremePocetka());
        }catch(ClassCastException e) {
            return 0;
        }
    }

    // pozvace se samo ako se radi o anonimnoj klasi
    @Override
    public String toString() {
        Calendar cal = Calendar.getInstance();
        cal.setTime(getVremePocetka());

        int year = cal.get(Calendar.YEAR);
        int month = cal.get(Calendar.MONTH) + 1;
        int day = cal.get(Calendar.DAY_OF_MONTH);
        int hour = cal.get(Calendar.HOUR_OF_DAY);
        int minute = cal.get(Calendar.MINUTE);

        return day + "." + month + "." + year + " " + hour + ":" + minute + " - " + getNaziv();
    }
}