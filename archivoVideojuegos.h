#ifndef ARCHIVOVIDEOJUEGOS_H_INCLUDED
#define ARCHIVOVIDEOJUEGOS_H_INCLUDED

class ArchivoVideojuegos{
    private:
    char _nombre[40];
    public:
    ArchivoVideojuegos(const char *n="videojuegos.dat"){
        strcpy(_nombre,n);
    }

    bool agregarVideojuego(Videojuego reg){
        FILE *p;
        p=fopen(_nombre, "ab");
        if(p==NULL){return false;}
        bool grabo=fwrite(&reg, sizeof (Videojuego), 1, p);
        fclose(p);
        return grabo;
    }

    bool listarTodosVideojuegos(){
        FILE *p;
        Videojuego aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        aux.mostrarEncabezado();
        while(fread(&aux, sizeof (Videojuego), 1, p)==1){
            if(aux.getEstado()==true){aux.Mostrar();}
        }
        fclose(p);
        return true;
    }

    int buscarPorID(int id){
        FILE *p;
        Videojuego aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return -1;}
        while(fread(&aux, sizeof(Videojuego), 1, p)){
            if(aux.getIdJuego()==id && aux.getEstado()==true){
                int pos=(ftell(p)/sizeof (Videojuego))-1;
                fclose(p);
                return pos;
            }
            if(aux.getEstado()==false && aux.getIdJuego()==id)return -2;
        }
        fclose(p);
        return -1;
    }

    Videojuego leerRegistro(int pos){
        FILE *p;
        Videojuego aux;
        p=fopen(_nombre, "rb");
        if(p==NULL){return aux;}
        fseek(p, pos * sizeof (Videojuego),0);
        fread(&aux, sizeof(Videojuego), 1, p);
        fclose(p);
        return aux;
    }

    bool modificarRegistro(Videojuego reg, int pos){
        FILE *p;
        p = fopen(_nombre, "rb+");
        if(p==NULL){return false;}
        fseek(p, pos * sizeof (Videojuego), 0);
        bool modifico = fwrite(&reg, sizeof (Videojuego), 1, p);
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
        return tam/sizeof(Videojuego);
    }
};


#endif // ARCHIVOVIDEOJUEGOS_H_INCLUDED
