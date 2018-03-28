#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Knjiga {
	char naziv[SIZE];
	char autor[SIZE];
	char isbn[SIZE];
	char izdavac[SIZE];
	struct Knjiga* levo;
	struct Knjiga* desno;
} Knjiga;

Knjiga* koren = NULL;

Knjiga* novaKnjiga() {
	Knjiga* k = (Knjiga*) malloc(sizeof(Knjiga));

	if(!k) {
		printf("Greska: Nedovoljno memorije\n");
		exit(1);
	}	

	return k;
}

void ubaci(Knjiga* koren, Knjiga* cvor) {
	if(!koren) {
		extern Knjiga* koren;
		koren = cvor;
		return;	
	}

	int cmp = strcmp(koren->naziv, cvor->naziv);

	if(cmp < 0) {
		if(!koren->desno) {
			koren->desno = cvor;
		}else {
			ubaci(koren->desno, cvor);
		}
	}else if(cmp > 0) {
		if(!koren->levo) {
			koren->levo = cvor;
		}else {
			ubaci(koren->levo, cvor);
		}
	}
}

void stampaj(Knjiga* koren, FILE* out) {
	if(!koren) {
		return;	
	}

	stampaj(koren->levo, out);

	fprintf(out, "%s,%s,%s,%s\n", koren->naziv, koren->autor, koren->isbn, koren->izdavac);

	stampaj(koren->desno, out);
}

void snimiTest(char imeFajla[]) {
	FILE* out = fopen(imeFajla, "w");

	if(!out) {
		printf("Greska: Otvaranje fajla\n");
		return;
	}

	stampaj(koren, out);
	
	if(fclose(out) == EOF) {
		printf("Greska: Zatvaranje fajla\n");
	}
}

int pocinjeSa(char *pre, char *str) {
	return strncmp(pre, str, strlen(str)) == 0;
}

void ucitaj(char imeFajla[]) {
	FILE* in = fopen(imeFajla, "r");

	if(!in) {
		printf("Greska: Otvaranje fajla\n");
		return;
	}

	char row[SIZE];

	while(1) {
		if(!fgets(row, SIZE, in)) {
			break;
		}

		char sep[2] = ",";

		Knjiga* k = novaKnjiga();

		strcpy(k->naziv, strtok(row, sep));
		strcat(k->naziv, "\0");

		strcpy(k->autor, strtok(NULL, sep));
		strcat(k->autor, "\0");

		strcpy(k->isbn, strtok(NULL, sep));
		strcat(k->isbn, "\0");

		strcpy(k->izdavac, strtok(NULL, sep));
		strcat(k->izdavac, "\0");
		
		char *newLine = strchr(k->izdavac, '\n');
		
		if(newLine) {
			*newLine = 0;	
		}
		
		ubaci(koren, k);
	}

	if(fclose(in) == EOF) {
		printf("Greska: Zatvaranje fajla\n");
	}
}

void traziPocetak(Knjiga* koren, char s[]) {
	if(!koren) {
		return;	
	}

	int cmp = pocinjeSa(koren->naziv, s);

	if(cmp) {
		printf("%s %s %s %s\n", koren->naziv, koren->autor, koren->isbn, koren->izdavac);
	}
	
	traziPocetak(koren->levo, s);
	traziPocetak(koren->desno, s);
}

Knjiga* traziCvor(Knjiga* koren, char s[]) {
	if(!koren) {
		return NULL;	
	}

	int cmp = strcmp(koren->naziv, s);

	if(cmp < 0) {
		return traziCvor(koren->desno, s);
	}else if(cmp > 0) {
		return traziCvor(koren->levo, s);
	}else {
		return koren;	
	}
}

void postoji() {
	char s[SIZE];

	printf("Naziv knjige: ");
	scanf("%s", s);

	if(!traziCvor(koren, s)) {
		printf("Ne postoji\n");
	}else {
		printf("Postoji\n");	
	}
}

void trazi() {
	char s[SIZE];

	printf("Pocetak naziva knjige: ");
	scanf("%s", s);

	traziPocetak(koren, s);
}

int ukupno(Knjiga* koren) {
	if(!koren) {
		return 0;	
	}

	return 1 + ukupno(koren->levo) + ukupno(koren->desno);
}

void izbroji() {
	printf("Ukupno knjiga u knjizari: %d\n", ukupno(koren));
}

void obrisi(Knjiga* koren) {
	if(!koren) {
		return;	
	}	

	obrisi(koren->levo);
	obrisi(koren->desno);

	free(koren);
}

void izadji() {
	obrisi(koren);
	koren = NULL;
}

void prikaziMeni() {
		printf("[1] Provera da li naziv postoji\n");
		printf("[2] Prikaz svih knjiga ciji naziv pocinje na uneti deo reci\n");
		printf("[3] Prikaz ukupnog broj kjniga u knjizari\n");
		printf("[4] Izlaz\n");

		int n;

		printf("Izbor: ");
		scanf("%d", &n);

		switch(n) {
			case 1:
				postoji();
				break;	
			case 2:
				trazi();
				break;
			case 3:
				izbroji();
				break;
			case 4:
				izadji();
				break;
			default:
				printf("Nepostojeca opcija\n");
				break;
		}

		if(n != 4) {
			prikaziMeni();	
		}
}

int main() {
	ucitaj("kni.txt");

	prikaziMeni();

	izadji();

	return 0;
}
