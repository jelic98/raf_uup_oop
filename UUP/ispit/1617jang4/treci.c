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

void ispisProizvodaIzKategorije() {
	char kat[SIZE];

	printf("Kategroija: ");
	scanf("%s", kat);

	Proizvod* tmp = root;

	if(!tmp) {
		printf("Greska: Nema proizvoda\n");
		return;
	}

	int found = 0;

	while(tmp) {
		if(!strcmp(tmp->kategorija, kat)) {
			printf("%s,%s,%f\n", tmp->kategorija, tmp->naziv, tmp->cena);
			found = 1;
		}

		tmp = tmp->next;
	}

	if(!found) {
		printf("Greska: Nema kategorije\n");
	}
}

void ispisSvihKategorija() {
	char arr[SIZE][SIZE];

	Proizvod* tmp = root;

	int i, count = 0, found;
	
	while(tmp) {
		found = 0;

		for(i = 0; i < count; i++) {
			if(!strcmp(tmp->kategorija, arr[i])) {
				found = 1;
				break;
			}
		}	

		if(!found) {
			strcpy(arr[count++], tmp->kategorija);
		}
		
		tmp = tmp->next;
	}

	for(i = 0; i < count; i++) {
		printf("%s\n", arr[i]);	
	}
}

void obrisiSkuplje() {
	float cena;

	printf("Cena: ");
	scanf("%f", &cena);

	Proizvod* tmp = root;
	Proizvod* prev = NULL;

	while(tmp) {
        if(tmp->cena > cena) {
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
	printf("[3] Ispis proizvoda iz kategorije\n");	
	printf("[4] Ispis svih kategorija\n");	
	printf("[5] Brisanje proizvoda skupljih od\n");	
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
			ispisProizvodaIzKategorije();
			break;
		case 4:
			ispisSvihKategorija();
			break;
		case 5:
			obrisiSkuplje();
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
