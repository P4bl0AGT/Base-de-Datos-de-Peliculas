#include "mostrar.h"

// Función para mostrar una lista de cadenas

void mostrarListaC(List *lista) 
{
  char *cadena = (char * ) list_first(lista); // Obtiene el primer elemento de la lista
  int cont = 0; 
  printf("[");
  while(cadena != NULL)
  {
    if(cont == 0)
    {
      printf("%s", cadena);
      cont = 1;
      cadena = list_next(lista);
      continue;
    }
    printf(", %s", cadena);
    cadena = list_next(lista);
  }
  printf("]\n");
}

// Función para mostrar una lista de enteros

void mostrarListaI(List *lista)
{
  int *numero = (int * ) list_first(lista);
  int cont = 0;
  printf("[");
  while(numero != NULL)
  {
    if(cont == 0)
    {
      printf("%i", *numero);
      cont = 1;
      numero = list_next(lista);
      continue;
    }
    printf(", %i", *numero);
    numero = list_next(lista);
  }
  printf("]\n");
}

// Función para verificar si una cadena existe en una lista

int noExiste(List *lista, char *cadenaEncontrar)
{
  char *cadena = (char *)list_first(lista);
  while(cadena != NULL)
  {
    if(strcmp(cadena, cadenaEncontrar) == 0) //SI SON IGUALES EXISTE
      return 0;
    cadena = (char *)list_next(lista);
  }
  return 1;
}