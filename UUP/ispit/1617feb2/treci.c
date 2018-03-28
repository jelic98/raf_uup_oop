#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Rec {
	char v[SIZE];
	struct Rec* next;
} Rec;

Rec* root = NULL;

char filename[SIZE];

int opened = 1;

Rec* novaRec() {
	Rec* p = (Rec*) malloc(sizeof(Rec));

	if(!p) {
		printf("Greska: Nema dovoljno memorije\n");
		exit(1);
	}

	return p;
}

void dodajNaKraj(Rec* novi) {
	if(!root) {
		root = novi;
		return;
	}

	Rec* tmp = root;

	while(tmp->next) {
		tmp = tmp->next;
	}

	tmp->next = novi;
}

void ucitajFajl() {	
	printf("Ime fajla: ");
	scanf("%s", filename);

	strcat(filename, ".txt");

	FILE* in = fopen(filename, "r");

	if(!in) {
		printf("Greska: Nemoguce otvaranje fajla\n");
		return;
	}

	char row[SIZE];

	while(1) {
		if(!fgets(row, SIZE, in)) {
			break;
		}
	
		char sep[2] = " ";
		char *p = strtok(row, sep);

		while(p) {
			Rec* nova = novaRec();
			
			strcpy(nova->v, p);		
			strcat(nova->v, "\0");
		
			p = strtok(NULL, sep);
			
			dodajNaKraj(nova);
		}			
	}

	if(fclose(in) == EOF) {
		printf("Greska: Zatvaranje fajla");
		return;
	}

	opened = 1;
}

void sve() {
	Rec* tmp = root;
	
	while(tmp) {
		printf("%s\n", tmp->v);

		tmp = tmp->next;
	}
}

void broj() {
	char rec[SIZE];

	printf("Rec: ");
	scanf("%s", rec);

	Rec* tmp = root;

	if(!tmp) {
		printf("Greska: Nema reci\n");
		return;
	}

	int count = 0;

	while(tmp) {
		if(!strcmp(tmp->v, rec)) {
			count++;	
		}

		tmp = tmp->next;
	}

	printf("Broj reci %s je %d\n", rec, count);
}

void pocetnoSlovo() {
	char slovo[SIZE];

	printf("Slovo: ");
	scanf("%s", slovo);

	Rec* tmp = root;
	Rec* prev = NULL;

	while(tmp) {
        if(tmp->v[0] == slovo[0]) {
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

void snimanje() {
	if(!opened) {
		printf("Greska: Nije ucitaj fajl");	
		return;
	}

	printf("asd: %s\n", filename);

	FILE* out = fopen(filename, "w");

	if(!out) {
		printf("Greska: Otvaranje fajla");
		return;
	}

	Rec* tmp = root;

	while(tmp) {
		fprintf(out, "%s\n", tmp->v);

		tmp = tmp->next;	
	}

	if(fclose(out) == EOF) {
		printf("Greska: Zatvaranje fajla");
	}
}

void obrisiListu() {
	Rec* tmp = NULL;

	while(root) {
		tmp = root->next;

		free(root);

		root = tmp;
	}	
}

void prikaziMeni() {
	printf("[1] Ucitavanje teksta iz fajla\n");	
	printf("[2] Ispis svih reci iz liste\n");	
	printf("[3] Broj pojavljivanja reci\n");	
	printf("[4] Izbacivanje reci sa pocetnim slovom\n");	
	printf("[5] Snimanje liste recu u fajl\n");	
	printf("[6] Izlaz\n");	
	printf("Izbor: ");
	
	int n;

	scanf("%d", &n);

	switch(n) {
		case 1:
			ucitajFajl();
			break;
		case 2:
			sve();
			break;
		case 3:
			broj();
			break;
		case 4:
			pocetnoSlovo();
			break;
		case 5:
			snimanje();
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
