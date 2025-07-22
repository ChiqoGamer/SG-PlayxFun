#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class Venta{
    private:
        int _codigoDeVenta;
        int _idJuego;
        int _idEmpleado;
        Fecha _fechaDeVenta;
        int _cantidad;
        float _importeUnitario;
        float _importeTotal;
        bool _estado;
    public:
        bool Cargar(){
            cout<<"ID DEL JUEGO: ";
            int idJ;
            cin>>idJ;
            if(setIdJuego(idJ)==false){return false;}
            cout<<"ID DEL EMPLEADO: ";
            int idE;
            cin>>idE;
            if(setEmpleado(idE)==false){return false;}
            cout<<"CANTIDAD DE PRODUCTOS A VENDER: ";
            int cant;
            cin>>cant;
            if(setCantidad(cant)==false){return false;}
            _estado=true;
            return true;
        }
        void Mostrar(){
//            cout<<"CODIGO DE VENTA: "<<_codigoDeVenta<<endl;
//            ArchivoVideojuegos arcVideojuegos;
//            Videojuego reg=arcVideojuegos.leerRegistro(arcVideojuegos.buscarPorID(_idJuego));
//            cout<<"ID DEL JUEGO: "<<_idJuego<<" ---> "<<reg.getNombre()<<endl;
//            ArchivoEmpleados arcEmpleados;
//            Empleado aux=arcEmpleados.leerRegistro(arcEmpleados.buscarPorID(_idEmpleado));
//            cout<<"ID DEL EMPLEADO: "<<_idEmpleado<<" ---> "<<aux.getNombre()<<" "<<aux.getApellido()<<endl;
//            cout<<"FECHA DE VENTA: ";
//            _fechaDeVenta.Mostrar();
//            cout<<"CANTIDAD DE PRODUCTOS VENDIDOS: "<<_cantidad<<endl;
//            cout<<"IMPORTE UNITARIO: $ "<<reg.getImporte()<<endl;
//            cout<<"IMPORTE TOTAL: $ "<<reg.getImporte()*getCantidad()<<endl;
            cout << left;
            cout << setw(4)  <<_codigoDeVenta;
            ArchivoVideojuegos arcVideojuegos;
            Videojuego reg=arcVideojuegos.leerRegistro(arcVideojuegos.buscarPorID(_idJuego));
            cout << setw(3)  <<_idJuego<< setw(22)<<reg.getNombre();
            ArchivoEmpleados arcEmpleados;
            Empleado aux=arcEmpleados.leerRegistro(arcEmpleados.buscarPorID(_idEmpleado));
            cout << setw(2)  <<_idEmpleado<< setw(10)<<aux.getNombre()<< setw(12)<<aux.getApellido();
            _fechaDeVenta.Mostrar();
            cout << setw(7) <<_cantidad;
            cout << fixed<<setw(2) << "$" << setw(12) << setprecision(2)<<_importeUnitario;
            cout <<setw(2) << "$" << setw(12) << setprecision(2)<<_importeTotal<<endl;
        }

        void mostrarEncabezado(){
            cout<<endl<<"\t\t\t\t\t  VENTAS"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;
            cout << left;
            cout << setw(4)  << "ID";
            cout << setw(25)  << "ID DE JUEGO";
            cout << setw(24)  << "ID DE EMPLEADO";
            cout << setw(14) << "FECHA";
            cout << setw(7) << "CANT";
            cout << setw(14)<< "IMP UNITARIO";
            cout << setw(14) << "IMP TOTAL"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;
        }

        void setCodigoVenta(int cod){_codigoDeVenta=cod;}
        bool setIdJuego(int idj){
            ArchivoVideojuegos arcVideojuegos;
            Videojuego obj;
            if(arcVideojuegos.buscarPorID(idj)>-1){_idJuego=idj;}
            else{return false;}
            return true;
        }
        bool setEmpleado(int ide){
            ArchivoEmpleados arcEmpleados;
            Empleado obj;
            if(arcEmpleados.buscarPorID(ide)>-1){_idEmpleado=ide;}
            else{return false;}
            return true;
        }
        void setFechaVenta(Fecha f){_fechaDeVenta=f;}
        bool setCantidad(int cant){
            if(cant>0){
                _cantidad=cant;
                return true;
            }
            return false;
        }
        void setImporteUnitario(float impU){_importeUnitario=impU;}
        void setImporteTotal(float impT){_importeTotal=impT;}
        void setEstado(bool e){_estado=e;}

        int getCodigoVenta(){return _codigoDeVenta;}
        int getIdJuego(){return _idJuego;}
        int getEmpleado(){return _idEmpleado;}
        Fecha getFechaVenta(){return _fechaDeVenta;}
        int getCantidad(){return _cantidad;}
        float getImporteUnitario(){return _importeUnitario;}
        float getImporteTotal(){return _importeTotal;}
        bool getEstado(){return _estado;}
};

#endif // VENTAS_H_INCLUDED
