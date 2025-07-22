#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

class Empleado{
    private:
        int _idEmpleado;
        int _dni;
        char _nombre[30];
        char _apellido[30];
        int _telefono;
        Fecha _fechaingreso;
        bool _estado;
    public:
        bool Cargar(){
            rlutil::showcursor();
            cout<<"NOMBRE: ";
            cargarCadena(_nombre,30);
            cout<<"APELLIDO: ";
            cargarCadena(_apellido,30);
            cout<<"TELEFONO: ";
            cin>>_telefono;
            cout<<"FECHA DE INGRESO";
            Fecha fechaIngreso;
            if(fechaIngreso.Cargar()==false){return false;}
            else if(setFechaIngreso(fechaIngreso)==false){return false;}
            _estado=true;
            return true;
        }
        void Mostrar(){
//            cout<<"ID EMPLEADO: "<<_idEmpleado<<endl;
//            cout<<"DNI: "<<_dni<<endl;
//            cout<<"NOMBRE: "<<_nombre<<endl;
//            cout<<"APELLIDO: "<<_apellido<<endl;
//            cout<<"TELEFONO: "<<_telefono<<endl;
//            cout<<"FECHA DE INGRESO: ";

            cout << left;
            cout << setw(4)  <<_idEmpleado;
            cout << setw(7) <<_dni;
            cout << setw(14) <<_nombre;
            cout << setw(14) <<_apellido;
            cout << setw(14) <<_telefono;
            _fechaingreso.Mostrar();
            cout<<endl;
        }

         void mostrarEncabezado(){
            cout<<endl<<"\t\t\t EMPLEADOS"<<endl;
            cout<<"--------------------------------------------------------------"<<endl;
            cout << left;
            cout << setw(4)  << "ID";
            cout << setw(7) << "DNI";
            cout << setw(14) << "NOMBRE";
            cout << setw(14) << "APELLIDO";
            cout << setw(14) << "TELEFONO";
            cout << setw(14) << "INGRESO"<<endl;
            cout<<"--------------------------------------------------------------"<<endl;
        }


        void setIdEmpleado(int id){_idEmpleado=id;}
        void setDNI(int dni){_dni=dni;}
        void setNombre(const char *n){strcpy(_nombre,n);}
        void setApellido(const char *a){strcpy(_apellido,a);}
        void setTelefono(int tel){_telefono=tel;}
        bool setFechaIngreso(Fecha f){
            Fecha fechaActual;
            if(f.getAnio()<fechaActual.getAnio() ||
                (f.getAnio()==fechaActual.getAnio() && f.getMes()<fechaActual.getMes()) ||
                (f.getAnio()==fechaActual.getAnio() && f.getMes()==fechaActual.getMes() &&
                 f.getDia()<=fechaActual.getDia())){
                    _fechaingreso=f;
                    return true;
            }
            else {return false;}
        }

        void setEstado(bool e){_estado=e;}

        int getIdEmpleado(){return _idEmpleado;}
        int getDNI(){return _dni;}
        const char *getNombre(){return _nombre;}
        const char *getApellido(){return _apellido;}
        int getTelefono(){return _telefono;}
        Fecha getFechaIngreso(){return _fechaingreso;}
        bool getEstado(){return _estado;}
};


#endif // EMPLEADO_H_INCLUDED
