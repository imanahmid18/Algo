#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int val ;
    struct element* suivant;
} element;

element* creerListe() {
    return NULL;   
element* chargerListe(int Tab[], int taille, element* liste) {
    element* temp = NULL; 
    element* fin = NULL;  

    for (int i = 0; i < taille; i++) {
        element* nouveau = (element*)malloc(sizeof(element)); 
        if (!nouveau) {
            printf("خطأ في تخصيص الذاكرة\n");
            exit(EXIT_FAILURE);
        }
        nouveau->val = Tab[i];       
        nouveau->suivant = NULL;     

        if (liste == NULL) {         
            liste = nouveau;         
        } else {
            fin->suivant = nouveau;  
        }
        fin = nouveau;               
    }
    return liste;
}

void afficherListe(element* liste) {
    element* temp = liste;
    while (temp != NULL) {
        printf("%d-", temp->val);  
        temp = temp->suivant;    
    }
    printf(">NULL\n"); 
}

element* supprimerEnFin(element* liste) {
    if (liste == NULL) return NULL; 
    if (liste->suivant == NULL) {  
        free(liste);
        return NULL;
    }

    element* temp = liste;
    while (temp->suivant->suivant != NULL) {
        temp = temp->suivant;
    }
    free(temp->suivant); 
    temp->suivant = NULL;
    return liste;
}


element* ajouterEnDebut(element* liste, int valeur) {
    element* nouveau = (element*)malloc(sizeof(element)); 
    if (!nouveau) {
        printf("خطأ في تخصيص الذاكرة\n");
        exit(EXIT_FAILURE);
    }
    nouveau->val = valeur;      
    nouveau->suivant = liste;   
    return nouveau;
}


void viderListe(element* liste) {
    element* temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp); 
    }
    printf("القائمة فارغة.\n");
}


int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};

    
    element* liste = creerListe();

    
    liste = chargerListe(Tab, 10, liste);
    printf("القائمة المحملة:\n");
    afficherListe(liste);

    liste = supprimerEnFin(liste);
    printf("القائمة بعد حذف العنصر الأخير:\n");
    afficherListe(liste);

    liste = ajouterEnDebut(liste, 40);
    printf("القائمة بعد إضافة العنصر 40 في البداية:\n");
    afficherListe(liste);

    viderListe(liste);

    return 0;
}
