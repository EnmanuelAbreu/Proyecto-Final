#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define VENDIDO 1
#define NO_VENDIDO 0

int menu();
void RegistrarCelular (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);
int SelecionarCelularDeUnaLista (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);
int RecomendarUnCelulaBasadoEnSusPreferencias(int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);
void venderCelulares(int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25], int idAVender);
void ConsultarInventarioCelulares (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25], char aplicarFiltro);
void ConsultaVentasXMarca (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);
void GenerarSolicitudCompraCelulares (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);

int main(){

    int cantidadCelulares, idAVender, opcion;
    float datos[cantidadCelulares][5];
    char marcaCelular [cantidadCelulares][25];
    char aplicarFiltro;

    memset(datos, 0, sizeof(datos));

    printf("Ingrese la cantidad de Celulares: ");
    scanf("%d", &cantidadCelulares);

    do{
        opcion = menu();

        switch (opcion){

            case 1:
                RegistrarCelular(cantidadCelulares, datos, marcaCelular);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("\nSaliendo");
                for (int i = 0; i < 3; i++){
                    printf(". ");
                }
                break;
        }

        if(opcion != 6){
            printf("\nPresione una tecla para continuar...");
            getche();
            system("cls");
        }

    }while(opcion != 6);

return 0;
}

int menu(){
    int opcion, verificar;
    printf("****************** PUComunicaciones, SRL ******************\n");
    printf("1. Registrar Celular\n");
    printf("2. Vender Celular\n");
    printf("3. Consultar Inventario de Celular\n");
    printf("4. Consultar Ventas x Marca\n");
    printf("5. Generar Solicitud Compra Celulares\n");
    printf("6. Salir\n\n");

    do {
    printf("Seleccione opci%cn: ", 162);

    verificar = scanf("%d", &opcion);

    if (verificar != 1){
        printf("Debe introducir un n%cmero\n\n", 163);
        fflush(stdin);
        continue;
    }
    if (opcion < 1 || opcion > 6){
        printf("Debe introducir una de las opciones disponibles\n\n");
    }


    }while(verificar != 1 || opcion < 1 || opcion > 6);

    return opcion;
}

void RegistrarCelular (int cantidadCelulares, float datos[cantidadCelulares][5], 
                       char marcaCelular[cantidadCelulares][25]) 
{
    static int registrados = 0;  // Para recordar cuántos se han ingresado anteriormente
    char opcion;

    do {
        if (registrados == cantidadCelulares) {
            printf("Ya se ha registrado la cantidad maxima de celulares (%d).\n", cantidadCelulares);
            return;
        }

        printf("\n************ R E G I S T R O   C E L U L A R E S ************\n");
        printf("Introducir los datos del celular No. %d\n", registrados + 1);

        int id;
        int idRepetido;

        // VALIDAR ID NO REPETIDO
        do {
            idRepetido = 0;
            printf("ID: ");
            scanf("%d", &id);

            for (int i = 0; i < registrados; i++) {
                if ((int)datos[i][0] == id) {
                    printf("ERROR: El ID ya existe, introduzca otro.\n");
                    idRepetido = 1;
                    break;
                }
            }
        } while (idRepetido == 1);

        datos[registrados][0] = id;  // Guardar ID

        printf("Marca: ");
        fflush(stdin);
        fgets(marcaCelular[registrados], 25, stdin);

        // Eliminar salto de línea de fgets
        marcaCelular[registrados][strcspn(marcaCelular[registrados], "\n")] = '\0';

        printf("Almacenamiento (GB): ");
        scanf("%f", &datos[registrados][1]);

        printf("Memoria RAM (GB): ");
        scanf("%f", &datos[registrados][2]);

        printf("Precio de Venta: ");
        scanf("%f", &datos[registrados][3]);

        registrados++;

        // Preguntar si desea registrar otro
        do {
            printf("\n¿Desea registrar otro celular (S/N)?: ");
            fflush(stdin);
            scanf("%c", &opcion);
            opcion = toupper(opcion);
        } while (opcion != 'S' && opcion != 'N');

    } while (opcion == 'S');
}


void ConsultarInventarioCelulares (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25], char aplicarFiltro){
    char aplicarFiltro;
    printf("************************************* I N V E N T A R I O  D E  C E L U L A R E S **************************************\n");

    printf("Si desea aplicar un filtro, favor introducir S: ");
    scanf(" %c", &aplicarFiltro);

    printf("%-6s %9s %20s %8s %6s %9s %9s\n", "ID", "Marca", "Disco", "RAM", "Precio", "Vendido");
    printf("------------------------------------------------------------------------------------------\n");
    if(aplicarFiltro == 'S'){

    }else{
        for(int i = 0; i < cantidadCelulares; i++){
            for(int j = 0; j < 5; j++){
                printf("HOLA MUNDO");
            }
        }
    }
    printf("------------------------------------------------------------------------------------------\n");
}
