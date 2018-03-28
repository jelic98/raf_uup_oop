#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Node {
	char ime[SIZE];
	char prezime[SIZE];
	unsigned long pasos;
	char destinacija[SIZE];
	char polazak[SIZE];
	char kraj[SIZE];
	struct Node* l;
	struct Node* r;
} Node;

Node* root;

Node* novi() {
	Node* p = (Node*) malloc(sizeof(Node));
	
	if(!p) {
		printf("Greska: Nedovoljno memorije\n");
		exit(1);
	}

	p->l = NULL;
	p->r = NULL;

	return p;
}

Node* min(Node* p) {
	while(p->l) {
		p = p->l;
	}

	return p;
}

Node* obrisi(Node* p, long pasos) {
	if(p) {
		if(!pasos) {
			p->l = obrisi(p->l, pasos);
			p->r = obrisi(p->r, pasos);
			
			free(p);

			p = NULL;
		}else {
			if(pasos > p->pasos) {
				p->r = obrisi(p->r, pasos);
			}else if(pasos < p->pasos) {
				p->l = obrisi(p->l, pasos);
			}else {
				if(!p->l && !p->r) {
					free(p);

					p = NULL;
				}else if(p->l && !p->r) {
					Node* tmp = p->l;

					free(p);

					p = tmp;
				}else if(!p->l && p->r) {
					Node* tmp = p->r;

					free(p);

					p = tmp;
				}else {
					Node* tmp = min(p->r);

					free(p);

					p = tmp;
				}
			}
		}
	}

	return p;
}

void ispisi(Node* p, int sort, FILE* out) {
	if(!p) {
		return;
	}

	if(sort) {
		ispisi(p->l, sort, out);

		fprintf(out, "%s %s %lu %s %s %s\n", p->ime, p->prezime, p->pasos, p->destinacija, p->polazak, p->kraj);

		ispisi(p->r, sort, out);
	}else {
		fprintf(out, "%s %s %lu %s %s %s\n", p->ime, p->prezime, p->pasos, p->destinacija, p->polazak, p->kraj);
	
		ispisi(p->l, sort, out);
		ispisi(p->r, sort, out);
	}
}

Node* ubaci(Node* root, Node* p) {
	if(!root) {
		extern Node* root;
		root = p;
		return root;	
	}

	if(p->pasos < root->pasos) {
		if(root->l) {
			root->l = ubaci(root->l, p);	
		}else {
			root->l = p;
		}
	}else {
		if(root->r) {
			root->r = ubaci(root->r, p);	
		}else {
			root->r = p;
		}
	}

	return root;
}

void ucitaj(Node* root, char* name) {
	char s[SIZE];

	if(!name) {
		printf("Ime fajla: ");
		scanf("%s", s);

		name = s;
	}

	FILE* in = fopen(name, "r");
	
	if(!in) {
		printf("Greska: Otvaranje fajla\n");	
		exit(1);
	}

	char row[SIZE];

	while(fgets(row, SIZE, in)) {
		Node* p = novi();
		
		char sep[2] = ";";

		char *newline = strchr(row, '\n');
	
		if(newline) {
			*newline = 0;
		}
		
		char* t = strtok(row, sep);
	
		int i = 0;

		while(*t != ' ') {
			p->ime[i++] = *t;
			t++;
		}

		strcat(p->ime, "\0");

		t++;

		i = 0;

		while(*t) {
			p->prezime[i++] = *t;
			t++;
		}
		
		strcat(p->prezime, "\0");

		p->pasos = strtoul(strtok(NULL, sep), NULL, 10);
		
		strcpy(p->destinacija, strtok(NULL, sep));
		strcat(p->destinacija, "\0");

		strcpy(p->polazak, strtok(NULL, sep));
		strcat(p->polazak, "\0");

		strcpy(p->kraj, strtok(NULL, sep));
		strcat(p->kraj, "\0");

		root = ubaci(root, p);
	}

	if(fclose(in) == EOF) {
		printf("Greska: Zatvaranje fajla\n");	
		exit(1);
	}
}

void prikaziMeni() {
	printf("\n");
	printf("[1] Dodavanje putnika\n");
	printf("[2] Brisanje putnika\n");
	printf("[3] Ucitavanje putnika iz fajla\n");
	printf("[4] Snimanje putnika u fajl\n");
	printf("[5] Ispis svih putnika sortiran po pasosu\n");
	printf("[6] Ukupan broj putnika koji su trenutno na letovanju\n");
	printf("[7] Ispis svih putnika\n");
	printf("[8] Izlaz\n");
	printf("Izbor: ");

	int n;
	scanf("%d", &n);

	if(n == 1) {
			Node* p = novi();
			
			printf("Ime: ");
			scanf("%s", p->ime);
			strcat(p->ime, "\0");

			printf("Prezime: ");
			scanf("%s", p->prezime);
			strcat(p->prezime, "\0");

			printf("Broj pasosa: ");
			scanf("%lu", &p->pasos);

			printf("Destinacija: ");
			scanf("%s", p->destinacija);
			strcat(p->destinacija, "\0");

			printf("Datum polaska: ");
			scanf("%s", p->polazak);
			strcat(p->polazak, "\0");

			printf("Datum kraja: ");
			scanf("%s", p->kraj);
			strcat(p->kraj, "\0");
			
			root = ubaci(root, p);
	}else if(n == 2) {
			unsigned long pasos;
		
			printf("Broj pasosa: ");
			scanf("%lu", &pasos);

			root = obrisi(root, pasos);
	}else if(n == 3) {
			ucitaj(root, NULL);
	}else if(n == 4) {
			char name[SIZE];

			printf("Ime fajla: ");
			scanf("%s", name);

			FILE* out = fopen(name, "w");
			
			if(!out) {
				printf("Greska: Otvaranje fajla\n");	
				exit(1);
			}

			ispisi(root, 0, out);

			if(fclose(out) == EOF) {
				printf("Greska: Zatvaranje fajla\n");	
				exit(1);
			}
	}else if(n == 5) {
			ispisi(root, 1, stdout);
	}else if(n == 6) {
		// TODO
	}else if(n == 7) {
			ispisi(root, 0, stdout);
	}else if(n == 8) {
			root = obrisi(root, 0);
			exit(0);
	}else {
			printf("Greska: Nepostojeca opcija\n");
			exit(1);
	}

	prikaziMeni();
}

int main(int argc, char *argv[]) {
	ucitaj(root, argv[1]);

	prikaziMeni();

	return 0;
}
