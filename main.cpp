#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "rlutil.h"
#include "Fecha.h"

#include "Proveedor.h"
#include "archivoProveedores.h"

#include "Videojuego.h"
#include "archivoVideojuegos.h"

#include "Empleado.h"
#include "archivoEmpleados.h"

#include "Ventas.h"
#include "archivoVentas.h"

#include "reportes.h"

#include "funciones.h"

int main(){
    int opc=1,y=0;
    while(opc!=0){
        MostrarCartel();
        MenuBlanco(" -------------------------------- ",47,4);
        MenuBlanco("                                  ",47,5);
        MenuVacio("      MENU PRINCIPAL      ",51,5);
        MenuBlanco(" -------------------------------- ",47,6);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();
        mostrarOpcion("      MENU VIDEOJUEGOS      ",50,8,y==0);
        mostrarOpcion("       MENU EMPLEADOS       ",50,9,y==1);
        mostrarOpcion("      MENU PROVEEDORES      ",50,10,y==2);
        mostrarOpcion("        MENU VENTAS         ",50,11,y==3);
        mostrarOpcion("       MENU REPORTES        ",50,12,y==4);
        mostrarOpcion("      FIN DEL PROGRAMA      ",50,13,y==5);
        int tecla= rlutil::getkey();
        switch(tecla){
        case 14: //ARRIBA
            rlutil::locate(50,10+y);
            cout<<" "<<endl;
            y--;
            if(y<0){y=0;}
            break;
        case 15: //ABAJO
            rlutil::locate(50,10+y);
            cout<<" "<<endl;
            y++;
            if(y>5){y=5;}
            break;
        case 1: //ENTER
            system("cls");
            switch(y){
            case 0: MenuVideojuegos();
                break;
            case 1: MenuEmpleados();
                break;
            case 2: MenuProveedores();
                break;
            case 3:MenuVentas();
                break;
            case 4: MenuReportes();
                break;
            case 5:
                opc=0;
                break;
            }
            break;
        }
    }
    return 0;
}

