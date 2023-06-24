#include <iostream>
#include <iomanip>
#include "Logo.hpp"
#include "votos.hpp"
#include "DUI.hpp"

using namespace std;

void MenuAdministrador();
void MenuGeneral();

string DUI;

void MainMenu()
{
  system("clear");
  //Logo();
  cout << "Tribunal Supremo Electoral" << endl;
  cout << "Hacemos que contar papeles suene interesante" << endl;
  cout << setfill('.')
       << setw(60 + 3) << left << ""
       << endl
       << "."
       << setw(30) << left << "Opciones Administrador"
       << "."
       << setw(30) << right << "[1]"
       << "."
       << endl
       << "."
       << setw(30) << left << "Opciones Generales"
       << "."
       << setw(30) << right << "[2]"
       << "."
       << endl
       << "."
       << setw(30) << left << "Salir"
       << "."
       << setw(30) << right << "[3]"
       << "."
       << endl;
  int option;
  cout << right << ">";
  cin >> option;

  switch (option)
  {
  case 1:
    system("clear");
    cout << "Menu Administrador" << endl;
    MenuAdministrador();
    break;
  case 2:
    system("clear");
    MenuGeneral();
    break;
  default:
    cout << "Cerrando..." << endl;
    break;
  }
}

void MenuAdministrador()
{
  system("clear");
  cout << setfill('.')
       << setw(30) << left << "Mostrar Resultados"
       << setw(30) << right << "[1]"
       << endl
       << setw(30) << left << "Mostrar Informacion DUI"
       << setw(30) << right << "[2]"
       << endl
       << setw(30) << left << "Generar Registro de DUI's"
       << setw(30) << right << "[3]"
       << endl
       << setw(30) << left << "Volver al menu anterior <-"
       << setw(30) << right << "[4]"
       << endl;
  int option;
  cout << ":";
  cin >> option;
  switch (option)
  {
  case 1:
    cout << "mostrar resultados" << endl;
    break;
  case 2:
    cout << "mostrar info" << endl;
    Mostrarinformacion();
    break;
  case 3:
    cout << "generar info" << endl;
    break;
  default:
    MainMenu();
    break;
  }
}

void MenuGeneral()
{
  system("clear");
  cout << setfill('.')
       << setw(30) << left << "Buscar Departamento"
       << setw(30) << right << "[1]"
       << endl
       << setw(30) << left << "Mostrar Candidatos"
       << setw(30) << right << "[2]"
       << endl
       << setw(30) << left << "Votar"
       << setw(30) << right << "[3]"
       << endl
       << setw(30) << left << "Volver al menu anterior <-"
       << setw(30) << right << "[4]"
       << endl;
  int option;
  cout << ":";
  cin >> option;
  string aux;
  switch (option)
  {
  case 1:
    system("clear");
    cout << "Buscar Departamento" << endl;
    BuscarDepartamento(IngresoDui());

    cout << "Su departamento es: " << departamento << endl;
    cout << "Escriba [ok] para continuar..." << endl;
    cin >> aux;
    MainMenu();
    break;
  case 2:
    system("clear");
    cout << "Mostrar Candidatos" << endl;
    MostrarCandidatos(BuscarDepartamento(IngresoDui()));

    cout << "Escriba [ok] para continuar..." << endl;
    cin >> aux;
    MainMenu();
    break;
  case 3:
    system("clear");
    DUI = IngresoDui();
    Votar(BuscarDepartamento(DUI));
    RegistrarVotante(DUI);

    cout << "Escriba [ok] para continuar..." << endl;
    cin >> aux;
    MainMenu();
    break;
  default:
    MainMenu();
    break;
  }
}