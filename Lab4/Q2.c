/*
La variable global who_p contiene el index del proceso que invocó
el syscall en la tabla de procesos del PM (array mproc[NR_PROCS]).
 La variable global mp representa al proceso que invocó el system call.
  El array mproc[] puede ser accedido globalmente.
  Este contiene información de todos los procesos de usuario.
   Vea el archivo forkexit.c en el servidor pm para saber cómo puede recorrerlo.

La estructura de un proceso en el servidor PM contiene una estructura “message”
que puede utilizarse para retornar valores a la función que invocó el syscall.
 Algunos de sus campos son renombrados en el archivo param.h del PM.
 El loop principal del PM se encuentra en main.c

Teniendo en cuenta que la información de procesos del PM está contenida en /usr/src/servers/pm/mproc.h:

¿Puedes identificar 5 atributos de los procesos?
¿Qué flag que puede utilizarse para saber si un proceso está en uso.?

No hace falta contestar algo en este ejercicio.  El conocimiento adquirido en él será útil para resolver los siguientes.

Answer:
1. mp_exitstatus

2. mp_pid

3. mp_parent

4. mp_tracer

5. mp_flag



El flag mp_flag se puede utilizar para saber si es un proceso esta en uso
*/