
#include "Estudiante.h"
#include <iostream>
using namespace  std;

int main()
{

	string car, nom,ape, dir, genero,email,fech;
	int tel;
	cout << "Ingrese carnet: ";
	getline(cin, car);
	cout << "Ingrese Nombre: ";
	getline(cin, nom);
	cout << "Ingrese Apellido: ";
	getline(cin, ape); 
	cout << "Ingrese Direccion: ";
	getline(cin, dir);
	cout << "Ingrese Genero: ";
	getline(cin, genero);
	cout << "Ingrese Email: ";
	getline(cin, email);
	cout << "Ingrese Fecha de Nacimiento: ";
	getline(cin, fech);
	cout << "Ingrese Telefono: ";
	cin >> tel;
	cin.ignore();

	Estudiante e = Estudiantes(car, nom, ape, dir, genero, email, fech,tel);

	e.crear();
	e.leer();
	e.actualizar();
	e.eliminar();

	system("pause");
	return 0;
}

