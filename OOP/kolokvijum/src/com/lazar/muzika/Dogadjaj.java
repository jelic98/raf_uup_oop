package com.lazar.muzika;

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
        Date datum = getVremePocetka();

        return datum.getDay() + "." + datum.getMonth() + "." + datum.getYear() + " "
                + datum.getHours() + ":" + datum.getMinutes() + " - " + getNaziv();
    }
}