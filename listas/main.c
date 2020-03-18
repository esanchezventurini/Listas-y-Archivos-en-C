#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
   char nombreAlumno[60];
   int legajoAlumno;
   int promedio;
}alumno;

typedef struct nod
{
   alumno info;
   struct nod *sgte;
}nodo;

nodo *crearNodo(alumno informacion) {
    nodo *nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->info = informacion;
    nuevoNodo -> sgte =NULL;
    return nuevoNodo;
}

nodo* buscarAlumnoPorLegajo(nodo *cabezaLista, int legajo)
{
   nodo* aux = cabezaLista;

    while(aux && aux->info.legajoAlumno != legajo)
    {
        aux = aux->sgte;
    }
    return aux;
}

nodo* alumnoAnterior(nodo* nodoAlumno, nodo* cabezaLista){
    nodo* aux = cabezaLista;
    if(nodoAlumno == cabezaLista){
        return NULL;
    }
    else{
        while(aux -> sgte != nodoAlumno){
            aux = aux -> sgte;
        }
        return aux;
    }
}

int elAlumnoExiste(int legajo, nodo* cabezaLista){
    nodo* aux = NULL;
    aux = buscarAlumnoPorLegajo(cabezaLista,legajo);
    if(aux){
        return 1;
    }
    else{
        return 0;
    }
}

nodo *agregarAlumnoOrdenadoPorPromedio(nodo *cabezaLista, alumno informacion) {
    nodo *nuevoNodo = crearNodo(informacion);
    nodo *aux;
    nodo *aux2;

    if(cabezaLista == NULL)
    {
        cabezaLista = nuevoNodo;
    }
    else
    {
        if(!elAlumnoExiste(informacion.legajoAlumno,cabezaLista)){
            if(cabezaLista->info.promedio < informacion.promedio){
                aux = cabezaLista;
                cabezaLista = nuevoNodo;
                nuevoNodo->sgte = aux;
            }
            else{
                aux = cabezaLista;
                aux2 = cabezaLista->sgte;
                while(aux2 && (aux2->info.promedio > informacion.promedio)){
                    aux = aux2;
                    aux2 = aux2->sgte;
                }
                aux->sgte = nuevoNodo;
                nuevoNodo->sgte = aux2;
            }
        }
    }
    return cabezaLista;
}

nodo *agregarAlumno(nodo *cabezaLista, alumno informacion) {
    nodo *nuevoNodo = crearNodo(informacion);
    nodo *aux = cabezaLista;

    if(cabezaLista == NULL)
    {
        cabezaLista = nuevoNodo;
    }
    else
    {
       if(!elAlumnoExiste(informacion.legajoAlumno,cabezaLista)){
           while(aux->sgte)
           {
               aux = aux->sgte;
           }
           aux->sgte = nuevoNodo;
        }
    }
    return cabezaLista;
}

void modificarPromedio(nodo* cabezaLista, int legajoAlumno, int nuevoPromedio){
    if(elAlumnoExiste(legajoAlumno,cabezaLista)){
        nodo* nodoLoco = buscarAlumnoPorLegajo(cabezaLista,legajoAlumno);
        nodoLoco->info.promedio = nuevoPromedio;
    }
    else{
        printf("El alumno buscado no existe. Pulse una tecla para volver al menu");
        getch();
    }
}

void imprimirNodo(nodo *unNodo)
{
    if(unNodo){
            printf("Nombre y apelldio: %s \n", unNodo->info.nombreAlumno);
            printf("Legajo: %i \n", unNodo->info.legajoAlumno);
            printf("Promedio: %i \n \n", unNodo->info.promedio);
        }
}

void imprimirLista(nodo* cabezaLista){
    nodo* aux;
    aux = cabezaLista;
    while(aux){
        imprimirNodo(aux);
        aux = aux -> sgte;
    }
}

int cantidadAlumnos(nodo* cabezaLista){
    int cantidad = 0;
    nodo* aux = cabezaLista;
    while(aux){
        cantidad++;
        aux = aux->sgte;
    }
    return cantidad;
}

nodo* ultimoAlumno(nodo* cabezaLista){
    nodo* aux = cabezaLista;
    while(aux->sgte){
        aux = aux->sgte;
    }
    return aux;
}

nodo* eliminarAlumno(nodo* cabezaLista, int legajo){
    if(elAlumnoExiste(legajo,cabezaLista)){
        nodo *aBorrar = buscarAlumnoPorLegajo(cabezaLista,legajo);
        if(alumnoAnterior(aBorrar,cabezaLista)){
            nodo* anterior = alumnoAnterior(aBorrar, cabezaLista);
            anterior->sgte = aBorrar->sgte;
            free(aBorrar);
        }
        else{
            cabezaLista = aBorrar->sgte;
            free(aBorrar);
        }
    }
    else{
        printf("El alumno que desea eliminar no existe. Pulse una tecla para continuar.");
        getch();
    }
    return cabezaLista;
}

void menu(){
    nodo* lista = NULL;
    int seleccion = 0;

    while(seleccion != 9){

        printf("Ingrese 1 para agregar un alumno \nIngrese 2 para consultar la lista de alumnos \nIngrese 3 para modiciar el promedio de un alumno\nIngrese 4 para eliminar un alumno \nIngrese 9 para finalizar\n");
        scanf("%i",&seleccion);
        system("cls");

        if(seleccion == 1){
            alumno nuevoAlumno;
            fflush(stdin);
            printf("Ingrese nombre y apellido \n");
            fflush(stdin);
            scanf("%[^\n]",nuevoAlumno.nombreAlumno);
            printf("Ingrese legajo \n");
            fflush(stdin);
            scanf("%i",&nuevoAlumno.legajoAlumno);
            printf("Ingrese promedio \n");
            fflush(stdin);
            scanf("%i",&nuevoAlumno.promedio);
            lista = agregarAlumnoOrdenadoPorPromedio(lista,nuevoAlumno);
        }
        if(seleccion == 2){
            printf("LISTA DE ALUMNOS: \n \n");
            imprimirLista(lista);
            printf("Presione una tecla para volver al menu \n");
            getch();
        }
        if(seleccion == 3){
            int legajo;
            int nuevoPromedio;
            fflush(stdin);
            printf("Ingrese legajo \n");
            scanf("%i",&legajo);
            fflush(stdin);
            printf("Ingrese el nuevo promedio \n");
            scanf("%i",&nuevoPromedio);
            modificarPromedio(lista, legajo, nuevoPromedio);
        }
        if(seleccion == 4){
            int legajo;
            printf("Ingrese legajo \n");
            scanf("%i",&legajo);
            fflush(stdin);
            lista = eliminarAlumno(lista,legajo);
        }
        system("cls");
    }
}



int main()
{
    menu();

/*
    Asi podría cargarse e imprimirse la lista de forma manual:

    nodo* nuevaLista = NULL;

    alumno informacionPrimerAlumno;
    alumno informacionSegundoAlumno;

    strcpy (informacionPrimerAlumno.nombreAlumno , "Pedro El Pollo");
    informacionPrimerAlumno.legajoAlumno = 1678539;
    informacionPrimerAlumno.promedio = 8;

    strcpy (informacionSegundoAlumno.nombreAlumno , "Juan Carlos Trico");
    informacionSegundoAlumno.legajoAlumno = 1950231;
    informacionSegundoAlumno.promedio = 5;

    nuevaLista = agregarAlumno(nuevaLista, informacionPrimerAlumno);
    nuevaLista = agregarAlumno(nuevaLista, informacionSegundoAlumno);

    imprimirLista(nuevaLista);
*/



    return 0;
}



