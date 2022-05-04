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

    char codigo[7];
    char grupo[10];
    char especie[20];
    char nacimiento[11];
    char sexo;
    char premio;
    char nomre[30];

}estructura_animal;


/**************************************************************************/
/* Declaracion funciones*/
/**************************************************************************/
int date_check(const char date[11]);
void get_other(estructura_animal *reg_animal);
void get_code(estructura_animal *reg_animal);


int main(){

    estructura_animal reg_animal;
    FILE *file_animales;
    char resp;

    file_animales=fopen("animales.dat","wb");


    system("color F0");
    do{
        get_code(&reg_animal);
        printf("\n");
        printf("\n");
        get_other(&reg_animal);

        printf("\n");

        do{
            printf("\n\tDesea guardar los datos en el disco(S/n):");
            fflush(stdin);
            resp=toupper(getchar());
            if(resp=='S'||resp=='\n'){
                fwrite(&reg_animal,sizeof(estructura_animal),1,file_animales);
                printf("\n\tEscito en fichero");
        }}while(resp!='N' && resp!='S' && resp!='\n');

        do{
            resp='S';
            printf("\n\n\tDesea introducir otro animal(S/n):");
            fflush(stdin);
            resp=toupper(getchar());
        }while(resp!='N' && resp!='S' && resp!='\n');

    }while(resp=='S'||resp=='\n');


    fclose(file_animales);

    return 0;
}



/**************************************************************************/
/* Subprograma: Obtencion y chequeo codigo zoologico */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe un registro animal pasado por referencia*/
/* Objetivo: Ingreso del codigo del animal y comprobacion de que este sea correcto */
/**************************************************************************/
void get_code(estructura_animal *reg_animal){

    do{
        system("cls");
        printf("\n\n Introduzca el codigo del animal de la forma (AA-000): ");
        reg_animal->codigo[0]=toupper(getch());
        putchar(reg_animal->codigo[0]);
        reg_animal->codigo[1]=toupper(getch());
        putchar(reg_animal->codigo[1]);
        printf("-");
        reg_animal->codigo[2]='-';
        reg_animal->codigo[3]=getch();
        putchar(reg_animal->codigo[3]);
        reg_animal->codigo[4]=getch();
        putchar(reg_animal->codigo[4]);
        reg_animal->codigo[5]=getch();
        putchar(reg_animal->codigo[5]);
        reg_animal->codigo[6]='\0';
    }while(((64>reg_animal->codigo[0])||(90<reg_animal->codigo[0]))||((64>reg_animal->codigo[1])||(90<reg_animal->codigo[1]))||((48>reg_animal->codigo[3])||(57<reg_animal->codigo[3]))||((48>reg_animal->codigo[4])||(57<reg_animal->codigo[4]))||((48>reg_animal->codigo[5])||(57<reg_animal->codigo[5])));

}


/**************************************************************************/
/* Subprograma: Obtencion resto de los datos del animal */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe un registro animal pasado por referencia*/
/* Objetivo: Pedir al usuario el resto de datos relaccionados con los animales */
/**************************************************************************/
void get_other(estructura_animal *reg_animal){

    int i;
    char grupos[6][10]={{"Mamiferos"},{"Aves"},{"Peces"},{"Anfibios"},{"Reptiles"}};

    //grupo
        printf("\n\n");
        printf("\t0-%s\n",grupos[0]);
        printf("\t1-%s\n",grupos[1]);
        printf("\t2-%s\n",grupos[2]);
        printf("\t3-%s\n",grupos[3]);
        printf("\t4-%s\n",grupos[4]);
    do{
        printf("\n  Seleccione una de las opciones:");
        scanf("%i",&i);
    }while(i<0||i>4);

    strcpy(reg_animal->grupo,grupos[i]);

    //fecha de nacimineto
    do{
        printf("\n  Introduzca la fecha de nacimineto:");
        reg_animal->nacimiento[0]=getch();
        putchar(reg_animal->nacimiento[0]);
        reg_animal->nacimiento[1]=getch();
        putchar(reg_animal->nacimiento[1]);
        reg_animal->nacimiento[2]='/';
        putchar(reg_animal->nacimiento[2]);
        reg_animal->nacimiento[3]=getch();
        putchar(reg_animal->nacimiento[3]);
        reg_animal->nacimiento[4]=getch();
        putchar(reg_animal->nacimiento[4]);
        reg_animal->nacimiento[5]='/';
        putchar(reg_animal->nacimiento[5]);
        reg_animal->nacimiento[6]=getch();
        putchar(reg_animal->nacimiento[6]);
        reg_animal->nacimiento[7]=getch();
        putchar(reg_animal->nacimiento[7]);
        reg_animal->nacimiento[8]=getch();
        putchar(reg_animal->nacimiento[8]);
        reg_animal->nacimiento[9]=getch();
        putchar(reg_animal->nacimiento[9]);
        reg_animal->nacimiento[10]='\0';

    }while(date_check(reg_animal->nacimiento)==1);

    do{
        printf("\n\n  Introduzca el sexo (H/M) hembra o macho:");
        fflush(stdin);
        reg_animal->sexo=toupper(getchar());
    }while((reg_animal->sexo!='H')&&(reg_animal->sexo!='M'));

    printf("\n  Introduzca el nombre:");
    fflush(stdin);
    fgets(reg_animal->nomre,30,stdin);

    printf("\n  Introduzca la especie:");
    fflush(stdin);
    fgets(reg_animal->especie,20,stdin);


    reg_animal->premio='N';


}


/**************************************************************************/
/* Subprograma: Chequeo fecha de nacimiento */
/* Tipo: Procedimiento (función tipo void) */
/* Prerrequisitos: Recibe un un string con la fecha en el formato dd/mm/aaaa*/
/* Objetivo: Comprobar que la fecha introducida sea coerente */
/**************************************************************************/
int date_check(const char date[10]){//devolver 1 si fecha erronea

    int day,mounth,year;


    day=((date[0]-48)*10)+(date[1]-48);
    mounth=((date[3]-48)*10)+(date[4]-48);
    year=((date[6]-48)*1000)+((date[7]-48)*100)+((date[8]-48)*10)+(date[9]-48);

    if(mounth>12){return 1;}
    else{
        if(day<28){return 0;}
        else{
            switch(day){
                case 28:
                    if(mounth==2){
                        return 0;
                    }else{
                        return 1;
                    }
                    break;
                case 29://((año divisible por 4) Y ((año no divisible por 100) O (año divisible por 400)))
                    if((mounth==2) && ((year%4==0)&&(year%100!=0)||(year%400==0))){
                        return 0;
                    }else{
                        return 1;
                    }
                    break;
                case 30:
                    if(mounth==4||mounth==6||mounth==9||mounth==11){
                        return 0;
                    }else{
                        return 1;
                    }
                    break;
                case 31:
                    if(mounth==1||mounth==3||mounth==5||mounth==7||mounth==8||mounth==10||mounth==12){
                        return 0;
                    }else{
                        return 1;
                    }
                    break;
                default:
                    return 1;
            }
        }
    }

}
