#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Candidatos
{
  int departamento;
  //id sirve para luego reutlizarlo en la funcion de votar por tal candidato
  int id;
  string nombre;
  string apellido;
  string partido;
  int votos;
  //se hace un array de esto
} candidatos[56];

void GuardarEnCandidatos()
{
  fstream Votos("votos.txt", ios::in);
  for (int i = 0; i < 56; i++)
  {
    //Por cada vuelta del bucle este mismo leera una linea
    //omitiendo espacios por lo tanto se usa el struct para captar la informacion que el struct recibe
    //Esto guarda cada una de las string y valores numericos en la estructura
    //de esta manera podemos acceder a la estructura para cualquier cosa como escribir esos datos en el archivo
    Votos >> candidatos[i].departamento 
          >> candidatos[i].id 
          >> candidatos[i].nombre 
          >> candidatos[i].apellido 
          >> candidatos[i].votos 
          >> candidatos[i].partido;
  }
}

void ActualizarVotos(int idCandidato)
{
  fstream Votos("votos.txt", ios::out);
  //Se decrementa el numero ya que si se ingresa 1 ira a la linea 2
  //porque el indice de los array empiezan en 0
  idCandidato--;
  //recorre el array de structuras candidatos y guarda cada campo dejando un espacio para que se pueda volver a leer
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

void MostrarCandidatos(int departamento){
  GuardarEnCandidatos();
  for(int i = 0; i < 56; i++){
    if (candidatos[i].departamento == departamento){
      cout << setfill('-')
           << "|"
           << setw(10) << left << candidatos[i].id
           << "|"
           << setw(10) << left << candidatos[i].nombre
           << "|"
           << setw(10) << left << candidatos[i].apellido
           << "|"
           << setw(10) << left << candidatos[i].partido
           << "|"
           << endl;
    }
  }
}

void Votar(int departamentoId){
  cout << setfill('-')
       << "|"
       << setw(10) << left << "id"
       << "|"
       << setw(10) << left << "nombre"
       << "|"
       << setw(10) << left << "apellido"
       << "|"
       << setw(10) << left << "partido"
       << "|"
       << endl;
  MostrarCandidatos(departamentoId);
  int candidato = 0;
  cout << "ingrese el numero del candidato por el que quiere votar" << endl;
  cin >> candidato;
  ActualizarVotos(candidato);
}