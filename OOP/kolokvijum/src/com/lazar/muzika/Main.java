package com.lazar.muzika;

import java.util.Date;

public class Main {

    public static void main(String[] args) {
        Festival festival = new Festival("EXIT");

        Koncert koncert1 = new Koncert("Samo ljubav", new Date(1, 1, 2018), "Hot Dog");
        Koncert koncert2 = new Koncert("Rokenrolcina klasicna", new Date(2, 10, 1998), "Brackica");
        Koncert koncert3 = new Koncert("Nesto chill", new Date(12, 3, 2014), "Kobaja Grande");

        festival.dodajDogadjaj(koncert1);
        festival.dodajDogadjaj(koncert2);
        festival.dodajDogadjaj(koncert3);

        Turnir turnir = new Turnir("Turnin brate", new Date(5, 10, 2018));
        Izbor izbor = new Izbor("Eurovision", new Date(10, 5, 2018));

        festival.dodajDogadjaj(turnir);
        festival.dodajDogadjaj(izbor);

        Ucesnik muzicar1 = new Ucesnik("Kobaja Grande", TipUcesnika.MUZICAR);
        Ucesnik muzicar2 = new Ucesnik("Brackica", TipUcesnika.MUZICAR);
        Ucesnik muzicar3 = new Ucesnik("PSY", TipUcesnika.MUZICAR);
        Ucesnik muzicar4 = new Ucesnik("FOX", TipUcesnika.MUZICAR);
        Ucesnik muzicar5 = new Ucesnik("The Glitch Mob", TipUcesnika.MUZICAR);

        izbor.dodajUcesnika(muzicar1);
        izbor.dodajUcesnika(muzicar2);
        izbor.dodajUcesnika(muzicar3);
        izbor.dodajUcesnika(muzicar4);
        izbor.dodajUcesnika(muzicar5);

        turnir.dodajUcesnika(muzicar1);
        turnir.dodajUcesnika(muzicar2);
        turnir.dodajUcesnika(muzicar3);
        turnir.dodajUcesnika(muzicar4);
        turnir.dodajUcesnika(muzicar5);

        Ucesnik gost1 = new Ucesnik("Paja Patak", TipUcesnika.GOST);
        Ucesnik gost2 = new Ucesnik("Miki Maus", TipUcesnika.GOST);
        Ucesnik gost3 = new Ucesnik("Mini Maus", TipUcesnika.GOST);
        Ucesnik gost4 = new Ucesnik("Snupi", TipUcesnika.GOST);
        Ucesnik gost5 = new Ucesnik("Sundjer Bob", TipUcesnika.GOST);

        turnir.dodajUcesnika(gost1);
        turnir.dodajUcesnika(gost2);
        turnir.dodajUcesnika(gost3);
        turnir.dodajUcesnika(gost4);
        turnir.dodajUcesnika(gost5);

        festival.odrziGlasanje();
        festival.ispisiProgram("ispis_programa.txt");
        festival.ispisiRangListe();
    }
}