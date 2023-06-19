#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/* Funciones para validacion y busqueda de departamento de votacion */

struct Departamentos
{
    int idDep;
    string nombreD;
} departamentos[14];

string departamento;

void GuardarEnDepartamentos()
{
    fstream DepartamentosF("Dep.txt", ios::in);

    for (int i = 0; i < 14; i++)
    {
        DepartamentosF >> departamentos[i].idDep;
        getline(DepartamentosF, departamentos[i].nombreD);
    }
}

bool ValidarDUI(string DUI);
bool ValidarVotacion(string DUI);
int BuscarDepartamento(string DUI);
void RegistrarVotante(string DUI);

void IngresoDui()
{
    string DUI;
    cout << "ingrese su numero de DUI 8 digitos: ";
    cin >> DUI;
    if (ValidarDUI(DUI) == true && ValidarVotacion(DUI) != false)
    {
        Votar(BuscarDepartamento(DUI));
        RegistrarVotante(DUI);
    }
    else if (ValidarVotacion(DUI) == false)
    {
        cout << "Usted ya ha votado anteriormente" << endl;
    }
    else
    {
        cout << "DUI no valido deben ser 8 digitos y los ultimos dos tienen que ser menores que 14" << endl;
    }
}

/*
    Esta funcion valida tanto que el numero de DUI tenga 8 digitos como que este mismo sea
    valido dentro del numero de departamentos por lo tanto solo acepta numeros que sean desde
    01 hasta 14
 */

bool ValidarDUI(string DUI)
{
    string ultimosDigitos;
    // agarra los ultimos numeros para compararlos
    int size = DUI.size();
    ultimosDigitos.push_back(DUI[size - 2]);
    ultimosDigitos.push_back(DUI[size - 1]);

    // Se convierte a int con la funcion stoi || string to int
    if (DUI.size() == 8 && stoi(ultimosDigitos) <= 14)
    {
        return true;
    }
    return false;
}

int BuscarDepartamento(string DUI)
{
    GuardarEnDepartamentos();
    string ultimosDigitos;
    // agarra los ultimos numeros para compararlos
    ultimosDigitos.push_back(DUI[6]);
    ultimosDigitos.push_back(DUI[7]);
    // cout << numeroDepartamento;
    for (int i = 0; i < 14; i++)
    {
        if (departamentos[i].idDep == stoi(ultimosDigitos))
        {
            departamento = departamentos[i].nombreD;
            return departamentos[i].idDep;
        }
    }
    return 1;
}

/* Funciones para validacion de votacion
   Solo valida si las personas votaron anteriormente
*/
bool ValidarVotacion(string DUI)
{
    fstream RegistroVotantes("Registro_Votantes.txt", ios::in);
    string DUIActual;
    if (RegistroVotantes.is_open())
    {
        while (getline(RegistroVotantes, DUIActual))
        {
            if (DUI == DUIActual)
            {
                return false;
            }
        }
    }
    return true;
}

void RegistrarVotante(string DUI)
{
    fstream RegistroVotantes("Registro_Votantes.txt", ios::app);
    RegistroVotantes << DUI << endl;
}