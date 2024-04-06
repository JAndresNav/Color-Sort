//José Andrés Navarro
//Bryan Edgardo Romo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

int stack_confirmar(STACK *stacks[], int desde, int destino) {

    if (stacks[destino]->size == 0) {
        return 1;
    }

    if (stacks[destino]->size < 4) {
        TYPE *elem1 = stack_peek(stacks[desde]);
        TYPE *elem2 = stack_peek(stacks[destino]);

        if (char_val(elem1) == char_val(elem2)) {
            return 1;
        }
    }

    return 0;
}

TYPE mover_elementos(STACK *stacks[],int desde,int destino) {

    TYPE *elem = stack_pop(stacks[desde]);
    stacks[desde]->size--;
    if (elem != NULL) {
        stack_push(stacks[destino], elem);
    }

}

TYPE liberarStacks(STACK *stacks[]){
    stack_destroy(stacks[0]);
    stack_destroy(stacks[1]);
    stack_destroy(stacks[2]);
    stack_destroy(stacks[3]);
    stack_destroy(stacks[4]);
    stack_destroy(stacks[5]);
    stack_destroy(stacks[6]);
    stack_destroy(stacks[7]);
}

TYPE inicializarStacks(STACK *stacks[]);

TYPE printStacks(STACK *stacks[]) {

    printf("stack 0\n--------|\n");

    struct STRSNODE *new = stacks[0]->top;
    for (int i = 0; i < 4; ++i) {
        if(new != NULL){
        printf(" %c", char_val(new->elem));
        new = new->prev;
        }
    }

    printf("|\n--------|\nstack 1\n--------|\n");

    new = stacks[1]->top;
    for (int i = 0; i < 4; ++i) {
        if(new != NULL){
            printf(" %c", char_val(new->elem));
            new = new->prev;
        }
    }

    printf("|\n--------|\nstack 2\n--------|\n");

    new = stacks[2]->top;
    for (int i = 0; i < 4; ++i) {
        if(new != NULL){
            printf(" %c", char_val(new->elem));
            new = new->prev;
        }
    }

    printf("|\n--------|\nstack 3\n--------|\n");

    new = stacks[3]->top;
    for (int i = 0; i < 4; ++i) {
        if(new != NULL){
            printf(" %c", char_val(new->elem));
            new = new->prev;
        }
    }

    printf("|\n--------|\nstack 4\n--------|\n");

    new = stacks[4]->top;
    for (int i = 0; i < 4; ++i) {
        if(new != NULL){
            printf(" %c", char_val(new->elem));
            new = new->prev;
        }
    }

    printf("|\n--------|\nstack 5\n--------|\n");

    new = stacks[5]->top;
    for (int i = 0; i < 4; ++i) {
        if(new != NULL){
            printf(" %c", char_val(new->elem));
            new = new->prev;
        }
    }

    printf("|\n--------|\nstack 6\n--------|\n");

    new = stacks[6]->top;
    for (int i = 0; i < 4; ++i) {
        if(new != NULL){
            printf(" %c", char_val(new->elem));
            new = new->prev;
        }
    }

    printf("|\n--------|\nstack 7\n--------|\n");

    new = stacks[7]->top;
    for (int i = 0; i < 4; ++i) {
        if(new != NULL){
            printf(" %c", char_val(new->elem));
            new = new->prev;
        }
    }

    printf("|\n--------|\n");

}

int juegoterminado(STACK *stacks[]) {
    int vacios = 0;
    int stacksLlenos = 0;


    for (int i = 0; i < 8; ++i) {

        if (stacks[i]->size == 0) {
            vacios++;
        } else if(stacks[i]->size < 4){
            return 0;
        } else
            {
                struct STRSNODE *new = stacks[i]->top;
                char prev_color = char_val(new->elem);


                for (int j = 1; j < 4; ++j) {
                    new = new->prev;
                    if (prev_color != char_val(new->elem)) {
                        return 1;
                    }
                }
                stacksLlenos++;
            }
    }

    if (vacios == 2 && stacksLlenos == 6) {
        return 1;
    }

    return 0;
}


int main() {

    STACK* stacks[8];

    // Inicializar todas las pilas
    for (int i = 0; i < 8; i++) {
        stacks[i] = stack_new();
    }

    inicializarStacks(stacks);
    printStacks(stacks);

    int desde, destino;

    while (1){
        printf("De:");
        scanf("%i",&desde);
        printf("a:");
        scanf("%i",&destino);
        if(stack_confirmar(stacks,desde,destino)){
            mover_elementos(stacks,desde,destino);
            printf("elemento agregado correctamente\n");
        }else{
            printf("No se puede mover el elemento\n");
        }
        printStacks(stacks);
        if(juegoterminado(stacks)){
            break;
        }
    }

    printf("Felicidades, completaste el juego\n");
    liberarStacks(stacks);
    return 0;
}

TYPE inicializarStacks(STACK *stacks[]) {

    int cont0 = 0,cont1 = 0,cont2 = 0,cont3 = 0,cont4 = 0,cont5 = 0;
    int contblanco = 0,contazul = 0,controjo = 0,contverde = 0,contnaranja = 0,contmorado = 0;

    srand(time(NULL));

    while (1) {
        int randomstack = rand() % 6;
        int randomcolor = rand() % 6;

        if (randomstack == 0) {
            if (cont0 < 4) {
                if (randomcolor == 0 && contblanco < 4) {
                    char color = 'b';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[0], elem);
                    cont0++;
                    contblanco++;
                } else if (randomcolor == 1 && contazul < 4) {
                    char color = 'a';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[0], elem);
                    cont0++;
                    contazul++;
                } else if (randomcolor == 2 && controjo < 4) {
                    char color = 'r';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[0], elem);
                    cont0++;
                    controjo++;
                } else if (randomcolor == 3 && contverde < 4) {
                    char color = 'v';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[0], elem);
                    cont0++;
                    contverde++;
                } else if (randomcolor == 4 && contnaranja < 4) {
                    char color = 'n';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[0], elem);
                    cont0++;
                    contnaranja++;
                } else if (randomcolor == 5 && contmorado < 4) {
                    char color = 'm';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[0], elem);
                    cont0++;
                    contmorado++;
                }
            }
        }
        else if (randomstack == 1) {
            if (cont1 < 4) {
                if (randomcolor == 0 && contblanco < 4) {
                    char color = 'b';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[1], elem);
                    cont1++;
                    contblanco++;
                } else if (randomcolor == 1 && contazul < 4) {
                    char color = 'a';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[1], elem);
                    cont1++;
                    contazul++;
                } else if (randomcolor == 2 && controjo < 4) {
                    char color = 'r';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[1], elem);
                    cont1++;
                    controjo++;
                } else if (randomcolor == 3 && contverde < 4) {
                    char color = 'v';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[1], elem);
                    cont1++;
                    contverde++;
                } else if (randomcolor == 4 && contnaranja < 4) {
                    char color = 'n';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[1], elem);
                    cont1++;
                    contnaranja++;
                } else if (randomcolor == 5 && contmorado < 4) {
                    char color = 'm';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[1], elem);
                    cont1++;
                    contmorado++;
                }
            }
        }
        else if (randomstack == 2) {
            if (cont2 < 4) {
                if (randomcolor == 0 && contblanco < 4) {
                    char color = 'b';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[2], elem);
                    cont2++;
                    contblanco++;
                } else if (randomcolor == 1 && contazul < 4) {
                    char color = 'a';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[2], elem);
                    cont2++;
                    contazul++;
                } else if (randomcolor == 2 && controjo < 4) {
                    char color = 'r';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[2], elem);
                    cont2++;
                    controjo++;
                } else if (randomcolor == 3 && contverde < 4) {
                    char color = 'v';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[2], elem);
                    cont2++;
                    contverde++;
                } else if (randomcolor == 4 && contnaranja < 4) {
                    char color = 'n';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[2], elem);
                    cont2++;
                    contnaranja++;
                } else if (randomcolor == 5 && contmorado < 4) {
                    char color = 'm';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[2], elem);
                    cont2++;
                    contmorado++;
                }
            }
        }
        else if (randomstack == 3) {
            if (cont3 < 4) {
                if (randomcolor == 0 && contblanco < 4) {
                    char color = 'b';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[3], elem);
                    cont3++;
                    contblanco++;
                } else if (randomcolor == 1 && contazul < 4) {
                    char color = 'a';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[3], elem);
                    cont3++;
                    contazul++;
                } else if (randomcolor == 2 && controjo < 4) {
                    char color = 'r';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[3], elem);
                    cont3++;
                    controjo++;
                } else if (randomcolor == 3 && contverde < 4) {
                    char color = 'v';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[3], elem);
                    cont3++;
                    contverde++;
                } else if (randomcolor == 4 && contnaranja < 4) {
                    char color = 'n';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[3], elem);
                    cont3++;
                    contnaranja++;
                } else if (randomcolor == 5 && contmorado < 4) {
                    char color = 'm';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[3], elem);
                    cont3++;
                    contmorado++;
                }
            }
        }
        else if (randomstack == 4) {
            if (cont4 < 4) {
                if (randomcolor == 0 && contblanco < 4) {
                    char color = 'b';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[4], elem);
                    cont4++;
                    contblanco++;
                } else if (randomcolor == 1 && contazul < 4) {
                    char color = 'a';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[4], elem);
                    cont4++;
                    contazul++;
                } else if (randomcolor == 2 && controjo < 4) {
                    char color = 'r';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[4], elem);
                    cont4++;
                    controjo++;
                } else if (randomcolor == 3 && contverde < 4) {
                    char color = 'v';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[4], elem);
                    cont4++;
                    contverde++;
                } else if (randomcolor == 4 && contnaranja < 4) {
                    char color = 'n';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[4], elem);
                    cont4++;
                    contnaranja++;
                } else if (randomcolor == 5 && contmorado < 4) {
                    char color = 'm';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[4], elem);
                    cont4++;
                    contmorado++;
                }
            }
        }
        else if (randomstack == 5) {
            if (cont5 < 4) {
                if (randomcolor == 0 && contblanco < 4) {
                    char color = 'b';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[5], elem);
                    cont5++;
                    contblanco++;
                } else if (randomcolor == 1 && contazul < 4) {
                    char color = 'a';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[5], elem);
                    cont5++;
                    contazul++;
                } else if (randomcolor == 2 && controjo < 4) {
                    char color = 'r';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[5], elem);
                    cont5++;
                    controjo++;
                } else if (randomcolor == 3 && contverde < 4) {
                    char color = 'v';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[5], elem);
                    cont5++;
                    contverde++;
                } else if (randomcolor == 4 && contnaranja < 4) {
                    char color = 'n';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[5], elem);
                    cont5++;
                    contnaranja++;
                } else if (randomcolor == 5 && contmorado < 4) {
                    char color = 'm';
                    TYPE *elem = char_new(color);
                    stack_push(stacks[5], elem);
                    cont5++;
                    contmorado++;
                }
            }
        }


        // Verificar si todos los stacks están llenos y salir del bucle si es así
        if (cont0 == 4 && cont1 == 4 && cont2 == 4 && cont3 == 4 &&
            cont4 == 4 && cont5 == 4) {
            stacks[0]->size = 4;
            stacks[1]->size = 4;
            stacks[2]->size = 4;
            stacks[3]->size = 4;
            stacks[4]->size = 4;
            stacks[5]->size = 4;
            stacks[6]->size = 0;
            stacks[7]->size = 0;

            break;
        }
    }

}

// REFERENCIAS
/*

Implement an array of stacks in C. (n.d.). Stack Overflow. https://stackoverflow.com/questions/1720911/implement-an-array-of-stacks-in-c

*/