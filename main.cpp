#include <iostream>
#include <fstream>

using namespace std;

int main(){
  fstream Archivo;

  Archivo.open("votos-fmln.txt", ios::in);
  string line;
  if (Archivo.is_open()){
    getline(Archivo, line);
    cout << line << endl;
    Archivo.close();
  }

  Archivo.open("votos-fmln.txt", ios::out);
  int votos = stoi(line);
  if (Archivo.is_open()){
    votos++;
    Archivo << votos;
    Archivo.close();
  }

  Archivo.open("votos-fmln.txt", ios::in);
  if (Archivo.is_open()){
    getline(Archivo, line);
    cout << line << endl;
    Archivo.close();
  }
  return 0;
}