//escrever em ficheiro csv
void escreverFicheiroCSV(char *nomeFicheiro, char *texto)
{
    FILE *ficheiro;
    ficheiro = fopen(nomeFicheiro, "a");
    fprintf(ficheiro, "%s", texto);
    fclose(ficheiro);
}