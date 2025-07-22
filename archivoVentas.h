#ifndef ARCHIVOVENTAS_H_INCLUDED
#define ARCHIVOVENTAS_H_INCLUDED

class ArchivoVentas{
    private:
    char _nombre[40];
    public:
    ArchivoVentas(const char *n="ventas.dat"){
        strcpy(_nombre,n);
    }

    bool agregarVenta(Venta reg){
        FILE *p;
        p=fopen(_nombre, "ab");
        if(p==NULL){return false;}
        bool grabo=fwrite(&reg, sizeof (Venta), 1, p);
        fclose(p);
        return grabo;
    }

    bool listarTodasLasVentas(){
        FILE *p;
        Venta aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        aux.mostrarEncabezado();
        while(fread(&aux, sizeof (Venta), 1, p)==1){
            if(aux.getEstado()==true){aux.Mostrar();}
        }
        fclose(p);
        return true;
    }

    int buscarPorCodigoVenta(int cod){
        FILE *p;
        Venta aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return -1;}
        while(fread(&aux, sizeof(Venta), 1, p)){
            if(aux.getCodigoVenta()==cod && aux.getEstado()==true){
                int pos=(ftell(p)/sizeof (Venta))-1;
                fclose(p);
                return pos;
            }
        }
        fclose(p);
        return -1;
    }

    Venta leerRegistro(int pos){
        FILE *p;
        Venta aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return aux;}
        fseek(p, pos * sizeof (Venta),0);
        fread(&aux, sizeof(Venta), 1, p);
        fclose(p);
        return aux;
    }

    bool modificarRegistro(Venta reg, int pos){
        FILE *p;
        p = fopen(_nombre, "rb+");
        if(p==NULL){return false;}
        fseek(p, pos * sizeof (Venta), 0);
        bool modifico = fwrite(&reg, sizeof (Venta), 1, p);
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
        return tam/sizeof(Venta);
    }
};

#endif // ARCHIVOVENTAS_H_INCLUDED
