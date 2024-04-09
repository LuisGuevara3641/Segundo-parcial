#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <sstream>

using namespace std;

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

class persona 
{
    private:
    string nombre, apellido, ocupacion;
    int edad;
    
    public:
    persona(string nombre1, string apellido1, string ocupacion1, int edad1)
    {
        nombre = nombre1;
        apellido = apellido1;
        ocupacion = ocupacion1;
        edad = edad1;
    }
    void mostrarInfo()
    {
        cout << "_________________________________"
            << "\nNombre: " << nombre << "\nApellido: " << apellido << "\nOcupacion: " << ocupacion << "\nEdad: " << edad << "\n_________________________________" << endl;
    }
    const string& getNombre() const { return nombre; } // Se hace esto para poder acceder a esta información
    const string& getApellido() const { return apellido; }
    const string& getOcupacion() const { return ocupacion; }
    const int& getEdad() const { return edad; }
};

class estudiante : public persona // Hereda de la clase persona
{
private:
    string numeroCarnet;
    double promedioCalificaciones;

public:
    estudiante(string nombre1, string apellido1, int edad1, string carnet, double promedio)
        : persona(nombre1, apellido1, "", edad1), numeroCarnet(carnet), promedioCalificaciones(promedio) {}

    void mostrarInfo() const
    {
        cout << "_________________________________" 
            << "\nNombre: " << getNombre() 
            << "\nApellido: " << getApellido() 
            << "\nEdad: " << getEdad()
            << "\nCarnet: " << numeroCarnet 
            << "\nPromedio: " << promedioCalificaciones 
            << "\n_________________________________" << endl;
    }

    const string& getNumeroCarnet() const { return numeroCarnet; }
    const double& getPromedioCalificaciones() const { return promedioCalificaciones; }
};

vector<estudiante> listaEstudiantes; // Se inicializan estos vectores que son como listas, para manejar de mejor manera los datos.
vector<persona> listaPersonas;
void crearPersona(const string& nombreArchivo);
void crearEstudiante(const string& nombreArchivo);
string crearArchivo();
void guardarPersonaEnArchivo(const persona& p, const string& nombreArchivo);
void guardarEstudianteEnArchivo(const estudiante& e, const string& nombreArchivo);
void leerDatosDesdeArchivo(const string& nombreArchivo);
void leerArchivo(const string& nombreArchivo);
void ordenarEstudiantes();
void ordenarPersonas();
bool archivoExiste(const string& nombreArchivo);

int main()
{
    string nombreArchivo = crearArchivo();
    leerDatosDesdeArchivo(nombreArchivo); // Se leen los datos, ya que cuando se abre por segunda vez el archivo se pierde la info en memoria.
    system("cls");
    int opc;
    do
    {
        gotoxy(45, 1);
        cout << "MENU PRINCIPAL" << endl;
        cout << "1- Crear archivo.txt y trabajar con el apartir de ahora" << endl;
        cout << "2- Crear persona." << endl;
        cout << "3- Crear estudiante." << endl;
        cout << "4- Leer archivo.txt." << endl;
        cout << "5- Ordenar personas." << endl;
        cout << "6- Ordenar estudiantes." << endl;
        cout << "7- Salir del menu." << endl;
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
        {
            system("cls");
            nombreArchivo = crearArchivo();

            system("pause");
            cout << endl;
            break;
        }

        case 2:
		{
            system("cls");
            if (archivoExiste(nombreArchivo)) {
                crearPersona(nombreArchivo);
            } else {
                cout << "No se encontró el archivo '" << nombreArchivo << "'. Debe crear uno primero." << endl;
            }
            system("pause");
            cout << endl;
            break;
		}

        case 3:
		{
            system("cls");
            if (archivoExiste(nombreArchivo)) {
                crearEstudiante(nombreArchivo);
            } else {
                cout << "No se encontró el archivo '" << nombreArchivo << "'. Debe crear uno primero." << endl;
            }
            system("pause");
            cout << endl;
            break;
		}

        case 4:
		{
            system("cls");
            if (archivoExiste(nombreArchivo)) {
                leerArchivo(nombreArchivo);
            } else {
                cout << "No se encontró el archivo '" << nombreArchivo << "'. Debe crear uno primero." << endl;
            }
            system("pause");
            cout << endl;
            break;
		}

        case 5:
		{
            system("cls");
            ordenarPersonas();
            cout << "Personas ordenadas por nombre:" << endl;
            for (size_t i = 0; i < listaPersonas.size(); i++) {
                listaPersonas[i].mostrarInfo();
            }
            system("pause");
            cout << endl;
            break;
		}

        case 6:
		{
            system("cls");
            ordenarEstudiantes();
            cout << "Estudiantes ordenados por nombre:" << endl;
            for (size_t i = 0; i < listaEstudiantes.size(); i++) {
                listaEstudiantes[i].mostrarInfo();
            }
            system("pause");
            cout << endl;
            break;
		}
    
        default:
			break;
		}
        system("cls");
	} while (opc != 7);

    cout << "Fuera del programa";
    system("pause");
    return 0;
}
/************************************************************crearArchivo()***************************************************************************/
string crearArchivo() {
    string nombreArchivo;
    do {
        system("cls");
        gotoxy(45, 1);
        cout << "Crear archivo txt:" << endl << endl;
        cout << "Ingrese el nombre del archivo (sin .txt): ";
        getline(cin, nombreArchivo); // Leer toda la línea, permitiendo espacios
        nombreArchivo += ".txt";

        if (archivoExiste(nombreArchivo)) {
            cout << "El archivo '" << nombreArchivo << "' ya existe. Desea utilizarlo? (s/n): ";
            char respuesta;
            cin >> respuesta;
            cin.ignore(); // Ignorar el salto de línea

            if (respuesta == 's' || respuesta == 'S') {
                // Limpiar las listas de personas y estudiantes antes de leer el archivo, así se evita la mezcla de información entre archivos
                listaPersonas.clear();
                listaEstudiantes.clear();
                leerDatosDesdeArchivo(nombreArchivo);
                return nombreArchivo;
            } else {
                continue;
            }
        } else {
            ofstream archivo(nombreArchivo.c_str());
            if (archivo.is_open()) {
                cout << "Archivo '" << nombreArchivo << "' creado exitosamente." << endl;
                archivo.close();
                return nombreArchivo;
            } else {
                cout << "No se pudo crear el archivo '" << nombreArchivo << "'." << endl;
            }
        }
    } while (true);
}
/************************************************************crearPersona()***************************************************************************/
void crearPersona(const string& nombreArchivo){
    string nombre, apellido, ocupacion;
    int edad;
    gotoxy(45,1);
    cout << "Ingresar Persona:" << endl << endl;

    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;

    cout << "Ingrese el apellido de la persona: ";
    cin >> apellido;

    cout << "Ingrese la ocupacion de la persona: ";
    cin >> ocupacion;

    cout << "Ingrese la edad de la persona: ";
    cin >> edad;

    persona persona1(nombre, apellido, ocupacion, edad); // Se instancia con los datos ingresados por el usuario
    listaPersonas.push_back(persona1); // Se guarda en memoria
    guardarPersonaEnArchivo(persona1, nombreArchivo); // Se guarda en .txt
}

/************************************************************guardarPersonaArchivo()******************************************************************/
void guardarPersonaEnArchivo(const persona& p, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << p.getNombre() << endl;
        archivo << "Apellido: " << p.getApellido() << endl;
        archivo << "Ocupacion: " << p.getOcupacion() << endl;
        archivo << "Edad: " << p.getEdad() << endl;
        archivo << "-------------------" << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
/************************************************************leerArchivo()***************************************************************************/
void leerArchivo(const string& nombreArchivo) {
    gotoxy(45,1);
    cout << "Informacion del documento:" << endl << endl;
    ifstream archivo(nombreArchivo.c_str());
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
/************************************************************comprobacionArchivo()*********************************************************************/
bool archivoExiste(const string& nombreArchivo) { // Verifica si el archivo existe
    ifstream archivo(nombreArchivo.c_str());
    bool existe = archivo.good();
    archivo.close();
    return existe;
}
/************************************************************crearEstudiante()*************************************************************************/
void crearEstudiante(const string& nombreArchivo){
    string nombre, apellido, carnet;
    int edad;
    float promedio;
    gotoxy(45,1);
    cout << "Ingresar Estudiante:" << endl << endl;

    cout << "Ingrese el nombre del Estudiante: ";
    cin >> nombre;

    cout << "Ingrese el apellido del Estudiante: ";
    cin >> apellido;

    cout << "Ingrese la edad del Estudiante: ";
    cin >> edad;

    cout << "Ingrese el carnet del Estudiante: ";
    cin >> carnet;

    cout << "Ingrese el promedio del Estudiante: ";
    cin >> promedio;

    estudiante estudiante1(nombre, apellido, edad, carnet, promedio); // Se instancia con los datos ingresados por el usuario
    listaEstudiantes.push_back(estudiante1); // Se guarda en memoria
    guardarEstudianteEnArchivo(estudiante1, nombreArchivo); // Se guarda en .txt
}
/**********************************************************guardarEstudianteArchivo()******************************************************************/
void guardarEstudianteEnArchivo(const estudiante& e, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << e.getNombre() << endl;
        archivo << "Apellido: " << e.getApellido() << endl;
        archivo << "Edad: " << e.getEdad() << endl;
        archivo << "Carnet: " << e.getNumeroCarnet() << endl;
        archivo << "Promedio: " << e.getPromedioCalificaciones() << endl;
        archivo << "-------------------" << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
/**********************************************************ordenarEstudiantes()******************************************************************/
void ordenarEstudiantes() { // Los ordena por su nombre
    gotoxy(45,1);
    cout << "Estudiantes ordenados:" << endl << endl;
    int n = listaEstudiantes.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (listaEstudiantes[j].getNombre() > listaEstudiantes[j + 1].getNombre()) {
                swap(listaEstudiantes[j], listaEstudiantes[j + 1]);
            }
        }
    }
}
/**********************************************************ordenarPersonas()******************************************************************/
void ordenarPersonas() { // los ordena por su nombre
    gotoxy(45,1);
    cout << "Personas ordenadas:" << endl << endl;
    int n = listaPersonas.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (listaPersonas[j].getNombre() > listaPersonas[j + 1].getNombre()) {
                swap(listaPersonas[j], listaPersonas[j + 1]);
            }
        }
    }
}
/**********************************************************leerDatosDesdeArchivo()******************************************************************/
void leerDatosDesdeArchivo(const string& nombreArchivo) { //Vuelve a leer los datos del .txt para tenerlos en memoria
    listaEstudiantes.clear();
    listaPersonas.clear();

    ifstream archivo(nombreArchivo.c_str());
    if (archivo.is_open()) {
        string linea;
        bool esEstudiante = false;
        string nombre, apellido, ocupacion, carnet;
        int edad;
        double promedio;

        while (getline(archivo, linea)) {
            if (linea.find("Nombre: ") != string::npos) {
                nombre = linea.substr(8);
            } else if (linea.find("Apellido: ") != string::npos) {
                apellido = linea.substr(10);
            } else if (linea.find("Ocupacion: ") != string::npos) {
                ocupacion = linea.substr(11);
            } else if (linea.find("Edad: ") != string::npos) {
                istringstream(linea.substr(6)) >> edad;
            } else if (linea.find("Carnet: ") != string::npos) {
                carnet = linea.substr(8);
                esEstudiante = true;
            } else if (linea.find("Promedio: ") != string::npos) {
                istringstream(linea.substr(10)) >> promedio;
                estudiante e(nombre, apellido, edad, carnet, promedio);
                listaEstudiantes.push_back(e);
                esEstudiante = false;
            } else if (linea.find("-------------------") != string::npos) {
                if (!esEstudiante) {
                    persona p(nombre, apellido, ocupacion, edad);
                    listaPersonas.push_back(p);
                }
            }
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
