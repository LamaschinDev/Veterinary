/*  ACTIVIDAD INTEGRADORA: VETERINARIA

    MATERIA: PROGRAMACIÓN
    PROFESORA: OSORIO ANGEL, SONIA
    ALUMNO: LAMAS ABBADIE, ADOLFO BENJAMIN
    CARRERA: INGENIERÍA EN INFORMATICA
    CLAVE: I5882
    SECCIÓN: D23

    CONSEJO: leer todos los comentarios del código para entender más facilmente la función de cada sección.
*/

//Librerías
#include <stdio.h> //Librería principal para la realización del código.
#include <string.h> //Para el uso de funciones para acomodar el registro por orden alfabetico.
#include <stdlib.h> //Librería principal para la realización del código.
#include <windows.h> //Para dar estética al código una vez en consola.
#include <conio.h> //Para detener el programa x segundos una vez en consola para dar una mejor estética visual al programa.
#define TAM 10 //Tamaño de mi vector para registrar mascotas, cambiar en caso de querer agregar más mascotas.

//Estructura
struct Mascotas{ //Estructura
    char Nombre[15];
    char Animal[30];
    float Peso;
    int Edad;
    char Propietario[50];
}pet[TAM];

//Guardar en un archivo
int Archivo(int t, int A){ //Guardar Registros en archivo en caso de ya haber registrado animales.
    if(t>0){
        system("cls");
        FILE* fichero;
        fichero= fopen("RegistroAnimales.txt", "wt"); //Nombre del archivo.
        if(t!=TAM+1){
            for (int j=0; j<t; j++){ //Se imprime en el archivo los datos del registro.
                fprintf(fichero, "===============Mascota %i===============\n\n", j+1);
                fprintf(fichero, " Nombre: %s", pet[j].Nombre);
                fprintf(fichero, "\n Animal: %s", pet[j].Animal);
                fprintf(fichero, "\n Peso: %.2f Kg", pet[j].Peso);
                if (pet[j].Edad==1){
                    fprintf(fichero, "\n Edad: %i a%co", pet[j].Edad, 164);
                }
                else{
                    fprintf(fichero, "\n Edad: %i a%cos", pet[j].Edad, 164);
                }
                fprintf(fichero, "\n Propietario: %s\n\n", pet[j].Propietario);
            }
            fprintf(fichero, "========================================");
            fclose(fichero);
        }
        else{ //Si se sale del programa sin guardar los datos y ya se registro y se borro un animal y no hay registros.
            fprintf(fichero, "\t\t\t\t\n\n"); //entonces el programa limpia el archivo completo, dejandolo en blanco.
            fprintf(fichero, "\t\t\t\t");
            fprintf(fichero, "\n\t\t\t\t");
            fprintf(fichero, "\n\t\t\t\t");
            fprintf(fichero, "\n\t\t\t\t");
            fprintf(fichero, "\n\t\t\t\t\n\n");
            fprintf(fichero, "\t\t\t\t");
            fclose(fichero);
        }
        for(int i=0; i<=1; i++){
            printf("\n\n\t\tGuardando Archivo.");
            Sleep(300);
            system("cls");
            printf("\n\n\t\tGuardando Archivo..");
            Sleep(300);
            system("cls");
            printf("\n\n\t\tGuardando Archivo...");
            Sleep(300);
            system("cls");
        }
        printf("\n\n\t\t***ARCHIVO GUARDADO***");
        printf("\n\n\t\tNOMBRE DEL ARCHIVO: RegistroAnimales");
        printf("\n\n\t\tTIPO DE ARCHIVO: .txt");
        Sleep(2000);
        A=0;
        return A;
    }
    else{
        system("cls");
        printf("\n\n\n\t\t\t***No hay registros para guardar en el archivo***", 163);
        Sleep(2000);
        return A;
    }
}

//Registrar
void Acomodo(int total){ //Acomodar por orden alfabetico los nombres.
    int i, j, iaux;
    float faux;
    char Naux[50], Aaux[30], aux3[50];

    for(i=0; i<total; i++){
        for(j=i+1; j<=total; j++){
            if(stricmp(pet[i].Nombre, pet[j].Nombre)>0){
                strcpy(Naux, pet[i].Nombre);//Nombre
                strcpy(pet[i].Nombre, pet[j].Nombre);
                strcpy(pet[j].Nombre, Naux);
                strcpy(Aaux, pet[i].Animal);//Animal
                strcpy(pet[i].Animal, pet[j].Animal);
                strcpy(pet[j].Animal, Aaux);
                faux=pet[i].Peso;//Peso
                pet[i].Peso=pet[j].Peso;
                pet[j].Peso=faux;
                iaux=pet[i].Edad;//Edad
                pet[i].Edad=pet[j].Edad;
                pet[j].Edad=iaux;
                strcpy(aux3, pet[i].Propietario);//Propietario
                strcpy(pet[i].Propietario, pet[j].Propietario);
                strcpy(pet[j].Propietario, aux3);
            }
        }
    }
}

int Registrar(int t){ //Registrar animales.
    if(t<TAM){
        system("cls");
        printf("    ===============REGISTRO===============\n");
        printf("\n\tNombre de la mascota: ");
        fflush(stdin);
        scanf("%[^\n]", &pet[t].Nombre);
        printf("\n\tTipo de animal: ");
        fflush(stdin);
        scanf("%[^\n]", &pet[t].Animal);
        printf("\n\tPeso: ");
        scanf("%f", &pet[t].Peso);
        printf("\n\tEdad: ");
        scanf("%i", &pet[t].Edad);
        printf("\n\tNombre el propietario: ");
        fflush(stdin);
        scanf("%[^\n]", &pet[t].Propietario);
        if (t>0){
            Acomodo(t);
        }
        system("cls");
        for(int i=0; i<=1; i++){
            printf("\n\n\t\tRegistrando animal.");
            Sleep(300);
            system("cls");
            printf("\n\n\t\tRegistrando animal..");
            Sleep(300);
            system("cls");
            printf("\n\n\t\tRegistrando animal...");
            Sleep(300);
            system("cls");
        }
        printf("\n\n\t\t***ANIMAL REGISTRADO***");
        Sleep(2000);
        t+=1;
    }
    else{
        system("cls");
        printf("\n\n\t\t***N%cmero de Registro m%cximo alcanzado***", 163, 160);
        printf("\n\n\t\t- Elimine 1 registro para poder hacer otro.");
        Sleep(2500);
    }
    return t;
}

//Mostrar
void Todos(int total){ //Mostrar todos los animales.
    system("cls");
    for (int j=0; j<total; j++){
        printf("===============Mascota %i===============\n\n", j+1);
        printf(" Nombre: %s", pet[j].Nombre);
        printf("\n Animal: %s", pet[j].Animal);
        printf("\n Peso: %.2f Kg", pet[j].Peso);
        if (pet[j].Edad==1){
            printf("\n Edad: %i a%co", pet[j].Edad, 164);
        }
        else{
            printf("\n Edad: %i a%cos", pet[j].Edad, 164);
        }
        printf("\n Propietario: %s\n\n", pet[j].Propietario);
    }
    printf("========================================");
}

void Tipo(int total){ //Mostrar un tipo de animal.
    int i, c=0;
    char aux[30];
    system("cls");
    printf("\n\t%cQu%c tipo de animal desea buscar?: ", 168, 130);
    fflush(stdin);
    scanf("%[^\n]", &aux);
    system("cls");
    for(i=0; i<total; i++){//Busqueda
        if(stricmp(aux, pet[i].Animal)==0){
            c+=1;
        }
    }
    for(int i=0; i<=1; i++){
        printf("\n\n\t\tBuscando animales.");
        Sleep(300);
        system("cls");
        printf("\n\n\t\tBuscando animales..");
        Sleep(300);
        system("cls");
        printf("\n\n\t\tBuscando animales...");
        Sleep(300);
        system("cls");
    }
    if(c!=0){//Impresión en caso de existir el animal buscado en los registros.
        printf("\nAnimales encontrados: %i\n", c);
        printf("\n------------------------------------\n");
        for(i=0; i<total; i++){
            if(stricmp(aux, pet[i].Animal)==0){
                printf("\n Nombre: %s", pet[i].Nombre);
                printf("\n Animal: %s", pet[i].Animal);
                printf("\n Peso: %.2f Kg", pet[i].Peso);
                if (pet[i].Edad==1){
                    printf("\n Edad: %i a%co", pet[i].Edad, 164);
                }
                else{
                    printf("\n Edad: %i a%cos", pet[i].Edad, 164);
                }
                printf("\n Propietario: %s", pet[i].Propietario);
                printf("\n\n====================================\n\n");
            }
        }
        printf("\n\nPresione cualquier tecla para continuar...");
        getch();
    }
    else{
        printf("\n\n\n\t\t\t***NO SE ENCONTRARON ANIMALES EN EL REGISTRO***");
        Sleep(2000);
    }
}

void Propietario(int total){ //Mostrar por nombre del propietario.
    int i, c=0;
    char aux[30];
    system("cls");
    printf("\n\t%cCu%cl es el nombre del propietario?: ", 168, 160);
    fflush(stdin);
    scanf("%[^\n]", &aux);
    system("cls");
    for(i=0; i<total; i++){//Busqueda
        if(stricmp(aux, pet[i].Propietario)==0){
            c+=1;
        }
    }
    for(int i=0; i<=1; i++){
        printf("\n\n\t\tBuscando propietario.");
        Sleep(300);
        system("cls");
        printf("\n\n\t\tBuscando propietario..");
        Sleep(300);
        system("cls");
        printf("\n\n\t\tBuscando propietario...");
        Sleep(300);
        system("cls");
    }
    if(c!=0){//Impresión en caso de existir el animal buscado en los registros.
        printf("\nAnimales encontrados del due%co: %i\n", 164, c);
        printf("\n------------------------------------\n");
        for(i=0; i<total; i++){
            if(stricmp(aux, pet[i].Propietario)==0){
                printf("\n Nombre: %s", pet[i].Nombre);
                printf("\n Animal: %s", pet[i].Animal);
                printf("\n Peso: %.2f Kg", pet[i].Peso);
                if (pet[i].Edad==1){
                    printf("\n Edad: %i a%co", pet[i].Edad, 164);
                }
                else{
                    printf("\n Edad: %i a%cos", pet[i].Edad, 164);
                }
                printf("\n Propietario: %s", pet[i].Propietario);
                printf("\n\n====================================\n");
            }
        }
        printf("\n\nPresione cualquier tecla para continuar...");
        getch();
    }
    else{
        printf("\n\n\n\t***NO SE ENCONTRARON ANIMALES EN EL REGISTRO CON EL NOMBRE DEL DUE%cO PROPORCIONADO***", 165);
        Sleep(2000);
    }
}

void Mascota(int total){ //Mostrar una mascota en específico.
    char Naux[15], Aaux[30], Paux[50];
    int i, s=0;
    system("cls");
    printf("\n\t====================Llene el siguiente formato para buscar la mascota====================");
    printf("\n\n\t\tNombre de la mascota: ");
    fflush(stdin);
    scanf("%[^\n]", &Naux);
    printf("\n\t\tAnimal: ");
    fflush(stdin);
    scanf("%[^\n]", &Aaux);
    printf("\n\t\tPropietario: ");
    fflush(stdin);
    scanf("%[^\n]", &Paux);
    system("cls");
    for (i=0; i<total; i++){
        if(stricmp(Naux, pet[i].Nombre)==0 && stricmp(Aaux, pet[i].Animal)==0 && stricmp(Paux, pet[i].Propietario)==0){
            s+=1;
        }
    }
    for(int i=0; i<=1; i++){
        printf("\n\n\t\tBuscando mascota.");
        Sleep(300);
        system("cls");
        printf("\n\n\t\tBuscando mascota..");
        Sleep(300);
        system("cls");
        printf("\n\n\t\tBuscando mascota...");
        Sleep(300);
        system("cls");
    }
    if(s>0){
        for (i=0; i<total; i++){
            if(stricmp(Naux, pet[i].Nombre)==0 && stricmp(Aaux, pet[i].Animal)==0 && stricmp(Paux, pet[i].Propietario)==0){
                printf("===============Mascota %i===============\n\n", i+1);
                printf(" Nombre: %s", pet[i].Nombre);
                printf("\n Animal: %s", pet[i].Animal);
                printf("\n Peso: %.2f Kg", pet[i].Peso);
                if (pet[i].Edad==1){
                    printf("\n Edad: %i a%co", pet[i].Edad, 164);
                }
                else{
                    printf("\n Edad: %i a%cos", pet[i].Edad, 164);
                }
                printf("\n Propietario: %s\n\n", pet[i].Propietario);
            }
        }
        printf("\n\nPresione cualquier tecla para continuar...");
        getch();
    }
    else{
        printf("\n\n\n\t***NO SE ENCONTRARON ANIMALES EN EL REGISTRO CON LOS DATOS PROPORCIONADOS***");
        Sleep(2000);
    }
}

void Mostrar(int t){ //Menú para mostrar animales.
    char i;
    if (t>0){
        while(i!='5'){ //Menú secundario del programa (Para mostrar mascotas)
            system("cls");
            printf("\n\t%cQu%c registros desea imprimir?\n", 168, 130);
            printf("\n\t1. Todos los registros");
            printf("\n\t2. Tipo de animal");
            printf("\n\t3. Por Due%co", 164);
            printf("\n\t4. Mascota en especifico");
            printf("\n\t5. Volver al inicio.");
            printf("\n\n\tOPCI%cN: ", 224);
            fflush(stdin);
            scanf("%c", &i);
            switch(i){
                case '1': //Mostrar todos los registros.
                    Todos(t);
                    printf("\n\nPresione cualquier tecla para continuar...");
                    getch();
                    fflush(stdin);
                    i='5';
                    break;
                case '2': //Mostrar un tipo de animal.
                    Tipo(t);
                    fflush(stdin);
                    i='5';
                    break;
                case '3': //Mostrar por propietario.
                    Propietario(t);
                    fflush(stdin);
                    i='5';
                    break;
                case '4': //Mostrar mascota en especifico.
                    Mascota(t);
                    fflush(stdin);
                    i='5';
                    break;
                default:;
            }
        }
    }
    else{
        system("cls");
        printf("\n\n\n\t\t\t***No se ha registrado ning%cn animal***", 163);
        Sleep(2000);
    }
}

//ELiminar
int Eliminar(int t){//Eliminar un registro.
    int i, j, aux=0;
    char x;
    if(t>0){
        while(aux<t && aux>=0){
            system("cls");
            Todos(t);
            printf("\n\nSeg%cn el n%cmero de mascota, escoga el que desee eliminar.", 163, 163);
            printf("\n\n\tOPCI%cN: ", 224);
            scanf("%i", &aux);
            system("cls");
            for(int i=0; i<=1; i++){
                printf("\n\n\t\tBuscando mascota.");
                Sleep(300);
                system("cls");
                printf("\n\n\t\tBuscando mascota..");
                Sleep(300);
                system("cls");
                printf("\n\n\t\tBuscando mascota...");
                Sleep(300);
                system("cls");
            }
            if(aux-1<t && aux>0){
                printf("\n\n\t\t***MASCOTA ENCONTRADA***");
                Sleep(2000);
                for(j=aux, i=aux-1; j<t; j++, i++){
                    pet[i]=pet[j];
                }
                system("cls");
                for(int i=0; i<=1; i++){
                    printf("\n\n\t\tEliminando mascota.");
                    Sleep(300);
                    system("cls");
                    printf("\n\n\t\tEliminando mascota..");
                    Sleep(300);
                    system("cls");
                    printf("\n\n\t\tEliminando mascota...");
                    Sleep(300);
                    system("cls");
                }
                t-=1;
                printf("\n\n\t\t***MASCOTA ELIMINADA***");
                Sleep(2000);
                aux=-1;
            }
            else{
                system("cls");
                printf("\n\n\t\t***MASCOTA NO ENCONTRADA***");
                Sleep(2000);
                while(x!='2' && x!='1'){
                    system("cls");
                    printf("\n\t%cDesea volver a la pantalla de inicio?", 168);
                    printf("\n\t1. Seguir Eliminado");
                    printf("\n\t2. Volver");
                    printf("\n\n\tOPCI%cN: ", 224);
                    scanf("%c", &x);
                    switch(x){
                        case '1':
                            aux=0;
                            break;
                        case '2':
                            aux=-1;
                            break;
                        default:;
                    }
                }
                x='3';
            }
        }
    }
    else{
        system("cls");
        printf("\n\n\n\t\t\t***No se ha registrado ning%cn animal***", 163);
        Sleep(2000);
    }
    return t;
}

//Programa principal
int main(){ //Programa principal.
    int tmascotas=0, A=0, aux;
    char s, i;

    //Bienvenida
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t%c Bienvenid%c a la Veterinaria !", 173, 64);
    Sleep(2000);

    while (s!='5'){ //Menú principal del programa.
        system("cls");
        printf("\n\t%cQu%c desea hacer?\n", 168, 130);
        printf("\n\t1. REGISTRAR MASCOTA");
        printf("\n\t2. MOSTRAR MASCOTAS");
        printf("\n\t3. ELIMINAR MASCOTA");
        printf("\n\t4. GUARDAR INFORMACI%CN EN ARCHIVO", 224);
        printf("\n\t5. SALIR");
        printf("\n\n\t\tOPCI%cN: ", 224);
        fflush(stdin);
        scanf("%c", &s);

        switch(s){
            case '1': //Agregar una Mascota
                tmascotas=Registrar(tmascotas);
                A=1;
                break;
            case '2': //Mostrar Mascotas
                Mostrar(tmascotas);
                break;
            case '3': //Eliminar una Mascota.
                aux=tmascotas;
                tmascotas=Eliminar(tmascotas);
                if(aux!=tmascotas){ //Si "aux" no es igual a "tmascotas" después de entrar en la función ELIMINAR, entonces,
                    A=1; //Se eliminó un registro, por ende hubo un cambio, por ende A=1 (Qué representa un cambio en el registro).
                }
                break;
            case '4': //Guardar información de registros en archivo.
                A=Archivo(tmascotas, A);
                break;
            default:; //se repite el menú.
        }
    }
    if (A!=0){ //Si hubo cambios y no se guardó, antes de cerrar el programa se pregunta al usuario si desea guardar los datos modificados.
        while(i!='2'){
            system("cls");
            printf("\n\n\t%cDesea guardar los cambios en el archivo?", 168);
            printf("\n\t1. S%c.", 161);
            printf("\n\t2. No.");
            printf("\n\n\t\tOPCI%cN: ", 224);
            scanf("%c", &i);
            if(i=='1'){
                if(tmascotas==0){ //Si se borraron todas las mascotas.
                    tmascotas=TAM+1; //Se da este valor para entrar a poner el archivo en blanco.
                    A=Archivo(tmascotas, A); //Se llama la función para limpiar el archivo de cualquier registro.
                    i='2'; //Salimos del submenú de salida para terminar el programa.
                }
                else{
                    A=Archivo(tmascotas, A); //Si hay registros aún y se modifico el programa en consola sin guardar los datos, se guardan en el archivo.
                    i='2'; //Salimos del submenú de salida para terminar el programa.
                }
            }
        }
    }
    system("cls");
    printf("\n\n\t\t*******PROGRAMA FINALIZADO*******\n\n");
    return 0;
}
