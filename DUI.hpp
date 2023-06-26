#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/* Funciones para validacion y busqueda de departamento de votacion */
// Aqui se guarda la info de procedencia de los DUI
struct Departamentos
{
    int idDep;
    string nombreD;
} departamentos[14];

/* la variable departamento se usa como parámetro a usar para las funciones de votos.hpp, por eso es declarada de forma global
no como variable local de la función */
string departamento;

// Esta funcion guarda lo que esta en el archivo departamentos en la estructura
void GuardarEnDepartamentos()
{
    fstream DepartamentosF("Dep.txt", ios::in);

    if (DepartamentosF.is_open())
    {
        for (int i = 0; i < 14; i++)
        {
            DepartamentosF >> departamentos[i].idDep;
            getline(DepartamentosF, departamentos[i].nombreD);
        }
        DepartamentosF.close();
    }
}

// funciones de validacion
bool ValidarDUI(string DUI);
bool ValidarVotacion(string DUI);
int BuscarDepartamento(string DUI);
void RegistrarVotante(string DUI);

// funcion para ingresar DUI
string IngresoDui()
{
    string DUI;
    cout << "ingrese su numero de DUI 8 digitos: ";
    cin >> DUI;
    // Esto valida si el DUI ya voto y si el DUI es valido en el pais
    if (ValidarDUI(DUI) == true && ValidarVotacion(DUI) != true)
    {
        return DUI;
    }
    else if (ValidarVotacion(DUI) == true)
    {
        cout << "Usted ya ha votado anteriormente" << endl;
        return DUI;
    }
    else
    {
        cout << "DUI no valido deben ser 8 digitos y los ultimos dos tienen que ser menores que 14" << endl;
        return DUI;
    }

    return "";
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
// Esto sirve para no tener que meter manualmente el numero de Departamento en Votar
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
        if (departamentos[i].idDep == stoi(ultimosDigitos) && ValidarVotacion(DUI) == false)
        {
            departamento = departamentos[i].nombreD;
            return departamentos[i].idDep;
        }
    }
    return 0;
}

void Mostrarinformacion()
{
    string estado;
    string DUI;
    cout << "ingrese su DUI" << endl;
    cin >> DUI;

    ValidarDUI(DUI);
    BuscarDepartamento(DUI);

    if (ValidarVotacion(DUI) == true)
    {
        estado = "Si";
    }
    else
    {
        estado = "No";
    }

    cout << setfill('.')
         << "|"
         << setw(20) << left << "Departamento"
         << "|"
         << setw(20) << left << "Estado"
         << "|"
         << endl;
    cout << setfill('.')
         << "|"
         << setw(20) << left << departamento
         << "|"
         << setw(20) << left << estado
         << "|"
         << endl;
}

bool ValidarVotacion(string DUI)
{
    fstream RegistroVotantes;
    RegistroVotantes.open("Registro_Votantes.txt", ios::in);

    string DUIActual;
    if (RegistroVotantes.is_open())
    {
        while (getline(RegistroVotantes, DUIActual))
        {
            if (DUI == DUIActual)
            {
                return true;
            }
        }
    }
    RegistroVotantes.close();
    
    return false;
}

// Esto sirve para guardar en Registro_Votantes.txt
void RegistrarVotante(string DUI)
{
    fstream RegistroVotantes;
    RegistroVotantes.open("Registro_Votantes.txt", ios::app);
    if(RegistroVotantes.is_open()){
        RegistroVotantes << DUI << endl;
        RegistroVotantes.close();
    }
}
