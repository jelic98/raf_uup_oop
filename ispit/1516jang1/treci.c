#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Student {
	char ime[SIZE];
	char prezime[SIZE];
	char smer[SIZE];
	float prosek;
	struct Student* levo;	
	struct Student* desno;	
} Student;

Student* koren = NULL;

Student* napraviNovog() {
	Student* s = (Student*) malloc(sizeof(Student));

	if(!s) {
		printf("Greska: Nedovoljno memorije\n");	
		exit(1);
	}

	return s;
}

void ubaci(Student* koren, Student* cvor) {
	if(!koren) {
		extern Student* koren;
		koren = cvor;
		return;
	}

	int cmp = strcmp(koren->ime, cvor->ime);

	if(cmp < 0) {
		if(!koren->desno) {
			koren->desno = cvor;
		}else {
			ubaci(koren->desno, cvor);
		}
	}else if(cvor > 0) {
		if(!koren->levo) {
			koren->levo = cvor;
		}else {
			ubaci(koren->levo, cvor);
		}
	}else {
		cmp = strcmp(koren->prezime, cvor->prezime);

		if(cvor <= 0) {	
			if(!koren->desno) {
				koren->desno = cvor;
			}else {
				ubaci(koren->desno, cvor);
			}
		}else {
			if(!koren->levo) {
				koren->levo = cvor;
			}else {
				ubaci(koren->levo, cvor);
			}
		}
	}
}

void dodaj() {
	Student* s = napraviNovog();

	printf("Ime: ");
	scanf("%s", s->ime);
	strcat(s->ime, "\0");

	printf("Prezime: ");
	scanf("%s", s->prezime);
	strcat(s->prezime, "\0");

	printf("Smer: ");
	scanf("%s", s->smer);
	strcat(s->smer, "\0");
	
	printf("Prosek: ");
	scanf("%f", &s->prosek);

	ubaci(koren, s);
}

void obrisi(Student* s) {
	if(!s) {
		return;
	}

	obrisi(s->levo);
	obrisi(s->desno);
	
	free(s);
	
	koren = NULL;
}

void stampaj(Student* s, char* smer, FILE* out) {
	if(!s) {
		return;
	}	

	stampaj(s->levo, smer, out);

	if(!smer || (smer && !strcmp(smer, s->smer))) {	
		if(out) {	
			fprintf(out, "%s %s %s %f\n", s->ime, s->prezime, s->smer, s->prosek);
		}else {
			printf("%s %s %s %f\n", s->ime, s->prezime, s->smer, s->prosek);
		}
	}
	
	stampaj(s->desno, smer, out);
}

void snimiFajl() {
	char s[SIZE];

	printf("Ime fajla: ");	
	scanf("%s", s);

	FILE* out = fopen(s, "w");

	if(!out) {
		printf("Greska: otvaranje fajla\n");	
		return;
	}
	
	stampaj(koren, NULL, out);

	if(fclose(out) == EOF) {
		printf("Greska: Zatvanje fajla\n");
	}
}

void ucitajFajl() {
	char s[SIZE];

	printf("Ime fajla: ");	
	scanf("%s", s);

	FILE* in = fopen(s, "r");

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

		Student* s = napraviNovog();

		strcpy(s->ime, strtok(row, sep));
		strcat(s->ime, "\0");

		strcpy(s->prezime, strtok(NULL, sep));
		strcat(s->prezime, "\0");
		
		strcpy(s->smer, strtok(NULL, sep));
		strcat(s->smer, "\0");
		
		s->prosek = atof(strtok(NULL, sep));

		ubaci(koren, s);
	}

	if(fclose(in) == EOF) {
		printf("Greska: Zatvaranje fajla\n");	
	}
}

Student* traziBoljeg(Student* s) {
    if(!s) {
      return NULL;
	}

	Student* l = traziBoljeg(s->levo);
    
	Student* d = traziBoljeg(s->desno);
    
	if(l && l->prosek > s->prosek) {
    	s = l; 
	}

    if(d && d->prosek > s->prosek) {
	    s = d;
	}

    return s;
}

void najbolji() {
	Student* s = traziBoljeg(koren);
	
	if(s) {
		printf("%s %s %s %f\n", s->ime, s->prezime, s->smer, s->prosek);
	}
}

int uzmiSmerove(Student* s, char all[SIZE][SIZE], int n) {
	if(!s) {
		return n;
	}
	
	strcpy(all[n++], s->smer);

	n = uzmiSmerove(s->levo, all, n);
	n = uzmiSmerove(s->desno, all, n);

	return n;
}

void prikaziSmerove() {
	char unik[SIZE][SIZE], all[SIZE][SIZE];

	int i, j, n, m, found;

	n = uzmiSmerove(koren, all, 0);

	m = 0;

	for(i = 0; i < n; i++) {
		found = 0;
	
		for(j = 0; j < m; j++) {
			if(!strcmp(all[i], unik[j])) {
				found = 1;
			}
		}

		if(!found) {
			strcpy(unik[m++], all[i]);
		}
	}

	for(i = 0; i < m; i++) {
		printf("%s\n", unik[i]);
	}
}

void prikaziSmer() {
	char s[SIZE];

	printf("Smer: ");
	scanf("%s", s);

	stampaj(koren, s, NULL);
}

void prikaziMeni() {
	printf("[1] Ucitavanje iz fajla\n");
	printf("[2] Dodavanje studenta\n");
	printf("[3] Prikaz svih studenata\n");
	printf("[4] Prikaz studenata na smeru\n");
	printf("[5] Najbolji student\n");
	printf("[6] Prikaz svih smerova\n");
	printf("[7] Snimanje u fajl\n");
	printf("[8] Izlaz\n");

	int n;

	printf("Izbor: ");
	scanf("%d", &n);

	switch(n) {
		case 1:
			ucitajFajl();
			break;
		case 2:
			dodaj();
			break;
		case 3:
			stampaj(koren, NULL, NULL);
			break;
		case 4:
			prikaziSmer();
			break;
		case 5:
			najbolji();
			break;
		case 6:
			prikaziSmerove();
			break;
		case 7:
			snimiFajl();
			break;
		case 8:
			obrisi(koren);
			break;
		default:
			printf("Greska: Nepostojeca opcija\n");
			break;
	}

	if(n != 8) {
		prikaziMeni();	
	}
}

int main() {
	printf("Lazar Jelic RN27/17\n");

	prikaziMeni();

	obrisi(koren);

	return 0;
}
