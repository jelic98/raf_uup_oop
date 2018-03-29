package com.lazar.itdays;

import java.util.Date;

public class Predavanje extends Dogadjaj implements Glasanje {

    private int brojGlasova;
    private boolean potrebanProjektor;

    public Predavanje(String nazivDogadjaja, String imePredavaca, Date vremePocetka, boolean potrebanProjektor) {
        super(nazivDogadjaja, imePredavaca, vremePocetka);

        this.potrebanProjektor = potrebanProjektor;
    }

    public int getBrojGlasova() {
        return brojGlasova;
    }

    public boolean isPotrebanProjektor() {
        return potrebanProjektor;
    }

    @Override
    public void glasaj() {
        brojGlasova++;
    }

    @Override
    public int compareTo(Object o) {
        try {
            return getBrojGlasova() - ((Predavanje) o).getBrojGlasova();
        }catch(ClassCastException e) {
            return 0;
        }
    }
}
