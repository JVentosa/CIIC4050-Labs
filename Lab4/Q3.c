/*
Investiga cómo funcionan los syscalls gepid y getppid.
Ayuda: Busca los archivos getpid.c y getppid.c.
Utiliza lo aprendido en el laboratorio para encontrar
las demás partes de la implementación de estos
syscalls a partir del nombre de las mismas.


directory:

/usr/src/lib/libc/sys-minix/getpid.c OR getppid.c
Answer:
-getpid: implementacion POSIX que utiliza wrappers para saber
si existe un proceso mediante el mismo process id.
Si el proceso no exista, devuelve un -1.

-getppid: implementacion POSIX que devuelve un numero mayor que 0 si existe un
process id del parent id.
Si el proceso no exista, devuelve un -1.
*/