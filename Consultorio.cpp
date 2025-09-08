//Programa Principal CPP

#include "iostream"
#include "fstream"
#include "string"
#include "chrono"
#include "conio.h"
#include "ctime"
using namespace std;

#include "Consultorio.h"

int main(){
    int n = 0, r=0, ren = 0, ren2 = 0, ren3 = 0; string rpt;//contadores
    string listaPacientes[10][7]; int numeroPaciente[10][10];

    //Instance de los objetos de cada clase
    Paciente *clientes[10]; 
    Doctora *doctora = new Doctora("Olivia del Olivo","ladocoli223", "laDoctora123", "Pediatra");

    //numero de pacientes que se pueden registrar y datos de los pacientes
    int numPaciente; string nombre, edad, sexo, calle, colonia, municipio, telefono, status; 
    fstream CambiarPacientes;

    //datos de usuario y contraseña de bloc de notas
    fstream Acceso; string usuarios[11][11], usuario, contrasena;
    
     //verifica contrasena dentro del programa
    string username, password;

    //Inicializa el programa y pregunta el tipo de usuario   
    int opcion;
    cout<<"Bienvenid@ al Consultorio de la Dra. Olivia!\n";
    cout<<"Desea ingresar como la Doctora o como Paciente?: (1 = Doctora | 2 = Paciente) \n";
    cin>> opcion;

        while(opcion != 1 and opcion != 2){
         cout<<"Porfavor ingrese un numero entre el 1 y el 2 :\n"; cin>>opcion;
        }
    //While que opera mientras el usuario ingresa su usuario y/o contraseña

    if (opcion == 1)    
        {
            ifstream LeerAcceso;
            LeerAcceso.open("ControlDeAcceso.txt"); //read
            while(LeerAcceso >> usuario >> contrasena){        
                usuarios[ren][0] = usuario;
                usuarios[ren][1] = contrasena;
                //cout<<"usuario "<< ren << " copiado \n";
                ren++;
            }   LeerAcceso.close();

            cout<<"Favor de ingresar la contrasenia: \n";
            cin>> password;
        while(password != usuarios[0][1])
        {cout<<"Contraseña equivocada, intente de nuevo:\n"; cin >> password;}

        if(password == usuarios[0][1]){   //SI LA CONTRASENIA DE LA DOCTORA SON CORRECTOS

        do{
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            cout<<" ===== Consultorio Dra. Olivia(Usuario: Doctora Olivia) =====\n";
            cout<<"1) Registrar un Paciente \n2) Modificar datos del Paciente \n3) Agendar una cita\n";
            cout<<"4) Mostrar la cita \n5) Ver Pacientes \n6) Salir \n";
   
            cout<<"Eliga una opcion:" ;

        //SWITCH DE LA DOCTORA -- USUARIO DE DOCTORA -- A LO QUE LA DOCTORA TIENE ACCESO
        int opcion2;
        cin>>opcion2;
            while(opcion2 < 1 or opcion2 > 8 ){
                cout<<"Por favor escoja una opcion entre el 1 y el 8: ";
                cin>>opcion2;
            }
        ifstream LeerPacientes;
        switch (opcion2){
            case 1: //NUEVO USUARIO / REGISTRARSE / Registrar un Paciente
                cin.ignore();
                cout<<"Bienvenido al registro de pacientes!\n Le pedimos que por favor ingrese los siguientes datos: ";
                cout<<"\nNombre: "; getline(cin, nombre);
                cout<<"\nEdad: "; getline(cin, edad);
                cout<<"\nSexo: "; getline(cin, sexo);

                cout<<"\n --- Datos de domicilio --- ";
                cout<<"\nCalle: "; getline(cin, calle);
                cout<<"\nColonia: "; getline(cin, colonia);
                cout<<"\nMunicipio: "; getline(cin, municipio);
                cout<<"\nTelefono: "; getline(cin, telefono);
                status = "Indefinido";

                clientes[ren] = new Paciente(nombre, edad, sexo, calle, colonia, municipio, telefono, status);
                clientes[ren] -> leerPacientes();
                clientes[ren] -> registrarPacientes(nombre, edad, sexo, calle, colonia, municipio, telefono, status);
            break;

            case 2: //Modificar datos de un Paciente
            doctora->modificarPacientes();
            break;

            case 3: //Agendar una cita para un paciente
            doctora->agendarCita();
            break;

            case 4: //Mostrar la cita
            doctora->verCalendario();
            break;

            case 5: //Ver Pacientes
            doctora->verPacientes();
            break;
        
            case 6: //Salir del programa
            exit(0);

        }//CIERRA SWITCH
        cout<<"Desea ir al menu o salir del programa? Escriba Y para volver al menu o N para salir del programa\n";
        cin >> rpt;
            } while( rpt == "Y" or rpt == "y");
        //CIERRA SESION DE LA DOCTORA
        ////////////////////////////////////////////////////////////////////////////////////////////////
        
        }
        } 
        if (opcion == 2){
        do{
            int opcion3;
            cout<<"Ya esta registrado en el consultorio?: \n1) Si \n2) No\n";
            cin>>opcion3;

            while(opcion3 != 1 && opcion3 != 2){ cout<<"Porfavor escriba una opcion entre 1 y 2:\n"; cin>>opcion3;}
            if (opcion3 == 1)
            {
                
            }
            if (opcion3 == 2)
            {
                cin.ignore();
                cout<<"Bienvenido al registro de pacientes!\n Le pedimos que por favor ingrese los siguientes datos: ";
                cout<<"\nNombre: "; getline(cin, nombre);
                cout<<"\nEdad: "; getline(cin, edad);
                cout<<"\nSexo: "; getline(cin, sexo);

                cout<<"\n --- Datos de domicilio --- ";
                cout<<"\nCalle: "; getline(cin, calle);
                cout<<"\nColonia: "; getline(cin, colonia);
                cout<<"\nMunicipio: "; getline(cin, municipio);
                cout<<"\nTelefono: "; getline(cin, telefono);
                status = "Indefinido";

                clientes[ren] = new Paciente(nombre, edad, sexo, calle, colonia, municipio, telefono, status);
                clientes[ren] -> leerPacientes();
                clientes[ren] -> registrarPacientes(nombre, edad, sexo, calle, colonia, municipio, telefono, status);
            }
            
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            cout<<" ===== Consultorio Dra. Juguetes(Usuario:"<< nombre <<") =====\n";
            cout<<"1) Agendar una cita \n2) Ver Calendario de la doctora \n3) Pagar la cita\n";
            cout<<"4) Modificar una cita \n5) Salir\n";
   
            cout<<"Eliga una opcion:" ;

        //SWITCH DEL PACIENTE -- A LO QUE EL PACIENTE TIENE ACCESO
        int opcion2;
        cin>>opcion2;
            while(opcion2 < 1 or opcion2 > 8 ){
                cout<<"Por favor escoja una opcion entre el 1 y el 8: ";
                cin>>opcion2;
            }
        ifstream LeerPacientes;
        switch (opcion2){
            case 1: //Agendar una cita
            clientes[ren] -> agendarCita();
            break;

            case 2: //Ver Calendario de la doctora
            clientes[ren] -> verCalendario();
            break;

            case 3: //Pagar la cita
            clientes[ren] -> pagarCita(nombre);
            break;

            case 4: //Modificar una cita
            clientes[ren]->modificarCita();
            break;

            case 5: //Salir del programa
            exit(0);

        }//CIERRA SWITCH
        

        cout<<"Desea ir al menu o salir del programa? Escriba Y para volver al menu o N para salir del programa\n";
        cin >> rpt;
        } while( rpt == "Y" or rpt == "y");
        //CIERRA SESION DE LA DOCTORA 
    
        }
        return 0;
    }
        
    

