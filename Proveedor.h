#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

class Proveedor{
    private:
        int _idProveedor;
        char _nombre[30];
        int _telefono;
        bool _estado;
    public:
        bool Cargar(){
            rlutil::showcursor();
            cout<<"NOMBRE: ";
            cargarCadena(_nombre,30);
            cout<<"TELEFONO: ";
            cin>>_telefono;
            _estado=true;
            return true;
        }
        void Mostrar(){
//            cout<<"ID DEL PROVEEDOR: "<<_idProveedor<<endl;
//            cout<<"NOMBRE: "<<_nombre<<endl;
//            cout<<"TELEFONO: "<<_telefono<<endl;
            cout << setw(4)  <<_idProveedor;
            cout << setw(18) <<_nombre;
            cout << setw(14) <<_telefono<<endl;
        }

         void mostrarEncabezado(){
            cout<<endl<<"\t  PROVEEDORES"<<endl;
            cout<<"-------------------------------"<<endl;
            cout << left;
            cout << setw(4)  << "ID";
            cout << setw(18) << "NOMBRE";
            cout << setw(14) << "TELEFONO"<<endl;
            cout<<"-------------------------------"<<endl;
        }

        void setIdProveedor(int prov){_idProveedor=prov;}
        void setNombre(const char *n){strcpy(_nombre,n);}
        void setTelefono(int tel){_telefono=tel;}
        void setEstado(bool e){_estado=e;}

        int getIdProveedor(){return _idProveedor;}
        const char *getNombre(){return _nombre;}
        int getTelefono(){return _telefono;}
        bool getEstado(){return _estado;}
};

#endif // PROVEEDOR_H_INCLUDED
