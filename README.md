## Descripción del Programa
Este programa permite a los usuarios cargar datos de películas desde un archivo y de esta manera poder organizarlas y buscarlas según un código identificador, director, década de estreno , género/s de la película, rango de calificaciones, y finalmente una búsqueda que permite filtrar por década y género al mismo tiempo.

Con esta aplicación tenemos la intención de darle al usuario una experiencia dinámica a la hora de buscar películas y lograr encontrar la que se ajuste a sus gustos.

## Como compilar y ejecutar
Dado que el sistema está diseñado para ser accesible y fácil de probar, recomendamos usar [Repl.it](http://repl.it/) para una rápida configuración y ejecución. Sigue estos pasos para comenzar:

1. Visita [Repl.it](https://repl.it/).
2. Crea una nueva cuenta o inicia sesión si ya tienes una.
3. Una vez en tu dashboard, selecciona "New Repl" y elige "Import from GitHub".
4. Pega la URL del repositorio: `https://github.com/P4bl0AGT/Sistema-de-Gesti-n-de-Pacientes-en-Hospital`.
5. [Repl.it](http://repl.it/) clonará el repositorio y preparará un entorno de ejecución.
6. Presiona el botón "Run" para compilar y ejecutar la aplicación.

# Funcionalidades

## Funcionando correctamente:
* Cargar datos de las películas desde un archivo.
* Buscar las películas según su código identificador.
* Buscar las películas según su género
* Buscar las películas según su director
* Buscar las películas según su década
* Buscar las películas según su rango de clasificación
* Buscar las películas según su década y género
* Salir del programa

## Problemas conocidos:
* En el caso de la busqueda por director, el usuario puede ingresar el nombre en minusculas o mayusculas, pero si lleva tilde tiene que si o si poner el nombre con tilde, si no el programa no reconoce que se trata del mismo director
* Las décadas están preestablecidas, en el caso de que se agregue algún archivo con alguna década no preestablecida, la función buscarPorDecada tendrá problemas.
* Los rangos están preestablecidos, en el caso de que se agregue algún archivo con algún rango no preestablecido, la función buscarPorRango tendrá problemas.

## A mejorar:
* crear alguna funcion, que permita al usuario ingresar nombres sin tilden y que el programa reconozca que se trata del mismo director
* Interfaz más amigable con el usuario
* Poder cargar otras décadas que no estén preestablecidas
* Poder cargar otros rangos de clasificación que no estén preestablecidos

# Ejemplo de uso

## Opcion 1: Menú

* Al comenzar el programa se mostrará un menú en el cual aparecerán todas las opciones que se pueden seleccionar en este programa

````
========================================
    Base de Datos de Peliculas
========================================
(1) Cargar Peliculas
(2) Buscar por ID
(3) Buscar con Genero
(4) Buscar por Director
(5) Buscar por Decada
(6) Buscar por Rango de Clasificación
(7) Buscar por Decada y Genero
(8) Salir del programa
Ingrese una opción : 1
````
Nuestro usuario ha ingresado a la opción 1 del menú, por lo que procedemos a ingresar qué documento de películas quiere cargar, mostrándole las opciones, en este caso el usuario escoge la opción "1".

````
Elige que documento csv quieres cargar
(1) IMDbTop250
(2) Top1500
1
````

La lista que se elija va a ser la que se cargue en el sistema.

## Opcion 2: Buscar película por código identificador

````
========================================
    Base de Datos de Peliculas
========================================
(1) Cargar Peliculas
(2) Buscar por ID
(3) Buscar con Genero
(4) Buscar por Director
(5) Buscar por Decada
(6) Buscar por Rango de Clasificación
(7) Buscar por Decada y Genero
(8) Salir del programa
Ingrese una opción : 2

````

Nuestro usuario ha ingresado a la opcion 2 del menú, por lo que procedemos a pedirle que escriba el código al que quiere acceder, para así saber que película debemos mostrar.

````
Ingrese la id para buscar la pelicula : tt0048021
PELICULA CON EL ID tt0048021 :
-Du rifiti chez les hommes
Presione una tecla para continuar...
````

## Opcion 3: Buscar película por Genero

````
========================================
    Base de Datos de Peliculas
========================================
(1) Cargar Peliculas
(2) Buscar por ID
(3) Buscar con Genero
(4) Buscar por Director
(5) Buscar por Decada
(6) Buscar por Rango de Clasificación
(7) Buscar por Decada y Genero
(8) Salir del programa
Ingrese una opción : 3
````

El usuario ingresa la opción 3 del menú por lo que le solicitamos ingresar un género, mostrándole los que hay disponibles. en este caso, el usuario va a ingresar "Sport"

````
GENEROS :
[Drama, Crime, Action, Thriller, Biography, History, Adventure, Fantasy, Western, Romance, Sci-Fi, Mystery, Family, War, Comedy, Animation, Horror, Music, Musical, Film-Noir, Sport]
Ingrese un genero para buscar la/as pelicula/as : Sport
PELICULAS CON EL GENERO SPORT:
-Dangal
-Raging Bull
-Warrior
-Million Dollar Baby
-Bacheha-Ye aseman
-Ford v Ferrari
-Rocky
-Rush
Presione una tecla para continuar...
````

## Opcion 4: Buscar pelicula por director

````
========================================
    Base de Datos de Peliculas
========================================
(1) Cargar Peliculas
(2) Buscar por ID
(3) Buscar con Genero
(4) Buscar por Director
(5) Buscar por Decada
(6) Buscar por Rango de Clasificación
(7) Buscar por Decada y Genero
(8) Salir del programa
Ingrese una opción : 4
````
El usuario ingresa la opción 4 del menú por lo que le solicitamos ingresar el nombre de un director, mostrándole los que hay disponibles. en este caso el usuario va a ingresar "Francis Ford Coppola"

````
DIRECTORES:
[Frank Darabont, Francis Ford Coppola, Christopher Nolan, Sidney Lumet, Steven Spielberg, Peter Jackson, Quentin Tarantino, Sergio Leone, Robert Zemeckis, David Fincher, Irvin Kershner, Lilly Wachowski, Lana Wachowski, Martin Scorsese, Milos Forman, Akira Kurosawa, Frank Capra, Jonathan Demme, Kátia Lund, Fernando Meirelles, Roberto Benigni, George Lucas, James Cameron, Hayao Miyazaki, Alfred Hitchcock, Roman Polanski, Bong Joon Ho, Luc Besson, Rob Minkoff, Roger Allers, Ridley Scott, Tony Kaye, Bryan Singer, Damien Chazelle, Michael Curtiz, Masaki Kobayashi, Isao Takahata, Olivier Nakache, Éric Toledano, Charles Chaplin, Giuseppe Tornatore, Andrew Stanton, Florian Henckel von Donnersmarck, Billy Wilder, Stanley Kubrick, Anthony Russo, Joe Russo, Bob Persichetti, Rodney Rothman, Peter Ramsey, Sam Mendes, Park Chan-wook, Adrian Molina, Lee Unkrich, Todd Phillips, John Lasseter, Mel Gibson, Wolfgang Petersen, Gus Van Sant, Makoto Shinkai, Darren Aronofsky, Gene Kelly, Stanley Donen, Rajkumar Hirani, Joseph Kosinski, Richard Marquand, Nadine Labaki, Michel Gondry, Thomas Vinterberg, Elem Klimov, Orson Welles, Fritz Lang, David Lean, Jean-Pierre Jeunet, Thomas Kail, Brian De Palma, Robert Mulligan, George Roy Hill, Denis Villeneuve, Pete Docter, Bob Peterson, Michael Mann, Asghar Farhadi, Curtis Hanson, John McTiernan, Guy Ritchie, Vittorio De Sica, Aamir Khan, Amole Gupte, Oliver Hirschbiegel, Nitesh Tiwari, Joseph L. Mankiewicz, Florian Zeller, Peter Farrelly, Stanley Kramer, Guillermo del Toro, Clint Eastwood, Paul Thomas Anderson, Peter Weir, M. Night Shyamalan, Ron Howard, John Huston, Terry Jones, Terry Gilliam, Jon Watts, John Sturges, Joel Coen, Ethan Coen, John Carpenter, David Lynch, James McTeigue, Sam Wood, George Cukor, Victor Fleming, Ronnie Del Carmen, Juan José Campanella, Martin McDonagh, Danny Boyle, Gavin O'Connor, Majid Majidi, Elia Kazan, Richard Linklater, Steve McQueen, David Yates, William Wyler, Carlos Martínez López, Sergio Pablos, Ingmar Bergman, Carol Reed, Buster Keaton, Clyde Bruckman, Wes Anderson, Michael Cimino, Jim Sheridan, Henri-Georges Clouzot, Damián Szifron, George Miller, Lenny Abrahamson, Adam Elliot, Chris Sanders, Dean DeBlois, David Silverman, Carl Theodor Dreyer, Yasujirô Ozu, Terry George, James Mangold, John G. Avildsen, Oliver Stone, Tom McCarthy, Rob Reiner, Brad Bird, Jan Pinkava, Satyajit Ray, Sean Penn, King Vidor, Harold Ramis, William Friedkin, Ernst Lubitsch, Gillo Pontecorvo, Mathieu Kassovitz, Lasse Hallström, T.J. Gnanavel, Çagan Irmak, Gore Verbinski, John Ford, Alejandro G. Iñárritu, Stuart Rosenberg, François Truffaut, Robert Wise, Ron Clements, John Musker, Tate Taylor, Richard Attenborough, Jules Dassin]
Ingrese un director para buscar la/as pelicula/as : Francis Ford Coppola
PELICULAS CON EL DIRECTOR FRANCIS FORD COPPOLA:
-The Godfather
-The Godfather Part II
-Apocalypse Now
Presione una tecla para continuar...
````

## Opcion 5: Buscar pelicula por Decada

````
========================================
    Base de Datos de Peliculas
========================================
(1) Cargar Peliculas
(2) Buscar por ID
(3) Buscar con Genero
(4) Buscar por Director
(5) Buscar por Decada
(6) Buscar por Rango de Clasificación
(7) Buscar por Decada y Genero
(8) Salir del programa
Ingrese una opción : 5
````

El usuario ingresa la opción 5 del menú por lo que le solicitamos ingresar la década en la que se estrenaron la películas, mostrándole las que hay disponibles. en este caso, el usuario va a ingresar "2020"

````
DECADAS :
[1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, 2010, 2020]
Ingrese una decada para buscar la/as pelicula/as : 2020
PELICULAS CON LA DECADA 2020 :
-Top Gun: Maverick
-Hamilton
-The Father
-Spider-Man: No Way Home
-Jai Bhim
Presione una tecla para continuar...
````

## Opcion 6: Buscar pelicula por Rango de Clasificación

````
========================================
    Base de Datos de Peliculas
========================================
(1) Cargar Peliculas
(2) Buscar por ID
(3) Buscar con Genero
(4) Buscar por Director
(5) Buscar por Decada
(6) Buscar por Rango de Clasificación
(7) Buscar por Decada y Genero
(8) Salir del programa
Ingrese una opción : 6
````
El usuario ingresa la opción 6 del menú por lo que le solicitamos ingresar el rango de claisificacion en la que se encuentran las películas, mostrándole las que hay disponibles. en este caso, el usuario va a ingresar la opción 9, que es de "9.0 - 9.4"

````
(1) 5.0 - 5.4
(2) 5.5 - 5.9
(3) 6.0 - 6.4
(4) 6.5 - 6.9
(5) 7.0 - 7.4
(6) 7.5 - 7.9
(7) 8.0 - 8.4
(8) 8.5 - 8.9
(9) 9.0 - 9.4
(10) 9.5 - 9.9
(11) 10.0
Escoga alguna de los siguientes rangos de clasificacion : 9
PELICULAS CON EL RANGO ELEGIDO:
-The Shawshank Redemption
-The Godfather
-The Dark Knight
-The Godfather Part II
-12 Angry Men
-Schindler's List
-The Lord of the Rings: The Return of the King
Presione una tecla para continuar...
````

## Opcion 7: Buscar pelicula por Decada y Genero

````
========================================
    Base de Datos de Peliculas
========================================
(1) Cargar Peliculas
(2) Buscar por ID
(3) Buscar con Genero
(4) Buscar por Director
(5) Buscar por Decada
(6) Buscar por Rango de Clasificación
(7) Buscar por Decada y Genero
(8) Salir del programa
Ingrese una opción : 7
````
El usuario ingresa la opción 7 del menú por lo que le solicitamos ingresar el Genero de la película y la década en la que fue estrenada, mostrando en cada caso la lista disponible. en este caso, el usuario va a ingresar "Comedy" para el genero que y "1980" para la década.

````
GENEROS :
[Drama, Crime, Action, Thriller, Biography, History, Adventure, Fantasy, Western, Romance, Sci-Fi, Mystery, Family, War, Comedy, Animation, Horror, Music, Musical, Film-Noir, Sport]
Ingrese el genero para buscar la/as pelicula/as : Comedy
DECADAS :
[1910, 1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, 2010, 2020]
Ingrese una decada para buscar la/as pelicula/as : 1980
PELICULAS CON EL GENERO COMEDY y DECADA 1980
-Back to the Future 
-Tonari no Totoro 
-Dead Poets Society 
-Stand by Me 
Presione una tecla para continuar...
````
## Opcion 8: Salir del Programa

````
========================================
    Base de Datos de Peliculas
========================================
(1) Cargar Peliculas
(2) Buscar por ID
(3) Buscar con Genero
(4) Buscar por Director
(5) Buscar por Decada
(6) Buscar por Rango de Clasificación
(7) Buscar por Decada y Genero
(8) Salir del programa
Ingrese una opción : 8
Gracias por elegir nuestro servicio :D
````

El usuario ingresa la opción 8, que es para cerrar el programa, por lo que se finaliza el proceso de base de datos de películas.

## Contribuciones Individuales

*Pablo Aguilera Tapia:
-Rol asumido: Conductor.
-Implementacion y modularizacion del codigo.
-Documentacion y comentarios en el codigo.
-Diseño y Redaccion del README.
-Auto-evaluacion : 3(APORTE EXCELENTE)

*Benjamin Gomez Beltran
-Rol asumido: Navegador.
-Revision y correcion de errores.
-Sugerencia de cambios y enfoque en las repuestas.
-Diseño y Redaccion del README.
-Auto-evaluacion: 3(APORTE EXCELENTE)