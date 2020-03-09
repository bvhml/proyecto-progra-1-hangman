#include <stdio.h>
#include <stdlib.h>
// I need string functions, strcpy
// https://www.programiz.com/c-programming/library-function/string.h
#include <string.h>
#include <time.h>

// Macros https://gcc.gnu.org/onlinedocs/cpp/Object-like-Macros.html#Object-like-Macros
// este macro dictara la cantidad maxima de palabras que habra en nuestro banco de palabras
#define MAX_WORDS 23



// # FUNCTION PROTOTYPES
// defina aqui todos los prototipos de funciones que vaya a implementar.
const char* get_random_word(void);
void clearscreen(){
    system("@cls||clear");
}
void message(char* msg){
    char* wait;
    clearscreen();
    printf("%s",msg);
    scanf("%s", wait);
    clearscreen();
}

void jugar(){
    const char* palabra_elegida = get_random_word();
    char* user;
    char entrada[] = "";
    int palabra_length = strlen(palabra_elegida);
    int entrada_length;
    char palabra_oculta[] = "";
    int intentos = 10;
    int aciertos = 0;
    clearscreen();
    printf("Ingresa tu nombre: ");
    scanf("%s", user);
    for(int i = 0; i < palabra_length + 1; i++){
        palabra_oculta[i] = *"_";
    }
    while (intentos > 0){
        clearscreen();
        printf("Jugador: %s\n",user);
        printf("Intenstos: %d/10\n", intentos);
        printf("Aciertos %d\n", aciertos);
        printf("Palabra: %s\n\n\t", palabra_elegida);
        for(int i = 0; i < palabra_length; i++){
            printf("%c ",  *(palabra_oculta + i));
        }
        printf("\n\nIngresa una letra: ");
        scanf("%s",entrada);
        entrada_length = strlen(entrada);
        for(int j = 0; j < palabra_length; j++){
            if(palabra_elegida[j] == entrada[0]){
                palabra_oculta[j] = palabra_elegida[j];
                aciertos++;
            }
        }
        if(strcmp(palabra_elegida, palabra_oculta) < 0){
            clearscreen();
            printf("Palabra adivinada: %s\n", palabra_elegida);
            printf("Jugador: %s\n", user);
            printf("Intentos: %d/10\n\n", intentos);
            break;
        }else{
            intentos--;
        }
    }
    if (intentos == 0){
        printf("Palabra a adivinadar: %s\n", palabra_elegida);
        printf("Jugador: %s\n", user);
        printf("Intentos: %d/10\n\n", intentos);
        scanf("%s", entrada);
    }
    printf("Presione cualquier tecla seguido de enter para volver a Menu\n");
    scanf("%s", entrada);
    exit(0);
}

void menu(){
    int opciones;
    printf("\n 1. Juegar\n 2. Ver Instrucciones\n 3. About\n 4. Salir\n");
    scanf("%d", &opciones);
    switch (opciones){
        case 4: exit(0); break; 
        case 3:
        message("Desarrollador: Regina S Morales L 20190379 Estuadiante de la Universidad Francisco Marroquín de la carrera Ingenieria Empresarial, Segundo año.");
        menu();break;
        case 2: 
        message("Instrucciones: \n Para comenzar se dará en una palabra y se dibujará  una línea por cada letra. \nEn el turno del jugador se pedirá una letra o adivinar la palabra. Y se revisará si la letra pedida, se encuentra en la palabra secreta. \n Si la letra está, entonces el juego lo anotará en lugar de  la línea que ocupa su lugar en la palabra secreta.\n Si la letra no está, entonces se anotará la letra y dibujará una linea en la parte del hagnman. \n El hagnman se tendra cabeza, tronco y extremidades. \n Si acierta la palabra, entonces se completa la solución en el papel.");
        menu(); break;
        case 1: jugar();  break; 
        default: exit(0); break;
    }
}

// Global variables
// este sera nuestro banco de palabras, por favor agregue, quite, modifique las palabras que quiera
// puede agregar hasta un maximo de MAX_WORDS palabras, si desea agregar mas de 23 palabras
// modifique MAX_WORDS a la cantidad que se ajuste a sus necesidades.
// ! NO AGREGUE PALABRAS QUE CONTENGAN NUMEROS
// ? este es un arreglo de strings, un arreglo de punteros ;)
const char *word_collection[MAX_WORDS]= {
                    "zapato","hola","vegetal","banco","pescado",
                    "palabras","sientase","marroquin","libertad",
                    "universidad","agregar","cosas","cantidad","musica",
                    "palabra","lampara","usted","desee","hasta",
                    "programacion","maximo","comida","bruh"
                    };

/*
 ? function get_random_word(), no recibe argumentos porque trabajara con la variable global word_collection (banco de palabras)
 ? y devolvera una palabra aleatoria del banco de palabras
 */
const char* get_random_word(void){
    // seed the random generator.
    srand ( time (0) );
    // obtain a 0 < randon number < MAX_WORDS
    int random_position = rand() % MAX_WORDS;
    //printf("Random number is: %i\n", random_position);
    return word_collection[random_position];
}



/*
Insert your code here
*/

int main(){
    // note como se invoca la funcion, la funcion se invoca de esta manera y se guarda en una variable
    clearscreen();
    printf ("Bienvenido, por favor seleccione una opcion: ");
    menu();

    // comparemos 2 strings. puede remover estas lineas.
    // char str1[] = "abcd", str2[] = "abcd", str3[]="abCd";
    // printf("strcmp(str1, str2) = %d\n", strcmp(str1,str2));
    // printf("strcmp(str1, str2) = %d\n", strcmp(str1,str3));

    /*
        Insert your code here
    */
    return 0;
}
