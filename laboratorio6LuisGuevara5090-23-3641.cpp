#include <iostream>
#include <windows.h>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
/****************************************************Clase Biblioteca************************************************************************/
class biblioteca
{
private:
    string titulo, autor, genero;
    int anio_publicacion;
    float precio_prestamo;

public:
    biblioteca(string tituloLibro, string autorLibro, string generoLibro, int anioPublicacion, float precioPrestamo)
    {
        titulo = tituloLibro;
        autor = autorLibro;
        genero = generoLibro;
        anio_publicacion = anioPublicacion;
        precio_prestamo = precioPrestamo;
    }
    void mostrarInfo()
    {
        cout << "_________________________________"
            << "\nTitulo: " << titulo << "\nAutor: " << autor << "\nGenero: " << genero << "\nAnio de publicacion: " << anio_publicacion << "\nPrecio prestamo: Q" << precio_prestamo << "\n_________________________________" << endl;
    }
};
/****************************************************Clase Estudiante************************************************************************/
class estudiante
{
private:
    string nombre, apellido, carrera;
    int edad, carnet;

public:
    estudiante(string nombreEstudiante, string apellidoEstudiante, string carreraEstudiante, int edadEstudiante, float carnetEstudiante)
    {
        nombre = nombreEstudiante;
        apellido = apellidoEstudiante;
        carrera = carreraEstudiante;
        edad = edadEstudiante;
        carnet = carnetEstudiante;
    }
    void mostrarInfo()
    {
        cout << "_________________________________"
            << "\nNombre: " << nombre << "\nApellido: " << apellido << "\nCarrera: " << carrera << "\nEdad: " << edad << "\nCarnet: " << carnet << "\n_________________________________" << endl;
    }
};
/****************************************************Clase Calculadora************************************************************************/
class calculadora
{
private:
    float num1, num2;

public:
    calculadora(float numero1, float numero2)
    {
        num1 = numero1;
        num2 = numero2;
    }
    void suma()
    {
        float resultado = num1 + num2;
        cout << "La suma de " << num1 << " y " << num2 << " es: " << resultado << endl;
    }
    void resta()
    {
        float resultado = num1 - num2;
        cout << "La resta de " << num1 << " y " << num2 << " es: " << resultado << endl;
    }
    void multiplicacion()
    {
        float resultado = num1 * num2;
        cout << "La multiplicacion de " << num1 << " y " << num2 << " es: " << resultado << endl;
    }
    void division()
    {
        if (num2 != 0)
        {
            float resultado = num1 / num2;
            cout << "La division de " << num1 << " entre " << num2 << " es: " << resultado << endl;
        }
        else
        {
            cout << "Error: No se puede dividir por cero." << endl;
        }
    }
};
/****************************************************Clase GestionCuentaBancaria************************************************************************/
class gestioncuentabancaria
{
private:
    string nombre;
    int numeroCuenta;
    float saldo;

public:
    gestioncuentabancaria(string nombreBanco, int numeroCuentaBanco, int saldoBanco)
    {
        nombre = nombreBanco;
        numeroCuenta = numeroCuentaBanco;
        saldo = saldoBanco;
    }
    void deposito()
    {
        float cantidadDepositar;

        cout << "Ingrese la cantidad a depositar: ";
        cin >> cantidadDepositar;

        saldo = saldo + cantidadDepositar;

        cout << "Deposito hecho con exito, el saldo actual es de: " << saldo;
    }
    void retiro()
    {
        float cantidadRetirar;

        cout << "Ingrese la cantidad a retirar: ";
        cin >> cantidadRetirar;

        if (cantidadRetirar <= saldo)
        {
            saldo = saldo - cantidadRetirar;
            cout << "Retiro hecho con exito, el saldo acutal es de: " << saldo;
        }
        else
        {
            cout << "No tiene suficiente dinero en la cuenta";
        }
    }
    void consultaSaldo()
    {
        cout << "El saldo en esta cuenta  bancaria es de: " << saldo;
    }
};
/****************************************************Clase Pelicula************************************************************************/
class pelicula
{
private:
    string titulo, director, genero;
    int anioPublicacion;

public:
    pelicula(string tituloPelicula, string directorPelicula, string generoPelicula, int anioPublicacionPelicula)
    {
        titulo = tituloPelicula;
        director = directorPelicula;
        genero = generoPelicula;
        anioPublicacion = anioPublicacionPelicula;
    }
    void mostrarInfo()
    {
        cout << "_________________________________"
            << "\nTitulo: " << titulo << "\nDirector: " << director << "\nGenero: " << genero << "\nAnio Publicacion: " << anioPublicacion << "\n_________________________________" << endl;
    }
};

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void bibliotecainfo();
void estudianteinfo();
void peliculainfo();
/****************************************************Int main()************************************************************************/
int main()
{
    int opc;
    srand(time(NULL));

    do
    {
        gotoxy(45, 1);
        cout << "MENU PRINCIPAL" << endl;
        cout << "1- Biblioteca." << endl;
        cout << "2- Estudiante." << endl;
        cout << "3- Calculadora." << endl;
        cout << "4- Gestion de cuenta bancaria." << endl;
        cout << "5- Pelicula." << endl;
        cout << "6- Salir del menu." << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1: // Biblioteca
        {
            system("cls");

            bibliotecainfo();

            system("pause");
            cout << endl;
            break;
        }

        case 2: // Estudiante
        {
            system("cls");

            estudianteinfo();

            system("pause");
            cout << endl;
            break;
        }

        case 3: // Calculadora
        {
            do
            {
                system("cls");
                gotoxy(45, 1);
                cout << "Calculadora" << endl;
                cout << "1- Suma." << endl;
                cout << "2- Resta." << endl;
                cout << "3- Multiplicacion." << endl;
                cout << "4- Division." << endl;
                cout << "5- Salir del menu." << endl;
                cout << "Opcion: ";
                cin >> opc;

                switch (opc)
                {
                case 1:
                {
                    char continuar;

                    do
                    {
                        system("cls");
                        int num1, num2;

                        cout << "Ingrese su primer numero: ";
                        cin >> num1;

                        cout << "Ingrese su segundo numero: ";
                        cin >> num2;

                        calculadora operacion1(num1, num2);
                        operacion1.suma();
                        cout << endl;

                        cout << "Desea ejecutarlo nuevamente? (s/n): ";
                        cin >> continuar;

                    } while (continuar == 's' || continuar == 'S');

                    system("pause");
                    cout << endl;
                    break;
                }

                case 2:
                {
                    char continuar;

                    do
                    {
                        system("cls");
                        int num1, num2;

                        cout << "Ingrese su primer numero: ";
                        cin >> num1;

                        cout << "Ingrese su segundo numero: ";
                        cin >> num2;

                        calculadora operacion2(num1, num2);
                        operacion2.resta();
                        cout << endl;

                        cout << "Desea ejecutarlo nuevamente? (s/n): ";
                        cin >> continuar;

                    } while (continuar == 's' || continuar == 'S');

                    system("pause");
                    cout << endl;
                    break;
                }

                case 3:
                {
                    char continuar;

                    do
                    {
                        system("cls");
                        int num1, num2;

                        cout << "Ingrese su primer numero: ";
                        cin >> num1;

                        cout << "Ingrese su segundo numero: ";
                        cin >> num2;

                        calculadora operacion3(num1, num2);
                        operacion3.multiplicacion();
                        cout << endl;

                        cout << "Desea ejecutarlo nuevamente? (s/n): ";
                        cin >> continuar;
                    } while (continuar == 's' || continuar == 'S');

                    system("pause");
                    cout << endl;
                    break;
                }

                case 4:
                {
                    char continuar;

                    do
                    {
                        system("cls");
                        int num1, num2;

                        cout << "Ingrese su primer numero: ";
                        cin >> num1;

                        cout << "Ingrese su segundo numero: ";
                        cin >> num2;

                        calculadora operacion1(num1, num2);
                        operacion1.division();
                        cout << endl;

                        cout << "Desea ejecutarlo nuevamente? (s/n): ";
                        cin >> continuar;

                    } while (continuar == 's' || continuar == 'S');

                    system("pause");
                    cout << endl;
                    break;
                }

                default:
                    break;
                }
                system("cls");
            } while (opc != 5);

            system("pause");
            cout << endl;
            break;
        }

        case 4: // Gestion cuenta bancaria
        {
            system("cls");
            string nombreCompleto;
            int numeroCuenta;
            float saldo;
            cout << "Ingrese su nombre: ";
            cin >> nombreCompleto;
            cout << "Ingrese el numero de cuenta: ";
            cin >> numeroCuenta;
            cout << "Ingrese el saldo inicial: Q";
            cin >> saldo;

            gestioncuentabancaria cuenta1(nombreCompleto, numeroCuenta, saldo);
            do
            {
                system("cls");
                gotoxy(45, 1);
                cout << "Cuenta Bancaria" << endl;
                cout << "1- Ver saldo." << endl;
                cout << "2- Depositar." << endl;
                cout << "3- Retirar." << endl;
                cout << "4- Salir del menu." << endl;
                cout << "Opcion: ";
                cin >> opc;

                switch (opc)
                {
                case 1:
                {
                    char continuar;

                    do
                    {
                        system("cls");

                        cuenta1.consultaSaldo();
                        cout << endl << endl;

                        cout << "Desea ejecutarlo nuevamente? (s/n): ";
                        cin >> continuar;

                    } while (continuar == 's' || continuar == 'S');

                    system("pause");
                    cout << endl;
                    break;
                }

                case 2:
                {
                    char continuar;

                    do
                    {
                        system("cls");

                        cuenta1.deposito();
                        cout << endl << endl;

                        cout << "Desea ejecutarlo nuevamente? (s/n): ";
                        cin >> continuar;

                    } while (continuar == 's' || continuar == 'S');

                    system("pause");
                    cout << endl;
                    break;
                }

                case 3:
                {
                    char continuar;

                    do
                    {
                        system("cls");

                        cuenta1.retiro();
                        cout << endl << endl;

                        cout << "Desea ejecutarlo nuevamente? (s/n): ";
                        cin >> continuar;
                    } while (continuar == 's' || continuar == 'S');

                    system("pause");
                    cout << endl;
                    break;
                }

                default:
                    break;
                }
                system("cls");
            } while (opc != 4);

            system("pause");
            cout << endl;
            break;
        }

        case 5: // Peliculas
        {
            system("cls");
            
            peliculainfo();

            system("pause");
            cout << endl;
            break;
        }

        default:
            break;
        }
        system("cls");
    } while (opc != 6);

    cout << "Fuera del programa";
    return 0;
}

/****************************************************void bibliotecainfo()************************************************************************/

void bibliotecainfo()
{
    biblioteca libro1("Cien anios de soledad", "Gabriel Garcia Marquez", "Ficcion", 1967, 15.99);
    biblioteca libro2("1984", "George Orwell", "Distopia", 1949, 12.5);
    biblioteca libro3("Orgullo y prejuicio", "Jane Austen", "Romance", 1813, 18.75);
    biblioteca libro4("To Kill a Mockingbird", "Harper Lee", "Novela", 1960, 20.3);
    biblioteca libro5("The Great Gatsby", "F. Scott Fitzgerald", "Ficcion", 1925, 22.8);

    gotoxy(45, 1);
    cout << "Biblioteca" << endl;

    libro1.mostrarInfo();
    libro2.mostrarInfo();
    libro3.mostrarInfo();
    libro4.mostrarInfo();
    libro5.mostrarInfo();
}

/****************************************************void estudiantecainfo()************************************************************************/

void estudianteinfo()
{
    estudiante estudiante1("Juan", "Perez", "Ingenieria", 20, 12345);
    estudiante estudiante2("Maria", "Gonzalez", "Medicina", 22, 23456);
    estudiante estudiante3("Carlos", "Lopez", "Arquitectura", 21, 34567);
    estudiante estudiante4("Ana", "Martinez", "Economia", 23, 45678);
    estudiante estudiante5("Pedro", "Ramirez", "Derecho", 22, 56789);

    gotoxy(45, 1);
    cout << "Estudiantes" << endl;

    estudiante1.mostrarInfo();
    estudiante2.mostrarInfo();
    estudiante3.mostrarInfo();
    estudiante4.mostrarInfo();
    estudiante5.mostrarInfo();
}

/****************************************************void peliculainfo()************************************************************************/

void peliculainfo()
{
    pelicula pelicula1("Titanic", "James Cameron", "Romance/Drama", 1997);
    pelicula pelicula2("The Shawshank Redemption", "Frank Darabont", "Drama", 1994);
    pelicula pelicula3("Inception", "Christopher Nolan", "Sci-Fi/Action", 2010);
    pelicula pelicula4("The Godfather", "Francis Ford Coppola", "Crime/Drama", 1972);
    pelicula pelicula5("The Dark Knight", "Christopher Nolan", "Action/Crime", 2008);

    gotoxy(45, 1);
    cout << "Peliculas" << endl;

    pelicula1.mostrarInfo();
    pelicula2.mostrarInfo();
    pelicula3.mostrarInfo();
    pelicula4.mostrarInfo();
    pelicula5.mostrarInfo();
}
