#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;

// TDA para usuario: paciente
struct paciente
{
    string nombres;
    string apellidos;
    string cedula;
    string fechaNacimiento;
    string genero;
    string telefono;
};

// TDA para cita
struct cita
{
    string cedPaciente;
    string nombrePaciente;
    string apellidoPaciente;
    string fecha;
    string hora;
    string especialidad;
    string nombreMedico;
    string estadoCita;
};

// funciones principales
void cargarArchivoCitas(cita archivoCita[]){

    //abrir y validar archivo
    ifstream archivoCitas("citas.txt");
    if (!archivoCitas.is_open()){
        cout << "AVISO DE SISTEMA: Error al cargar los datos" << endl;
        return;
    } else {
        cout<< "AVISO DE SISTEMA: Archivo abierto correctamente"<<endl;
    }

    //leer datos guardados a un array
    string linea;
    int pos = 0;
    while (getline(archivoCitas, linea)){
        stringstream ss(linea);
        getline(ss, archivoCita[pos].cedPaciente, '|');
        getline(ss, archivoCita[pos].nombrePaciente, '|');
        getline(ss, archivoCita[pos].apellidoPaciente, '|');
        getline(ss, archivoCita[pos].fecha, '|');
        getline(ss, archivoCita[pos].hora, '|');
        getline(ss, archivoCita[pos].especialidad, '|');
        getline(ss, archivoCita[pos].nombreMedico, '|');
        getline (ss, archivoCita[pos].estadoCita,'|');

        cout<< "Cita " << pos + 1 << ": "
             << archivoCita[pos].cedPaciente << ", "
             << archivoCita[pos].nombrePaciente << ", "
             << archivoCita[pos].apellidoPaciente << ", "
             << archivoCita[pos].fecha << ", "
             << archivoCita[pos].hora << ", "
             << archivoCita[pos].especialidad << ", "
             << archivoCita[pos].nombreMedico << ", "
             << archivoCita[pos].estadoCita << endl;
        pos++;
    }
}

void actualizarArchivoCitas (cita archivoCitas[]){

}

void validarUsuario()
{
}

void agendarCita(){

}

// funciones auxiliares
void buscarUsuario(string cedula){
}

int contarLineasArchivo(string nombreArchivo){
    int nLineas = 0;
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){
        cout << "AVISO DE SISTEMA: Error al abrir el archivo" << endl;
        return 0;
    }
    string linea;
    while (getline(archivo, linea)){
        nLineas++;
    }
    archivo.close();
    return nLineas;
}

// metodo principal
int main(){
    cita *archivoCita = new cita[contarLineasArchivo("citas.txt")];
    cargarArchivoCitas(archivoCita);
    getch();
    return 0;
}