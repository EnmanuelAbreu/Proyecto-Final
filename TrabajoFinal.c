#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    do{
        opcion = menu();

        switch (opcion){

            case 1:
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
                    sleep(1);
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
