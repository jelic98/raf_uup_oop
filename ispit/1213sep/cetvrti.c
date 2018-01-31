#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Node {
	int dan;
	int mesec;
	int godina;
	char sat[SIZE];
	char jezik[SIZE];
	char predavac[SIZE];
	int brojUcenika;
	struct Node* next;
} Node;

Node* root = NULL;

Node* novi() {
	Node* n = (Node*) malloc(sizeof(Node));

	if(!n) {
		printf("Greska: Nedovoljno memorije\n");
		exit(1);
	}

	n->next = NULL;

	return n;
}

void dodaj(Node* n) {
	if(!root) {
		root = n;
		return;
	}

	n->next = root;

	root = n;
}

void ucitaj(char* name) {
	char s[SIZE];
	
	if(!name) {
		printf("Ime fajla: ");
		scanf("%s", s);
		name = s;
	}

	FILE* in = fopen(name, "r");

	if(!in) {
		printf("Greska: Otvaranje fajla\n");
		return;
	}

	char row[SIZE];

	while(fgets(row, SIZE, in)) {
		Node* n = novi();
		
		char sep[2] = ",";

		n->dan = strtol(strtok(row, sep), NULL, 10);
		n->mesec = strtol(strtok(NULL, sep), NULL, 10);
		n->godina = strtol(strtok(NULL, sep), NULL, 10);
		
		strcpy(n->sat, strtok(NULL, sep));
		strcat(n->sat, "\0");
	
		strcpy(n->jezik, strtok(NULL, sep));
		strcat(n->jezik, "\0");
	
		strcpy(n->predavac, strtok(NULL, sep));
		strcat(n->predavac, "\0");

		n->brojUcenika = strtol(strtok(NULL, "\n"), NULL, 10);
		
		dodaj(n);
	}

	if(fclose(in) == EOF) {
		printf("Greska: Zatvaranje fajla\n");
	}
}

void prikazi(int d, int m, int y, FILE* out) {
	Node* tmp = root;

	if(d && m && y) {
		while(tmp) {
			if(tmp->dan == d && tmp->mesec == m && tmp->godina == y) {
				printf("%d %d %d %s %s %s %d\n", tmp->dan, tmp->mesec, tmp->godina, tmp->sat, tmp->jezik, tmp->predavac, tmp->brojUcenika);
			}

			tmp = tmp->next;
		}
	}else if(!d && !m && !y) {	
		while(tmp) {
			fprintf(out, "%d %d %d %s %s %s %d\n", tmp->dan, tmp->mesec, tmp->godina, tmp->sat, tmp->jezik, tmp->predavac, tmp->brojUcenika);

			tmp = tmp->next;
		}	
	}else {
		printf("Greska: Datum nije validan\n");	
	}
}

int ukupno(int d, int m, int y) {
	int sum = 0;

	Node* tmp = root;

	while(tmp) {
		if(tmp->dan == d && tmp->mesec == m && tmp->godina == y) {
			sum += tmp->brojUcenika;
		}

		tmp = tmp->next;	
	}

	return sum;
}

void ubaci() {
	Node* n = novi();

			printf("Dan: ");
			scanf("%d", &n->dan);

			printf("Mesec: ");
			scanf("%d", &n->mesec);

			printf("Godina: ");
			scanf("%d", &n->godina);

			printf("Sat: ");
			scanf("%s", n->sat);
			
			printf("Jezik: ");
			scanf("%s", n->jezik);

			getc(stdin);
			printf("Predavac: ");
			gets(n->predavac);

			printf("Broj ucenika: ");
			scanf("%d", &n->brojUcenika);

			dodaj(n);
}

void snimi() {
	char name[SIZE];

			printf("Ime fajla: ");
			scanf("%s", name);
			
			FILE* out = fopen(name, "w");

			if(!out) {
				printf("Greska: Otvaranje fajla\n");
				return;
			}

			prikazi(0, 0, 0, out);

			if(fclose(out) == EOF) {
				printf("Greska: Zatvaranje fajla\n");	
			}
}

void prikaziDatum() {
	int d, m, y;

			printf("Dan: ");
			scanf("%d", &d);

			printf("Mesec: ");
			scanf("%d", &m);

			printf("Godina: ");
			scanf("%d", &y);

			prikazi(d, m, y, stdout);
}

void prikaziUkupno() {
	int d, m, y;

			printf("Dan: ");
			scanf("%d", &d);

			printf("Mesec: ");
			scanf("%d", &m);

			printf("Godina: ");
			scanf("%d", &y);

			printf("Ukupan broj ucenika: %d\n", ukupno(d, m, y));
}

void prikaziJezike() {
	Node* tmp = root;

	char arr[SIZE] = {0};

	while(tmp) {
		if(!strstr(arr, tmp->jezik)) {
			strcat(arr, tmp->jezik);
			strcat(arr, "\n");
		}

		tmp = tmp->next;
	}

	printf("%s", arr);
}

void obrisi() {
		while(root) {
				Node* tmp = root;				

				root = root->next;	
				
				free(tmp);
			}
}

void prikaziMeni(Node* root) {
	printf("\n");
	printf("[1] Ucitavanje iz fajla\n");
	printf("[2] Unos\n");
	printf("[3] Prikaz svih kurseva\n");
	printf("[4] Prikaz svih odrzanih kurseva odredjenog datuma\n");
	printf("[5] Ukupan broj ucenika po datumu\n");
	printf("[6] Prikaz svih jezika\n");
	printf("[7] Snimanje u fajl\n");
	printf("[8] Izlaz iz programa\n");
	printf("Izbor: ");

	int n;

	scanf("%d", &n);

	switch(n) {
		case 1:
			ucitaj(NULL);
			break;
		case 2:
			ubaci();
			break;
		case 3:
			prikazi(0, 0, 0, stdout);
			break;
		case 4:
			prikaziDatum();	
			break;
		case 5:
			prikaziUkupno();
			break;
		case 6:
			prikaziJezike();
			break;
		case 7:
			snimi();
			break;
		case 8:
			obrisi();	
			break;
		default:
			printf("Greska: Nepostojeca opcija\n");
			break;
	}

	if(n != 8) {
		prikaziMeni(root);
	}
}

int main(int argc, char *argv[]) {
	Node* root = NULL;

	ucitaj(argv[1]);

	prikaziMeni(root);

	return 0;
}
