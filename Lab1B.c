#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Asignatura: Metodología de la programación
Alumno 1: <Leiro Arroyo Guillermo>
Alumno 2: <Void>
Grupo: <37>
Curso: 1º - Fecha: <29 Abril 2018>
*/

/**************************************************************************/
/* Estructuras de datos*/
/**************************************************************************/
typedef struct{

    char codigo[6];
    char tipo[10];
    char ciudad[20];
    float extension;
    int n_especies;
    float importe;
    char guia[30];

}struct_zoo;


/**************************************************************************/
/* Declaracion de funciones*/
/**************************************************************************/
void get_code(struct_zoo *reg_zoo);
void get_other_things(struct_zoo *reg_zoo);
void quitar_n(char cadena[]);


int main(){

    struct_zoo reg_zoo;
    FILE *file_zoos;
    int i;
    char resp;

    file_zoos=fopen("zoologicos.txt","w");

    system("color F0");
    do{
        get_code(&reg_zoo);
        get_other_things(&reg_zoo);


        do{
                printf("\n\tDesea guardar los datos en el disco(S/n):");
                fflush(stdin);
                resp=toupper(getchar());
                if(resp=='S'||resp=='\n'){
                    fprintf(file_zoos,"%s#%s#%s#%f#%i#%f#%s#\n",reg_zoo.codigo,reg_zoo.tipo,reg_zoo.ciudad,reg_zoo.extension,reg_zoo.n_especies,reg_zoo.importe,reg_zoo.guia);
                    printf("\tDatos guardados en el disco.\n\n\n");
            }}while(resp!='N' && resp!='S' && resp!='\n');

            do{
                resp='S';
                printf("\tDesea introducir otro animal(S/n):");
                fflush(stdin);
                resp=toupper(getchar());
            }while(resp!='N' && resp!='S' && resp!='\n');

    }while(resp=='S'||resp=='\n');

    fclose(file_zoos);
    return 0;
}

/**************************************************************************/
/* Subprograma: Obtencion y chequeo codigo animal */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe un registro animal pasado por referencia*/
/* Objetivo: Ingreso del codigo del animal y comprobacion de que este sea correcto */
/**************************************************************************/
void get_code(struct_zoo *reg_zoo){

    do{
        system("cls");
        printf("\n\n Introduzca el codigo del zologico de la siguiente forma (AAA00): ");
        reg_zoo->codigo[0]=toupper(getch());
        putchar(reg_zoo->codigo[0]);
        reg_zoo->codigo[1]=toupper(getch());
        putchar(reg_zoo->codigo[1]);
        reg_zoo->codigo[2]=toupper(getch());
        putchar(reg_zoo->codigo[2]);
        reg_zoo->codigo[3]=getch();
        putchar(reg_zoo->codigo[3]);
        reg_zoo->codigo[4]=getch();
        putchar(reg_zoo->codigo[4]);
        reg_zoo->codigo[5]='\0';

    }while(((64>reg_zoo->codigo[0])||(90<reg_zoo->codigo[0]))||((64>reg_zoo->codigo[1])||(90<reg_zoo->codigo[1]))||((64>reg_zoo->codigo[2])||(90<reg_zoo->codigo[2]))||((48>reg_zoo->codigo[3])||(57<reg_zoo->codigo[3]))||((48>reg_zoo->codigo[4])||(57<reg_zoo->codigo[4])));

}


/**************************************************************************/
/* Subprograma: Obtencion resto de los datos del animal */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe un registro animal pasado por referencia*/
/* Objetivo: Pedir al usuario el resto de datos relaccionados con los animales */
/**************************************************************************/
void get_other_things(struct_zoo *reg_zoo){

    char aux;

    do{
        printf("\n\n\t(acuatico/terrestre)\n");
        printf("  Tipo de zologico(A/T): ");
        fflush(stdin);
        aux=toupper(getchar());
    }while(aux!='A'&&aux!='T');

    if(aux=='A'){
        strcpy(reg_zoo->tipo,"Acuatico\0");
    }else{
        strcpy(reg_zoo->tipo,"Terrestre\0");
    }

    printf("\n  Ciuda de la instalacion: ");
    fflush(stdin);
    fgets(reg_zoo->ciudad,20,stdin);
    quitar_n(reg_zoo->ciudad);

    printf("\n  Extenxion de las instalaciones en Km: ");
    scanf("%f",&reg_zoo->extension);
    fflush(stdin);//estos fflush() despues de coger un numero los pongo por si se introduce una letra que no se salte los guientes campos aunque el numero almacenado sera el correspondiente al caracter ascii.

    printf("\n  Numero de especies: ");
    scanf("%i",&reg_zoo->n_especies);
    fflush(stdin);

    printf("\n  Importe: ");
    scanf("%f",&reg_zoo->importe);
    fflush(stdin);

    printf("\n  Guia del centro: ");
    fflush(stdin);
    fgets(reg_zoo->guia,30,stdin);
    quitar_n(reg_zoo->guia);


}


/**************************************************************************/
/* Subprograma: Quitar el \n */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe un un string cualquiera*/
/* Objetivo: Remplazar el \n del final de la cadena por un \0 */
/**************************************************************************/
void quitar_n(char cadena[]){

    int i,j;

    for(i=0;cadena[i]!='\n' && i<=strlen(cadena);i++){


    }
    if(cadena[i]=='\n'){
        cadena[i]='\0';
    }

}
