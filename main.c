#include <stdio.h>
#include "descifrado.h"
int main() {
    const char *archivoCifrado = "cifrado.txt";
    const char *archivoDescifrado = "descifrado.txt";
    const char *clave = "miClaveSecreta";

    int i = descifrarArchivo(archivoCifrado, archivoDescifrado, clave);

    if (i == 0){
        printf("Archivo descifrado exitosamente\n");
    }else{
        printf("No se pudo descifrar el archivo\n");
    }

    return 0;
}
