#include <iostream>

using namespace std;

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
            ult++;
            alumnos = alumno;
            cout << endl << "Alumno agregado correctamente" << endl;
        }

        void desencolar() const
        {
            if (vacia())
            {
                cout << endl << "No hay constancias por hacer..." << endl;
            }
            else
            {
                
            }
        }

    private:
        Alumno alumnos;
        int ult;
};

int menu(int op)
{
	cout << 
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