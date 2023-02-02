#include <iostream>
#include <string>

using namespace std;

class Aviones{
    private:
     string id, marca , mod;
     int  asis;
    public:
    //atributo
    Aviones(){
        asis = 0;
        id = "";
        marca = "";
        mod = "";
    };

    //metodos
    void leerdatos(){
cout << "\nIngrese la marca del avion: " << endl;
        fflush(stdin);
        getline(cin, marca);
        cout << "Ingrese el modelo del avion: " << endl;
        getline(cin, mod);
        cout << "Ingrese el identificador del avion:  " << endl;
        getline(cin, id);
        cout <<"Ingrese la cantidad de asientos del avion: " << endl;
        cin >> asis;
}

int asientos(){
        return asis+0;
    }

 void mostrar(){
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << mod << endl;
        cout << "Identificador: " << id << endl;
        cout << "Numero de asientos: " << asis << endl;
    }
};
class Aero{
    //atributos
    private:
    string nombre;
    string dir;
    int canest;
    Aviones avion[30];
    
    //metodos
    public:
    Aero(){
        nombre = "";
        dir = "";
    };
    void leer(void){
        cout <<"Nombre del Aeropuerto: " << endl;
       getline(cin, nombre);
        cout << "Direccion: " << endl;
       getline(cin, dir);
        cout <<  "Cantidad de aviones: " << endl;
        cin >> canest;
        do{
        if(canest<0 || canest > 30){
            cout <<"Cantidad de aviones fuera de los limites, Por favor intentelo de nuevo: "<< endl;
            cin >> canest;
        }
        }while (canest < 0 || canest >30);

        for(int i=0; i<canest; i++){
            avion[i].leerdatos();
        };
    }
     void mostrar(void){
        system ("cls");
        cout <<"Nombre del Aeropuerto: "<< nombre << endl;
        cout << "Direccion: "   << dir << endl;
        cout <<  "Cantidad de aviones: "<< canest << endl;
    for(int i=0; i<canest; i++){
            avion[i].mostrar();
        };
    }

void mostrarporasis(){
   int asismin;
   cout << "Asientos a comparar: "; cin >> asismin;
   for(int i=0; i < canest; i++){
      if (avion[i].asientos() <= asismin){
         avion[i].mostrar();
      }
   }
}
~Aero(){};
};

int main() {
    Aero a1;

    a1.leer();
    a1.mostrar();
    a1.mostrarporasis();
    system("pause");
    return 0;
}