void generate_SIGSEGV()
{

    char *test = "sigSegv";

    test[100] = 'f';
}

void generate_SIGFPE()
{
    int a = 0;
    int b = 2;
    int c = b / a;
    a = c;
}