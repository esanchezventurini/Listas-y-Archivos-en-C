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
    }
    else{
        printf("No se pudo abrir el archivo \n");
    }
    fclose(archivo);
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
    }
    fclose(archivo);
}

void agregarLineaEnArchivo(FILE* archivo, char* nombreArchivo, char* textoAIngresar){  //Agrega una linea (un char*). Crea el archivo si no existe
    if(archivo = fopen(nombreArchivo , "a")){
        fprintf(archivo,"%s \n",textoAIngresar);
    }
    else{
        printf("No se pudo escribir en el archivo \n");
    }
    fclose(archivo);
}

int main()
{
    FILE *archivo;
    char* nombreArchivo = "prueba.txt";
    agregarLineaEnArchivo(archivo,nombreArchivo,"Ingrese texto aqui");
    leerArchivo(archivo,nombreArchivo);
}
