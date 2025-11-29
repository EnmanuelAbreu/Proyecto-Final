#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define VENDIDO 1
#define NO_VENDIDO 0

#define ID 0
#define DISCO 1
#define MEMORIA_RAM 2
#define PRECIO 3
#define VENTA 4

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
                printf("Si desea aplicar un filtro, favor introducir S: ");
                scanf(" %c", &aplicarFiltro);
                ConsultarInventarioCelulares(cantidadCelulares, datos, marcaCelular, aplicarFiltro);
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
        // ID
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

        datos[registrados][0] = id;

        // Marca
        printf("Marca: ");
        getchar();  // <-- ESTA LÍNEA SOLUCIONA TU PROBLEMA
        fgets(marcaCelular[registrados], 25, stdin);
        marcaCelular[registrados][strcspn(marcaCelular[registrados], "\n")] = '\0';

        // Almacenamiento
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
   char letraVendido[5];
   float montoTotal_Inventario = 0.00;
   float montoTotal_Registrado = 0.00;
   float Total_Vendido = 0.00;
   float AlmacenamientoEspecificado = 0, RAMEspecificada = 0, Precio_VentaEspecificado = 0;
   int VerificacionFiltro = 0;



    printf("************************************* I N V E N T A R I O  D E  C E L U L A R E S **************************************\n");
          
    if(aplicarFiltro == 's' || aplicarFiltro == 'S'){
        //! Titulos de la funcion
        printf("A continuaci%cn especificar los datos por los que desea filtrar. \n", 162);
        printf("**** Si no desea filtrar por alguno de ellos, especificar -1. **** \n");

        //!Especificaciones para el filtrado
        printf("Almacenamiento(GB): ");
        scanf("%f", &AlmacenamientoEspecificado);
        printf("Memoria RAM(GB): ");
        scanf("%f", &RAMEspecificada);
        printf("Precio Venta: ");
        scanf("%f", &Precio_VentaEspecificado);

        printf("%-6s %9s %20s %10s %15s %12s  \n", "ID", "Marca", "Disco", "RAM", "Precio", "Vendido");
        printf("------------------------------------------------------------------------------------------\n");
        int especificacionEncontrada = 0;
        //!Condicion cuando solo se especifica el Almacenamiento
        if((AlmacenamientoEspecificado > 0) && ((RAMEspecificada < 0) && (Precio_VentaEspecificado < 0))){

            for(int i = 0; i < cantidadCelulares; i++){
                if(AlmacenamientoEspecificado == datos[i][DISCO]){
                    //! Evaluamos si encontro algun celular con esa especificacion
                    especificacionEncontrada = 1;

                    //!Evaluamos si esta vendido o no, y le ponemos su letra correspondiente
                    if(datos[i][VENTA] == VENDIDO){
                        strcpy(letraVendido, "S");
                    }else{
                        strcpy(letraVendido, "N");
                    }
                    
                    //!Calculando todo lo ultimo (Inventario, Total Vendido, Registrado)
                    montoTotal_Registrado += datos[i][PRECIO];
                    if(datos[i][VENTA] == VENDIDO){
                        Total_Vendido += datos[i][PRECIO];
                    }else{
                        montoTotal_Inventario += datos[i][PRECIO];
                    }

                    printf("%-6.0f %9s %20.2f %10.2f %15.2f %12s \n", datos[i][ID], marcaCelular[i], datos[i][DISCO], datos[i][MEMORIA_RAM], datos[i][PRECIO], letraVendido);
                }
            }
            if(especificacionEncontrada != 1){
                printf("No se han encontrado celulares con esa especificaci%cn \n", 162);
            }
                 //! Condicion cunado se especifica ALmacenamiento y Ram
        }else if((AlmacenamientoEspecificado > 0) && (RAMEspecificada > 0) && (Precio_VentaEspecificado < 0)){
            for(int i = 0; i < cantidadCelulares; i++){
                if((AlmacenamientoEspecificado == datos[i][DISCO] && RAMEspecificada == datos[i][MEMORIA_RAM])){
                    //! Evaluamos si encontro algun celular con esa especificacion
                    especificacionEncontrada = 1;

                    //!Evaluamos si esta vendido o no, y le ponemos su letra correspondiente
                    if(datos[i][VENTA] == VENDIDO){
                        strcpy(letraVendido, "S");
                    }else{
                        strcpy(letraVendido, "N");
                    }
                    
                    //!Calculando todo lo ultimo (Inventario, Total Vendido, Registrado)
                    montoTotal_Registrado += datos[i][PRECIO];
                    if(datos[i][VENTA] == VENDIDO){
                        Total_Vendido += datos[i][PRECIO];
                    }else{
                        montoTotal_Inventario += datos[i][PRECIO];
                    }

                    printf("%-6.0f %9s %20.2f %10.2f %15.2f %12s \n", datos[i][ID], marcaCelular[i], datos[i][DISCO], datos[i][MEMORIA_RAM], datos[i][PRECIO], letraVendido);
                }
            }
            if(especificacionEncontrada != 1){
                printf("No se han encontrado celulares con esa especificaci%cn \n", 162);
            }
                //!Condicion para cuando se cumple las 3 especificaciones
        }else if((AlmacenamientoEspecificado > 0) && (RAMEspecificada > 0) && (Precio_VentaEspecificado > 0)){
            for(int i = 0; i < cantidadCelulares; i++){
                if((AlmacenamientoEspecificado == datos[i][DISCO]) && (RAMEspecificada == datos[i][MEMORIA_RAM] && Precio_VentaEspecificado == datos[i][PRECIO])){
                    //! Evaluamos si encontro algun celular con esa especificacion
                    especificacionEncontrada = 1;
                    
                    //!Evaluamos si esta vendido o no, y le ponemos su letra correspondiente
                    if(datos[i][VENTA] == VENDIDO){
                        strcpy(letraVendido, "S");
                    }else{
                        strcpy(letraVendido, "N");
                    }
                    
                    //!Calculando todo lo ultimo (Inventario, Total Vendido, Registrado)
                    montoTotal_Registrado += datos[i][PRECIO];
                    if(datos[i][VENTA] == VENDIDO){
                        Total_Vendido += datos[i][PRECIO];
                    }else{
                        montoTotal_Inventario += datos[i][PRECIO];
                    }

                    printf("%-6.0f %9s %20.2f %10.2f %15.2f %12s \n", datos[i][ID], marcaCelular[i], datos[i][DISCO], datos[i][MEMORIA_RAM], datos[i][PRECIO], letraVendido);
                }
            }
            if(especificacionEncontrada != 1){
                printf("No se han encontrado celulares con esa especificaci%cn \n", 162);
            }
                //!Condicion cuando se cumple solo la Ram
        }else if((RAMEspecificada > 0) && ((AlmacenamientoEspecificado < 0) || (Precio_VentaEspecificado < 0))){
            for(int i = 0; i < cantidadCelulares; i++){
                if(RAMEspecificada == datos[i][MEMORIA_RAM]){
                    //! Evaluamos si encontro algun celular con esa especificacion
                    especificacionEncontrada = 1;
                    
                    //!Evaluamos si esta vendido o no, y le ponemos su letra correspondiente
                    if(datos[i][VENTA] == VENDIDO){
                        strcpy(letraVendido, "S");
                    }else{
                        strcpy(letraVendido, "N");
                    }
                    
                    //!Calculando todo lo ultimo (Inventario, Total Vendido, Registrado)
                    montoTotal_Registrado += datos[i][PRECIO];
                    if(datos[i][VENTA] == VENDIDO){
                        Total_Vendido += datos[i][PRECIO];
                    }else{
                        montoTotal_Inventario += datos[i][PRECIO];
                    }

                    printf("%-6.0f %9s %20.2f %10.2f %15.2f %12s \n", datos[i][ID], marcaCelular[i], datos[i][DISCO], datos[i][MEMORIA_RAM], datos[i][PRECIO], letraVendido);
                }
            }
            if(especificacionEncontrada != 1){
                printf("No se han encontrado celulares con esa especificaci%cn \n", 162);
            }
                //!Condicion cuando se cumple Ram y Precio
        }else if((RAMEspecificada > 0) && (Precio_VentaEspecificado > 0) && (AlmacenamientoEspecificado < 0)){
            for(int i = 0; i < cantidadCelulares; i++){
                if((Precio_VentaEspecificado == datos[i][PRECIO] && RAMEspecificada == datos[i][MEMORIA_RAM])){
                    //! Evaluamos si encontro algun celular con esa especificacion
                    especificacionEncontrada = 1;
                 
                    //!Evaluamos si esta vendido o no, y le ponemos su letra correspondiente
                    if(datos[i][VENTA] == VENDIDO){
                        strcpy(letraVendido, "S");
                    }else{
                        strcpy(letraVendido, "N");
                    }
                    
                    //!Calculando todo lo ultimo (Inventario, Total Vendido, Registrado)
                    montoTotal_Registrado += datos[i][PRECIO];
                    if(datos[i][VENTA] == VENDIDO){
                        Total_Vendido += datos[i][PRECIO];
                    }else{
                        montoTotal_Inventario += datos[i][PRECIO];
                    }

                    printf("%-6.0f %9s %20.2f %10.2f %15.2f %12s \n", datos[i][ID], marcaCelular[i], datos[i][DISCO], datos[i][MEMORIA_RAM], datos[i][PRECIO], letraVendido);
                }
            }
            if(especificacionEncontrada != 1){
                printf("No se han encontrado celulares con esa especificaci%cn \n", 162);
            }
                //!Condicion para cuando se cumple solo el Precio
        }else if((Precio_VentaEspecificado > 0) && ((AlmacenamientoEspecificado < 0) || (RAMEspecificada < 0))){
            for(int i = 0; i < cantidadCelulares; i++){
                if(Precio_VentaEspecificado == datos[i][PRECIO]){
                    //! Evaluamos si encontro algun celular con esa especificacion
                    especificacionEncontrada = 1;
                   
                    //!Evaluamos si esta vendido o no, y le ponemos su letra correspondiente
                    if(datos[i][VENTA] == VENDIDO){
                        strcpy(letraVendido, "S");
                    }else{
                        strcpy(letraVendido, "N");
                    }
                    
                    //!Calculando todo lo ultimo (Inventario, Total Vendido, Registrado)
                    montoTotal_Registrado += datos[i][PRECIO];
                    if(datos[i][VENTA] == VENDIDO){
                        Total_Vendido += datos[i][PRECIO];
                    }else{
                        montoTotal_Inventario += datos[i][PRECIO];
                    }

                    printf("%-6.0f %9s %20.2f %10.2f %15.2f %12s \n", datos[i][ID], marcaCelular[i], datos[i][DISCO], datos[i][MEMORIA_RAM], datos[i][PRECIO], letraVendido);
                }
            }
            if(especificacionEncontrada != 1){
                printf("No se han encontrado celulares con esa especificaci%cn \n", 162);
            }
                //!Condicion cunado se cumple Almacenamiento y Precio
        }else if((AlmacenamientoEspecificado > 0) && (Precio_VentaEspecificado > 0) && (RAMEspecificada < 0)){
            for(int i = 0; i < cantidadCelulares; i++){
                if(Precio_VentaEspecificado == datos[i][PRECIO] && AlmacenamientoEspecificado == datos[i][DISCO]){
                    //! Evaluamos si encontro algun celular con esa especificacion
                    especificacionEncontrada = 1;
                   
                    //!Evaluamos si esta vendido o no, y le ponemos su letra correspondiente
                    if(datos[i][VENTA] == VENDIDO){
                        strcpy(letraVendido, "S");
                    }else{
                        strcpy(letraVendido, "N");
                    }
                    
                    //!Calculando todo lo ultimo (Inventario, Total Vendido, Registrado)
                    montoTotal_Registrado += datos[i][PRECIO];
                    if(datos[i][VENTA] == VENDIDO){
                        Total_Vendido += datos[i][PRECIO];
                    }else{
                        montoTotal_Inventario += datos[i][PRECIO];
                    }

                    printf("%-6.0f %9s %20.2f %10.2f %15.2f %12s \n", datos[i][ID], marcaCelular[i], datos[i][DISCO], datos[i][MEMORIA_RAM], datos[i][PRECIO], letraVendido);
                }
            }
            if(especificacionEncontrada != 1){
                printf("No se han encontrado celulares con esa especificaci%cn \n", 162);
            }
        } 
    }else if(aplicarFiltro == 'n' || aplicarFiltro == 'N'){
        printf("%-6s %9s %20s %10s %15s %12s  \n", "ID", "Marca", "Disco", "RAM", "Precio", "Vendido");
        printf("------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < cantidadCelulares; i++){
            //!Calculando todo lo ultimo (Inventario, Total Vendido, Registrado)
            montoTotal_Registrado += datos[i][PRECIO];
            if(datos[i][VENTA] == VENDIDO){
                Total_Vendido += datos[i][PRECIO];
            }else{
                montoTotal_Inventario += datos[i][PRECIO];
            }
            //!Evaluamos si esta vendido o no, y le ponemos su letra correspondiente
            if(datos[i][VENTA] == VENDIDO){
                strcpy(letraVendido, "S");
            }else{
                strcpy(letraVendido, "N");
            }
            
            //! Evaluamos que haiga datos dentro de esa fila
            if(datos[i][ID] == 0){
                printf("");
            }else{
                printf("%-6.0f %9s %20.2f %10.2f %15.2f %12s \n", datos[i][ID], marcaCelular[i], datos[i][DISCO], datos[i][MEMORIA_RAM], datos[i][PRECIO], letraVendido);
            }
        }
    }else{
        VerificacionFiltro = 1;
        printf("------------------------------------------------------------------------------------------\n");
        printf("Ingrese S para aplicar filtro o N para no aplicarlo.\n");
    }
    printf("------------------------------------------------------------------------------------------\n");
    if(VerificacionFiltro == 0){
        printf("Monto Total Registrado: %25.2f \n", montoTotal_Registrado); 
        printf("Monto Total Inventario: %25.2f \n", montoTotal_Inventario); 
        printf("Total Vendido:          %25.2f \n", Total_Vendido); 
    }else{
        printf("\n");
    }
}
