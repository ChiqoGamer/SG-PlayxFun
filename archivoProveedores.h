#ifndef ARCHIVOPROVEEDORES_H_INCLUDED
#define ARCHIVOPROVEEDORES_H_INCLUDED

class ArchivoProveedores{
    private:
    char _nombre[40];
    public:
    ArchivoProveedores(const char *n="proveedores.dat"){
        strcpy(_nombre,n);
    }

    bool agregarProveedor(Proveedor reg){
        FILE *p;
        p=fopen(_nombre, "ab");
        if(p==NULL){return false;}
        bool grabo=fwrite(&reg, sizeof (Proveedor), 1, p);
        fclose(p);
        return grabo;
    }

    bool listarTodosProveedores(){
        FILE *p;
        Proveedor aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        aux.mostrarEncabezado();
        while(fread(&aux, sizeof (Proveedor), 1, p)==1){
            if(aux.getEstado()==true){aux.Mostrar();}
        }
        fclose(p);
        return true;
    }

    int buscarPorID(int id){
        FILE *p;
        Proveedor aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return -1;}
        while(fread(&aux, sizeof(Proveedor), 1, p)){
            if(aux.getIdProveedor()==id && aux.getEstado()==true){
                int pos=(ftell(p)/sizeof (Proveedor))-1;
                fclose(p);
                return pos;
            }
        }
        fclose(p);
        return -1;
    }

    Proveedor leerRegistro(int pos){
        FILE *p;
        Proveedor aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return aux;}
        fseek(p, pos * sizeof (Proveedor),0);
        fread(&aux, sizeof(Proveedor), 1, p);
        fclose(p);
        return aux;
    }

    bool modificarRegistro(Proveedor reg, int pos){
        FILE *p;
        p = fopen(_nombre, "rb+");
        if(p==NULL){return false;}
        fseek(p, pos * sizeof (Proveedor), 0);
        bool modifico = fwrite(&reg, sizeof (Proveedor), 1, p);
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
        return tam/sizeof(Proveedor);
    }
};

#endif // ARCHIVOPROVEEDORES_H_INCLUDED
