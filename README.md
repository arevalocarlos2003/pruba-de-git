# Guia de como manejar archivos version 101

## Definicion

El manejo de archivos se maneja con la libreria de cabecera fstream, al incluir esta libreria tendriamos las funciones de escritura y lectura de una sola vez al contrario de usar ifstream y ofstream por separado

## Escritura de archivos y su creación

Para escribir archivos simplemente necesitamos incluir la libreria fstream y iostream y a su vez también definir el namespace std
```c++
#include <iostream>
#include <fstream>

using namespace std;
```
Luego para poder manejar un archivo debemos crear una "variable" con el tipo de dato fstream

```c++
fstream ARCHIVO;
```
Despues de lo anterior necesitamos usar el metodo (funcion) de fstream para poder abrir el archivo esta funcion se denomina open y recibe 2 parametros el nombre del archivo y la forma en la que lo abrimos

```c++
fstream ARCHIVO;
ARCHIVO.open("mi_archivo.txt", ios::out);
//puede ser lectura o escritura en este caso lo abri en forma de escritura
```
Luego de abrir el archivo debemos por buenas practicas y para evitar errores operar en el archivo solo si este esta abierto para validar eso usamos lo siguiente

```c++
if(ARCHIVO.is_open()){
    //operaciones para escritura
}

```

Para escribir en el archivo debemos fijarnos que al abrirlo dice out por lo que esto es una salida para nuestro programa por lo tanto

```c++
//esto
cout << "Hello Terminal!" << endl;
//es basicamente esto pero con terminal
ARCHIVO << "Hello File!" << endl;
```

asi que basicamente el codigo de escritura quedaria asi

```c++
fstream ARCHIVO;
ARCHIVO.open("mi_archivo.txt", ios::out);
if (ARCHIVO.is_open()){
    ARCHIVO << "HOLA" << endl;
    ARCHIVO << "HOLA X2" << endl;
    //importante luego de hacer lo que queramos con el archivo debemos cerrarlo
    ARCHIVO.close();
}
```

## Lectura

Es básicamente lo mismo solo que al abrir el archivo lo abrimos como ios::in y tambien al leerlo cambia algo mas

supongamos que tenemos el siguiente txt

```c++
Joseph
Diego
Mau
Carlos
Gabo
```
y deseamos mostrarlos por pantalla

para hacer eso usamos el proceso anterior

```c++
fstream ARCHIVO;
ARCHIVO.open("nombres.txt", ios::in);
string linea;
if (ARCHIVO.is_open()){
    while(getline(ARCHIVO, linea)){
        cout << "miembro de equipo: " << linea << endl;
    }
    ARCHIVO.close();
}
```
Lo que hace este código es básicamente Abrir el archivo para lectura y el while se usa ya que el archivo tiene texto en diferentes lineas y queremos mostrar todas 

le pasamos getline() como condicion ya que si getline no tiene entrada o no hay mas lineas hasta ahi para el ciclo

a getline se le pasan los siguientes parametros

```c++
getline(nombre_de_variable_de_archivo, variable_string_para_guardar_lineas);
```
y asi es como leemos el archivo hasta aqui llegaria lo básico en cuanto a como no sobreescribir lo veremos en el repaso

# Convenio de trabajo

## Variables y parametros

Deben usar Camel-Case

```c++
void Menu(credencialesAdministrador);
```

## Funciones y Archivos

Deben usar Pascal-Case

```c++
void RegistrarVotos();
fstream VotosPartido1();
```

usar nombres descriptivos para las funciones según lo que realizan.

## Funciones

Debemos trabajar separadamente las funciones en archivos por ejemplo si necesitamos una funcionalidad que maneje los menu del programa todas las funciones dedicadas al menu se manejaran en un archivo Menu.hpp, luego esta libreria se importará al final en el archivo main.cpp

## ¿Como pruebo si mi funciones sirven correctamente?

Se debe crear un archivo para tests locales estos archivos asi como los ejecutables serán ignorados por git para no subirse al repositorio.

Asi mismo el archivo test.cpp actuará como un main.cpp pero unicamente para probar nuestro codigo al verificar su funcionamiento podemos juntar nuestro trabajo con el de otro.

# Git - Ramas

Cada uno de nosotros debe usar una rama diferente con nuestro nombre, en la cual trabajaremos la funcionalidad asignada a nosotros.

## ¿Como junto el trabajo con el de otros?

Cada rama será una rama de desarrollo local por lo tanto nuestras ramas no deben hacer merge directamente con la rama main hasta que verifiquemos el funcionamiento total del programa.

Por lo tanto si deseamos tener funcionalidades terminadas de otro compañero debemos preguntar si su funcionalidad esta completa, luego hacemos el merge en nuestra rama y traemos los cambios de la suya.

## ¿Como resolvemos conflictos?

Para la resolución de conflictos debemos ponernos en contacto con la persona a la que le hicimos merge, si se llega a hacer merge con una rama que ya a habia tomado cambios de otras más deberemos hacer una reunión entre todos para acordar como reacomodaremos el código fuente

## ¿Como damos a entender que nuestro commit resuelve conflictos?

para hacer esto debemos llevar la siguiente nomenclatura:

```c++
git commit -m "arreglado conflicto en merge con [<nombre de nuestra rama> -> <nombre de la rama de la cual tomamos cambios>]"
```
## ¿Como puedo publicar mis cambios a github?

Importante al hacer un push es necesario realizar un git fetch para verificar si hay necesidad de realizar un git pull

```shell
// verificamos cambios en el repositorio remoto
git fetch

// nos movemos a la rama que tuvo cambios en el repositorio
git switch <rama>

// hacemos un git pull
git pull origin <nombre de rama a actualizar en repositorio local>

// nos movemos a nuestra rama nuevamente
git switch <nombre de nuestra rama>

// hacemos el git push
git push origin <nombre de nuestra rama>
```

Importante recordar que hay que especificar antes en el commit que tipo de cambio hicimos en nuestro codigo.