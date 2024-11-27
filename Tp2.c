البرنامج الرئيسي (main) 
طلب طول السلسلة النصية من المستخدم:

يتم إدخال الطول الأقصى للنص الذي سيدخله المستخدم باستخدام:
c
نسخ الكود
printf("veuillez saisir la taille maximale de la chaine: \n");
scanf("%d", &n);
n هو الطول الأقصى الذي يتم تخصيصه لاحقًا باستخدام الذاكرة الديناميكية.

2.استدعاء وظيفة ChargerChaine:

يتم استدعاء الدالة ChargerChaine(n) لتخصيص مساحة ديناميكية بحجم n باستخدام malloc، ثم قراءة النص من المستخدم.
النتيجة: مؤشر ch يشير إلى النص المدخل.

3.حساب طول النص باستخدام وظيفة Longueur:

يتم استدعاء الدالة Longueur(ch) لحساب طول النص المخزن في ch.
يتم استخدام النتيجة لتحديد حجم المصفوفات Tab وT التي سيتم العمل عليها.

4.نسخ النص إلى مصفوفة باستخدام ChargerTab:

الدالة ChargerTab(ch, Tab) تنسخ النص من المؤشر ch إلى المصفوفة Tab.
الهدف: تحويل النص المدخل إلى مصفوفة (array) ليستعد لاستخدام الوظائف الأخرى.

5.عرض النص باستخدام AfficherTab:

يتم استدعاء الدالة AfficherTab(Tab, m) لطباعة النص الموجود في المصفوفة Tab.
6.عكس النص باستخدام InverserTab:

الدالة InverserTab(Tab, T, m) تعكس محتويات المصفوفة Tab وتضع النتيجة في المصفوفة T.
على سبيل المثال: إذا كانت Tab = "hello", فإن T = "olleh"

7.عرض النص المعكوس:

يتم استدعاء الدالة AfficherTab(T, m) لطباعة النص المعكوس المخزن في المصفوفة T.
8.تحرير الذاكرة المخصصة ديناميكيًا:

يتم استخدام الدالة free(ch) لتحرير المساحة التي تم تخصيصها ديناميكيًا باستخدام malloc.
هذا يمنع تسريب الذاكرة.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ChargerChaine(int N) {
    char *chaine = (char*)malloc(N+1); 
    printf("Veuillez saisir la chaine:\n");
    fgets(chaine, N, stdin);
    chaine[strcspn(chaine, "\n")] = '\0'; 
    return chaine;
}

int Longueur(char *ch) {
    return strlen(ch);
}

void ChargerTab(char *p, char Tab[]) {
    strcpy(Tab, p);
}

void InverserTab(char Tab[], char T[], int m) {
    for (int i = 0; i < m; i++) {
        T[i] = Tab[m-i-1];
    }
}

void AfficherTab(char Tab[], int m) {
    for (int i = 0; i < m; i++) {
        printf("%c", Tab[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Veuillez saisir la taille maximale de la chaine:\n");
    scanf("%d", &n);
    char *ch = ChargerChaine(n);
    int m = Longueur(ch);
    char Tab[m], T[m];
    ChargerTab(ch, Tab);
    printf("La chaine originale: \n");
    AfficherTab(Tab, m);
    InverserTab(Tab, T, m);
    printf("La chaine inversée:\n");
    AfficherTab(T, m);
    free(ch);
    return 0;
}