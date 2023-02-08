// Add handler functions here
void sigint_handler(int signame)
{
    printf("Received signal SIGINT!!!");
}
void sigquit_handler(int sigquit)
{
    printf("Received signal SIGQUIT!!!");
}
void sigterm_handler(int sigterm)
{
    printf("Received signal SIGTERM!!!");
}
void sigfpe_handler(int sigfpe)
{
    printf("Received signal SIGFPE!!!");
}
void sigsegv_handler(int sigsegv)
{
    printf("Received signal SIGSEGV!!!");
}
void sigill_handler(int sigill)
{
    printf("Received signal SIGILL!!!");
}
void setup_signal_handlers()
{
    // Setup handlers here
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGTERM, sigterm_handler);
    signal(SIGFPE, sigfpe_handler);
    signal(SIGSEGV, sigsegv_handler);
    signal(SIGILL, sigill_handler);
}