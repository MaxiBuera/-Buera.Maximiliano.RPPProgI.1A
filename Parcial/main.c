#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//1.Desarrollar una función llamada duplicar impares, que reciba un vector de enteros y su tamaño y duplique los valores impares. *
void duplicarImpares(int vectorEnteros[], int tam);
void mostrarResutlado1(int vectorEnteros[], int tam);

/*2.Desarrollare una función que se llame subirVocales que reciba solo una cadena de
 caracteres como parámetro y su responsabilidad es buscar vocales en minúsculas en la
 cadena y pasarlas a mayúsculas. Ejemplo si le pasamos "aleatoriamente" la deja como "AlEAtOrIAmEntE" */
void subirVocales(char* cadena);

/*3. Dada las estructuras de la imagen. Hardcodear un array de estructuras eComida de tamaño 5 y escribir el código que lo
ordene decreciente por año de vencimiento y ante igualdad de año lo ordene alfabéticamente por descripción */
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char descripcion[20];
    float precio;
    eFecha fechaVencimiento;
    int isEmpty;
}eComida;

int tamArray=5;
eComida arrayComidas[5] = {
    {0,"Hamburgesa",10,{22,1,2020},1},
    {1,"Papas",20,{2,1,2015},1},
    {2,"Sopa",16,{1,1,2010},1},
    {3,"Pollo",80,{3,1,2014},1},
    {4,"Ensalada",20,{10,1,2019},1}
};
void ordenarArray(eComida* arrayComidas,int tamArray);

int main()
{
    //1)
    int tam = 5;
    int vectorEnteros[] = {1,5,4,6,8};
    duplicarImpares(vectorEnteros,tam);
    mostrarResutlado1(vectorEnteros,tam);
    printf("\n");

    //2)
    char cadena[20]="aleatoriamente";
    subirVocales(cadena);
    printf("\n%s",cadena);

    //3)
    int i;
    ordenarArray(arrayComidas,tamArray);
    for(i=0;i<tamArray;i++){

        printf("\n%s %d",arrayComidas[i].descripcion,arrayComidas[i].fechaVencimiento.anio);
    }
    printf("\n");

    return 0;
}

void duplicarImpares(int vectorEnteros[], int tam){

    if(vectorEnteros != NULL && tam > 0){

        int i;
        for(i=0;i<tam;i++){

            if(vectorEnteros[i] % 2 == 0){
                vectorEnteros[i] = vectorEnteros[i] + vectorEnteros[i];
            }
        }
    }
}

void mostrarResutlado1(int vectorEnteros[], int tam){

    int i;
    for(i=0;i<tam;i++){

        printf("%d-",vectorEnteros[i]);
    }
}


void subirVocales(char* cadena){

    int i=0;

    while(cadena[i] != '\0'){

        if(cadena[i] == 'a' || cadena[i] == 'e'|| cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u'){

            cadena[i] = toupper(cadena[i]);
        }

        i++;
    }
}


void ordenarArray(eComida* arrayComidas,int tamArray){

    int i,j;
    eComida auxiliar;

    if(arrayComidas != NULL)
    {
        for(i=0;i<tamArray-1;i++){

            for(j=i+1;j<tamArray;j++){

                if(arrayComidas[i].fechaVencimiento.anio < arrayComidas[j].fechaVencimiento.anio){

                    auxiliar = arrayComidas[i];
                    arrayComidas[i] = arrayComidas[j];
                    arrayComidas[j] = auxiliar;
                }
                else if(arrayComidas[i].precio < arrayComidas[j].fechaVencimiento.anio && (strcmp(arrayComidas[i].descripcion, arrayComidas[j].descripcion) == 0 )){

                    auxiliar = arrayComidas[i];
                    arrayComidas[i] = arrayComidas[j];
                    arrayComidas[j] = auxiliar;
                }
            }
        }
    }

}


