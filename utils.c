//escrever em ficheiro csv
void escreverFicheiroCSV(char *nomeFicheiro, char *texto)
{
    FILE *ficheiro;
    ficheiro = fopen(nomeFicheiro, "a");
    fprintf(ficheiro, "%s", texto);
    fclose(ficheiro);
}

// RELOGIO

typedef struct
{
    time_t START;
    time_t STOP;
    int VELOCIDADE;
    time_t Hora_Inicio;
}Relogio;

void StartRelogio(Relogio *R, int Vel, const char *H_Inicio)
{
    R->START = time(0);
    R->VELOCIDADE = Vel;
    struct tm *tmp = localtime(&R->START);
    sscanf(H_Inicio, "%d:%d:%d", &tmp->tm_hour, &tmp->tm_min, &tmp->tm_sec);
    R->Hora_Inicio = mktime(tmp);
    printf("Hora de Arranque = [%s]\n", asctime(localtime(&(R->Hora_Inicio))));
}


void ResumeRelogio(Relogio *R) {
    R->Hora_Inicio = R->STOP;
    R->START = time(0);
    R->STOP = 0;
}

time_t VerTimeRelogio(Relogio *R)
{
    time_t Dif = difftime(time(0), R->START);
    time_t Simulada = R->Hora_Inicio + Dif * R->VELOCIDADE;
    return Simulada;
}

void StopRelogio(Relogio *R) {
    R->STOP = VerTimeRelogio(R);
}

void WaitSegundos(Relogio *R, int s)
{
     int tempoEspera = (s * 1000000) / R->VELOCIDADE; // tempoEspera está em microssegundos
    usleep(tempoEspera);
}