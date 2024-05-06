#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

// Declaración de la función para mostrar una lista de cadenas
void mostrarListaC(List *lista);

// Declaración de la función para mostrar una lista de enteros
void mostrarListaI(List *lista);

// Declaración de la función para verificar si una cadena existe en una lista
int noExiste(List *lista, char *cadenaEncontrar);