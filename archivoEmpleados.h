#ifndef ARCHIVOEMPLEADOS_H_INCLUDED
#define ARCHIVOEMPLEADOS_H_INCLUDED

class ArchivoEmpleados{
    private:
    char _nombre[40];
    public:
    ArchivoEmpleados(const char *n="empleados.dat"){
        strcpy(_nombre,n);
    }

    bool agregarEmpleado(Empleado reg){
        FILE *p;
        p=fopen(_nombre, "ab");
        if(p==NULL){return false;}
        bool grabo=fwrite(&reg, sizeof (Empleado), 1, p);
        fclose(p);
        return grabo;
    }

    bool listarTodosEmpleados(){
        FILE *p;
        Empleado aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        aux.mostrarEncabezado();
        while(fread(&aux, sizeof (Empleado), 1, p)==1){
            if(aux.getEstado()==true){aux.Mostrar();}
        }
        fclose(p);
        return true;
    }

    int buscarPorID(int id){
        FILE *p;
        Empleado aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return -1;}
        while(fread(&aux, sizeof(Empleado), 1, p)){
            if(aux.getIdEmpleado()==id && aux.getEstado()==true){
                int pos=(ftell(p)/sizeof (Empleado))-1;
                fclose(p);
                return pos;
            }
        }
        fclose(p);
        return -1;
    }

    int buscarPorDNI(int dni){
        FILE *p;
        Empleado aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return -1;}
        while(fread(&aux, sizeof(Empleado), 1, p)){
            if(aux.getDNI()==dni){
                int pos=(ftell(p)/sizeof (Empleado))-1;
                fclose(p);
                if(aux.getEstado()==false)return -2;
                return pos;
            }
        }
        fclose(p);
        return -1;
    }

    int buscarPorDNIeliminado(int dni){
        FILE *p;
        Empleado aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return -1;}
        while(fread(&aux, sizeof(Empleado), 1, p)){
            if(aux.getDNI()==dni && aux.getEstado()==false){
                int pos=(ftell(p)/sizeof (Empleado))-1;
                fclose(p);
                return pos;
            }
        }
        fclose(p);
        return -1;
    }

    Empleado leerRegistro(int pos){
        FILE *p;
        Empleado aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return aux;}
        fseek(p, pos * sizeof (Empleado),0);
        fread(&aux, sizeof(Empleado), 1, p);
        fclose(p);
        return aux;
    }

    bool modificarRegistro(Empleado reg, int pos){
        FILE *p;
        p = fopen(_nombre, "rb+");
        if(p==NULL){return false;}
        fseek(p, pos * sizeof (Empleado), 0);
        bool modifico = fwrite(&reg, sizeof (Empleado), 1, p);
        fclose(p);
        return modifico;
    }

    int getCantidad(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL){return 0;}
        fseek(p, 0, 2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Empleado);
    }
};

#endif // ARCHIVOEMPLEADOS_H_INCLUDED
