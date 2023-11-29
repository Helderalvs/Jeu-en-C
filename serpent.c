#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


#define LARGEUR 20
#define HAUTEUR 10

int gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;

void setup() {
    gameOver = 0;
    dir = STOP;
    x = LARGEUR / 2;
    y = HAUTEUR / 2;
    fruitX = rand() % LARGEUR;
    fruitY = rand() % HAUTEUR;
    score = 0;
}

void draw() {
    system("cls"); // Efface l'écran

    for (int i = 0; i < LARGEUR + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            if (j == 0)
                printf("#");

            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else {
                int isTail = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        isTail = 1;
                    }
                }
                if (!isTail)
                    printf(" ");
            }

            if (j == LARGEUR - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < LARGEUR + 2; i++)
        printf("#");
    printf("\n");

    printf("Score:%d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'q':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'z':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }
}

void algorithm() {
    Sleep(200);
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if (x < 0 || x >= LARGEUR || y < 0 || y >= HAUTEUR)
        gameOver = 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % LARGEUR;
        fruitY = rand() % HAUTEUR;
        nTail++;
    }
}

int main() {
    setup();

    while (!gameOver) {
        draw();
        input();
        algorithm();
    }

    return 0;
}
