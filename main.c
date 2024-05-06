#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tdas/extra.h"
#include "tdas/list.h"
#include "tdas/map.h"
#include "tdas/mostrar.h"

typedef struct
{
  Map *mapaID; // Mapa que asocia ID de películas con su información.
  Map *mapaGenero; // Mapa que asocia géneros con películas que pertenecen a cada género.
  Map *mapaDirector; // Mapa que asocia directores con películas que han dirigido.
  Map *mapaDecada; // Mapa que asocia décadas con películas lanzadas en cada década.
  Map *mapaClasificacion; // Mapa que asocia rangos de clasificación con películas en cada rango.
  List *generos; // Lista de géneros sin repeticiones.
  List *directores; // Lista de directores sin repeticiones.
  List *decadas;// Lista de décadas sin repeticiones.
  List *clasificaciones; // Lista de clasificaciones sin repeticiones.
} tipoTDAs; // Estructura que contiene todos los TDAs necesarios para almacenar información sobre películas.

typedef struct
{
  char *id; // ID única de la película.
  char *titulo; // Título de la película.
  List *generos;  // Lista de géneros a los que pertenece la película.
  List *directores; // Lista de directores de la película.
  float clasificacion;  // Clasificación de la película.
  int fecha;  // Año de lanzamiento de la película.
} tipoPelicula; // Estructura que representa una película con su información relevante.

#define ROJO printf("\x1b[31m");
#define VERDE printf("\x1b[32m");
#define AMARILLO printf("\x1b[33m");
#define BLANCO printf("\x1b[m");
#define AZUL printf("\x1b[34m");

//Inicializa la estructura tipoTDAs con los mapas y listas necesarios.
tipoTDAs *inicializarTDAs()
{
  tipoTDAs *mapas = (tipoTDAs *) malloc(sizeof(tipoTDAs));
  mapas->mapaID = map_create(NULL);
  mapas->mapaGenero = map_create(NULL);
  mapas->mapaDirector = map_create(NULL);
  mapas->mapaDecada = map_create(NULL);
  mapas->mapaClasificacion = map_create(NULL);
  mapas->generos = list_create();
  mapas->directores = list_create();
  mapas->decadas = list_create();
  for(int decada = 1910 ; decada <= 2020 ; decada+=10)
  {
    int *dec = (int *)malloc(sizeof(int));
    *dec = decada;
    list_pushBack(mapas->decadas, dec);
  }
  mapas->clasificaciones = list_create();
  for(float clasificacion = 5.0 ; clasificacion <= 10.0 ; clasificacion+=0.5)
  {
    float *clas = (float *)malloc(sizeof(float));
    *clas = clasificacion;
    list_pushBack(mapas->clasificaciones, clas);
  }
  return mapas;
}

//Muestra los titulos de las peliculas de una lista
void mostrarPeliculas(List *lista)
{
  tipoPelicula *pelicula = (tipoPelicula *) list_first(lista);
  while(pelicula != NULL)
  {
    printf("-%s\n", pelicula->titulo);
    pelicula = (tipoPelicula *) list_next(lista);
  }
}

//Muestra el ID y titulo de cada pelicula de un mapa
void mostrarMapa(Map *mapa)
{
  MapPair *pareja = map_first(mapa);
  tipoPelicula *pelicula;
  while(pareja != NULL)
  {
    pelicula = (tipoPelicula *) pareja->value;
    printf("(ID : %10s) Titulo : %s  \n", pelicula->id, pelicula->titulo);
    pareja = map_next(mapa);
  }
}

//Crea una lista sin repeticiones a partir de una lista secundaria.
void crearListaSinRepeticiones(List* listaPrincipal, List* listaSecundaria)
{
  char *genero = (char *)list_first(listaSecundaria);
  while(genero != NULL)
  {
    if(noExiste(listaPrincipal, genero)) //si no existe quiero meter el genero a mi lista
      list_pushBack(listaPrincipal, genero);
    genero = (char *) list_next(listaSecundaria);
  }
}

//Crea un mapa que relaciona cada genero con las peliculas que lo tienen como genero
void crearMapaPorGenero(Map *mapaID, Map *mapaGenero, List* generos)
{
  char *genero = (char *) list_first(generos);
  while(genero != NULL) //RECORRO TODOS LOS GENEROS SIN REPETICION
  {
    List *lista = list_create();
    MapPair *pareja = map_first(mapaID);
    
    while(pareja != NULL) //POR CADA GENERO RECORREMOS TODAS LAS PELICULAS
    {
      tipoPelicula *pelicula = (tipoPelicula *)pareja->value;
      if(!noExiste(pelicula->generos, genero)) //SI EXISTE
        list_pushBack(lista, pelicula); 
      pareja = map_next(mapaID);
    }
    map_insert(mapaGenero, genero, lista);
    genero = (char *) list_next(generos);
  }
}

// Crea un mapa que relaciona cada director con las películas que ha dirigido
void crearMapaPorDirector(Map *mapaID, Map *mapaDirector, List* directores)
{
  char *director = (char *) list_first(directores);
  while(director != NULL) //RECORRO TODOS LOS GENEROS SIN REPETICION
  {
    List *lista = list_create();
    MapPair *pareja = map_first(mapaID);

    while(pareja != NULL) //POR CADA GENERO RECORREMOS TODAS LAS PELICULAS
    {
      tipoPelicula *pelicula = (tipoPelicula *)pareja->value;
      if(!noExiste(pelicula->directores, director)) //SI EXISTE
        list_pushBack(lista, pelicula); 
      pareja = map_next(mapaID);
    }
    map_insert(mapaDirector, director, lista);
    director = (char *) list_next(directores);
  }
}

// Crea un mapa que relaciona cada década con las películas que fueron lanzadas en esa década.
void crearMapaPorDecada(Map *mapaID, Map *mapaDecada, List* decadas)
{
  int *decada = (int *) list_first(decadas);
  while(decada != NULL)
  {
    List *lista = list_create();
    MapPair *pareja = map_first(mapaID);
    while(pareja != NULL)
    {
      tipoPelicula *pelicula = (tipoPelicula *)pareja->value;
      if( (*decada) <= pelicula->fecha &&  pelicula->fecha <= ((*decada)+10) )
        list_pushBack(lista, pelicula);
      pareja = map_next(mapaID);
    }
    map_insert(mapaDecada, decada, lista);
    decada = (int *)list_next(decadas);
  }
}

// Crea un mapa que relaciona cada rango de clasificación con las películas que tienen esa clasificación.
void crearMapaPorClasificacion(Map *mapaID, Map *mapaClasificacion, List* clasificaciones)
{
  float *clasificacion = (float *) list_first(clasificaciones);
  while(clasificacion != NULL)
  {
    List *lista = list_create();
    MapPair *pareja = map_first(mapaID);
    while(pareja != NULL)
    {
      tipoPelicula *pelicula = (tipoPelicula *)pareja->value;
      if( (*clasificacion) <= pelicula->clasificacion && pelicula->clasificacion <= ((*clasificacion)+0.4) )
        list_pushBack(lista, pelicula);
      pareja = map_next(mapaID);
    }
    map_insert(mapaClasificacion, clasificacion, lista);
    clasificacion = (float *)list_next(clasificaciones);
  }
}

// Carga las películas desde un archivo CSV seleccionado por el usuario.
tipoTDAs *cargarPeliculas()
{
  tipoTDAs *TDAs = inicializarTDAs();
  
  limpiarPantalla();
  //Preguntar al usuario que opcion de csv va a querer
  int opcion = 0;
  AZUL
  printf("Elige que documento csv quieres cargar\n");
  printf("(1) IMDbTop250\n");
  printf("(2) Top1500\n");
  fscanf(stdin, "%i", &opcion);
  limpiarBuffer();

  //Si el usuario ingresa una opcion valida se abre el archivo sino se retorna al main
  FILE *archivo = NULL;
  if(opcion == 1)
    archivo = fopen("data/IMDbTop250.csv", "r");
  else if(opcion == 2)
    archivo = fopen("data/Top1500.csv", "r");

  if(archivo == NULL)
  {
    ROJO
    printf("el archivo no se pudo abrir o ingreso una opcion no valida\n");
    presioneTeclaParaContinuar();
    return NULL;
  }
  //se lee la primera linea del csv
  BLANCO
  char **campos = leer_linea_csv(archivo, ',');
  tipoPelicula *pelicula;

  //se leen todos los registros del csv y se almacenan en una estructura, para posteriormente ingresarlos a cada mapa correspondiente
  while( (campos = leer_linea_csv(archivo, ',')) != NULL)
  {
    pelicula = (tipoPelicula *) malloc(sizeof(tipoPelicula));
    pelicula->id = strdup(campos[1]);
    pelicula->titulo = strdup(campos[5]);
    pelicula->generos = convertirCadenaALista(campos[11]);
    pelicula->directores = convertirCadenaALista(campos[14]);
    pelicula->clasificacion = atof(campos[8]);
    pelicula->fecha = atoi(campos[10]);
    crearListaSinRepeticiones(TDAs->generos, pelicula->generos);
    crearListaSinRepeticiones(TDAs->directores, pelicula->directores);
    map_insert(TDAs->mapaID, pelicula->id, pelicula);
  }
  fclose(archivo);
  mostrarMapa(TDAs->mapaID);
  crearMapaPorGenero(TDAs->mapaID, TDAs->mapaGenero, TDAs->generos);
  crearMapaPorDirector(TDAs->mapaID, TDAs->mapaDirector, TDAs->directores);
  crearMapaPorDecada(TDAs->mapaID, TDAs->mapaDecada, TDAs->decadas);
  crearMapaPorClasificacion(TDAs->mapaID, TDAs->mapaClasificacion, TDAs->clasificaciones);
  presioneTeclaParaContinuar();
  return TDAs;
}

// Busca una película por su ID.
void buscarPorID(Map *mapa)
{
  printf("Ingrese la id para buscar la pelicula : ");
  char *id = (char *) malloc(sizeof(char) * 16);
  fscanf(stdin, "%16s", id);
  limpiarBuffer();

  MapPair *pareja = map_first(mapa);
  while(pareja != NULL) //se itera sobre el mapa
  {
    if(!strcmp(pareja->key, id))//si el id a buscar coindice con mi key se imprime la pelicula con esa key
    {
      tipoPelicula *pelicula = (tipoPelicula *)pareja->value;
      AZUL
      printf("PELICULA CON EL ID %s : \n-%s\n", id ,pelicula->titulo);
      BLANCO
      presioneTeclaParaContinuar();
      return;
    }
    pareja = map_next(mapa);
  }
  ROJO
  printf("PELICULA NO ENCONTRADA\n");
  BLANCO
  presioneTeclaParaContinuar();
}

// Busca películas por género.
void buscarPorGenero(Map *mapa, List *lista)
{
  AZUL
  printf("GENEROS :\n");
  mostrarListaC(lista);
  BLANCO
  printf("Ingrese un genero para buscar la/as pelicula/as : ");
  char *genero = (char *) malloc(sizeof(char) * 64);
  char *cadenaKey = (char *) malloc(sizeof(char) * 64);
  fscanf(stdin, "%63s", genero);
  limpiarBuffer();
  
  MapPair *pareja = map_first(mapa);
  while(pareja != NULL)//se itera sobre el mapa
  {
    cadenaKey = strdup((char *)pareja->key);
    mayusc(cadenaKey);
    mayusc(genero);
    if(!strcmp(cadenaKey, genero))//si el genero a buscar coindice con mi key se imprimen todas las peliculas con ese key
    {
      AZUL
      printf("PELICULAS CON EL GENERO %s:\n", genero);
      mostrarPeliculas(pareja->value);
      BLANCO
      presioneTeclaParaContinuar();
      return;
    }
    pareja = map_next(mapa);
  }
  ROJO
  printf("GENERO NO ENCONTRADO\n");
  BLANCO
  presioneTeclaParaContinuar();
}

// Busca películas por director.
void buscarPorDirector(Map *mapa, List *lista)
{
  AZUL
  printf("DIRECTORES :\n");
  mostrarListaC(lista);
  BLANCO
  printf("Ingrese un director para buscar la/as pelicula/as : ");
  char *director = (char *) malloc(sizeof(char) * 64);
  char *cadenaKey = (char *) malloc(sizeof(char) * 64);
  fscanf(stdin, "%63[^\n]s", director);
  limpiarBuffer();
  
  MapPair *pareja = map_first(mapa);
  while(pareja != NULL)//se itera sobre el mapa
  {
    cadenaKey = strdup((char *) pareja->key);
    mayusc(cadenaKey);
    mayusc(director);
    
    if(!strcmp(cadenaKey, director))//si el director a buscar coincide con mi key se imprimen todas las peliculas con ese key
    {
      AZUL
      printf("PELICULAS CON EL DIRECTOR %s:\n", director);
      mostrarPeliculas(pareja->value);
      BLANCO
      presioneTeclaParaContinuar();
      return;
    }
    pareja = map_next(mapa);
  }
  ROJO
  printf("DIRECTOR NO ENCONTRADO\n");
  BLANCO
  presioneTeclaParaContinuar();

}

// Busca películas por década.
void buscarPorDecada(Map *mapa, List* lista)
{
  AZUL
  printf("DECADAS :\n");
  mostrarListaI(lista);
  int decada;
  BLANCO
  printf("Ingrese una decada para buscar la/as pelicula/as : ");
  fscanf(stdin, "%i", &decada);
  limpiarBuffer();
  
  MapPair *pareja = map_first(mapa);
  while(pareja != NULL)//se itera sobre el mapa
  {
    if(*(int *)pareja->key == decada)//si la decada a buscar coincide con mi key se imprimen todas las peliculas con ese key
    {
      AZUL
      printf("PELICULAS CON LA DECADA %i :\n", decada);
      mostrarPeliculas(pareja->value);
      BLANCO
      presioneTeclaParaContinuar();
      return;
    }
    pareja = map_next(mapa);
  }
  ROJO
  printf("DECADA NO ENCONTRADA\n");
  BLANCO
  presioneTeclaParaContinuar();
}

// Busca películas por rango de clasificación.
void buscarPorClasificacion(Map *mapa)
{
  AZUL
  printf("(1) 5.0 - 5.4\n");
  printf("(2) 5.5 - 5.9\n");
  printf("(3) 6.0 - 6.4\n");
  printf("(4) 6.5 - 6.9\n");
  printf("(5) 7.0 - 7.4\n");
  printf("(6) 7.5 - 7.9\n");
  printf("(7) 8.0 - 8.4\n");
  printf("(8) 8.5 - 8.9\n");
  printf("(9) 9.0 - 9.4\n");
  printf("(10) 9.5 - 9.9\n");
  printf("(11) 10.0\n");
  BLANCO
  printf("Escoga alguna de los siguientes rangos de clasificacion : ");
  
  int opcion;
  fscanf(stdin, "%i", &opcion);
  limpiarBuffer();
  opcion -= 1;
  MapPair *pareja = map_first(mapa);
  while(pareja != NULL)//se itera sobre el mapa
  {
    float clasificacion = *(float *) pareja->key; //se lee el año de mi pelicula
    int clas = round( (clasificacion - 5.0) * 2); //se hace una operacion que transforma mi año a mi sistema de clasificacion
    if(clas == opcion)//si el rango de clasificacion a buscar coincide con mi key se imprimen todas las peliculas con ese key
    {
      AZUL
      printf("PELICULAS CON EL RANGO ELEGIDO:\n");
      mostrarPeliculas(pareja->value);
      BLANCO
      presioneTeclaParaContinuar();
      return;
    }
    pareja = map_next(mapa);
  }
  ROJO
  printf("ERROR ELEGISTE UN RANGO QUE NO EXISTE\n");
  BLANCO
  presioneTeclaParaContinuar();
}

// Busca películas por género y década.
void buscarPorDecadaYGenero(Map *mapaDecada, Map *mapaGeneros, List *decadas, List *generos)
{
  char *genero = (char *)malloc(sizeof(char) * 64);
  char *generoKey;
  int decada;
  AZUL
  printf("GENEROS :\n");
  mostrarListaC(generos);
  BLANCO
  printf("Ingrese el genero para buscar la/as pelicula/as : ");
  fscanf(stdin, "%63[^\n]s", genero);
  limpiarBuffer();

  AZUL
  printf("DECADAS :\n");
  mostrarListaI(decadas);
  BLANCO
  printf("Ingrese una decada para buscar la/as pelicula/as : ");
  fscanf(stdin, "%i", &decada);
  limpiarBuffer();

  MapPair *pareja = map_first(mapaGeneros);
  int cont = 0;
  
  while(pareja != NULL)//se itera sobre el mapa
  {
    generoKey = strdup((char *) pareja->key);
    mayusc(generoKey);
    mayusc(genero);
    
    if(!strcmp(generoKey, genero)) //si el genero a buscar coincide con mi generoKey continua con el siguiente paso que seria el de la decada
    {
      tipoPelicula *pelicula = (tipoPelicula *) list_first(pareja->value);
      while(pelicula != NULL) //se itera sobre la lista de peliculas de mi genero
      {
        if(decada <= pelicula->fecha && pelicula->fecha <= decada+10) //si la fecha de mi pelicula concide en el intervalo de mi decada entonces se imprime
        {
          if(cont == 0)//si es la primera pelicula que se encuentra se imprime este mensaje solo una vez
          {
            AZUL
            printf("PELICULAS CON EL GENERO %s y DECADA %i\n", genero, decada);
            cont++;
          }
          printf("-%s \n", pelicula->titulo);
        }
        pelicula = (tipoPelicula *) list_next(pareja->value);
      }
    }
    pareja = map_next(mapaGeneros);
  }
  ROJO
  if(cont == 0)
    printf("NO SE ENCONTRO EL GENERO Y/O LA DECADA\n");
  BLANCO
  presioneTeclaParaContinuar();
}

// Muestra el menú de opciones para el usuario.
void mostrarMenu()
{
  BLANCO
  printf("========================================\n");
  printf("     Base de Datos de Películas\n");
  printf("========================================\n");
  printf("(1) Cargar Peliculas\n");
  printf("(2) Buscar por id\n");
  printf("(3) Buscar por Genero\n");
  printf("(4) Buscar por Director\n");
  printf("(5) Buscar por Decada\n");
  printf("(6) Buscar por Rango de Clasificación\n");
  printf("(7) Buscar por Decada y Genero\n");
  printf("(8) Salir del Programa\n");
}

// Función principal del programa que ejecuta el bucle principal y llama a las funciones correspondientes según la opción seleccionada por el usuario.
int main(void)
{
  tipoTDAs *TDAs = NULL;
  int opcion = 0;
  
  while(1)
  {
    limpiarPantalla();
    mostrarMenu();
    printf("Ingrese una opcion : ");
    fscanf(stdin, "%i", &opcion);
    limpiarBuffer();
    if(opcion == 1)
      TDAs = cargarPeliculas();
    else if(opcion == 2)
      buscarPorID(TDAs->mapaID);
    else if(opcion == 3)
      buscarPorGenero(TDAs->mapaGenero, TDAs->generos);
    else if(opcion == 4)
      buscarPorDirector(TDAs->mapaDirector, TDAs->directores);
    else if(opcion == 5)
      buscarPorDecada(TDAs->mapaDecada, TDAs->decadas);
    else if(opcion == 6)
      buscarPorClasificacion(TDAs->mapaClasificacion);
    else if(opcion == 7)
      buscarPorDecadaYGenero(TDAs->mapaDecada, TDAs->mapaGenero, TDAs->decadas, TDAs->generos);
    else if(opcion == 8)
        break;
    else
    {
      printf("ERROR \ningrese una opcion valida\n");
      presioneTeclaParaContinuar();
    }
  }
  printf("Gracias por elegir nuestro servicio :D");
  return 0;
}
