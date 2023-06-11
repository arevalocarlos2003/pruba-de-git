#include <iostream>
#include <iomanip>

using namespace std;
//Limpia pantallas
void LimpiarPantalla();

//Menus secundarios
void MenuAdmon();
void MenuGen();

void MenuPrincipal()
{
  LimpiarPantalla();
  int opcionMenu = 0;
  int size = 30;
  cout << setfill('-')
       << "|"
       << setw(size) << "Administracion"
       << "|"
       << setw(size) << "Usuario General"
       << "|"
       << endl
       << "|"
       << setw(size) << "[1]"
       << "|"
       << setw(size) << "[2]"
       << "|"
       << endl;
  cin >> opcionMenu;
  switch (opcionMenu){
    case 1:
      MenuAdmon();
      break;
    case 2:
      MenuGen();
      break;
    default:
      MenuGen();
      break;
  }
}

void LimpiarPantalla()
{
#ifdef _WIN32
  system("cls");
  cout << "Ejecutando en Windows" << endl;
#elif __linux__
  system("clear");
  cout << "Ejecutando en Linux" << endl;
#else
  system("cls");
  cout << "Ejecutando en un sistema desconocido" << endl;
#endif
}

void MenuAdmon(){
  LimpiarPantalla();
  cout << "algo";
}

void MenuGen(){
  LimpiarPantalla();
  cout << "General Menu";
}

void MostrarCandidatos(){
  
}