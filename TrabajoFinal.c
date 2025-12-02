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
#define MAX 1000

int menu();
void RegistrarCelular (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);
int SelecionarCelularDeUnaLista (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);
int RecomendarUnCelulaBasadoEnSusPreferencias(int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);
void venderCelulares(int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25], int idAVender);
void ConsultarInventarioCelulares (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25], char aplicarFiltro);
void ConsultaVentasXMarca (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);
void GenerarSolicitudCompraCelulares (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]);

int main(){

    int cantidadCelulares = 0, idAVender, opcion;
    int opcionVentas, verificar;
    float datos[MAX][5];
    char marcaCelular [MAX][25];
    char aplicarFiltro;

    memset(datos, 0, sizeof(datos));

    do{
        opcion = menu();

        switch (opcion){

            case 1:
               if(cantidadCelulares == 0){
                    do{
                        printf("Favor introduzca la cantidad total de celulares a registrar: ");
                        if(scanf("%d", &cantidadCelulares) != 1)
                        {
                            printf("Debe ingresar un n%cmero!!!!\n\n",163);
                            int c;
                            // Limpia el buffer de entrada leyendo y descartando todos los caracteres
                            // hasta encontrar un salto de línea (ENTER) o el fin del archivo (EOF).
                            while ((c = getchar()) != '\n' && c != EOF);

                            cantidadCelulares = 0;
                            continue;
                        }
                        if(cantidadCelulares < 1)
                        {
                            printf("Valor invalido\n\n");
                            cantidadCelulares = 0;
                        }
                    }while(cantidadCelulares < 1);
                    }
                    RegistrarCelular(cantidadCelulares, datos, marcaCelular);
                break;
            case 2:
                printf("\n************ V E N T A  D E  C E L U L A R E S ************\n");
                    printf("\nFavor selecionar una de las siguientes opciones:\n");
                    printf("1. Seleccionar celular de una lista\n");
                    printf("2. Recomendar un celular basado en su Preferencia\n");
                    printf("3. Cancelar Venta\n");

                    do {
                        printf("\nSeleccione una opci%cn: ", 162);
                        verificar = scanf("%d", &opcionVentas);
                         if (verificar != 1){
                            printf("Debe introducir un n%cmero\n\n", 163);
                            fflush(stdin);
                            continue;
                        }
                        if (opcionVentas < 1 || opcionVentas > 3){
                            printf("Debe introducir una de las opciones disponibles\n\n");
                        }
                    }while(verificar != 1 || opcionVentas < 1 || opcionVentas > 3);


                    if (opcionVentas == 1){
                        idAVender = SelecionarCelularDeUnaLista (cantidadCelulares, datos,marcaCelular);
                    }else if (opcionVentas == 2){
                        idAVender = RecomendarUnCelulaBasadoEnSusPreferencias(cantidadCelulares ,datos ,marcaCelular);
                    }else if (opcionVentas == 3){
                        printf("\nCancelando la Venta");
                        for (int i = 0; i < 3; i++){
                            Sleep(1);
                            printf(". ");
                        }
                        printf("\n");
                       break;
                    }
                    if (idAVender != -1){
                       venderCelulares(cantidadCelulares, datos, marcaCelular, idAVender);
                    }else {
                        printf("\nCancelando la Venta");
                        for (int i = 0; i < 3; i++){
                            Sleep(1);
                            printf(". ");
                        }
                    }
                break;
            case 3:
                printf("Si desea aplicar un filtro, favor introducir S: ");
                scanf(" %c", &aplicarFiltro);
                ConsultarInventarioCelulares(cantidadCelulares, datos, marcaCelular, aplicarFiltro);
                break;
            case 4:
                ConsultaVentasXMarca(cantidadCelulares, datos, marcaCelular);
                break;
            case 5:
                GenerarSolicitudCompraCelulares(cantidadCelulares, datos, marcaCelular);
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

void RegistrarCelular(int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25])
{
    char continuarRegistrando;
    static int registrados = 0;

    printf("\n****** R E G I S T R O  C E L U L A R E S ******\n");
    //en caso de que ya se hayan resgistrado la cantidad de celulares que el usuario ingreso y quiera seguir poniendo mas/
    if(registrados >= cantidadCelulares)
    {
        printf("\nYa ha registrado el m%cximo de celulares permitidos.\n",160);
        return;
    }
    //bucle para resgisgrar los celulares/
    for(int i = registrados; i < cantidadCelulares; i++)
    {
        //Esto lo declare para usarlo la comprobacion del id/
        float idTemporal;
        int validarEntrada;
        char respuestaID;

        printf("\nIntroducir los datos del celular No. %d\n", i+1);

        while(1)
        {
            //Validar ID/
            printf("ID: ");
            validarEntrada = scanf("%f", &idTemporal);
            //Verificar que el usuario introduzca un numero/
            if(validarEntrada != 1)
            {
                printf("Entrada inv%clida. Debe ingresar un n%cmero para el ID.\n", 160, 163);
                int ch; while ((ch = getchar()) != '\n' && ch != EOF); // limpiar buffer
                continue;
            }
            //Verificar que el ID sea un numero positivo
            if(idTemporal <= 0)
            {
                printf("ID no puede ser un n%cmero negativo.\n",163);
                continue;
            }
            //Verificar que el ID no este repetido/
            int repetido = 0;
            for(int j = 0; j < registrados; j++)
            {
                if(datos[j][ID] == idTemporal)
                {
                    repetido = 1;
                    break;
                }
            }
            if(repetido != 1)
            {
                /* ID válido y no repetido -> salir del loop */
                break;
            }
            while(1)
            {
                int ch;
                //si el id esta repetido: preguntar al usuario si quiere ingresar otro ID diferente o salir/
                while ((ch = getchar()) != '\n' && ch != EOF);
                printf("ID: %.0f ha sido especificado previamente\n",idTemporal);
                printf("%cDesea especificar otro ID(S/N)?: ",168);
                if(scanf(" %c", &respuestaID) != 1)
                {
                    /* lectura fallida: limpiar y repetir */
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    continue;
                }
                respuestaID = toupper(respuestaID);
                while ((ch = getchar()) != '\n' && ch != EOF);
                //Si responde si el programa le pregunta el id de nuevo como el profe lo pidio/
                if(respuestaID == 'S')
                {
                    break;
                }
                //Si responde que no el programa sale de la funcion/
                else if(respuestaID == 'N')
                {
                    return;
                }
                else
                {
                    //verificar que el usuario responde con S o N, de lo contrario vuelve a preguntar/
                     printf("Respuesta inv%clida. Responda 'S' o 'N'.\n", 160);
                     continue;
                }
            }
        }
        //aqui se completa la parte del arreglo de id/
        datos[i][ID] = idTemporal;

        printf("Marca: ");
        scanf("%24s", marcaCelular[i]);

        //Validacion para el almacenamiento/
        float almacenamientoTemporal;
        while(1)
        {
            printf("Almacenamiento(GB): ");
            validarEntrada = scanf("%f", &almacenamientoTemporal);

            //aqui verificamos que el usuario no introduzca una letra/
            if(validarEntrada != 1)
            {
                printf("Respuesta inv%clida. Debe ingresar un n%cmero.\n", 160, 163);
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF); // limpiar buffer
                continue;
            }
            //aqui verificamos que el numero introducido por el usuario sea positivo/
            if(almacenamientoTemporal <= 0)
            {
                printf("El almacenamiento debe ser un n%cmero positivo.\n", 163);
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF); // limpiar buffer
                continue;
            }
            break;
        }
        //Aqui se llena el arrglo del almacenamiento/
        datos[i][DISCO] = almacenamientoTemporal;

        //validacion de memoria ram/
        float memoriaRamTemporal;
        while(1)
        {
            printf("Memoria RAM(GB): ");
            validarEntrada = scanf("%f", &memoriaRamTemporal);

            //verificamos que el usuario introduzca un numero/
            if(validarEntrada != 1)
            {
                printf("Respuesta inv%clida, debe introducir un n%cmero\n", 160, 163);
                int ch;
                while((ch = getchar()) != '\n' && ch != EOF); //Limpiar buffer
                continue;
            }
            //verificamos que el usuario introduzca un numero positivo/
            if(memoriaRamTemporal <= 0)
            {
                printf("La memoria RAM debe ser un n%cmero positivo\n", 163);
                int ch;
                while((ch = getchar()) != '\n' && ch != EOF); // Limpiar buffer
                continue;
            }
            break;
        }
        //llenamos el arreglo de memoria ram/
        datos[i][MEMORIA_RAM] = memoriaRamTemporal;

        //validacion de precio de venta/
        float precioTemporal;
        while(1)
        {
            printf("Precio de Venta: ");
            validarEntrada = scanf("%f", &precioTemporal);

            if(validarEntrada != 1)
            {
                printf("Respuesta inv%clida, debe introducir un n%cmero\n", 160, 163);
                int ch;
                while((ch = getchar()) != '\n' && ch != EOF); // limpiar buffer
                continue;
            }
            if(precioTemporal <= 0)
            {
                printf("El precio debe ser un n%cmero positivo\n",163);
                int ch;
                while((ch = getchar()) != '\n' && ch != EOF); // limpiar buffer
                continue;
            }
            break;
        }
        datos[i][PRECIO] = precioTemporal;

        /*en esta variable estatica llevamos el conteo de los celulares registrados
        sin que se pierda la informacion en caso de que el usuario decida salir de la funcion*/
        registrados++;

        do
        {
            printf("Desea registrar otro celular(S/N)?: ");
            //getchar();
            scanf(" %c", &continuarRegistrando);
            continuarRegistrando = toupper(continuarRegistrando);
            //En caso de que el usario introduzca algo que no es S o N/
            if(continuarRegistrando != 'S' && continuarRegistrando != 'N')
            {
                printf("\nrepuesta invalida, Por favor responda (S/N)\n");
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
            }
        } while(continuarRegistrando != 'S' && continuarRegistrando != 'N');

        if(continuarRegistrando == 'N')
        {
            return;
        }
        if(continuarRegistrando == 'S')
        {
            //en caso de que ya el usuario haya resgistrado la cantidad maxima de celulares permitidos/
            if(registrados >= cantidadCelulares)
            {
                printf("\nYa ha registrado el m%cximo de celulares permitidos.\n",160);
                return;
            }
            continue;
        }
    }
}

//!Funcion la cual selecciona un celular de los que esten registrados para la venta
int SelecionarCelularDeUnaLista (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]){

    char marca[25];
    int idAVender, verificar;
    int existeMarca = 0;
    int idValido;

    printf("\nEspeficicar marca: ");
    getchar();
    gets(marca);
    printf("\n");


    for (int i = 0; i < cantidadCelulares; i++){    //verifica si hay celulares
        if (strcasecmp(marca, marcaCelular[i]) == 0 && datos[i][VENTA] == NO_VENDIDO){
            existeMarca = 1;
            break;
        }
    }
    if (existeMarca == 0){ //si no hay celulares muestra el mensaje
        printf("No hay celulares registrados con esa marca o ya fueron vendidos\n");
        return -1;
    }

    printf("%-12s %25s %12s %10s %20s\n", "ID", "Marca", "Disco", "RAM", "Precio");
    printf("--------------------------------------------------------------------------------------------\n");   //imprime la lista con los celulares de la marca selecionada

    for (int i = 0; i < cantidadCelulares; i++){
        if (strcasecmp(marca, marcaCelular[i]) == 0 && datos[i][VENTA] == NO_VENDIDO){      //comparar si la marca conincide con la introducida con el usuario y imprimir los datos en caso de que si
            printf("%-12.0f %25s %12.2f %10.2f %20.2f\n",
                   datos[i][ID], marcaCelular[i], datos[i][DISCO], datos[i][MEMORIA_RAM], datos[i][PRECIO]);
        }
    }

    printf("--------------------------------------------------------------------------------------------\n");

    while (1){  //bucle para validar el ID
        idValido = 0;

        printf("Favor especificar el ID del celular que desea o -1 para cancelar la compra: ");
        while (scanf("%d", &idAVender) != 1) {
            printf("Debe introducir un n%cmero\n", 163);
            fflush(stdin);
        }

        if (idAVender == -1){
            return -1;
        }
         for (int i = 0; i < cantidadCelulares; i++){   //Confirma que el ID introducido si este dentro de las opciones de celular con esa marca
            if (strcasecmp(marca, marcaCelular[i]) == 0 && datos[i][VENTA] == NO_VENDIDO && datos[i][ID] == idAVender){
                idValido = 1;
                break;
            }
        }
        if (idValido == 1){ //Salir del bucle para retornar el ID
            break;
        }
        printf("Ese ID no existe dentro de las opciones. Intente de nuevo\n\n");
    }

    return idAVender;

}

//!Funcion la cual recomienda un celular apartir de las especificaciones que le des
int RecomendarUnCelulaBasadoEnSusPreferencias(int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]){

    float maxPrecio, minDisco, minRAM;
    int idAVender, idValido;
    int encontrados[2];     // Guarda los indices de los 2 mejores celulares
    int cantEncontrados = 0;

    printf("Favor introducir el m%cnimo permitido para las siguientes caracter%csticas: \n", 161, 161);
    printf("Mayor Precio Permitido: ");
    while (scanf("%f", &maxPrecio) != 1){
    printf("Debe introducir un n%cmero: ", 163);
    fflush(stdin);
    }
    printf("Menor Almacenamiento Permitido(GB): ");             //validar datos y pedir minimos y maximos para buscar las recomendaciones
    while (scanf("%f", &minDisco) != 1){
    printf("Debe introducir un n%cmero: ", 163);
    fflush(stdin);
    }
    printf("Menor RAM Permitida(GB): ");
    while (scanf("%f", &minRAM) != 1){
    printf("Debe introducir un n%cmero: ", 163);
    fflush(stdin);
    }



    for (int i = 0; i < cantidadCelulares; i++){

        if (datos[i][VENTA] == NO_VENDIDO && datos[i][PRECIO] <= maxPrecio && datos[i][DISCO] >= minDisco && datos[i][MEMORIA_RAM] >= minRAM){
            encontrados[cantEncontrados] = i;
            cantEncontrados++;
            if (cantEncontrados == 2) {
                break;  // detiene el bucle para solo dejar los 2 con estas caracteristicas
            }
        }
    }
    if (cantEncontrados == 0){      //si ninguno cumple
        printf("\nNo se encontraron celulares con esas caracter%csticas.\n", 161);
        return -1;
    }

    // mostrar los resultados
    printf("\n%-12s %25s %12s %10s %20s\n", "ID", "Marca", "Disco", "RAM", "Precio");
    printf("--------------------------------------------------------------------------------------------\n");

    for (int j = 0; j < cantEncontrados; j++){
        int indiceCelular = encontrados[j];
        printf("%-12.0f %25s %12.2f %10.2f %20.2f\n",
            datos[indiceCelular][ID], marcaCelular[indiceCelular], datos[indiceCelular][DISCO],
            datos[indiceCelular][MEMORIA_RAM], datos[indiceCelular][PRECIO]);
    }

    printf("--------------------------------------------------------------------------------------------\n");

    while (1){  //bucle para validar el ID
        printf("Favor especificar el ID del celular que desea o -1 para cancelar la compra: ");
        while (scanf("%d", &idAVender) != 1) {
            printf("Debe introducir un n%cmero\n", 163);
            fflush(stdin);
        }
        if (idAVender == -1){
            return -1;
        }
        idValido = 0;

        for (int j = 0; j < cantEncontrados; j++){
            int indiceCelular = encontrados[j];

            if (datos[indiceCelular][ID] == idAVender){
                idValido = 1;           //confirmar que el ID introducido esta dentro de las opciones
                break;
            }
        }
        if (idValido == 1){
            break;}

        printf("Ese ID no existe dentro de las opciones. Intente de nuevo\n\n");
    }

    return idAVender;
}

//!Funcion que realiza la venta de los celulares
void venderCelulares(int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25], int idAVender){

    char confirmar;
    int indice = -1;

    for (int i = 0; i < cantidadCelulares; i++){    //bucle para buscar en que posicion esta en ID del celular a vender
        if (datos[i][ID] == idAVender){
            indice = i;
            break;
        }
    }
    if (indice == -1){
        printf("\nEl ID no fue encontrado\n");  //en caso de no encontrar el ID
        return;
    }
    printf("\nAcontinuaci%cn los datos del celular seleccionado y monto a pagar:\n", 162);  //mostrar los datos del celular selecionado
    printf("%-12s %25s %12s %10s %20s\n", "ID", "Marca", "Disco", "RAM", "Precio");
    printf("\n--------------------------------------------------------------------------------------------\n");
    printf("%-12.0f %25s %12.2f %10.2f %20.2f\n", datos[indice][ID], marcaCelular[indice], datos[indice][DISCO], datos[indice][MEMORIA_RAM], datos[indice][PRECIO]);
    printf("--------------------------------------------------------------------------------------------\n");
    printf("%-20s %10.2f", "Total a Pagar", datos[indice][PRECIO]);

    do {
        printf("\nDesea completar la compra? (S/N): "); //confirmar la compra
        fflush(stdin);
        scanf(" %c", &confirmar);
        confirmar = toupper(confirmar);
        if (confirmar != 'S' && confirmar != 'N'){
            printf("Debe introducir S para confirmar o N para cancelar\n");
        }
    } while (confirmar != 'S' && confirmar != 'N');


    if (confirmar == 'S'){
        datos[indice][VENTA] = VENDIDO;     //cambiar el estado del celular al vendido
        printf("\n\nCompra registrada exitosamente!!\n");
    } else if (confirmar == 'N'){
        printf("\nLa compra ha sido cancelada\n");
        return;
    }

}

//!Funcion que consulta el inventario y los celulares registrados
void ConsultarInventarioCelulares (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25], char aplicarFiltro){
   char letraVendido[5];
   float montoTotal_Inventario = 0.00;
   float montoTotal_Registrado = 0.00;
   float Total_Vendido = 0.00;
   float AlmacenamientoEspecificado = 0, RAMEspecificada = 0, Precio_VentaEspecificado = 0;
   int VerificacionFiltro = 0, ValidarEntrada = 0;



    printf("************************************* I N V E N T A R I O  D E  C E L U L A R E S **************************************\n");

    if(datos[0][ID] == 0){
        VerificacionFiltro = 1;
        printf("%-6s %9s %20s %10s %15s %12s  \n", "ID", "Marca", "Disco", "RAM", "Precio", "Vendido");
        printf("------------------------------------------------------------------------------------------\n");
        printf("No hay celulare registrardos por el momento. \n");
        printf("------------------------------------------------------------------------------------------\n");
        return;
    }
          
    if(aplicarFiltro == 's' || aplicarFiltro == 'S'){
        //! Titulos de la funcion
        printf("A continuaci%cn especificar los datos por los que desea filtrar. \n", 162);
        printf("\n**** Si no desea filtrar por alguno de ellos, especificar -1. **** \n");
        //!Especificaciones para el filtrado
        printf("Almacenamiento(GB): ");
        ValidarEntrada = scanf("%f", &AlmacenamientoEspecificado);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if(ValidarEntrada != 1){
            printf("Acaba de ingresar una especificaci%cn inv%clida. Por favor intentar otra vez. \n", 162, 160);
            return;
        }

        printf("Memoria RAM(GB): ");
        ValidarEntrada = scanf("%f", &RAMEspecificada);
        while ((c = getchar()) != '\n' && c != EOF);
        if(ValidarEntrada != 1){
            printf("Acaba de ingresar una especificaci%cn inv%clida. Por favor intentar otra vez. \n", 162, 160);
            return;
        }

        printf("Precio Venta: ");
        ValidarEntrada = scanf("%f", &Precio_VentaEspecificado);
        while ((c = getchar()) != '\n' && c != EOF);
        if(ValidarEntrada != 1){
            printf("Acaba de ingresar una especificaci%cn inv%clida. Por favor intentar otra vez. \n", 162, 160);
            return;
        }

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
                VerificacionFiltro = 1;
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
                VerificacionFiltro = 1;
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
                VerificacionFiltro = 1;
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
                VerificacionFiltro = 1;
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
                VerificacionFiltro = 1;
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
                VerificacionFiltro = 1;
            }
                //!Condicion en caso de que el usuario ponga -1 en todas las especificaciones
        }else if((AlmacenamientoEspecificado < 0) && (RAMEspecificada < 0) && (Precio_VentaEspecificado < 0)){
                printf("Especificaci%cn inv%clida. \n", 162, 160);
                VerificacionFiltro = 1;
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

//!FUNCION LA CUAL CONSULTA LA VENTA POR LA MARCA, MEMORIA RAM Y ALMACENAMIENTO
void ConsultaVentasXMarca (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25])
{
    //verificar que el usuario primero haya registrado los celulares
    if(cantidadCelulares == 0)
    {
        printf("No puede consultar Ventas X Marca sin registrar los celulares!!!");
        return;
    }

    // Contar cuántos celulares están registrados realmente
    int celularesRegistrados = 0;
    for(int i = 0; i < cantidadCelulares; i++)
    {
        if(datos[i][ID] != 0)
        {
            celularesRegistrados++;
        }
    }

    // Extraer marcas únicas de celulares vendidos
    char marcasUnicas[celularesRegistrados][25];
    int totalMarcas = 0;

    for(int i = 0; i < cantidadCelulares; i++)
    {
        if(datos[i][VENTA] == VENDIDO)
        {
            int marcaExiste = 0;
            // Verificar si la marca ya está en el arreglo de marcas únicas
            for(int j = 0; j < totalMarcas; j++)
            {
                if(strcasecmp(marcaCelular[i], marcasUnicas[j]) == 0)
                {
                    marcaExiste = 1;
                    break;
                }
            }
            // Si la marca no existe, agregarla
            if(marcaExiste == 0)
            {
                strcpy(marcasUnicas[totalMarcas], marcaCelular[i]);
                totalMarcas++;
            }
        }
    }

    // Si no hay ventas registradas
    if(totalMarcas == 0)
    {
        printf("\nNo hay ventas registradas para mostrar.\n");
        return;
    }

    // Crear matriz para almacenar ventas por marca y rangos
    // [marca][rango] donde rango: 0 = RAM 6-10, 1 = RAM 12-16, 2 = DISCO 64-128, 3 = DISCO 256-512
    float ventasPorMarca[totalMarcas][4];

    // Inicializar matriz en 0
    for(int i = 0; i < totalMarcas; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            ventasPorMarca[i][j] = 0.0;
        }
    }

    // Calcular las ventas por marca y rango
    for(int i = 0; i < cantidadCelulares; i++)
    {
        if(datos[i][VENTA] == VENDIDO)
        {
            // Encontrar el índice de la marca
            int indiceMarca = -1;
            for(int j = 0; j < totalMarcas; j++)
            {
                if(strcasecmp(marcaCelular[i], marcasUnicas[j]) == 0)
                {
                    indiceMarca = j;
                    break;
                }
            }

            if(indiceMarca != -1)
            {
                // Verificar rango de RAM 6-10
                if(datos[i][MEMORIA_RAM] >= 6 && datos[i][MEMORIA_RAM] <= 10)
                {
                    ventasPorMarca[indiceMarca][0] += datos[i][PRECIO];
                }
                // Verificar rango de RAM 12-16
                if(datos[i][MEMORIA_RAM] >= 12 && datos[i][MEMORIA_RAM] <= 16)
                {
                    ventasPorMarca[indiceMarca][1] += datos[i][PRECIO];
                }
                // Verificar rango de DISCO 64-128
                if(datos[i][DISCO] >= 64 && datos[i][DISCO] <= 128)
                {
                    ventasPorMarca[indiceMarca][2] += datos[i][PRECIO];
                }
                // Verificar rango de DISCO 256-512
                if(datos[i][DISCO] >= 256 && datos[i][DISCO] <= 512)
                {
                    ventasPorMarca[indiceMarca][3] += datos[i][PRECIO];
                }
            }
        }
    }

    // Calcular totales generales
    float totalRAM_6_10 = 0.0;
    float totalRAM_12_16 = 0.0;
    float totalDISCO_64_128 = 0.0;
    float totalDISCO_256_512 = 0.0;

    for(int i = 0; i < totalMarcas; i++)
    {
        totalRAM_6_10 += ventasPorMarca[i][0];
        totalRAM_12_16 += ventasPorMarca[i][1];
        totalDISCO_64_128 += ventasPorMarca[i][2];
        totalDISCO_256_512 += ventasPorMarca[i][3];
    }

    // Imprimir el reporte
    printf("\n\n***** V E N T A  D E  C E L U L A R E S  X  M A R C A *****\n");
    printf("%43s %31s \n", "MEMORIA RAM(GB)", "ALMACENAMIENTO(GB)");
    printf("%49s %30s \n", "----------------------------", "----------------------------");
    printf("%31s %14s %16s %14s \n", "6 - 10", "12 - 16", "64 - 128", "256 - 512");
    printf("%34s %14s %15s %14s \n", "-------------", "-------------", "-------------","-------------");

    // Imprimir datos por marca
    for(int i = 0; i < totalMarcas; i++)
    {
        printf("%20s %13.2f %14.2f %15.2f %14.2f\n", marcasUnicas[i], ventasPorMarca[i][0], ventasPorMarca[i][1], ventasPorMarca[i][2], ventasPorMarca[i][3]);
    }
    printf("%34s %14s %15s %14s \n", "-------------", "-------------", "-------------","-------------");

    // Imprimir totales generales
    printf("%19s %14.2f %14.2f %15.2f %14.2f\n", "Total General:", totalRAM_6_10, totalRAM_12_16, totalDISCO_64_128, totalDISCO_256_512);
}

//!Funcion la cual genera una solicitud de compra dependiendo el grupo en el que es clasificado
void GenerarSolicitudCompraCelulares (int cantidadCelulares, float datos[cantidadCelulares][5], char marcaCelular [cantidadCelulares][25]){
    int cantidadCelulares_Registrado = 0;
    int CantidadComprar = 0;
    int GrupoGanadorA = 0, GrupoGanadorB = 0;

    //!Contamos cuantos celulares hay registrados, para crear el arreglo de ese tamaño.
    for(int i = 0; i < cantidadCelulares; i++){
        if(datos[i][ID] != 0){
            cantidadCelulares_Registrado++;
        }
    }
    //!Variables para evaluar el inventario inicial
    char InventarioInicial[cantidadCelulares_Registrado][25];
    int ContadorInventario[cantidadCelulares_Registrado];
    int TotalInventario = 0;

    for(int i = 0; i < cantidadCelulares; i++){
        int MarcaEncontrada = -1;

        //!Evaluamos dentro del arreglo MarcasGrupoA cuales se repiten
        for(int j = 0; j < TotalInventario; j++){
            if(strcmp(marcaCelular[i], InventarioInicial[j]) == 0){
                MarcaEncontrada = j;
                break;
            }
        }

        //!Si no se repite pues lo guardamos y lo igualamos a uno porque es la primera vez
        if(MarcaEncontrada == -1){
            strcpy(InventarioInicial[TotalInventario], marcaCelular[i]);
            ContadorInventario[TotalInventario] = 1;
            TotalInventario++;
        }else{
            ContadorInventario[MarcaEncontrada]++;
        }
    }

    //!Los de Grupo A son aquellos celulares con las caracteristicas(12 - 16GB - 256 - 512GB)
    int CelularesGrupoA[cantidadCelulares_Registrado];
    char MarcasGrupoA[cantidadCelulares_Registrado][25];
    char MarcasUnicasA[cantidadCelulares_Registrado][25];
    int ContadorMarcasA[cantidadCelulares_Registrado];

    //!Los de Grupo B son aquellos celulares con las caracteristicas(6 - 10GB - 64 - 128GB)
    int CelularesGrupoB[cantidadCelulares_Registrado];
    char MarcasGrupoB[cantidadCelulares_Registrado][25];
    char MarcasUnicasB[cantidadCelulares_Registrado][25];
    int ContadorMarcasB[cantidadCelulares_Registrado];

    //!Contadores para saber cauntos hay en cada grupo
    int totalGrupoA = 0;
    int totalGrupoB = 0;

    for(int i = 0; i < cantidadCelulares; i++){
        if(datos[i][VENTA] == VENDIDO){
            //!Evaluar cuales celulares de los vendidos cumple con las caracteristicas del grupo A
            if(((datos[i][MEMORIA_RAM] >= 12) && (datos[i][MEMORIA_RAM] <=  16)) && ((datos[i][DISCO] >= 256) && (datos[i][DISCO] <= 512))){
                CelularesGrupoA[totalGrupoA] = i;
                strcpy(MarcasGrupoA[totalGrupoA], marcaCelular[i]);
                totalGrupoA++;

                    //!Evaluar cuales celulares de los vendidos cumple con las caracteristicas del grupo B   
            }else if(((datos[i][MEMORIA_RAM] >= 6) && (datos[i][MEMORIA_RAM] <=  10)) && ((datos[i][DISCO] >= 64) && (datos[i][DISCO] <= 128))){
                CelularesGrupoB[totalGrupoB] = i;
                strcpy(MarcasGrupoB[totalGrupoB], marcaCelular[i]);
                totalGrupoB++;
            }      
        }
    }

    //!Contabilizamos cuantos celulares comrparon de cada marca del GRUPO A
    int totalUnicasA = 0;
    for(int i = 0; i < totalGrupoA; i++){
        int MarcaEncontrada = -1;

        //!Evaluamos dentro del arreglo MarcasGrupoA cuales se repiten
        for(int j = 0; j < totalUnicasA; j++){
            if(strcmp(MarcasGrupoA[i], MarcasUnicasA[j]) == 0){
                MarcaEncontrada = j;
                break;
            }
        }

        //!Si no se repite pues lo guardamos y lo igualamos a uno porque es la primera vez
        if(MarcaEncontrada == -1){
            strcpy(MarcasUnicasA[totalUnicasA], MarcasGrupoA[i]);
            ContadorMarcasA[totalUnicasA] = 1;
            totalUnicasA++;
        }else{
            ContadorMarcasA[MarcaEncontrada]++;
        }
    }

    //!Contabilizamos cuantos celulares comrparon de cada marca del GRUPO B
    int totalUnicasB = 0;
    for(int i = 0; i < totalGrupoB; i++){
        int MarcaEncontrada = -1;

        //!Evaluamos dentro del arreglo MarcasGrupoB cuales se repiten
        for(int j = 0; j < totalUnicasB; j++){
            if(strcmp(MarcasGrupoB[i], MarcasUnicasB[j]) == 0){
                MarcaEncontrada = j;
                break;
            }
        }

        //!Si no se repite pues lo guardamos y lo igualamos a uno porque es la primera vez
        if(MarcaEncontrada == -1){
            strcpy(MarcasUnicasB[totalUnicasB], MarcasGrupoB[i]);
            ContadorMarcasB[totalUnicasB] = 1;
            totalUnicasB++;
        }else{
            ContadorMarcasB[MarcaEncontrada]++;
        }
    }

    //!Evaluar cual es el grupo ganador en la seccion A
    for(int i = 0; i < totalUnicasA; i++){
        if(ContadorMarcasA[i] > ContadorMarcasA[GrupoGanadorA]){
            GrupoGanadorA = i;
        }
    }

    //!Evaluar cual es el grupo ganador en la seccion B
    for(int i = 0; i < totalUnicasB; i++){
        if(ContadorMarcasB[i] > ContadorMarcasB[GrupoGanadorB]){
            GrupoGanadorB = i;
        }
    }

    //! Buscar el inventario inicial de la marca ganadora del Grupo A
    int inventarioInicialMarcaGanadoraA = 0;
    for(int j = 0; j < TotalInventario; j++){
            //!Buscamos la marca ganadora en el inventario, cuyando encuentre el nombre tomara la cantidad del inventario de esa marca
        if(strcmp(MarcasUnicasA[GrupoGanadorA], InventarioInicial[j]) == 0){
            inventarioInicialMarcaGanadoraA = ContadorInventario[j];
            break;
        }
    }

    //!Realizamos los calculos para saber cuanto es el porcentaje y la cantidad a comprar
    float PorcentajeA = (float)ContadorMarcasA[GrupoGanadorA] / inventarioInicialMarcaGanadoraA;
    int CantidadComprarGrupoA = PorcentajeA * inventarioInicialMarcaGanadoraA;
    
    //! Buscar el inventario inicial de la marca ganadora del Grupo B
    int inventarioInicialMarcaGanadoraB = 0;
    for(int j = 0; j < TotalInventario; j++){
            //!Buscamos la marca ganadora en el inventario, cuyando encuentre el nombre tomara la cantidad del inventario de esa marca
        if(strcmp(MarcasUnicasB[GrupoGanadorB], InventarioInicial[j]) == 0){
            inventarioInicialMarcaGanadoraB = ContadorInventario[j];
            break;
        }
    }

    //!Realizamos los calculos para saber cuanto es el porcentaje y la cantidad a comprar
    float PorcentajeB = (float)ContadorMarcasB[GrupoGanadorB] / inventarioInicialMarcaGanadoraB;
    int CantidadComprarGrupoB = PorcentajeB * inventarioInicialMarcaGanadoraB;
    
    printf("******************** S O L I C I T U D   C O M P R A   C E L U L A R E S ********************\n\n");
    printf("%-15s %15s %19s %15s\n", "", "Memoria", "", "Cantidad");
    printf("%-15s %15s %19s %15s\n", "Marca", "RAM", "Almacenamiento", "Comprar");
    printf("--------------    --------------    ----------------    ------------    \n");
    //!Evaluamos si se ha realizado alguna compra de este grupo
    int verificador = 0;
    int VentaRealizada = 0;
    for(int i = 0; i < totalUnicasA; i++){
        if(ContadorMarcasA[i] != 0){
            VentaRealizada = 1;      
        }
    }

    if(VentaRealizada == 0){
        printf("No hay que reabastecer el inventario por el momento. \n");
        verificador = 1;
    }else{
        printf("%-15s %15s %19s %15d\n", MarcasUnicasA[GrupoGanadorA], "12 - 16 GB", "256 - 512 GB", CantidadComprarGrupoA);
    }

    //!Grupo B
    VentaRealizada = 0;
    for(int i = 0; i < totalUnicasB; i++){
        if(ContadorMarcasB[i] != 0){
            VentaRealizada = 1;
            break;
        }
    }

    if(VentaRealizada == 0){
        if(verificador == 0){
            printf("No hay que reabastecer el inventario por el momento.\n");
        }else{
            printf("");
        }
    }else{
        printf("%-15s %15s %19s %15d\n", MarcasUnicasB[GrupoGanadorB], "6 - 10 GB", "64 - 128 GB", CantidadComprarGrupoB);
    }
    printf("--------------    --------------    ----------------    ------------    \n");
}