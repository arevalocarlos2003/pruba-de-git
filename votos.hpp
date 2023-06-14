#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

/*Funcion de actualizar votos de candidatos segun numero ID
  correspondiente*/

void ActualizarDatos(int candidato)
{
    candidato -= 1;
    // Guardar cosas en memoria ram temporal para ocuparlas mas tarde
    vector<int> lineas;
    string linea;

    // manejo de archivos
    fstream Votos;
    Votos.open("votos.txt", ios::in);

    if (Votos.is_open())
    {
        while (getline(Votos, linea))
        {
            lineas.push_back(stoi(linea));
        }
        Votos.close();
    }

    Votos.open("votos.txt", ios::out);

    if (Votos.is_open())
    {
        for (int i = 0; i < lineas.size(); i++)
        {
            if (i != candidato)
            {
                Votos << lineas[i] << endl;
            }
            else
            {
                Votos << lineas[i] + 1 << endl;
            }
        }
    }
}

void MostrarCandidatos(string departamento)
{
    fstream Candidatos;
    Candidatos.open("candidatos.txt", ios::in);

    string linea;

    if (Candidatos.is_open())
    {
        cout << setfill('-')
             << "|"
             << setw(3) << left << "Dep"
             << "|"
             << setw(2) << left << "P"
             << "|"
             << setw(9) << left << "Numero"
             << "|"
             << setw(32) << left << "Nombre"
             << "|"
             << endl;
        while (getline(Candidatos, linea))
        {
            if (linea[0] == departamento[0] && linea[1] == departamento[1])
            {
                cout << "|"
                     << linea
                     << endl;
            }
            else if (departamento == "all" || departamento == "todos")
            {
                cout << "|"
                     << linea
                     << endl;
            }
        }
    }
}

void Votar()
{
    bool esValido = true;
    string candidatoVotado;
    if (esValido)
    {
        MostrarCandidatos("03");
        cout << "Ingrese el numero del candidato por el que quiere votar: ";
        cin >> candidatoVotado;
        ActualizarDatos(stoi(candidatoVotado));
    }
}

void MostrarResultados()
{
    fstream ResultadosCandidatos;
    fstream ResultadosVotos;
    ResultadosCandidatos.open("candidatos.txt", ios::in);
    ResultadosVotos.open("votos.txt", ios::in);

    string lineaVotos;
    string lineaCandidatos;

    cout << setfill('-')
         << "|"
         << setw(3) << left << "Dep"
         << "|"
         << setw(2) << left << "P"
         << "|"
         << setw(9) << left << "Numero"
         << "|"
         << setw(32) << left << "Nombre"
         << "|"
         << setw(10) << left << "Votos Totales"
         << "|"
         << endl;

    if (ResultadosCandidatos.is_open() && ResultadosVotos.is_open())
    {
        while (getline(ResultadosCandidatos, lineaCandidatos) && getline(ResultadosVotos, lineaVotos))
        {
            cout << setfill('-')
                 << "|"
                 << setw(0) << left << lineaCandidatos
                 << setw(13) << left << lineaVotos
                 << "|"
                 << endl;
        }
        ResultadosCandidatos.close();
        ResultadosVotos.close();
    }
}

void GuardarEnArchivo(string nombreDeArchivo)
{
    fstream ResultadosCandidatos;
    fstream ResultadosVotos;
    ResultadosCandidatos.open("candidatos.txt", ios::in);
    ResultadosVotos.open("votos.txt", ios::in);

    string lineaCandidatos, lineaVotos;
    vector<string> lineasCandidatos;
    vector<string> lineasVotos;

    if (ResultadosCandidatos.is_open() && ResultadosVotos.is_open())
    {
        while (getline(ResultadosCandidatos, lineaCandidatos) && getline(ResultadosVotos, lineaVotos))
        {
            lineasCandidatos.push_back(lineaCandidatos);
            lineasVotos.push_back(lineaVotos);
        }
        ResultadosCandidatos.close();
        ResultadosVotos.close();
    }

    fstream Archivo;
    Archivo.open(nombreDeArchivo, ios::app);

    if (Archivo.is_open())
    {
        Archivo << setfill('-')
                << "|"
                << setw(3) << left << "Dep"
                << "|"
                << setw(2) << left << "P"
                << "|"
                << setw(9) << left << "Numero"
                << "|"
                << setw(32) << left << "Nombre"
                << "|"
                << setw(10) << left << "Votos Totales"
                << "|"
                << endl;
        for (int i = 0; i < 56; i++)
        {
            Archivo << setfill('-')
                    << "|"
                    << setw(0) << left << lineasCandidatos[i]
                    << setw(13) << left << lineasVotos[i]
                    << "|"
                    << endl;
        }
    }
}