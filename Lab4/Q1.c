/*
Analiza el archivo /usr/src/include/minix/ipc.h (Struct message)

Modifica el recién creado system call para recibir e imprimir un parámetro de tipo long a través de la estructura “message” (el archivo System_Calls_in_Minix.pdf puede ser de ayuda). Desde el archivo de test se debe enviar el parámetro a la librería de usuario creada en el ejercicio anterior está a su vez envía el parámetro al syscall.  Tu librería debe utilizar el mensaje tipo M4.

El system call debe imprimir el número arbitrario que le envía el código de usuario por medio de la librería.  El formato de la salida debe ser:

Hola! El número es: <número>

donde <número> es el valor del parámetro enviado a la librería por medio del mensaje.

Incluye en la contestación las definiciones de las funciones

int do_mycall() {
}

int mycall(long integer) {
}
en ese orden, según las definiste y las probaste en tu copia de minix.
*/

/* Edit and Add this in the updated misc.c file in MINIX3
Directory:
 /usr/src/servers/pm/misc.c
*/
int do_mycall()
{
    long number = m_in.m4_l1;
    printf("Hola! El número es: %ld\n", number);
    return 0;
}

int mycall(long integer)
{
    message m;
    m.m_type = M4;
    m.m4_l1 = integer;
    return _syscall(PM_PROC_NR, MYCALL, &m);
}
