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

void ispisiPobede() {
	char name[SIZE];

	printf("Ime time: ");
	scanf("%s", name);

	Utakmica* tmp = root;
	
	while(tmp) {
		if(!strcmp(tmp->domacin, name)) {
			if(tmp->goloviDomacin > tmp->goloviGost) {
				printf("%s,%s,%d,%d\n", tmp->domacin, tmp->gost, tmp->goloviDomacin, tmp->goloviGost);
			}
		}

		if(!strcmp(tmp->gost, name)) {
			if(tmp->goloviDomacin < tmp->goloviGost) {
				printf("%s,%s,%d,%d\n", tmp->domacin, tmp->gost, tmp->goloviDomacin, tmp->goloviGost);
			}
		}

		tmp = tmp->next;
	}
}

void obrisiUtakmiceDomacina() {
	char name[SIZE];

	printf("Ime domaceg tima: ");
	scanf("%s", name);

	Utakmica* tmp = root;
	Utakmica* prev = NULL;

	while(tmp) {
        if(!strcmp(tmp->domacin, name)) {
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

void ispisSvihTimova() {
	char arr[SIZE][SIZE];

	Utakmica* tmp = root;

	int i, count = 0, foundDomacin, foundGost;
	
	while(tmp) {
		foundDomacin = 0;
		foundGost = 0;

		for(i = 0; i < count; i++) {
			if(!strcmp(tmp->domacin, arr[i])) {
				foundDomacin = 1;
			}

			if(strcmp(tmp->domacin, tmp->gost)) {	
				if(!strcmp(tmp->gost, arr[i])) {
					foundGost = 1;
				}
			}

			if(foundDomacin && foundGost) {
				break;
			}
		}	

		if(!foundDomacin) {
			strcpy(arr[count++], tmp->domacin);
		}

		if(!foundGost) {
			strcpy(arr[count++], tmp->gost);
		}
		
		tmp = tmp->next;
	}

	for(i = 0; i < count; i++) {
		printf("%s\n", arr[i]);	
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
	printf("[3] Ispis svih utakmica u kojima je pobedio odredjeni tim\n");	
	printf("[4] Brisanje utakmica domacina\n");	
	printf("[5] Ispis svih timova\n");	
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
			ispisiPobede();
			break;
		case 4:
			obrisiUtakmiceDomacina();
			break;
		case 5:
			ispisSvihTimova();
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
