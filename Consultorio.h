//Programa Consultorio.h

/*Se pide que se manejen ciclos para la validación de 
los datos que se capturan, control de acceso al programa 
a través de usuario y password. Se debe de utilizar, herencia simple, 
múltiple, constructores, destructores, setters, getters, 
cualificadores private, protected y public, polimorfismo, 
inicialización, arreglos, vectores, strings, menú de selecciones 
y manejo de memoria dinámica (optimización de memoria)
*/

#include "iostream"
#include "fstream"
#include "string"
#include "chrono"
#include "conio.h"
#include "ctime"
using namespace std;

class Consultorio{
    private:


    public:
        Consultorio();
        void leerPacientes();
        void registrarPacientes(string _nombre, string _edad, string _sexo, string _calle, string _colonia, string _municipio, string _telefono, string _status);
        virtual void agendarCita();
        virtual void verCalendario();
        ~Consultorio();

    protected:
        int r = 0;      //repetidores ciclos
        int ren = 0;    //lectura de pacientes
        int ren2 = 0;   //lectura de calendario
        int ren3 = 0;   //lectura de dias de calendario
        int ren4 = 0;   //escritura de calendario
        int dia, hora, minuto; string nombreDia, nombreHora, Horario;

        ifstream LeerCitas; fstream CambiarCitas;      //archivo para cambiar lista de pacientes
        string calendario[10][8], Lunes, Martes, Miercoles, Jueves, Viernes; //variables del calendario

        string listaPacientes[10][8]; int numeroPaciente[10][10];//numero de pacientes que se pueden registrar y datos de los pacientes
        int numPaciente; string nombre, edad, sexo, calle, colonia, municipio, telefono, status; 
        ifstream LeerPacientes;
        fstream CambiarPacientes; int cveModificar, numDato; string valorNuevo;     //archivo para cambiar lista de pacientes
        
};

        Consultorio::Consultorio(){}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////       
        void Consultorio::leerPacientes(){
            LeerPacientes.open("DatosDePacientes.txt");
            while(LeerPacientes>>numPaciente>>nombre>>edad>>sexo>>calle>>colonia>>municipio>>telefono>>status) // leo archivo de tabladeprecios.txt y lo vacio a la tabla
            {   
                cout<<"Lista "<<ren <<" copiada \n";
                numeroPaciente[ren][0]= ren+1;;
                listaPacientes[ren][1]= nombre;
                listaPacientes[ren][2]= edad;
                listaPacientes[ren][3]= sexo;
                listaPacientes[ren][4]= calle;
                listaPacientes[ren][5]= colonia;
                listaPacientes[ren][6]= municipio;
                listaPacientes[ren][7]= telefono;
                listaPacientes[ren][8]= status;
                ren++;
            }  LeerPacientes.close();// termina el while
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void Consultorio::registrarPacientes(string _nombre, string _edad, string _sexo, string _calle, string _colonia, string _municipio, string _telefono, string _status){
            
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            this-> numeroPaciente[ren][0]= ren+1;
            this-> listaPacientes[ren][1]= _nombre;
            this-> listaPacientes[ren][2]= _edad;
            this-> listaPacientes[ren][3]= _sexo;
            this-> listaPacientes[ren][4]= _calle;
            this-> listaPacientes[ren][5]= _colonia;
            this-> listaPacientes[ren][6]= _municipio;
            this-> listaPacientes[ren][7]= _telefono;
            this-> listaPacientes[ren][8]= _status;
            ren++;
            
        CambiarPacientes.open("DatosDePacientes.txt", ios::out); //write
        //for para cambiar datos del archivo de texto
        for (int r=0;r<ren;r++){
            CambiarPacientes<< numeroPaciente[r][0] <<" "<< listaPacientes[r][1]<<" "<< listaPacientes[r][2]<<" "<< listaPacientes[r][3]<<" "<< listaPacientes[r][4]<<" "<< listaPacientes[r][5]<<" "<< listaPacientes[r][6]<<" "<< listaPacientes[r][7]<<" "<< listaPacientes[r][8]<<endl;
        } // fin del for de archivo
        cout<<"El usuario se ha registrado correctamente!" << endl;      
        CambiarPacientes.close();
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void Consultorio::agendarCita(){
ren2 = 0;

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


        cout << "\x1B[2J\x1B[H";    //limpia pantalla
        cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
        cout<<"Que dia desea hacer la cita?: (Escriba el numero del 1 al 5) \n";
        cin >> dia;

        while (dia < 1 or dia > 5){
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
            cout<<"Porfavor, escriba un numero del 1 al 5: \n";
            cin >> dia; 
        }
            if(dia == 1){nombreDia = "Lunes";}
            if(dia == 2){nombreDia = "Martes";}
            if(dia == 3){nombreDia = "Miercoles";}
            if(dia == 4){nombreDia = "Jueves";}
            if(dia == 5){nombreDia = "Viernes";}
            cout<<"Horarios disponibles para el dia " << nombreDia << " : \n";

            cout<<"1) 8:00 AM \n2) 9:00 AM \n3) 10:00 AM \n4) 11:00 AM \n5) 12:00 PM \n6) 1:00 PM \n7) 3:00 PM \n8) 4:00 PM \n";
            cout<<"A que hora desea hacer la cita?: (Escriba el numero del 1 al 8) \n";
            cin >> hora;
            while(hora <1 or hora >8){
                cout<<"Porfavor, escriba un numero entre 1 y 8 \n";
                cin >> hora;
            }
            if(hora == 1){nombreHora = "8:00 AM";}
            if(hora == 2){nombreHora = "9:00 AM";}
            if(hora == 3){nombreHora = "10:00 AM";}
            if(hora == 4){nombreHora = "11:00 AM";}
            if(hora == 5){nombreHora = "12:00 PM";}
            if(hora == 6){nombreHora = "1:00 PM";}
            if(hora == 7){nombreHora = "3:00 PM";}
            if(hora == 8){nombreHora = "4:00 PM";}
            
            while(calendario[hora-1][dia] != "Disponible"){
                cout << "\x1B[2J\x1B[H";    //limpia pantalla
                cout << "El horario escogido esta ocupado\n";
                cout<<"1) 8:00 AM \n2) 9:00 AM \n3) 10:00 AM \n4) 11:00 AM \n5) 12:00 PM \n6) 1:00 PM \n7) 3:00 PM \n8) 4:00 PM \n";
                cout<<"A que hora desea hacer la cita?: (Escriba el numero del 1 al 8) \n";
                cin >> hora;
                    while(hora <1 or hora >8){
                        cout<<"Porfavor, escriba un numero entre 1 y 8 \n";
                        cin >> hora;
                    }
            }
                if(calendario[hora-1][dia] == "Disponible"){
                    cout << "Su cita ha sido agendada para el dia "<< nombreDia <<" a las " << nombreHora <<endl;
                    calendario[hora-1][dia] = "Ocupado";
                    
                } 

            //Muestra todo el calendario de disponibilidad ACTUALIZADO
            CambiarCitas.open("Calendario.txt", ios::out);
            for (int ren4=0;ren4<ren2;ren4++){
                CambiarCitas<< calendario[ren4][0] <<" "<< calendario[ren4][1] <<" "<<calendario[ren4][2]<<" "<<calendario[ren4][3]<<" "<<calendario[ren4][4]<<" "<<calendario[ren4][5]<<endl;
            } // fin del for de archivo
            CambiarCitas.close();
        cout<<"El calendario de ha actualizado correctamente!" << endl;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void Consultorio::verCalendario(){
            ren2 = 0;

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

            cout << "\x1B[2J\x1B[H";    //limpia pantalla

            //Muestra todo el calendario de disponibilidad
            cout<<"|   Calendario   |   Lunes   |   Martes   |   Miercoles   |   Jueves   |   Viernes   | \n";
            for(int r=0;r<ren2;r++){
                cout<<"|   "<< calendario[r][0] <<": 00    |    " << calendario[r][1]<<"  |    "<< calendario[r][2]<<"  |    " << calendario[r][3]<<"  |    "<< calendario[r][4]<<"  |    "<<calendario[r][5]<<" | \n";
            }
        }
        Consultorio::~Consultorio(){}

class Doctora : public Consultorio{
    private:
        string nombre, usuario, password;
        string especialidad;

    public:
        Doctora();
        Doctora(string _nombre, string _usuario, string _password, string _especialidad);
        string getNombre();
        void verPacientes();
        void verCalendario();
        void modificarPacientes();
        void agendarCita();
        ~Doctora();
};
        Doctora::Doctora(){}
        Doctora::Doctora(string _nombre, string _usuario, string _password, string _especialidad){
            this-> nombre = _nombre;
            this-> usuario = _usuario;
            this-> password = _password;
            this-> especialidad = _especialidad;
        }
        string Doctora::getNombre(){
            return this-> nombre;
        }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void Doctora::verPacientes(){
            ren = 0;
            LeerPacientes.open("DatosDePacientes.txt");
            while(LeerPacientes>>numPaciente>>nombre>>edad>>sexo>>calle>>colonia>>municipio>>telefono>>status) 
            {   
                cout<<"Lista "<<ren <<" copiada \n";
                numeroPaciente[ren][0]= ren+1;;
                listaPacientes[ren][1]= nombre;
                listaPacientes[ren][2]= edad;
                listaPacientes[ren][3]= sexo;
                listaPacientes[ren][4]= calle;
                listaPacientes[ren][5]= colonia;
                listaPacientes[ren][6]= municipio;
                listaPacientes[ren][7]= telefono;
                listaPacientes[ren][8]= status;
                ren++;
            }  LeerPacientes.close();// termina el while
            cout <<"|   Cve de Paciente   |   Nombre   |   Edad   |   Sexo   |   Calle   |   Colonia   |   Municipio   |   Telefono   |   Status   |\n";

            for (int r=0;r<ren;r++){
            cout<< "|   "<<numeroPaciente[r][0] <<"   |   "<< listaPacientes[r][1]<<"   |   "<< listaPacientes[r][2]<<"   |   "<< listaPacientes[r][3]<<"   |   "<< listaPacientes[r][4]<<"   |   "<< listaPacientes[r][5]<<"   |   "<< listaPacientes[r][6]<<"   |   "<< listaPacientes[r][7]<<"   |   "<< listaPacientes[r][8]<<"   |"<<endl;
            } // fin del for de archivo
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void Doctora::verCalendario(){
            ren2 = 0;

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

            cout << "\x1B[2J\x1B[H";    //limpia pantalla

            //Muestra todo el calendario de disponibilidad
            cout<<"|   Calendario   |   Lunes   |   Martes   |   Miercoles   |   Jueves   |   Viernes   | \n";
            for(int r=0;r<ren2;r++){
                cout<<"|   "<< calendario[r][0] <<": 00    |    " << calendario[r][1]<<"  |    "<< calendario[r][2]<<"  |    " << calendario[r][3]<<"  |    "<< calendario[r][4]<<"  |    "<<calendario[r][5]<<" | \n";
            }
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void Doctora::modificarPacientes(){

            ren = 0;
            LeerPacientes.open("DatosDePacientes.txt");
            while(LeerPacientes>>numPaciente>>nombre>>edad>>sexo>>calle>>colonia>>municipio>>telefono>>status) 
            {   
                numeroPaciente[ren][0]= ren+1;
                listaPacientes[ren][1]= nombre;
                listaPacientes[ren][2]= edad;
                listaPacientes[ren][3]= sexo;
                listaPacientes[ren][4]= calle;
                listaPacientes[ren][5]= colonia;
                listaPacientes[ren][6]= municipio;
                listaPacientes[ren][7]= telefono;
                listaPacientes[ren][8]= status;
                ren++;
            }  LeerPacientes.close();// termina el while
        
            cout << "Deme la clave del paciente del que desee modificar algun dato: (1-10): "<<endl;
            cin >> cveModificar;

            while(cveModificar < 0 or cveModificar > 10){
                cout << "Deme la clave del paciente del que desee modificar algun dato (1-10): "<<endl;
                cin >> cveModificar;
            }

            cout<<"1) Nombre\n2) Edad\n3) Sexo\n4) Calle\n5) Colonia\n6) Municipio \n7) Telefono \n8) Status \n Escriba el numero del dato que desee modificar: "<<endl; //Pido Nueva Cantidad para el almacen
            cin>>numDato;
            while(numDato < 0 or numDato > 9){
                cout<<"Por favor escoja un  numero del 1 al 9"<<endl; //Pido Nueva Cantidad para el almacen
                cin>>numDato;
            }

            cout<<"Escriba el nuevo dato: "<<endl;
            cin >> valorNuevo;

                if (cveModificar == numeroPaciente[cveModificar-1][0]){   //Buscar la clave que pidio modificar
                    listaPacientes[cveModificar-1][numDato] = valorNuevo;   //Modificar el producto
                    cout<<"Se encontro la clave del paciente\n";
                }

            //Cambiamos los datos dentro del archivo txt
        CambiarPacientes.open("DatosDePacientes.txt", ios::out); //write
        //for para cambiar datos del archivo de texto
        for (int r=0;r<ren;r++){
            CambiarPacientes<< numeroPaciente[r][0] <<" "<< listaPacientes[r][1]<<" "<< listaPacientes[r][2]<<" "<< listaPacientes[r][3]<<" "<< listaPacientes[r][4]<<" "<< listaPacientes[r][5]<<" "<< listaPacientes[r][6]<<" "<< listaPacientes[r][7]<<" "<< listaPacientes[r][8]<<endl;
        } // fin del for de archivo
        cout<<"El usuario se ha registrado correctamente!" << endl;      
        CambiarPacientes.close();         
        }
/////////////////////////////////////////////////////////////////////////////////////////////////
        void Doctora::agendarCita(){
        ren2 = 0;

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


        cout << "\x1B[2J\x1B[H";    //limpia pantalla
        cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
        cout<<"Que dia desea hacer la cita?: (Escriba el numero del 1 al 5) \n";
        cin >> dia;

        while (dia < 1 or dia > 5){
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
            cout<<"Porfavor, escriba un numero del 1 al 5: \n";
            cin >> dia; 
        }
            if(dia == 1){nombreDia = "Lunes";}
            if(dia == 2){nombreDia = "Martes";}
            if(dia == 3){nombreDia = "Miercoles";}
            if(dia == 4){nombreDia = "Jueves";}
            if(dia == 5){nombreDia = "Viernes";}
            cout<<"Horarios disponibles para el dia " << nombreDia << " : \n";

            cout<<"1) 8:00 AM \n2) 9:00 AM \n3) 10:00 AM \n4) 11:00 AM \n5) 12:00 PM \n6) 1:00 PM \n7) 3:00 PM \n8) 4:00 PM \n";
            cout<<"A que hora desea hacer la cita?: (Escriba el numero del 1 al 8) \n";
            cin >> hora;
            while(hora <1 or hora >8){
                cout<<"Porfavor, escriba un numero entre 1 y 8 \n";
                cin >> hora;
            }
            if(hora == 1){nombreHora = "8:00 AM";}
            if(hora == 2){nombreHora = "9:00 AM";}
            if(hora == 3){nombreHora = "10:00 AM";}
            if(hora == 4){nombreHora = "11:00 AM";}
            if(hora == 5){nombreHora = "12:00 PM";}
            if(hora == 6){nombreHora = "1:00 PM";}
            if(hora == 7){nombreHora = "3:00 PM";}
            if(hora == 8){nombreHora = "4:00 PM";}
            
            while(calendario[hora-1][dia] != "Disponible"){
                cout << "\x1B[2J\x1B[H";    //limpia pantalla
                cout << "El horario escogido esta ocupado\n";
                cout<<"1) 8:00 AM \n2) 9:00 AM \n3) 10:00 AM \n4) 11:00 AM \n5) 12:00 PM \n6) 1:00 PM \n7) 3:00 PM \n8) 4:00 PM \n";
                cout<<"A que hora desea hacer la cita?: (Escriba el numero del 1 al 8) \n";
                cin >> hora;
                    while(hora <1 or hora >8){
                        cout<<"Porfavor, escriba un numero entre 1 y 8 \n";
                        cin >> hora;
                    }
            }
                if(calendario[hora-1][dia] == "Disponible"){
                    cout << "Su cita ha sido agendada para el dia "<< nombreDia <<" a las " << nombreHora <<endl;
                    calendario[hora-1][dia] = "Ocupado";
                    
                } 

            //Muestra todo el calendario de disponibilidad ACTUALIZADO
            CambiarCitas.open("Calendario.txt", ios::out);
            for (int ren4=0;ren4<ren2;ren4++){
                CambiarCitas<< calendario[ren4][0] <<" "<< calendario[ren4][1] <<" "<<calendario[ren4][2]<<" "<<calendario[ren4][3]<<" "<<calendario[ren4][4]<<" "<<calendario[ren4][5]<<endl;
            } // fin del for de archivo
            CambiarCitas.close();
        cout<<"El calendario de ha actualizado correctamente!" << endl;
        }
///////////////////////////////////////////////////////////////////////////////////////////////////

        Doctora::~Doctora(){}
///////////////////////////////////////////////////////////////////////////////////////////////////
class Paciente : public Consultorio{


    public:
        Paciente();
        Paciente(string _nombre, string _edad, string _sexo, string _calle, string _colonia, string _municipio, string _telefono, string _status);
        
        string getNombre();
        void verCalendario();
        void agendarCita();
        void modificarCita();
        void pagarCita(string _nombre);
        ~Paciente();
};
////////////////////////////////////////////////////////////////////////////////////////////////
        Paciente::Paciente(){}
        Paciente::Paciente(string _nombre, string _edad, string _sexo, string _calle, string _colonia, string _municipio, string _telefono, string _status){
        this-> nombre = _nombre;
        this->edad = _edad;
        this->sexo = _sexo;
        this->calle = _calle;
        this->colonia = _colonia;
        this->municipio = _municipio;
        this->telefono = _telefono;
        this->status = _status;

        }
////////////////////////////////////////////////////////////////////////////////////////////////
        string Paciente::getNombre(){
            return this-> nombre;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void Paciente::verCalendario(){
        ren2 = 0;

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

            cout << "\x1B[2J\x1B[H";    //limpia pantalla

            //Muestra todo el calendario de disponibilidad
            cout<<"|   Calendario   |   Lunes   |   Martes   |   Miercoles   |   Jueves   |   Viernes   | \n";
            for(int r=0;r<ren2;r++){
                cout<<"|   "<< calendario[r][0] <<": 00    |    " << calendario[r][1]<<"  |    "<< calendario[r][2]<<"  |    " << calendario[r][3]<<"  |    "<< calendario[r][4]<<"  |    "<<calendario[r][5]<<" | \n";
            }
            
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void Paciente::agendarCita(){
ren2 = 0;

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


        cout << "\x1B[2J\x1B[H";    //limpia pantalla
        cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
        cout<<"Que dia desea hacer la cita?: (Escriba el numero del 1 al 5) \n";
        cin >> dia;

        while (dia < 1 or dia > 5){
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
            cout<<"Porfavor, escriba un numero del 1 al 5: \n";
            cin >> dia; 
        }
            if(dia == 1){nombreDia = "Lunes";}
            if(dia == 2){nombreDia = "Martes";}
            if(dia == 3){nombreDia = "Miercoles";}
            if(dia == 4){nombreDia = "Jueves";}
            if(dia == 5){nombreDia = "Viernes";}
            cout<<"Horarios disponibles para el dia " << nombreDia << " : \n";

            cout<<"1) 8:00 AM \n2) 9:00 AM \n3) 10:00 AM \n4) 11:00 AM \n5) 12:00 PM \n6) 1:00 PM \n7) 3:00 PM \n8) 4:00 PM \n";
            cout<<"A que hora desea hacer la cita?: (Escriba el numero del 1 al 8) \n";
            cin >> hora;
            while(hora <1 or hora >8){
                cout<<"Porfavor, escriba un numero entre 1 y 8 \n";
                cin >> hora;
            }
            if(hora == 1){nombreHora = "8:00 AM";}
            if(hora == 2){nombreHora = "9:00 AM";}
            if(hora == 3){nombreHora = "10:00 AM";}
            if(hora == 4){nombreHora = "11:00 AM";}
            if(hora == 5){nombreHora = "12:00 PM";}
            if(hora == 6){nombreHora = "1:00 PM";}
            if(hora == 7){nombreHora = "3:00 PM";}
            if(hora == 8){nombreHora = "4:00 PM";}
            
            while(calendario[hora-1][dia] != "Disponible"){
                cout << "\x1B[2J\x1B[H";    //limpia pantalla
                cout << "El horario escogido esta ocupado\n";
                cout<<"1) 8:00 AM \n2) 9:00 AM \n3) 10:00 AM \n4) 11:00 AM \n5) 12:00 PM \n6) 1:00 PM \n7) 3:00 PM \n8) 4:00 PM \n";
                cout<<"A que hora desea hacer la cita?: (Escriba el numero del 1 al 8) \n";
                cin >> hora;
                    while(hora <1 or hora >8){
                        cout<<"Porfavor, escriba un numero entre 1 y 8 \n";
                        cin >> hora;
                    }
            }
                if(calendario[hora-1][dia] == "Disponible"){
                    cout << "Su cita ha sido agendada para el dia "<< nombreDia <<" a las " << nombreHora <<endl;
                    calendario[hora-1][dia] = "Ocupado";
                    
                } 

            //Muestra todo el calendario de disponibilidad ACTUALIZADO
            CambiarCitas.open("Calendario.txt", ios::out);
            for (int ren4=0;ren4<ren2;ren4++){
                CambiarCitas<< calendario[ren4][0] <<" "<< calendario[ren4][1] <<" "<<calendario[ren4][2]<<" "<<calendario[ren4][3]<<" "<<calendario[ren4][4]<<" "<<calendario[ren4][5]<<endl;
            } // fin del for de archivo
            CambiarCitas.close();
        cout<<"El calendario de ha actualizado correctamente!" << endl;
            }
/////////////////////////////////////////////////////////////////////////////////////////////
        void Paciente::modificarCita(){
                    ren2 = 0;

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

        cout << "\x1B[2J\x1B[H";    //limpia pantalla
        cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
        cout<<"Que dia desea hacer la cita?: (Escriba el numero del 1 al 5) \n";
        cin >> dia;

        while (dia < 1 or dia > 5){
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            cout<<"1) Lunes \n2) Martes \n3) Miercoles \n4) Jueves \n5) Viernes\n";
            cout<<"Porfavor, escriba un numero del 1 al 5: \n";
            cin >> dia; 
        }
            if(dia == 1){nombreDia = "Lunes";}
            if(dia == 2){nombreDia = "Martes";}
            if(dia == 3){nombreDia = "Miercoles";}
            if(dia == 4){nombreDia = "Jueves";}
            if(dia == 5){nombreDia = "Viernes";}
            cout<<"Horarios disponibles para el dia " << nombreDia << " : \n";

            cout<<"1) 8:00 AM \n2) 9:00 AM \n3) 10:00 AM \n4) 11:00 AM \n5) 12:00 PM \n6) 1:00 PM \n7) 3:00 PM \n8) 4:00 PM \n";
            cout<<"A que hora desea hacer la cita?: (Escriba el numero del 1 al 8) \n";
            cin >> hora;
            while(hora <1 or hora >8){
                cout<<"Porfavor, escriba un numero entre 1 y 8 \n";
                cin >> hora;
            }
            if(hora == 1){nombreHora = "8:00 AM";}
            if(hora == 2){nombreHora = "9:00 AM";}
            if(hora == 3){nombreHora = "10:00 AM";}
            if(hora == 4){nombreHora = "11:00 AM";}
            if(hora == 5){nombreHora = "12:00 PM";}
            if(hora == 6){nombreHora = "1:00 PM";}
            if(hora == 7){nombreHora = "3:00 PM";}
            if(hora == 8){nombreHora = "4:00 PM";}
            
            if(calendario[hora-1][dia-1] == "Disponible"){
                cout << "Su cita ha sido agendada para el dia "<< nombreDia <<" a las " << nombreHora <<endl;
                calendario[hora-1][dia-1] = "Ocupado";
                cout <<calendario[hora-1][dia-1] <<endl;
            }

            //Muestra todo el calendario de disponibilidad ACTUALIZADO
            CambiarCitas.open("Calendario.txt", ios::out);
            for (int ren4=0;ren4<ren2;ren4++){
                CambiarCitas<< calendario[ren4][0] <<" "<< calendario[ren4][1] <<" "<<calendario[ren4][2]<<" "<<calendario[ren4][3]<<" "<<calendario[ren4][4]<<" "<<calendario[ren4][5]<<endl;
            } // fin del for de archivo
            CambiarCitas.close();
        cout<<"El calendario de ha actualizado correctamente!" << endl;
        }
/////////////////////////////////////////////////////////////////////////////////////////////

        void Paciente::pagarCita(string _nombre){
            cout << "\x1B[2J\x1B[H";    //limpia pantalla
            int opcion = 0;
            cout<<"Es su primera vez en el consultorio?:\n 1) Si \n2) No \n";
            cin >> opcion;
            while(opcion != 1 && opcion != 2){
                cout<<"Porfavor escoga un numero entre 1 y 2 solamente: \n";
                cin >> opcion;
            }

            if(opcion == 1){
                cout <<"Felicidades! Por ser su primera vez, su consulta es gratis! \n";
            }
            if(opcion == 2){

                    cout << "========= Ticket de Cobro ========= \n";
                    cout << "========= Cliente: "<< _nombre<<endl;
                    cout << "========= Doctor : Olivia "<< endl;
                    cout << "========= Precio: "<< " $500 pesos MXN " << endl;
                    cout << "========= Gracias por su visita! == \n";
            }

        }
        Paciente::~Paciente(){}