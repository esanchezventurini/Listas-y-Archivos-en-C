#include <stdio.h>
#include <stdlib.h>



void leerArchivo(FILE *archivo, char* nombreArchivo){   //Lee lineas enteras
    char temporal[100];
    int terminado = 0;
    if(archivo = fopen(nombreArchivo,"r")){
        terminado = fscanf(archivo," %[^\n]",&temporal);
        while(terminado!=EOF){
            printf("%s \n", temporal);
            terminado = fscanf(archivo," %[^\n]",&temporal);
        }
        fclose(archivo);
    }
    else{
        printf("No se pudo abrir el archivo \n");
    }
}

void leerArchivoPorCaracter(FILE* archivo, char* nombreArchivo) {  //Lee caracter por caracter
    char caracter;
    if(archivo = fopen(nombreArchivo, "r")){
        while(caracter != EOF){
            caracter = fgetc(archivo);
            printf("%c",caracter);
        }
    }
    else{
        printf("No se pudo abrir el archivo \n");
    }
    fclose(archivo);
}

void leerArchivoPorLinea(FILE* archivo, char* nombreArchivo) {  //Lee lineas de hasta 100 caracteres
    char caracteres[100];
    if(archivo=fopen(nombreArchivo,"r")){
        while(!feof(archivo)){
            fgets(caracteres,101,archivo);
            printf("%s",caracteres);
        }
        fclose(archivo);
    }
}

void agregarLineaEnArchivo(FILE* archivo, char* nombreArchivo, char* textoAIngresar){  //Agrega una linea (un char*). Crea el archivo si no existe
    if(archivo = fopen(nombreArchivo , "a")){
        fprintf(archivo,"%s \n",textoAIngresar);
        fclose(archivo);
    }
    else{
        printf("No se pudo escribir en el archivo \n");
    }
}

int cantidadLineasArchivo(FILE* archivo, char* nombreArchivo){
    char caracteres[100];
    int contador = 0;
    if(archivo = fopen(nombreArchivo,"r")){
        while(!feof(archivo)){
            fgets(caracteres,101,archivo);
            contador++;
        }
        return contador;
        fclose(archivo);
    }
}

void leerUnaLinea(FILE* archivo, char* nombreArchivo, int posicionLinea){     //Lee el contenido de una determinada linea, su posicion se envia como parametro
    char auxiliar[100];
    if(archivo = fopen(nombreArchivo,"r")){
        if(posicionLinea <= cantidadLineasArchivo(archivo,nombreArchivo)){
            for(int i = 0; i < posicionLinea; i++){
                fgets(auxiliar,100,archivo);
            }
            printf("%s \n",auxiliar);
        }
        else{
            printf("La linea %i no existe",posicionLinea);
        }
        fclose(archivo);
    }
}

int main()
{
    FILE *archivo;
    char* nombreArchivo = "prueba.txt";
    //agregarLineaEnArchivo(archivo,nombreArchivo,"Ingrese texto aqui");
    //leerArchivo(archivo,nombreArchivo);
    int cantidad = cantidadLineasArchivo(archivo,nombreArchivo);
    printf("El archivo tiene %i lineas \n",cantidad);
    //leerUnaLinea(archivo,nombreArchivo,7);
}
