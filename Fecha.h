#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

/// FUNCION CARGAR CADENA
void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

class Fecha{
    private:
        int _dia, _mes, _anio;
    public:
        bool Cargar(){
            cout<<endl<<"DIA: ";
            int dia;
            cin>>dia;
            if(setDia(dia)==false)return false;
            cout<<"MES: ";
            int mes;
            cin>>mes;
            if(setMes(mes)==false)return false;
            cout<<"ANIO: ";
            int anio;
            cin>>anio;
            if(setAnio(anio)==false)return false;
            return true;
        }

        void Mostrar(){
            if(_dia<10 && _mes<10){
                cout << setw(1)  << _dia << "/";
                cout << setw(1)  << _mes << "/";
                cout << setw(10)  << _anio;
            }
            else if(_dia<10){
                cout << setw(1)  << _dia << "/";
                cout << setw(2)  << _mes << "/";
                cout << setw(9)  << _anio;
            }
            else if(_mes<10){
                cout << setw(2)  << _dia << "/";
                cout << setw(1)  << _mes << "/";
                cout << setw(9)  << _anio;
            }
            else{
                cout << setw(2)  << _dia << "/";
                cout << setw(2)  << _mes << "/";
                cout << setw(8)  << _anio;
            }
        }

        Fecha(){
        time_t tiempo;
        struct tm *tmPtr;
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);
        _anio=tmPtr->tm_year+1900;
        _mes=tmPtr->tm_mon+1;
        _dia=tmPtr->tm_mday;
        }

        int getAnio(){return _anio;}
        int getMes(){return _mes;}
        int getDia(){return _dia;}

        bool setAnio(int a){
            if(a>=1900){
                _anio=a;
                return true;
            }
            else{return false;}
        }

        bool setMes(int m){
            if(m>=1 && m<=12){
                _mes=m;
                return true;
            }
            else{return false;}
        }

        bool setDia(int d){
            if(d>=1 && d<=31){
                _dia=d;
                return true;
            }
            else{return false;}
        }
};

#endif // FECHA_H_INCLUDED
