#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Génération d'un nombre aléatoire entre 1 et 100
    int nombreSecret = rand() % 100 + 1;

    int nombreEssais = 0;
    int proposition;

    printf("Bienvenue dans le jeu de devine le nombre!\n");
    printf("Devine le nombre entre 1 et 100.\n");

    do {
        printf("Propose un nombre : ");
        scanf("%d", &proposition);

        nombreEssais++;

        if (proposition < nombreSecret) {
            printf("C'est plus grand !\n");
        } else if (proposition > nombreSecret) {
            printf("C'est plus petit !\n");
        } else {
            printf("Bravo, tu as deviné le nombre en %d essais!\n", nombreEssais);
        }

    } while (proposition != nombreSecret);

    return 0;
}
