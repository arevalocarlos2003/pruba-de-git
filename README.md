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