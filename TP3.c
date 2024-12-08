#include <stdio.h>
#include <stdlib.h>

// تعريف هيكل العقدة في القائمة المرتبطة
typedef struct element {
    int val; // القيمة المخزنة في العقدة
    struct element* suivant; // مؤشر يشير إلى العقدة التالية
} element;

// وظيفة لإنشاء قائمة فارغة
element* creerListe() {
    return NULL; // القائمة الفارغة تكون ممثلة بمؤشر NULL
}

// وظيفة لتحميل قائمة من مصفوفة
element* chargerListe(int Tab[], int taille, element* liste) {
    element* temp = NULL; // عقدة مؤقتة
    element* fin = NULL;  // مؤشر على نهاية القائمة

    for (int i = 0; i < taille; i++) {
        element* nouveau = (element*)malloc(sizeof(element)); // إنشاء عقدة جديدة
        if (!nouveau) {
            printf("خطأ في تخصيص الذاكرة\n");
            exit(EXIT_FAILURE);
        }
        nouveau->val = Tab[i];       // تخزين القيمة
        nouveau->suivant = NULL;     // تعيين التالي إلى NULL

        if (liste == NULL) {         // إذا كانت القائمة فارغة
            liste = nouveau;         // العقدة الجديدة هي بداية القائمة
        } else {
            fin->suivant = nouveau;  // ربط العقدة الجديدة بالنهاية
        }
        fin = nouveau;               // تحديث مؤشر النهاية
    }
    return liste;
}

// إجراء لطباعة عناصر القائمة
void afficherListe(element* liste) {
    element* temp = liste;
    while (temp != NULL) {
        printf("%d-", temp->val); // طباعة القيمة متبوعة بـ "-"
        temp = temp->suivant;    // الانتقال إلى العقدة التالية
    }
    printf(">NULL\n"); // نهاية القائمة
}

// وظيفة لحذف العنصر الأخير من القائمة
element* supprimerEnFin(element* liste) {
    if (liste == NULL) return NULL; // إذا كانت القائمة فارغة
    if (liste->suivant == NULL) {   // إذا كانت تحتوي على عنصر واحد
        free(liste);
        return NULL;
    }

    element* temp = liste;
    while (temp->suivant->suivant != NULL) { // الوصول إلى العقدة قبل الأخيرة
        temp = temp->suivant;
    }
    free(temp->suivant); // تحرير الذاكرة الخاصة بالعقدة الأخيرة
    temp->suivant = NULL; // تعيين التالي إلى NULL
    return liste;
}

// وظيفة لإضافة عنصر في بداية القائمة
element* ajouterEnDebut(element* liste, int valeur) {
    element* nouveau = (element*)malloc(sizeof(element)); // إنشاء عقدة جديدة
    if (!nouveau) {
        printf("خطأ في تخصيص الذاكرة\n");
        exit(EXIT_FAILURE);
    }
    nouveau->val = valeur;      // تخزين القيمة
    nouveau->suivant = liste;   // ربط العقدة الجديدة بالبداية الحالية
    return nouveau;
}

// إجراء لتفريغ القائمة بالكامل
void viderListe(element* liste) {
    element* temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp); // تحرير الذاكرة
    }
    printf("القائمة فارغة.\n");
}

// الدالة الرئيسية
int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};

    // إنشاء قائمة فارغة
    element* liste = creerListe();

    // تحميل القائمة من المصفوفة
    liste = chargerListe(Tab, 10, liste);
    printf("القائمة المحملة:\n");
    afficherListe(liste);

    // حذف العنصر الأخير
    liste = supprimerEnFin(liste);
    printf("القائمة بعد حذف العنصر الأخير:\n");
    afficherListe(liste);

    // إضافة عنصر في البداية
    liste = ajouterEnDebut(liste, 40);
    printf("القائمة بعد إضافة العنصر 40 في البداية:\n");
    afficherListe(liste);

    // تفريغ القائمة
    viderListe(liste);

    return 0;
}
