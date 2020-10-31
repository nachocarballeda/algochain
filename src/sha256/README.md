## SHA256: implementación en C++

El código fuente que acompaña este documento contiene la implementación de referencia de la función de hash SHA256 que emplearemos a lo largo de los trabajos prácticos.

### Modo de uso

La función `sha256` recibe un `std::string` con caracteres arbitrarios y devuelve otro `std::string` formado por los 64 dígitos hexadecimales que representan el hash SHA256 de la entrada. Para utilizarla, se debe incluir el header `sha256.h` en nuestro archivo fuente:
```
#include "sha256.h"
...
std::string hash, input("Sarasa.");
hash = sha256(input);
...
```

No olvidar incluir el archivo fuente `sha256.cpp` en el proceso de compilación de nuestros programas.

### Ejemplos

Se adjunta también un programa con fines ilustrativos que permite calcular hashes SHA256 a través de esta implementación. La entrada consiste en cadenas de caracteres arbitrarias sin espacios:

```
$ make
g++ -Wall -c main.cpp -o main.o 
g++ -Wall -c sha256.cpp -o sha256.o 
g++ -Wall -c cmdline.cc -o cmdline.o 
g++ -Wall -o sha256 main.o sha256.o cmdline.o
rm -f *.o
$ ./sha256 -i Sarasa.
input: Sarasa.
output: 9c231858fa5fef160c1e7ecfa333df51e72ec04e9c550a57c59f22fe8bb10df2
```
