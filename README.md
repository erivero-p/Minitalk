# Minitalk
Un pequeño programa de intercambio de datos utilizando señales de UNIX

<h3>Project Tree</h3>

```
.
├── Makefile
├── libft/
├── client.c
├── client_bonus.c
├── server.c
└── server_bonus.c
```
# Tutorial para hacer tu propio Minitalk

## Información previa de utilidad

En el subject piden dos programas: cliente y servidor. El cliente enviará una string al servidor, que la mostrará y terminará. La comunicación entre ambos debe ser sólo con señales UNIX, concretamente con ```SIGUSR1``` y ```SIGUSR2```.

### Señales Unix

Las señales son una forma de interactuar con un proceso en los sistemas unix. Por ejemplo, cuando usamos ```^C``` para terminar un proceso. En este caso, ```SIGUSR1``` y ```SIGUSR2``` son señales personalizables. Nosotros elegiremos qué sucede cuando se recibe cada señal.

El orden de los eventos, según lo indicado en el subject, será:

- Se lanza el servidor y muestra su PID
- Se lanza el cliente, que tomará como parámetros la PID del servidor y una string.
- El cliente comunica la string al servidor.
- El servidor la recibe y la muestra.

El ***PID*** (Process IDentifier) es un número entero asignado a un proceso en un sistema operativo, para distinguirlo de otros procesos. Lo necesitaremos para enviar señales a ese proceso. En C, el tipo de dato utilizado para representar un PID es `pid_t`. Está definido en `<signal.h>`. Podré obtener el PID de un proceso con la función `getpid`, incluida en `<unistd.h>`. 

### Funciones autorizadas

Además de write, malloc, free, ft_printf o cualquiera de libft.h, y getpid, ya mencionada, me permiten usar:

- **pause**: Hace que el programa se pare hasta recibir una nueva señal.
- **kill** (`int kill(pid_t pid, int sig);`): Envía una señal a un proceso determinado. Si falla devolverá -1, si funciona correctamente, devuelve 0.
- **signal**: establece cómo se debe manejar una señal específica. Toma dos argumentos: el número de la señal a manejar, y un puntero a una función que actuará como el manejador de la señal.
- **sigemptyset** (`int sigemptyset(sigset_t *set);`): inicializa (”vacía”) un conjunto de señales, preparándolo para su posterior manipulación. Recibe un puntero a una variable tipo `sigset_t`, que representa el conjunto de señales. Devuelve 0 si funciona bien, y -1 en caso de error.
- **sigaddset** (`int sigaddset(sigset_t *set, int signum);`): Agrega una señal específica *signum* a un conjunto de señales *set*.
- **sigaction**:es como una versión de signal más compleja, hace falta para el bonus.   
- ******sleep****** (`unsigned int sleep(unsigned int seconds);`): Suspende la ejecución de un programa durante un número específico de segundos. Devuelve el número de segundos no dormidos, que será 0 si la función tiene éxito.
- ************usleep************ (`int usleep(useconds_t microseconds);`):  Suspende la ejecución de un programa durante un número específico de microsegundos. Devuelve 0 en caso de éxito y -1 en caso de error.
- **********exit********** (`void exit(int status);`): Finaliza de forma controlada la ejecución de un programa en cualquier punto. Recibe un int con el estado de salida del programa.

## Mandatory Part

### client.c

El cliente debe enviar, con señales unix, un string de caracteres al servidor. Por tanto, el `main` de mi cliente debe estar preparado para recibir argumentos, y mi función para enviar los bits (`send_bits`), deberá recibir un `int` con el pid del servidor. Además, deberá recibir un caracter, o bien una string de caracteres, dependerá de cómo queramos realizarlo.  En mi caso, mi main llama a `send_bits` con cada caracter.

Cada caracter ocupa un byte, y por tanto, estará formado por un octeto de bits. Para poderlos enviar, debemos saber [cómo trabajar con bits.](https://github.com/erivero-p/42-Tutorials/tree/master/Bits%20For%20Dummies) 

### server.c

El servidor, antes de nada, deberá mostrar por pantalla su `PID`, que obtendremos con `getpid`, y entrar en un bucle que mantenga el programa abierto. También deberá llamar a la función `signal` con las dos señales que puede recibir en este caso `SIGUSR2` y `SIGUSR1`, y con la función que creemos para el manejo de esas señales. 

La función para el manejo de las señales, será llamada cada vez que recibamos una señal, es decir, por cada caracter, la llamaremos 8 veces. Por tanto, debemos trabajar con variables estáticas que se acumulen en cada llamada. Cada 8 llamadas, deberemos mostrar por pantalla el caracter que hayamos acumulado, y reiniciar las variables estáticas.

## Bonus Part

- El servidor confirma cada señal recibida mandando una señal al cliente.
- Soporta los caracteres unicode.

### client_bonus.c

El cliente, además de hacer lo que hacía anteriormente, deberá estar preparado para recibir señales y mostrarlas por pantalla. La forma más sencilla de mostrarlas por pantalla, será directamente en binario, pero se puede hacer de otras formas. Sólo necesitamos demostrar que el servidor está enviando confirmación de haber recibido las señales.

Para recibir las señales, igual que lo hacíamos en server.c, tendremos que llamar a la función `signal`. 

### server_bonus.c

El servidor necesita obtener el PID del cliente para poderle enviar señales. Si en lugar de utilizar `signal`, utilizamos `sigaction` podemos solucionarlo. Entre sus argumentos, `sigaction` recibe un puntero a una estructura, que dentro de sus campos, entre otros, tiene un puntero a otra estructura, llamada `siginfo_t`, en esta tendremos información detallada sobre una señal en específico, entre otros, contiene un entero `si_pid`, con el PID del proceso que envió la señal que estamos recibiendo.

¿Cuando ejecutas más de una vez client_bonus.c para enviarle señales al server hay problemas? Una pista, a lo mejor tienes que vaciar cierta máscara…
