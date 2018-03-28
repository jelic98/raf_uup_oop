#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Utakmica {
	char domacin[SIZE];
	char gost[SIZE];
	int goloviDomacin;
	int goloviGost;
	struct Utakmica* next;
} Utakmica;

Utakmica* root = NULL;

Utakmica* novaUtakmica() {
	Utakmica* u = (Utakmica*) malloc(sizeof(Utakmica));

	if(!u) {
		printf("Greska: Nema dovoljno memorije\n");
		exit(1);
	}

	return u; 
}

void dodajNaKraj(Utakmica* nova) {
	if(!root) {
		root = nova;
		return;
	}

	Utakmica* tmp = root;

	while(tmp->next) {
		tmp = tmp->next;
	}

	tmp->next = nova;
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

		Utakmica* nova = novaUtakmica();

		while(count++ < 4) {
			switch(count) {
				case 1:
					strcpy(nova->domacin, strtok(row, sep));
					strcat(nova->domacin, "\0");
					break;
				case 2:
					strcpy(nova->gost, strtok(NULL, sep));
					strcat(nova->gost, "\0");
					break;
				case 3:
					nova->goloviDomacin = atoi(strtok(NULL, sep));
					break;
				case 4:
					nova->goloviGost = atoi(strtok(NULL, sep));
					break;
			}
		}

		dodajNaKraj(nova);
	}

	if(fclose(in) == EOF) {
		printf("Greska: Zatvaranje fajla\n");
	}
}

void ispisiSveUtakmice() {
	Utakmica* tmp = root;
	
	while(tmp) {
		printf("%s,%s,%d,%d\n", tmp->domacin, tmp->gost, tmp->goloviDomacin, tmp->goloviGost);

		tmp = tmp->next;
	}
}

void ispisiNereseneUtakmice() {
	Utakmica* tmp = root;
	
	while(tmp) {
		if(tmp->goloviDomacin == tmp->goloviGost) {
			printf("%s,%s,%d,%d\n", tmp->domacin, tmp->gost, tmp->goloviDomacin, tmp->goloviGost);
		}
		
		tmp = tmp->next;
	}	
}

void obrisiUtakmiceGosta() {
	char name[SIZE];

	printf("Ime gostujuceg tima: ");
	scanf("%s", name);

	Utakmica* tmp = root;
	Utakmica* prev = NULL;

	while(tmp) {
        if(!strcmp(tmp->gost, name)) {
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

void ispisPoenaTima() {
	char name[SIZE];
	
	printf("Ime tima: ");
	scanf("%s", name);

	Utakmica* tmp = root;

	int pts = 0;
	int found = 0;

	while(tmp) {
		if(!strcmp(tmp->domacin, name)) {
			found = 1;

			if(tmp->goloviDomacin > tmp->goloviGost) {
				pts += 3;
			}else if(tmp->goloviDomacin == tmp->goloviGost) {
				pts += 1;
			}
		}else if(!strcmp(tmp->gost, name)) {
			found = 1;

			if(tmp->goloviDomacin < tmp->goloviGost) {
				pts += 3;
			}else if(tmp->goloviDomacin == tmp->goloviGost) {
				pts += 1;
			}
		}

		tmp = tmp->next;
	}

	if(found) {
		printf("Broj poena za tim %s: %d\n", name, pts);
	}else {
		printf("Greska: Tim ne postoji\n");	
	}
}

void obrisiListu() {
	Utakmica* tmp = NULL;

	while(root) {
		tmp = root->next;

		free(root);

		root = tmp;
	}	
}

void prikaziMeni() {
	printf("[1] Ucitavanje podataka iz fajla\n");	
	printf("[2] Ispis svih utakmica iz liste\n");	
	printf("[3] Ispis svih utakmica sa neresenim rezultatom\n");	
	printf("[4] Brisanje utakmice gosta\n");	
	printf("[5] Ispis poena za tim\n");	
	printf("[6] Izlaz\n");	
	printf("Izbor: ");
	
	int n;

	scanf("%d", &n);

	switch(n) {
		case 1:
			ucitajFajl();
			break;
		case 2:
			ispisiSveUtakmice();
			break;
		case 3:
			ispisiNereseneUtakmice();
			break;
		case 4:
			obrisiUtakmiceGosta();
			break;
		case 5:
			ispisPoenaTima();
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
