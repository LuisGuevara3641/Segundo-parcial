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

class empleado 
{
    private:
    string nombre, apellido;
    int edad;
    double salario;
    public:
    empleado(string nombre1, string apellido1, int edad1, double salario1)
    {
        nombre = nombre1;
        apellido = apellido1;
        edad = edad1;
        salario = salario1;
    }
    void mostrarInfo()
    {
        cout << "_________________________________"
            << "\nNombre: " << nombre << "\nApellido: " << apellido << "\nEdad: " << edad << "\nSalario: Q" << salario << "\n_________________________________" << endl;
    }
    const string& getNombre() const { return nombre; } // Se hace esto para poder acceder a esta información
    const string& getApellido() const { return apellido; }
    const int& getEdad() const { return edad; }
    const double& getSalario() const { return salario; }
    
};
vector<empleado> listaEmpleados;// Se inicializan estos vectores que son como listas, para manejar de mejor manera los datos.
void crearEmpleado(const string& nombreArchivo);
string crearArchivo();
void guardarEmpleadoEnArchivo(const empleado& p, const string& nombreArchivo);
void leerArchivo(const string& nombreArchivo);
void ordenarEmpleados();
bool archivoExiste(const string& nombreArchivo);
void eliminarArchivo(const string& nombreArchivo);
void escribirEnArchivo(const string& nombreArchivo, const string& texto);
int main()
{
    string nombreArchivo = crearArchivo();
    system("cls");
    int opc;
    do
    {
        gotoxy(45, 1);
        cout << "MENU PRINCIPAL" << endl;
        cout << "1- Crear archivo.txt y trabajar con el apartir de ahora" << endl;
        cout << "2- Crear empleado." << endl;
        cout << "3- Leer archivo.txt." << endl;
        cout << "4- Ordenar empleados." << endl;
        cout << "5- Eliminar el archivo.txt." << endl;
        cout << "6- Escribir texto en el archivo.txt." << endl;
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
                crearEmpleado(nombreArchivo);
            } else {
                cout << "No se encontro el archivo '" << nombreArchivo << "'. Debe crear uno primero." << endl;
            }
            system("pause");
            cout << endl;
            break;
		}

        case 3:
		{
            system("cls");
            if (archivoExiste(nombreArchivo)) {
                leerArchivo(nombreArchivo);
            } else {
                cout << "No se encontro el archivo '" << nombreArchivo << "'. Debe crear uno primero." << endl;
            }
            system("pause");
            cout << endl;
            break;
		}

        case 4:
		{
            system("cls");
            ordenarEmpleados();
            cout << "Empleados ordenadas por nombre:" << endl;
            for (size_t i = 0; i < listaEmpleados.size(); i++) {
                listaEmpleados[i].mostrarInfo();
            }
            system("pause");
            cout << endl;
            break;
		}

        case 5:
        {
            system("cls");
            if (archivoExiste(nombreArchivo)) {
                eliminarArchivo(nombreArchivo);
            } else {
                cout << "No se encontro el archivo '" << nombreArchivo << "'. Debe crear uno primero." << endl;
            }
            system("pause");
            cout << endl;
            break;
        }

        case 6:
        {
            system("cls");
            if (archivoExiste(nombreArchivo)) {
                string texto;
                cout << "Ingrese el texto que desea escribir en el archivo: ";
                getline(cin, texto);
                escribirEnArchivo(nombreArchivo, texto);
            } else {
                cout << "No se encontro el archivo '" << nombreArchivo << "'. Debe crear uno primero." << endl;
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

    cout << "Fuera del programa" << endl;
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
                // Limpiar las listas de empleados antes de leer el archivo, así se evita la mezcla de información entre archivos
                listaEmpleados.clear();
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
/************************************************************crearEmpleado()***************************************************************************/
void crearEmpleado(const string& nombreArchivo){
    string nombre, apellido;
    int edad;
    double salario;
    gotoxy(45,1);
    cout << "Ingresar Empleado:" << endl << endl;

    cout << "Ingrese el nombre del empleado: ";
    cin >> nombre;

    cout << "Ingrese el apellido de la empleado: ";
    cin >> apellido;

    cout << "Ingrese la edad de la empleado: ";
    cin >> edad;

    cout << "Ingrese el sueldo del empleado: Q";
    cin >> salario;

    empleado empleado1(nombre, apellido, edad, salario); // Se instancia con los datos ingresados por el usuario
    listaEmpleados.push_back(empleado1); // Se guarda en memoria
    guardarEmpleadoEnArchivo(empleado1, nombreArchivo); // Se guarda en .txt
}

/************************************************************guardarEmpleadoArchivo()******************************************************************/
void guardarEmpleadoEnArchivo(const empleado& p, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << "Nombre: " << p.getNombre() << endl;
        archivo << "Apellido: " << p.getApellido() << endl;
        archivo << "Edad: " << p.getEdad() << endl;
        archivo << "Salario: " << p.getSalario() << endl;
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
/**********************************************************ordenarEmpleados()******************************************************************/
void ordenarEmpleados() { // los ordena por su nombre
    gotoxy(45,1);
    cout << "Empleados ordenadas:" << endl << endl;
    int n = listaEmpleados.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (listaEmpleados[j].getNombre() > listaEmpleados[j + 1].getNombre()) {
                swap(listaEmpleados[j], listaEmpleados[j + 1]);
            }
        }
    }
}
/**********************************************************eliminarArchivo()******************************************************************/
void eliminarArchivo(const string& nombreArchivo) {
    gotoxy(45, 1);
    cout << "Eliminando archivo..." << endl << endl;

    if (remove(nombreArchivo.c_str()) == 0) {
        cout << "Archivo '" << nombreArchivo << "' eliminado exitosamente." << endl;
        // Limpiar las listas de empleados después de eliminar el archivo
        listaEmpleados.clear();
    } else {
        cout << "No se pudo eliminar el archivo '" << nombreArchivo << "'." << endl;
    }
}
/**********************************************************escribirEnArchivo()******************************************************************/
void escribirEnArchivo(const string& nombreArchivo, const string& texto) {
    ofstream archivo(nombreArchivo.c_str(), ios::app);
    if (archivo.is_open()) {
        archivo << texto << endl;
        archivo.close();
        cout << "Texto escrito en el archivo exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
