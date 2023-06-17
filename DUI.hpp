#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ValidarDui(string);
void ValidarDepartamento(string);

void InputDui(){
    string DUI;
    cout << "ingrese su numero de DUI 8 Digitos: " << endl;
    cin >> DUI;
    ValidarDui(DUI);
}

void ValidarDui(string DUI){
    int duiSize = DUI.size();
    char digitos[2] = {DUI[duiSize-2], DUI[duiSize-1]};
    string digitosDepartamento = digitos;

    if(duiSize > 8 || duiSize < 8 || stoi(digitosDepartamento) > 14){
        cout << "Su DUI tiene mas de 8 digitos o los ultimos digitos\nno coinciden con ningun departamento del pais";
        InputDui();
    }

    fstream RegistroDui;
    RegistroDui.open("Registro_Votantes.txt", ios::in);
    string votantes;
    
    if(RegistroDui.fail()){
        RegistroDui.open("Registro_Votantes.txt", ios::out);
        RegistroDui.close();

        RegistroDui.open("Registro_Votantes.txt", ios::in);
        if(RegistroDui.is_open()){
            while(getline(RegistroDui, votantes)){
            if(DUI == votantes){
                cout << "Usted ha votado anteriormente..." << endl;
            }
        }
        }
    }else{
        while(getline(RegistroDui, votantes)){
            if(DUI == votantes){
                cout << "Usted ha votado anteriormente..." << endl;
            }
        }
    }
    /* if (RegistroDui.is_open()){
        
    } */
    ValidarDepartamento(digitos);
    //cout << stoi(digitos) + 1 << endl;

}

void ValidarDepartamento(string digitosDepartamento){
    fstream Departamentos;
    Departamentos.open("Departamentos.txt", ios::in);
    string idDep;
    string dep;
    if (Departamentos.is_open()){
        while(getline(Departamentos, idDep)){
            if(idDep[0] == digitosDepartamento[0] && idDep[1] == digitosDepartamento[1]){
                dep = idDep.substr(2, idDep.size() - 1);
                cout << "Su departamento correspondiente es: " << dep << endl;
            }
        }
    }
}