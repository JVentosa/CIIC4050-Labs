/*
Implementa un syscall que devuelva el id de
un proceso o el de su parent en función de un
parámetro recibido por la librería de usuario.
Para ello define dos constantes en dicha librería (CURRENT = 1, PARENT = 2),
dependiendo de la constante reciba retorne el valor correspondiente.
La llamada debe usar el tipo de mensaje M4.

Incluye en la contestación las definiciones de las funciones

//int my_getpid() { /* system call */
//}

// int mygetpid(long integer) { /* user library */
//}

/*
en ese orden, según las definiste y las probaste en tu copia de minix.
Incluye también las definiciones (#define) de CURRENT y PARENT y úsalas en tu código.
No debes setear mp_reply.


directory:
/usr/src/lib/libc/sys-minix/getpid.c OR getppid.c

*/

#define CURRENT 1
#define PARENT 2

int my_getpid()
{
    if (m_in.m4_l1 == 1)
    {
        return mproc[who_p].mp_pid;
    }
    return mproc[mp->mp_parent].mp_pid;
}

int mygetpid(long integer)
{
    message m;
    m.m_type = M4;
    m.m4_l1 = integer;
    return _syscall(PM_PROC_NR, MYCALL, &m);
}