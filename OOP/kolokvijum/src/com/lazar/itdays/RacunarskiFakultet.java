package com.lazar.itdays;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RacunarskiFakultet {

    private String nazivKonferencije;
    private ArrayList<Ucionica> ucionice;
    private ArrayList<Dogadjaj> dogadjaji;
    private ArrayList<Ucesnik> ucesniciKonferencije;
    private ArrayList<Kandidat> prijavljeniKandidati;

    public RacunarskiFakultet(String nazivKonferencije, ArrayList<Ucionica> ucionice) {
        this.nazivKonferencije = nazivKonferencije;
        this.ucionice = ucionice;

        dogadjaji = new ArrayList<>();
        ucesniciKonferencije = new ArrayList<>();
        prijavljeniKandidati = new ArrayList<>();
    }

    public ArrayList<Ucionica> getUcionice() {
        return ucionice;
    }

    public ArrayList<Dogadjaj> getDogadjaji() {
        return dogadjaji;
    }

    public ArrayList<Ucesnik> getUcesniciKonferencije() {
        return ucesniciKonferencije;
    }

    public ArrayList<Kandidat> getPrijavljeniKandidati() {
        return prijavljeniKandidati;
    }

    public void prijavaKandidata(String imeIPrezime, String grad) {
        prijavljeniKandidati.add(new Kandidat(imeIPrezime, grad));
    }

    private int brojMogucihMesta() {
        int brojMesta = 0;

        if(getUcionice() != null) {
            for(Ucionica u : getUcionice()) {
                brojMesta += u.getBrojMesta();
            }
        }

        return brojMesta;
    }

    private List<Glasanje> vratiDogadjajeGlasanje() {
        List<Glasanje> dogadjaji = new ArrayList<>();

        for(Dogadjaj d : getDogadjaji()) {
            if(d instanceof Glasanje) {
                dogadjaji.add((Glasanje) d);
            }
        }

        return dogadjaji;
    }

    public void polaganjeTesta() {
        for(Kandidat k : getPrijavljeniKandidati()) {
            k.polaganjeTesta();
        }

        Collections.sort(getPrijavljeniKandidati());

        for(int i = 0; i < brojMogucihMesta(); i++) {
            try {
                getUcesniciKonferencije().add(new Ucesnik(getPrijavljeniKandidati().get(i)));
            }catch(IndexOutOfBoundsException e) {
                break;
            }
        }
    }

    public void odaberiDogadjaje() {
        ArrayList<Glasanje> predavanja = (ArrayList<Glasanje>) vratiDogadjajeGlasanje();

        for(Ucesnik u : getUcesniciKonferencije()) {
            u.glasaj(predavanja);
        }

        Collections.sort(predavanja);

        /* todo
            1. Na osnovu rezultata glasanja određuju događaji koji će biti na seminaru.
               Voditi računa o tome da li predavanje zahteva projektor.

            2. Za radionice se ne glasa pa se one biraju u onom redosledu u kojem se pojavljuju u listi
               (prvih onoliko radionica koliko ima učionica sa racunarima)
        */
    }

    public void odstampajDogadjajeIUcesnike() {
        File out = new File("dogadjaji.txt");
        PrintWriter writer = null;

        try {
            writer = new PrintWriter(out);

            for(Dogadjaj d : getDogadjaji()) {
                writer.append(d.getNazivDogadjaja());
                writer.append(", ");
                writer.append(d.getImePredavaca());
                writer.append(", ");
                writer.append(d.getVremePocetka().toString());
                writer.append(", ");
                // todo stampaj ucionicu
                writer.append("\n");
            }
        }catch(IOException e) {
            e.printStackTrace();
        }finally {
            if(writer != null) {
                writer.flush();
                writer.close();
            }
        }

        out = new File("ucesnici.txt");
        writer = null;

        try {
            writer = new PrintWriter(out);

            for(Ucesnik u : getUcesniciKonferencije()) {
                writer.append(u.getImeIPrezime());
                writer.append(", ");
                writer.append(u.getKategorijaUcesnika().toString());
                writer.append("\n");
            }
        }catch(IOException e) {
            e.printStackTrace();
        }finally {
            if(writer != null) {
                writer.flush();
                writer.close();
            }
        }
    }
}