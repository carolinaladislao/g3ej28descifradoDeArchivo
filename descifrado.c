
//

#include "descifrado.h"
#include <stdlib.h>
#include<stdio.h>
#include <string.h>

int descifrarArchivo(const char *archivoCifrado, const char *archivoDescifrado, const char *clave) {

    FILE * entrada = fopen(archivoCifrado, "rb");
    FILE * salida = fopen(archivoDescifrado, "wb");

    if (entrada == NULL || salida == NULL) {
        perror("Error al abrir los archivos");
        if (entrada != NULL) fclose(entrada);
        if (salida != NULL) fclose(salida);
        return -1;
    }

    size_t claveLen = strlen(clave);
    int i = 0;
    int byte;

    // Leer cada byte, aplicarle XOR con la clave y escribir en el archivo de salida
    while ((byte = fgetc(entrada)) != EOF) {
        fputc(byte ^ clave[i % claveLen], salida);
        i++;
    }

    printf("Archivo descifrado correctamente.\n");

    fclose(entrada);
    fclose(salida);

    return 0;
}
