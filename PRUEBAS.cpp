#include "iostream"
#include "fstream"
#include "vector"
#include "string"

using namespace std;

int main(){
        ifstream LeerCitas;
        string calendario[8][6];
        string Lunes, Martes, Miercoles, Jueves, Viernes, Horario;
        int ren2 = 0;

         LeerCitas.open("Calendario.txt");
            while(LeerCitas>>Horario>>Lunes>>Martes>>Miercoles>>Jueves>>Viernes) // leo archivo de tabladeprecios.txt y lo vacio a la tabla
            {   
                calendario[ren2][0] = Horario;
                calendario[ren2][1] = Lunes;
                calendario[ren2][2] = Martes;
                calendario[ren2][3] = Miercoles;
                calendario[ren2][4] = Jueves;
                calendario[ren2][5] = Viernes;
                ren2++;
            }  LeerCitas.close();// termina el while
 /*
    int ren2 = 0; int ren = 0;
    string usuario, contrasena;
    fstream Acceso;
    string usuarios[11][11];//datos de usuario y contraseña

    //Check for error
    if(Acceso.fail()){ cerr<<"Error:No se pudo leer el archivo" << endl; exit(1); }


    Acceso.open("ControlDeAcceso.txt", ios::out); //write
    if(Acceso.is_open()){
        Acceso << "ladocoli223" << " laDoctora123" << endl;
 
        ren2++;
    }
        
    Acceso.close();


    
    ifstream LeerAcceso;
    LeerAcceso.open("ControlDeAcceso.txt"); //read
    
    while(LeerAcceso >> usuario >> contrasena){        
        usuarios[ren][0] = usuario;
        usuarios[ren][1] = contrasena;

        cout <<usuario<< "  |   "<<contrasena<< "   |   "<<endl;
        ren++;
    }
    LeerAcceso.close();
    
*/
    return 0;
}