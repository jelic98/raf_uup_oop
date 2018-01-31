#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Posetilac {
	char ime[SIZE];
	char prezime[SIZE];
	char grad[SIZE];
	int godine;
	struct Posetilac* levo;
	struct Posetilac* desno;
} Posetilac;

Posetilac* root = NULL;

Posetilac* novi() {
	Posetilac* p = (Posetilac*) malloc(sizeof(Posetilac));

	if(!p) {
		printf("Nedovoljno memorije\n");
		exit(1);
	}

	p->levo = NULL;
	p->desno = NULL;
	
	return p;
}

void ubaci(Posetilac* root, Posetilac* p) {
	if(!root) {
		extern Posetilac* root;
		root = p;
		return;
	}

	int cmp = strcmp(p->ime, root->ime);

	if(!cmp) {
		cmp = strcmp(p->prezime, root->prezime);
	}

	if(cmp > 0) {
		if(root->desno) {
			ubaci(root->desno, p);
		}else {
			root->desno = p;
		}
	}else {
		if(root->levo) {
			ubaci(root->levo, p);
		}else {
			root->levo = p;
		}
	}
}

Posetilac* obrisi(Posetilac* p) {
	if(p) {
		obrisi(p->levo);
		obrisi(p->desno);
	
		free(p);

		p = NULL;
	}

	return p;
}

int prebroji(Posetilac* p, char* grad) {
	if(!p) {
		return 0;	
	}

	int res = prebroji(p->levo, grad) + prebroji(p->desno, grad);

	if(!strcmp(p->grad, grad)) {
		res++;
	}

	return res;
}

void stampaj(Posetilac* p, char* grad, FILE* out) {
	if(!p) {
		return;	
	}
	
	if(!grad || (grad && !strcmp(grad, p->grad))) {
		fprintf(out, "%s %s %s %d\n", p->ime, p->prezime, p->grad, p->godine);
	}

	stampaj(p->levo, grad, out);
	stampaj(p->desno, grad, out);
}

int uzmiGradove(Posetilac* p, char all[SIZE][SIZE], int n) {
	if(p) {
		strcpy(all[n++], p->grad);

		n = uzmiGradove(p->levo, all, n);
		n = uzmiGradove(p->desno, all, n);
	}

	return n;
}

void ucitaj(char* s) {
	if(!s) {
		char name[SIZE];

		printf("Ime fajla: ");	
		scanf("%s", name);
		
		s = name;
	}

	FILE* in = fopen(s, "r");

	if(!in) {
		printf("Greska: Otvaranje fajla\n");
		return;
	}

	char row[SIZE];

	while(fgets(row, SIZE, in)) {
		Posetilac* p = novi();
		
		char sep[2] = ",";

		strcpy(p->ime, strtok(row, sep));
		strcat(p->ime, "\0");

		strcpy(p->prezime, strtok(NULL, sep));
		strcat(p->prezime, "\0");
		
		strcpy(p->grad, strtok(NULL, sep));
		strcat(p->grad, "\0");
		
		p->godine = atoi(strtok(NULL, sep));

		ubaci(root, p);
	}

	if(fclose(in) == EOF) {
		printf("Greska: Zatvaranje fajla\n");	
	}

}

void dodaj() {
	Posetilac * p = novi();

	printf("Ime: ");
	scanf("%s", p->ime);
	strcat(p->ime, "\0");

	printf("Prezime: ");
	scanf("%s", p->prezime);
	strcat(p->prezime, "\0");

	printf("Grad: ");
	scanf("%s", p->grad);
	strcat(p->grad, "\0");

	printf("Godine: ");
	scanf("%d", &p->godine);

	ubaci(root, p);
}

void prikaziSve() {
	stampaj(root, NULL, stdout);
}

void prikaziIzGrada() {
	char grad[SIZE];

	printf("Grad: ");
	scanf("%s", grad);

	stampaj(root, grad, stdout);
}

void prebrojiIzGrada() {
	char grad[SIZE];

	printf("Grad: ");
	scanf("%s", grad);

	printf("Broj posetilaca iz grada %s je %d\n", grad, prebroji(root, grad));
}

void prikaziGradove() {
	char svi[SIZE][SIZE], unik[SIZE][SIZE];
	int i, j, found, m = 0, n = uzmiGradove(root, svi, n);

	for(i = 0; i < n; i++) {
		found = 0;

		for(j = 0; j < m; j++) {
			if(!strcmp(svi[i], unik[j])) {
				found = 1;
				break;
			}
		}

		if(!found) {
			strcpy(unik[m++], svi[i]);
		}
	}

	for(i = 0; i < m; i++) {
		printf("%s\n", unik[i]);
	}
}

void snimi() {
	char s[SIZE];

	printf("Ime fajla: ");	
	scanf("%s", s);

	FILE* out = fopen(s, "w");

	if(!out) {
		printf("Greska: Otvaranje fajla\n");
		return;
	}
	
	stampaj(root, NULL, out);

	if(fclose(out) == EOF) {
		printf("Greska: Zatvanje fajla\n");
	}
}

void izlaz() {
	root = obrisi(root);
	exit(0);
}

void prikaziMeni() {
	printf("[1] Ucitavanje iz fajla\n");
	printf("[2] Dodavanje posetioca\n");
	printf("[3] Prikaz svih posetilaca\n");
	printf("[4] Prikaz posetilaca iz grada\n");
	printf("[5] Broj posetilaca iz grada\n");
	printf("[6] Prikaz svih gradova\n");
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
			dodaj();
			break;
		case 3:
			prikaziSve();
			break;
		case 4:
			prikaziIzGrada();
			break;
		case 5:
			prebrojiIzGrada();
			break;
		case 6:
			prikaziGradove();
			break;
		case 7:
			snimi();
			break;
		case 8:
			izlaz();
			break;
		default:
			printf("Neposotjeca opcija\n");
			exit(1);
	}
	
	prikaziMeni();
}

int main(int argc, char *argv[]) {
	printf("Lazar Jelic RN27/17\n");

	ucitaj(argv[1]);

	prikaziMeni();
	
	return 0;
}
