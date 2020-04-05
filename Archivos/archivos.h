#ifndef ARCHIVOS_H_
#define ARCHIVOS_H_

void leerArchivo(FILE *archivo, char* nombreArchivo);
void leerArchivoPorCaracter(FILE* archivo, char* nombreArchivo);
void leerArchivoPorLinea(FILE* archivo, char* nombreArchivo);
void agregarLineaEnArchivo(FILE* archivo, char* nombreArchivo, char* textoAIngresar);
int cantidadLineasArchivo(FILE* archivo, char* nombreArchivo);
void leerUnaLinea(FILE* archivo, char* nombreArchivo, int posicionLinea);


#endif // ARCHIVOS_H_
