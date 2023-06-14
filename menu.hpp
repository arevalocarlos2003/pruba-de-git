#include <iostream>
#include "votos.hpp"

using namespace std;

int Menu()
{
  system("clear");
  cout << setfill('-')
       << "|"
       << setw(8) << left << "opciones"
       << "|"
       << setw(20) << left << "Mostrar Resultados"
       << "|"
       << setw(20) << left << "Guardar en archivo"
       << "|"
       << setw(20) << left << "Votar"
       << "|"
       << setw(20) << left << "Salir"
       << "|"
       << endl;

  cout << setfill('-')
       << "|"
       << setw(8) << left << "        "
       << "|"
       << setw(20) << left << "Opcion[1]"
       << "|"
       << setw(20) << left << "Opcion[2]"
       << "|"
       << setw(20) << left << "Opcion[3]"
       << "|"
       << setw(20) << left << "Opcion[4]"
       << "|"
       << endl;

  int opcion = 0;

  cout << endl
       << "Ingrese el numero de la opcion que desea: ";
  cin >> opcion;

  switch (opcion)
  {
  case 1:
    system("clear");
    MostrarResultados();
    char tecla;
    cout << "Presione <Enter> para continuar..." << endl;
    cin >> tecla;
    Menu();
    break;
  case 2:
    system("clear");

    int opcionArchivo;

    cout << "Desea guardar los registros en un archivo?" << endl
         << "1--si" << endl
         << "2--no" << endl
         << "::";
    cin >> opcionArchivo;

    if (opcionArchivo == 1)
    {
      string nombre;
      cout << "ingrese el nombre del archivo: ";
      cin >> nombre;
      GuardarEnArchivo(nombre);
      break;
    }
    else
    {
      Menu();
      break;
    }

    break;
  case 3:
    system("clear");
    Votar();
    Menu();
    break;
  case 4:
    system("clear");
    return 0;
    break;
  }
  return 0;
}