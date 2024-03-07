#include <iostream>

using namespace std;

const int TAM = 5;

class Alumno
{
    public:
        Alumno() : nombre(""), carrera(""), materiasAprobadas(0), promedio(0.0) {}
        Alumno(string nombre, string carrera, int materiasAprobadas, float promedio) : nombre(nombre), carrera(carrera), materiasAprobadas(materiasAprobadas), promedio(promedio) {}

        friend istream& operator >> (istream& in, Alumno& i)
        {
            cout << endl << "Ingrese el nombre del Alumno: ";
            in.ignore();
            getline(in, i.nombre);

            cout << "Ingrese el nombre de la carrera del Alumno: ";
            in.ignore();
            getline(in, i.carrera);

            cout << "Ingrese las materias aprobadas del Alumno: ";
            in >> i.materiasAprobadas;

            cout << "Ingrese el promedio del Alumno: ";
            in >> i.promedio;

            return in;
        }

        friend ostream& operator << (ostream& out, const Alumno& o)
        {
            out << endl << 
            "Nombre del Alumno: " << o.nombre << endl << 
            "Carrera del Alumno: " << o.carrera << endl << 
            "Materias aprobadas: " << o.materiasAprobadas << endl << 
            "Promedio del Alumno: " << o.promedio << endl;

            return out;
        }

        Alumno& operator=(const Alumno& a)
        {
            nombre = a.nombre;
            carrera = a.carrera;
            materiasAprobadas = a.materiasAprobadas;
            promedio = a.promedio;

            return *this;
        }

        void mostrar() const
        {
            cout << endl << 
            "Nombre de Alumno: " << nombre << endl << 
            "Carrera del Alumno: " << carrera << endl << 
            "Materias aprobadas: " << materiasAprobadas << endl << 
            "Promedio del Alumno: " << promedio << endl;
        }

    private:
        string nombre;
        string carrera;
        int materiasAprobadas;
        float promedio;
};

class Cola
{
    public:
        Cola() : ult(-1), alumnos{} {}

        bool vacia() const
        {
            return ult == -1;
        }

        void encolar(const Alumno& alumno)
        {
            if (ult == TAM - 1)
            {
                cout << endl << "Cola llena. No se puede agregar el alumno." << endl;
                return;
            }
            else
            {
                ult++;
                alumnos[ult] = alumno;
                cout << endl << "Alumno agregado correctamente" << endl;
            }
        }

        void desencolar()
        {
            if (vacia())
            {
                cout << endl << "No hay constancias por hacer..." << endl;
            }
            else
            {
                cout << endl << "Alumno que recibe constancia: " << alumnos << endl;
                alumnos[0].mostrar();

                for (int i = 1; i <= ult; i++)
                {
                    alumnos[i - 1] = alumnos[i];
                }

                ult--;
                cout << endl << "Constancia entregada correctamente" << endl;
            }
        }

    private:
        Alumno alumnos[TAM];
        int ult;
};

int menu(int op)
{
	cout << endl <<
    "Menu" << endl << 
    " 1) Dar de alta solicitud de Alumno" << endl << 
    " 2) Elaborar constancia" << endl << 
    " 3) Salir" << endl << 
    "Ingresa una opción: ";
	cin >> op;

	return op;
}

int main()
{
	int op;
    Cola cola;

	do
	{
		switch(menu(op))
		{
			case 1:
            {
                Alumno alumno;
                cin >> alumno;
				cola.encolar(alumno);
                break;
            }

			case 2:
            {
				cola.desencolar();
                break;
            }


			case 3:
            {
				cout << endl << "Saliendo del programa..." << endl;
				return 0;
                break;
            }

			default:
            {
				cout << endl << "Orden no encontrada. Ingrese una orden correcta." << endl;
            }
		}
	} while (true);

    return 0;
}