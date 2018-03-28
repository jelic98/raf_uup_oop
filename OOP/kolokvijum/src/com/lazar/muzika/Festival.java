package com.lazar.muzika;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class Festival {

    private String naziv;
    private ArrayList<Dogadjaj> dogadjaji;

    public Festival(String naziv) {
        this.naziv = naziv;

        dogadjaji = new ArrayList<>();
    }

    public String getNaziv() {
        return naziv;
    }

    public boolean dodajDogadjaj(Dogadjaj dogadjaj) {
        dogadjaji.add(dogadjaj);

        return true;
    }

    public void odrziGlasanje() {
        Random random = new Random();

        ArrayList<Takmicenje> takmicenja = new ArrayList<>();
        ArrayList<Koncert> koncerti = new ArrayList<>();

        for(Dogadjaj d : dogadjaji) {
            if(d instanceof Takmicenje) {
                takmicenja.add((Takmicenje) d);
            }else if(d instanceof Koncert) {
                koncerti.add((Koncert) d);
            }
        }

        for(Takmicenje t : takmicenja) {
            for(Ucesnik u : t.getUcesnici()) {
                for(Koncert k : koncerti) {
                    if(random.nextInt(100) < 20) {
                        k.dodajGlas();
                    }
                }

                for(Takmicenje k : takmicenja) {
                    if(!(k instanceof Izbor)) {
                        continue;
                    }

                    for(Ucesnik ucesnik : t.getUcesnici()) {
                        if(!u.equals(ucesnik) && random.nextInt(100) < 30) {
                            ucesnik.dodajGlas();
                        }
                    }
                }
            }
        }
    }

    public void ispisiProgram(String nazivFajla) {
        File out = new File(nazivFajla);
        PrintWriter writer = null;

        try {
            writer = new PrintWriter(out);

            Collections.sort(dogadjaji);

            for(Dogadjaj d : dogadjaji) {
                writer.append(d.toString());
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

    public void ispisiRangListe() {
        File out = new File("rang_lista.txt");
        PrintWriter writer = null;

        try {
            writer = new PrintWriter(out);

            Collections.sort(dogadjaji);

            for(Dogadjaj d : dogadjaji) {
                if(d instanceof Turnir) {
                    Turnir turnir = (Turnir) d;

                    writer.append(turnir.getNaziv());
                    writer.append(" - ");
                    writer.append(turnir.odrediPobednika().toString());
                    writer.append("\n");
                }else if(d instanceof Izbor) {
                    Izbor izbor = (Izbor) d;

                    writer.append(izbor.getNaziv());
                    writer.append("\n");

                    ArrayList<Ucesnik> ucesnici = izbor.getUcesnici();

                    Collections.sort(ucesnici);

                    for(int i = 0; i < ucesnici.size(); i++) {
                        Ucesnik u = ucesnici.get(i);

                        writer.append(String.valueOf(i));
                        writer.append(". ");
                        writer.append(u.toString());
                        writer.append(" – ");
                        writer.append(String.valueOf(u.getBrojGlasova()));
                        writer.append("\n");
                    }
                }
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