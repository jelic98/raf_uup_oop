#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Proizvod {
	char kategorija[SIZE];
	char naziv[SIZE];
	double cena;
	struct Proizvod* next;
} Proizvod;

Proizvod* root = NULL;

Proizvod* noviProizvod() {
	Proizvod* p = (Proizvod*) malloc(sizeof(Proizvod));

	if(!p) {
		printf("Greska: Nema dovoljno memorije\n");
		exit(1);
	}

	return p; 
}

void dodajNaKraj(Proizvod* novi) {
	if(!root) {
		root = novi;
		return;
	}

	Proizvod* tmp = root;

	while(tmp->next) {
		tmp = tmp->next;
	}

	tmp->next = novi;
}

void ucitajFajl() {	
	char name[SIZE];

	printf("Ime fajla: ");
	scanf("%s", name);

	FILE* in = fopen(strcat(name, ".txt"), "r");

	if(!in) {
		printf("Greska: Nemoguce otvaranje fajla\n");
		return;
	}

	char row[SIZE];

	while(1) {
		if(!fgets(row, SIZE, in)) {
			break;
		}
	
		char sep[2] = ",";
		char *p;

		int count = 0;

		Proizvod* novi = noviProizvod();

		while(count++ < 4) {
			switch(count) {
				case 1:
					strcpy(novi->kategorija, strtok(row, sep));
					strcat(novi->kategorija, "\0");
					break;
				case 2:
					strcpy(novi->naziv, strtok(NULL, sep));
					strcat(novi->naziv, "\0");
					break;
				case 3:
					novi->cena = atof(strtok(NULL, sep));
					break;
			}
		}

		dodajNaKraj(novi);
	}
	
	if(fclose(in) == EOF) {
		printf("Greska: Zatvaranje fajla\n");
	}
}

void ispisiSveProizvode() {
	Proizvod* tmp = root;
	
	while(tmp) {
		printf("%s,%s,%f\n", tmp->kategorija, tmp->naziv, tmp->cena);

		tmp = tmp->next;
	}
}

void ispisiGraniceKategorije() {
	char kat[SIZE];

	printf("Kategorija: ");
	scanf("%s", kat);

	float min, max;
	int found = 0;
	char *minP, *maxP;

	if(!root) {
		printf("Greska: Nema proizvoda\n");
		return;	
	}
	
	Proizvod* tmp = root;

	while(tmp) {
		if(!strcmp(tmp->kategorija, kat)) {
			if(found) {
				if(tmp->cena < min) {
					min = tmp->cena;
					minP = tmp->naziv;
				}
				
				if(tmp->cena > max) {
					max = tmp->cena;
					maxP = tmp->naziv;
				}
			}else {
				found++;

				min = tmp->cena;
				minP = tmp->naziv;
				
				max = tmp->cena;
				maxP = tmp->naziv;
			}
		}

		tmp = tmp->next;	
	}

	if(!found) {
		printf("Greska: Nije pronadjena kategorija\n");
		return;
	}

	printf("Najskuplji proizvod u kategoriji %s je %s i kosta %f\n", kat, maxP, max);
	printf("Najjeftiniji proizvod u kategoriji %s je %s i kosta %f\n", kat, minP, min);
}

void ispisiCenuKolicine() {
	char naziv[SIZE];
	int kol;

	printf("Naziv i kolicina: ");
	scanf("%s%d", naziv, &kol);
	
	Proizvod* tmp = root;

	while(tmp) {
		if(!strcmp(tmp->naziv, naziv)) {
			printf("Cena proizvoda %s za kolicinu %d je %f\n", naziv, kol, kol*tmp->cena);
			return;	
		}

		tmp = tmp->next;
	}

	printf("Greska: Proizvod nije pronadjen\n");
}

void obrisiKategoriju() {
	char name[SIZE];

	printf("Kategorija: ");
	scanf("%s", name);

	Proizvod* tmp = root;
	Proizvod* prev = NULL;

	while(tmp) {
        if(!strcmp(tmp->kategorija, name)) {
			if(prev) {
            	prev->next = tmp->next;

				free(tmp);

				tmp = prev->next;
			}else {
				root = tmp->next;

				free(tmp);

				tmp = root;
			}
        }else {
        	tmp = (prev = tmp)->next;
		}
    }
}

void obrisiListu() {
	Proizvod* tmp = NULL;

	while(root) {
		tmp = root->next;

		free(root);

		root = tmp;
	}	
}

void prikaziMeni() {
	printf("[1] Ucitavanje podataka iz fajla\n");	
	printf("[2] Ispis svih proizvoda iz liste\n");	
	printf("[3] Ispis najskupljeg i najjeftinieg proizvoda iz kategorije\n");	
	printf("[4] Ispis cene za kolicinu\n");	
	printf("[5] Brisanje svih proizvoda jedne kategorije\n");	
	printf("[6] Izlaz\n");	
	printf("Izbor: ");
	
	int n;

	scanf("%d", &n);

	switch(n) {
		case 1:
			ucitajFajl();
			break;
		case 2:
			ispisiSveProizvode();
			break;
		case 3:
			ispisiGraniceKategorije();
			break;
		case 4:
			ispisiCenuKolicine();
			break;
		case 5:
			obrisiKategoriju();
			break;
		case 6:
			obrisiListu();
			break;
		default:
			printf("Nepostojeca opcija\n");
			break;
	}

	if(n > 0 && n < 6) {
		prikaziMeni();
	}
}

int main() {
	prikaziMeni();

	obrisiListu();

	return 0;
}
