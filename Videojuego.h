#ifndef VIDEOJUEGO_H_INCLUDED
#define VIDEOJUEGO_H_INCLUDED

class Videojuego{
    private:
        int _idJuego;
        char _nombre[30];
        int _proveedor;
        Fecha _fechaDeLanzamiento;
        int _categoria;
        int _generacion;
        float _importe;
        bool _estado;
    public:
        bool Cargar(){
            rlutil::showcursor();
            cout<<"NOMBRE: ";
            cargarCadena(_nombre,30);
            cout<<"ID PROVEEDOR: ";
            int prov;
            cin>>prov;
            if(setProveedor(prov)==false){return false;}
            cout<<"FECHA DE LANZAMIENTO";
            if(_fechaDeLanzamiento.Cargar()==false){return false;}
            cout<<"CATEGORIA(NUMERO ENTRE 1 y 8): ";
            int cat;
            cin>>cat;
            if(setCategoria(cat)==false){return false;}
            cout<<"GENERACION(1-NEXT GEN, 2-OLD GEN): ";
            int gen;
            cin>>gen;
            if(setGeneracion(gen)==false){return false;}
            cout<<"IMPORTE($): ";
            cin>>_importe;
            _estado=true;
            return true;
        }

        void mostrarEncabezado(){
            cout<<endl<<"\t\t\t\t\t  VIDEOJUEGOS"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------"<<endl;
            cout << left;
            cout << setw(4)  << "ID";
            cout << setw(22) << "NOMBRE";
            cout << setw(20) << "PROVEEDOR";
            cout << setw(14) << "LANZAMIENTO";
            cout << setw(15) << "CATEGORIA";
            cout << setw(13) << "GENERACION";
            cout << setw(15) << "IMPORTE" << endl;
            cout<<"-----------------------------------------------------------------------------------------------"<<endl;
        }

        void Mostrar(){
//            cout<<"ID DEL JUEGO: "<<_idJuego<<endl;
//            cout<<"NOMBRE: "<<_nombre<<endl;
//            ArchivoProveedores arcProveedores;
//            Proveedor reg=arcProveedores.leerRegistro(arcProveedores.buscarPorID(_proveedor));
//            cout<<"ID PROVEEDOR: "<<reg.getIdProveedor()<<" ---> "<<reg.getNombre()<<endl;
//            cout<<"FECHA DE LANZAMIENTO: ";
//            _fechaDeLanzamiento.Mostrar();
//            switch(_categoria){
//            case 1: cout<<"CATEGORIA: 1 ---> Accion"<<endl;
//                break;
//            case 2: cout<<"CATEGORIA: 2 ---> Aventura"<<endl;
//                break;
//            case 3: cout<<"CATEGORIA: 3 ---> Arcade"<<endl;
//                break;
//            case 4: cout<<"CATEGORIA: 4 ---> Deportes"<<endl;
//                break;
//            case 5: cout<<"CATEGORIA: 5 ---> Estrategia"<<endl;
//                break;
//            case 6: cout<<"CATEGORIA: 6 ---> Simulacion"<<endl;
//                break;
//            case 7: cout<<"CATEGORIA: 7 ---> Pelea"<<endl;
//                break;
//            case 8: cout<<"CATEGORIA: 8 ---> Musical"<<endl;
//                break;
//            }
//            if(_generacion==1) {cout<<"GENERACION: 1 ---> Next gen"<<endl;}
//            else if (_generacion==2) {cout<<"GENERACION: 2 ---> Old gen"<<endl;}
//            cout<<"IMPORTE: $ "<<_importe<<endl;

            cout << left;
            cout << setw(4)  << _idJuego;
            cout << setw(22) << _nombre;
            ArchivoProveedores arcProveedores;
            Proveedor reg=arcProveedores.leerRegistro(arcProveedores.buscarPorID(_proveedor));
            cout << setw(2) << _proveedor << setw(18)<<reg.getNombre();
            _fechaDeLanzamiento.Mostrar();
            char vecCategoria[8][30];
            strcpy(vecCategoria[0],"1 Accion");
            strcpy(vecCategoria[1],"2 Aventura");
            strcpy(vecCategoria[2],"3 Arcade");
            strcpy(vecCategoria[3],"4 Deportes");
            strcpy(vecCategoria[4],"5 Estrategia");
            strcpy(vecCategoria[5],"6 Simulacion");
            strcpy(vecCategoria[6],"7 Pelea");
            strcpy(vecCategoria[7],"8 Musical");
            cout << setw(15) <<vecCategoria[_categoria-1];
            if(_generacion==1) {cout << setw(13) <<"1 Next gen";}
            else if (_generacion==2) {cout << setw(13) <<"2 Old gen";}
            cout << fixed<< setw(2) << "$" << setw(8) << setprecision(2)<<_importe << endl;
        }

        void setIdJuego(int id){_idJuego=id;}
        void setNombre(const char *n){strcpy(_nombre,n);}
        bool setProveedor(int prov){
            ArchivoProveedores arcProveedores;
            Proveedor reg;
            if(arcProveedores.buscarPorID(prov)>-1){_proveedor=prov;}
            else{return false;}
            return true;
        }

        void setFechaLanzamiento(Fecha f){_fechaDeLanzamiento=f;}
        bool setCategoria(int cat){
            if(cat>=1 && cat<=8){
                _categoria=cat;
                return true;
            }
            else {return false;}
        }
        bool setGeneracion(int gen){
            if(gen==1 || gen==2){
            _generacion=gen;
            return true;
            }
            else {return false;}
        }
        void setImporte(float imp){_importe=imp;}
        void setEstado(bool est){_estado=est;}

        int getIdJuego(){return _idJuego;}
        const char *getNombre(){return _nombre;}
        int getProveedor(){return _proveedor;}
        Fecha getFechaLanzamiento(){return _fechaDeLanzamiento;}
        int getCategoria(){return _categoria;}
        int getGeneracion(){return _generacion;}
        float getImporte(){return _importe;}
        bool getEstado(){return _estado;}

};

#endif // VIDEOJUEGO_H_INCLUDED
