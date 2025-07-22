#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/// PINTAR FONDO DE VERDE
void mostrarOpcion(const char* text,int columna,int fila,bool seleccion){
    if(seleccion){
        rlutil::setBackgroundColor(rlutil::RED);
        rlutil::locate(columna-3,fila);
        cout<<" "<<(char)175<<" "<<text<<" "<<(char)174<<" ";
    }
    else{
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(columna-3,fila);
        cout<<"   "<<text<<"   "<<endl;
    }
    rlutil::locate(columna,fila);
    cout<<text<<endl;
    rlutil::setBackgroundColor(rlutil::BLACK);
}

/// PINTAR FONDO BLANCO "MENU PRINCIPAL"
void MenuBlanco(const char* text,int columna,int fila){
    rlutil::setBackgroundColor(rlutil::RED);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(columna,fila);
    cout<<text<<endl;
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
}

/// PINTAR FONDO "MENU PRINCIPAL"
void MenuVacio(const char* text,int columna,int fila){
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(columna,fila);
    cout<<text<<endl;
    rlutil::setBackgroundColor(rlutil::LIGHTGREEN);
}

/// MOSTRAR CARTEL PLAY X FUN
void MostrarCartel(){
    gotoxy(38,18);cout<<" ____  _        _ __   __ __  __  _____ _   _ _   _"<<endl;
    gotoxy(38,19);cout<<"|  _ "<<(char)92<<"| |      / "<<(char)92<<(char)92<<" "<<(char)92<<" / / "<<(char)92<<" "<<(char)92<<"/ / |  ___| | | | "<<(char)92<<" | |"<<endl;
    gotoxy(38,20);cout<<"| |_) | |     / _ "<<(char)92<<(char)92<<" V /   "<<(char)92<<"  /  | |_  | | | |  "<<(char)92<<"| |"<<endl;
    gotoxy(38,21);cout<<"|  __/| |___ / ___ "<<(char)92<<"| |    /  "<<(char)92<<"  |  _| | |_| | |"<<(char)92<<"  |"<<endl;
    gotoxy(38,22);cout<<"|_|   |_____/_/   "<<(char)92<<"_"<<(char)92<<"_|   /_/"<<(char)92<<"_"<<(char)92<<" |_|    "<<(char)92<<"___/|_| "<<(char)92<<"_|"<<endl;
}


/// AGREGAR VIDEOJUEGO
void agregarVideojuego(){
    rlutil::showcursor();
    Videojuego reg;
    ArchivoVideojuegos arcVideojuegos;
    int pos=arcVideojuegos.getCantidad()+1;
    reg.setIdJuego(pos);
    if(reg.Cargar()==true){
        if(arcVideojuegos.agregarVideojuego(reg)==false){
            cout<<"ERROR AL ABRIR EL ARCHIVO :("<<endl;
        }
        else cout<<endl<<"REGISTRO AGREGADO AL ARCHIVO"<<endl;
    }
    else cout<<endl<<"AGREGO ALGUN DATO INVALIDO, REGISTRO NO GUARDADO"<<endl;
}

/// LISTAR VIDEOJUEGO POR ID
void listarVideojuegoPorID(){
    rlutil::showcursor();
    int id;
    ArchivoVideojuegos arcVideojuegos;
    Videojuego obj;
    cout<<"INGRESAR ID DEL JUEGO QUE DESEA BUSCAR: ";
    cin>>id;
    cout<<endl;
    if(arcVideojuegos.buscarPorID(id)==-1){
        cout<<"EL ID DEL JUEGO NO EXISTE EN EL ARCHIVO"<<endl;
        return ;
    }
    obj=arcVideojuegos.leerRegistro(arcVideojuegos.buscarPorID(id));
    obj.mostrarEncabezado();
    obj.Mostrar();
    cout<<endl;
}

/// MODIFICAR IMPORTE
void modificarImporte(){
    rlutil::showcursor();
    ArchivoVideojuegos arcVideojuegos;
    Videojuego reg;
    int id;
    cout<<"INGRESAR ID DEL JUEGO QUE DESEA BUSCAR: ";
    cin>>id;
    cout<<endl;
    if(arcVideojuegos.buscarPorID(id)==-1){
        cout<<"EL ID DEL JUEGO NO EXISTE EN EL ARCHIVO"<<endl;
        return ;
    }
    reg=arcVideojuegos.leerRegistro(arcVideojuegos.buscarPorID(id));
    cout<<"INGRESAR EL NUEVO IMPORTE ($): ";
    float importe;
    cin>>importe;
    reg.setImporte(importe);
    bool modifico=arcVideojuegos.modificarRegistro(reg,arcVideojuegos.buscarPorID(id));
    if(modifico!=0)cout<<"\nIMPORTE MODIFICADO CORRECTAMENTE\n";
}

/// ELIMINAR VIDEOJUEGO
void eliminarVideojuego(){
    rlutil::showcursor();
    ArchivoVideojuegos arcVideojuegos;
    cout<<"INGRESAR ID DEL JUEGO QUE DESEA BUSCAR, PARA LUEGO ELIMINAR : ";
    int id;
    cin>>id;
    if(arcVideojuegos.buscarPorID(id)==-1){
        cout<<"\nNO EXISTE EL ID DEL JUEGO EN EL ARCHIVO\n"<<endl;
        return;}
    else if(arcVideojuegos.buscarPorID(id)==-2){
        cout<<"\nEL ID DEL JUEGO EXISTE PERO YA FUE DADO DE BAJA EN EL ARCHIVO\n"<<endl;
        return;
    }

    Videojuego reg;
    reg = arcVideojuegos.leerRegistro(arcVideojuegos.buscarPorID(id));
    cout<<endl;
    reg.mostrarEncabezado();
    reg.Mostrar();
    cout<<endl<<"ESTAS SEGURO QUE QUIERES ELIMINAR ESTE VIDEOJUEGO?(1-SI,0-NO): ";
    int opc;
    cin>>opc;
    if(opc==1){
    reg.setEstado(false);
    bool modifico=arcVideojuegos.modificarRegistro(reg,arcVideojuegos.buscarPorID(id));
    if(modifico!=0)cout<<"\nREGISTRO ELMINADO CORRECTAMENTE\n";
    }
    else{
        cout<<"\n\nENTONCES PARA QUE BUSCAS EL REGISTRO SI NO LO QUERES ELIMINAR?\nQUIEN TE ENTIENDE..."<<endl;
    }
}

/// MENU VIDEOJUEGOS
void MenuVideojuegos(){
    ArchivoVideojuegos arcVideojuegos;
    int opc=1,y=0;
    while(opc!=0){
        MostrarCartel();
        MenuBlanco(" -------------------------------- ",47,4);
        MenuBlanco("                                  ",47,5);
        MenuVacio("     MENU VIDEOJUEGOS     ",51,5);
        MenuBlanco(" -------------------------------- ",47,6);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();
        mostrarOpcion("     AGREGAR VIDEOJUEGO     ",50,8,y==0);
        mostrarOpcion("  LISTAR VIDEOJUEGO POR ID  ",50,9,y==1);
        mostrarOpcion("         LISTAR TODO        ",50,10,y==2);
        mostrarOpcion("      MODIFICAR IMPORTE     ",50,11,y==3);
        mostrarOpcion("     ELIMINAR VIDEOJUEGO    ",50,12,y==4);
        mostrarOpcion("  VOLVER AL MENU PRINCIPAL  ",50,13,y==5);
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
            case 0: agregarVideojuego();
                break;
            case 1: listarVideojuegoPorID();
                break;
            case 2: arcVideojuegos.listarTodosVideojuegos();
                break;
            case 3: modificarImporte();
                break;
            case 4: eliminarVideojuego();
                break;
            case 5: opc=0;
                break;
            }
            if(opc!=0) cout<<"\n\n\n\n"<<system("pause");
            system("cls");
            break;
        }
    }
}

/// AGREGAR EMPLEADO
void agregarEmpleado(){
    rlutil::showcursor();
    Empleado reg;
    ArchivoEmpleados arcEmpleados;
    int pos=arcEmpleados.getCantidad()+1;
    reg.setIdEmpleado(pos);
    cout<<"DNI: ";
    int dni;
    cin>>dni;
    if(arcEmpleados.buscarPorDNI(dni)==-1 && reg.Cargar()==true){
        reg.setDNI(dni);
        if(arcEmpleados.agregarEmpleado(reg)==false){
            cout<<"ERROR AL ABRIR EL ARCHIVO :("<<endl;
        }
        else cout<<endl<<"REGISTRO AGREGADO AL ARCHIVO"<<endl;
    }
    else if(arcEmpleados.buscarPorDNI(dni)==-2){
        cout<<"EL DNI EXISTE PERO FUE DADO DE BAJA, QUIERE VOLVER A AGREGAR A ESTE EMPLEADO?(1-SI, 0-NO): ";
        int opc;
        cin>>opc;
        if(opc==true){
            Empleado reg;
            reg=arcEmpleados.leerRegistro(arcEmpleados.buscarPorDNIeliminado(dni));
            reg.setEstado(true);
            bool modifico=arcEmpleados.modificarRegistro(reg,arcEmpleados.buscarPorDNIeliminado(dni));
            if(modifico!=0)cout<<"\nEMPLEADO AGREGADO CORRECTAMENTE\n";
        }
    }
    else cout<<endl<<"AGREGO ALGUN DATO INVALIDO, REGISTRO NO GUARDADO"<<endl;
}

/// LISTAR EMPLEADO POR ID
void listarEmpleadoPorID(){
    rlutil::showcursor();
    int id;
    ArchivoEmpleados arcEmpleados;
    Empleado obj;
    cout<<"INGRESAR ID DEL EMPLEADO QUE DESEA BUSCAR: ";
    cin>>id;
    cout<<endl;
    if(arcEmpleados.buscarPorID(id)==-1){
        cout<<"EL ID DEL EMPLEADO NO EXISTE EN EL ARCHIVO"<<endl;
        return ;
    }
    obj=arcEmpleados.leerRegistro(arcEmpleados.buscarPorID(id));
    obj.mostrarEncabezado();
    obj.Mostrar();
    cout<<endl;
}

/// MODIFICAR TELEFONO
void modificarTelefonoEmpleado(){
    rlutil::showcursor();
    ArchivoEmpleados arcEmpleados;
    Empleado reg;
    int id;
    cout<<"INGRESAR ID DEL EMPLEADO QUE DESEA BUSCAR: ";
    cin>>id;
    cout<<endl;
    if(arcEmpleados.buscarPorID(id)==-1){
        cout<<"EL ID DEL EMPLEADO NO EXISTE EN EL ARCHIVO"<<endl;
        return ;
    }
    reg=arcEmpleados.leerRegistro(arcEmpleados.buscarPorID(id));
    cout<<"INGRESAR EL NUEVO TELEFONO: ";
    int tel;
    cin>>tel;
    reg.setTelefono(tel);
    bool modifico=arcEmpleados.modificarRegistro(reg,arcEmpleados.buscarPorID(id));
    if(modifico!=0)cout<<"\nTELEFONO MODIFICADO CORRECTAMENTE\n";
}

/// ELIMINAR EMPLEADO
void eliminarEmpleado(){
    rlutil::showcursor();
    ArchivoEmpleados arcEmpleados;
    cout<<"INGRESAR ID DEL EMPLEADO QUE DESEA BUSCAR, PARA LUEGO ELIMINAR : ";
    int id;
    cin>>id;
    if(arcEmpleados.buscarPorID(id)<0){
        cout<<"\nNO EXISTE EL ID DEL EMPLEADO EN EL ARCHIVO\n"<<endl;
        return;}
    Empleado reg;
    reg = arcEmpleados.leerRegistro(arcEmpleados.buscarPorID(id));
    reg.setEstado(false);
    bool modifico=arcEmpleados.modificarRegistro(reg,arcEmpleados.buscarPorID(id));
    if(modifico!=0)cout<<"\nREGISTRO ELMINADO CORRECTAMENTE\n";
}

/// MENU EMPLEADOS
void MenuEmpleados(){
    ArchivoEmpleados arcEmpleados;
    int opc=1,y=0;
    while(opc!=0){
        MostrarCartel();
        MenuBlanco(" -------------------------------- ",47,4);
        MenuBlanco("                                  ",47,5);
        MenuVacio("      MENU EMPLEADOS      ",51,5);
        MenuBlanco(" -------------------------------- ",47,6);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();
        mostrarOpcion("      AGREGAR EMPLEADO      ",50,8,y==0);
        mostrarOpcion("   LISTAR EMPLEADO POR ID   ",50,9,y==1);
        mostrarOpcion("        LISTAR TODO         ",50,10,y==2);
        mostrarOpcion("     MODIFICAR TELEFONO     ",50,11,y==3);
        mostrarOpcion("     ELIMINAR EMPLEADO      ",50,12,y==4);
        mostrarOpcion("  VOLVER AL MENU PRINCIPAL  ",50,13,y==5);
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
            case 0: agregarEmpleado();
                break;
            case 1: listarEmpleadoPorID();
                break;
            case 2: arcEmpleados.listarTodosEmpleados();
                break;
            case 3: modificarTelefonoEmpleado();
                break;
            case 4: eliminarEmpleado();
                break;
            case 5: opc=0;
                break;
            }
            if(opc!=0) cout<<"\n\n\n\n"<<system("pause");
            system("cls");
            break;
        }
    }
}

/// AGREGAR PROVEEDOR
void agregarProveedor(){
    rlutil::showcursor();
    Proveedor reg;
    ArchivoProveedores arcProveedores;
    int pos=arcProveedores.getCantidad()+1;
    reg.setIdProveedor(pos);
    if(reg.Cargar()==true){
        if(arcProveedores.agregarProveedor(reg)==false){
            cout<<"ERROR AL ABRIR EL ARCHIVO :("<<endl;
        }
        else cout<<endl<<"REGISTRO AGREGADO AL ARCHIVO"<<endl;
    }
    else cout<<endl<<"AGREGO ALGUN DATO INVALIDO, REGISTRO NO GUARDADO"<<endl;
}

/// LISTAR PROVEEDOR POR ID
void listarProveedorPorID(){
    rlutil::showcursor();
    int id;
    ArchivoProveedores arcProveedores;
    Proveedor obj;
    cout<<"INGRESAR ID DEL PROVEEDOR QUE DESEA BUSCAR: ";
    cin>>id;
    cout<<endl;
    if(arcProveedores.buscarPorID(id)==-1){
        cout<<"EL ID DEL PROVEEDOR NO EXISTE EN EL ARCHIVO"<<endl;
        return ;
    }
    obj=arcProveedores.leerRegistro(arcProveedores.buscarPorID(id));
    obj.mostrarEncabezado();
    obj.Mostrar();
    cout<<endl;
}

/// MODIFICAR TELEFONO PROVEEDOR
void modificarTelefonoProveedor(){
    rlutil::showcursor();
    ArchivoProveedores arcProveedores;
    Proveedor reg;
    int id;
    cout<<"INGRESAR ID DEL PROVEEDOR QUE DESEA BUSCAR: ";
    cin>>id;
    cout<<endl;
    if(arcProveedores.buscarPorID(id)==-1){
        cout<<"EL ID DEL PROVEEDOR NO EXISTE EN EL ARCHIVO"<<endl;
        return ;
    }
    reg=arcProveedores.leerRegistro(arcProveedores.buscarPorID(id));
    cout<<"INGRESAR EL NUEVO TELEFONO: ";
    int tel;
    cin>>tel;
    reg.setTelefono(tel);
    bool modifico=arcProveedores.modificarRegistro(reg,arcProveedores.buscarPorID(id));
    if(modifico!=0)cout<<"\nTELEFONO MODIFICADO CORRECTAMENTE\n";
}

/// ELIMINAR PROVEEDOR
void eliminarProveedor(){
    rlutil::showcursor();
    ArchivoProveedores arcProveedores;
    cout<<"INGRESAR ID DEL PROVEEDOR QUE DESEA BUSCAR, PARA LUEGO ELIMINAR : ";
    int id;
    cin>>id;
    if(arcProveedores.buscarPorID(id)<0){
        cout<<"\nNO EXISTE EL ID DEL PROVEEDOR EN EL ARCHIVO\n"<<endl;
        return;}
    Proveedor reg;
    reg = arcProveedores.leerRegistro(arcProveedores.buscarPorID(id));
    reg.setEstado(false);
    bool modifico=arcProveedores.modificarRegistro(reg,arcProveedores.buscarPorID(id));
    if(modifico!=0)cout<<"\nREGISTRO ELMINADO CORRECTAMENTE\n";
}

/// MENU PROVEEDORES
void MenuProveedores(){
    ArchivoProveedores arcProveedores;
    int opc=1,y=0;
    while(opc!=0){
        MostrarCartel();
        MenuBlanco(" -------------------------------- ",47,4);
        MenuBlanco("                                  ",47,5);
        MenuVacio("     MENU PROVEEDORES     ",51,5);
        MenuBlanco(" -------------------------------- ",47,6);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();
        mostrarOpcion("     AGREGAR PROVEEDOR      ",50,8,y==0);
        mostrarOpcion("  LISTAR PROVEEDOR POR ID   ",50,9,y==1);
        mostrarOpcion("        LISTAR TODO         ",50,10,y==2);
        mostrarOpcion("    MODIFICAR TELEFONO      ",50,11,y==3);
        mostrarOpcion("    ELIMINAR PROVEEDOR      ",50,12,y==4);
        mostrarOpcion("  VOLVER AL MENU PRINCIPAL  ",50,13,y==5);
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
            case 0: agregarProveedor();
                break;
            case 1: listarProveedorPorID();
                break;
            case 2: arcProveedores.listarTodosProveedores();
                break;
            case 3: modificarTelefonoProveedor();
                break;
            case 4: eliminarProveedor();
                break;
            case 5: opc=0;
                break;
            }
            if(opc!=0) cout<<"\n\n\n\n"<<system("pause");
            system("cls");
            break;
        }
    }
}

/// AGREGAR VENTA
void agregarVenta(){
    rlutil::showcursor();
    Venta reg;
    ArchivoVentas arcVentas;
    int pos=arcVentas.getCantidad()+1;
    reg.setCodigoVenta(pos);
    if(reg.Cargar()==true){
        ArchivoVideojuegos arcVideojuegos;
        Videojuego jug=arcVideojuegos.leerRegistro(arcVideojuegos.buscarPorID(reg.getIdJuego()));
        reg.setImporteUnitario(jug.getImporte());
        reg.setImporteTotal(jug.getImporte()*reg.getCantidad());
        if(arcVentas.agregarVenta(reg)==false){
            cout<<"ERROR AL ABRIR EL ARCHIVO :("<<endl;
        }
        else cout<<endl<<"REGISTRO AGREGADO AL ARCHIVO"<<endl;
    }
    else cout<<endl<<"AGREGO ALGUN DATO INVALIDO, REGISTRO NO GUARDADO"<<endl;
}

/// LISTAR VENTA POR CODIGO
void listarVentaPorCodigo(){
    rlutil::showcursor();
    int id;
    ArchivoVentas arcVentas;
    Venta obj;
    cout<<"INGRESAR EL CODIGO DE LA VENTA QUE DESEA BUSCAR: ";
    cin>>id;
    cout<<endl;
    if(arcVentas.buscarPorCodigoVenta(id)==-1){
        cout<<"EL CODIGO DE LA VENTA NO EXISTE EN EL ARCHIVO"<<endl;
        return ;
    }
    obj=arcVentas.leerRegistro(arcVentas.buscarPorCodigoVenta(id));
    obj.mostrarEncabezado();
    obj.Mostrar();
    cout<<endl;
}

/// MODIFICAR ID EMPLEADO SEGUN VENTA
void modificarEmpleadoVenta(){
    rlutil::showcursor();
    ArchivoVentas arcVentas;
    Venta reg;
    int id;
    cout<<"INGRESAR EL CODIGO DE LA VENTA QUE DESEA BUSCAR: ";
    cin>>id;
    cout<<endl;
    if(arcVentas.buscarPorCodigoVenta(id)==-1){
        cout<<"EL CODIGO DE LA VENTA NO EXISTE EN EL ARCHIVO"<<endl;
        return ;
    }
    reg=arcVentas.leerRegistro(arcVentas.buscarPorCodigoVenta(id));
    cout<<"INGRESAR EL NUEVO ID DEL EMPLEADO: ";
    int emple;
    cin>>emple;
    if(reg.setEmpleado(emple)==true){
        bool modifico=arcVentas.modificarRegistro(reg,arcVentas.buscarPorCodigoVenta(id));
        if(modifico!=0)cout<<"\nID DEL EMPLEADO EN LA VENTA MODIFICADO CORRECTAMENTE\n";
    }
    else{cout<<"EL ID DEL EMPLEADO NO EXISTE, REGISTRO NO MODIFICADO";}
}

/// ELIMINAR VENTA
void eliminarVenta(){
    rlutil::showcursor();
    ArchivoVentas arcVentas;
    cout<<"INGRESAR EL CODIGO DE LA VENTA QUE DESEA BUSCAR, PARA LUEGO ELIMINAR : ";
    int id;
    cin>>id;
    if(arcVentas.buscarPorCodigoVenta(id)<0){
        cout<<"\nNO EXISTE EL CODIGO DE LA VENTA EN EL ARCHIVO\n"<<endl;
        return;}
    Venta reg;
    reg = arcVentas.leerRegistro(arcVentas.buscarPorCodigoVenta(id));
    reg.setEstado(false);
    bool modifico=arcVentas.modificarRegistro(reg,arcVentas.buscarPorCodigoVenta(id));
    if(modifico!=0)cout<<"\nREGISTRO ELMINADO CORRECTAMENTE\n";
}

/// MENU VENTAS
void MenuVentas(){
    ArchivoVentas arcVentas;
    int opc=1,y=0;
    while(opc!=0){
        MostrarCartel();
        MenuBlanco(" -------------------------------- ",47,4);
        MenuBlanco("                                  ",47,5);
        MenuVacio("       MENU VENTAS        ",51,5);
        MenuBlanco(" -------------------------------- ",47,6);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();
        mostrarOpcion("     AGREGAR UNA VENTA      ",50,8,y==0);
        mostrarOpcion("  LISTAR VENTA POR CODIGO   ",50,9,y==1);
        mostrarOpcion("        LISTAR TODO         ",50,10,y==2);
        mostrarOpcion("   MODIFICAR ID EMPLEADO    ",50,11,y==3);
        mostrarOpcion("      ELIMINAR VENTA        ",50,12,y==4);
        mostrarOpcion("  VOLVER AL MENU PRINCIPAL  ",50,13,y==5);
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
            case 0: agregarVenta();
                break;
            case 1: listarVentaPorCodigo();
                break;
            case 2: arcVentas.listarTodasLasVentas();
                break;
            case 3: modificarEmpleadoVenta();
                break;
            case 4: eliminarVenta();
                break;
            case 5: opc=0;
                break;
            }
            if(opc!=0) cout<<"\n\n\n\n"<<system("pause");
            system("cls");
            break;
        }
    }
}

void funcion(){
    char vecCategoria[8][30];
    strcpy(vecCategoria[0],"Accion");
    cout<<vecCategoria[0];
}

/// MENU REPORTES
void MenuReportes(){
    int opc=1,y=0;
    while(opc!=0){
        MostrarCartel();
        MenuBlanco(" -------------------------------- ",47,4);
        MenuBlanco("                                  ",47,5);
        MenuVacio("      MENU REPORTES       ",51,5);
        MenuBlanco(" -------------------------------- ",47,6);
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();
        mostrarOpcion("          PUNTO 1           ",50,8,y==0);
        mostrarOpcion("          PUNTO 2           ",50,9,y==1);
        mostrarOpcion("          PUNTO 3           ",50,10,y==2);
        mostrarOpcion("  VOLVER AL MENU PRINCIPAL  ",50,11,y==3);
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
            if(y>3){y=3;}
            break;
        case 1: //ENTER
            system("cls");
            switch(y){
            case 0: funcion();
                break;
            case 1: cout<<"HOLA MUNDO";
                break;
            case 2: cout<<"HOLA MUNDO";
                break;
            case 3: opc=0;
                break;
            }
            if(opc!=0) cout<<"\n\n\n\n"<<system("pause");
            system("cls");
            break;
        }
    }
}

#endif // FUNCIONES_H_INCLUDED
