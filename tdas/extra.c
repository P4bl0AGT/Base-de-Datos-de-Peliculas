#include "extra.h"

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 300

char **leer_linea_csv(FILE *archivo, char separador) {
  static char linea[MAX_LINE_LENGTH];
  static char *campos[MAX_FIELDS];
  char *ptr, *start;
  int idx = 0;

  if (fgets(linea, MAX_LINE_LENGTH, archivo) == NULL) {
    return NULL; // No hay más líneas para leer
  }

  // Eliminar salto de linea
  linea[strcspn(linea, "\n")] = '\0';

  ptr = start = linea;
  while (*ptr) {
    if (idx >= MAX_FIELDS - 1)
      break;

    if (*ptr == '\"') { // Inicio de un campo entrecomillado
      start = ++ptr;    // Saltar la comilla inicial
      while (*ptr && !(*ptr == '\"' && *(ptr + 1) == separador))
        ptr++;
    } else { // Campo sin comillas
      start = ptr;
      while (*ptr && *ptr != separador)
        ptr++;
    }

    if (*ptr) {
      *ptr = '\0'; // Reemplazar comilla final o separador por terminación
      ptr++;
      if (*ptr == separador)
        ptr++;
    }

    // Quitar comilla final si existe
    if (*(ptr - 2) == '\"') {
      *(ptr - 2) = '\0';
    }

    campos[idx++] = start;
  }

  campos[idx] = NULL; // Marcar el final del array
  return campos;
}

// Función para limpiar la pantalla
void limpiarPantalla() { system("clear"); }

void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  //getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

void borrarComillas(char *str) { 

    int len = strlen(str); //Obtenemos la longitud de la cadena

    if (str[0] == '"') { //SI el primer carácter es una comilla:

        memmove(str, str + 1, len); //Movemos el inicio de la cadena a un espacio a la derecha

        len--; //Bajamos en 1 el tamaño de la cadena

    }

    if (len > 0 && str[len - 1] == '"') { //Si el último carácter es una comilla

        str[len - 1] = '\0'; //Lo cambiamos al carácter nulo para que ahí termine la cadena.

    }

}

char *espacioInicial(char *str) {

    while (isspace((unsigned char)*str)) str++; //Mientras el primer carácter es un espacio, avanzamos el puntero del inicio de la cadena

    return str; //Retornamos la cadena cambiada

}

void limpiarBuffer()
{
  while(getchar() != '\n');
}

void mayusc(char *cadena)
{
  while( (*cadena) != '\0' )
  {
    *cadena = toupper(*cadena);
    cadena++;
  }
  *cadena = '\0';
}

List *convertirCadenaALista(char *cadena)
{
  borrarComillas(cadena);
  List *lista = list_create();
  char *token = strtok(cadena, ",");
  while(token != NULL)
  {
    char *tokenLimpio = espacioInicial(token);
    list_pushBack(lista, strdup(tokenLimpio));
    token = strtok(NULL, ",");
  }
  return lista;
}