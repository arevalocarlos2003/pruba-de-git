#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Candidatos
{
  int departamento;
  int id;
  string nombre;
  string apellido;
  string partido;
  int votos;
} candidatos[56];

void GuardarEnCandidatos()
{
  fstream Votos("votos.txt", ios::in);
  for (int i = 0; i < 56; i++)
  {
    Votos >> candidatos[i].departamento >> candidatos[i].id >> candidatos[i].nombre >> candidatos[i].apellido >> candidatos[i].votos >> candidatos[i].partido;
    cout << setfill('-')
         << "|"
         << setw(2) << left << candidatos[i].departamento
         << "|"
         << setw(2) << left << candidatos[i].id
         << "|"
         << setw(15) << left << candidatos[i].nombre
         << "|"
         << setw(15) << left << candidatos[i].apellido
         << "|"
         << setw(2) << left << candidatos[i].votos
         << "|"
         << setw(10) << left << candidatos[i].partido
         << endl;
  }
}

void ActualizarVotos(int idCandidato)
{
  fstream Votos("votos.txt", ios::out);
  idCandidato--;
  for (int i = 0; i < 56; i++)
  {
    if (i == idCandidato)
    {
      candidatos[i].votos = candidatos[i].votos + 1;
    }
    Votos << candidatos[i].departamento
          << " "
          << candidatos[i].id
          << " "
          << candidatos[i].nombre
          << " "
          << candidatos[i].apellido
          << " "
          << candidatos[i].votos
          << " "
          << candidatos[i].partido
          << endl;
  }
}