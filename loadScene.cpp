#include "loadScene.hpp"


float* loadRow(char* line, int num)
{
    const char* tok;
    float tab[3];
    tok = strtok(line, ";");
    tab[0] = atof(tok);
    tok = strtok(NULL, ";");
    tab[1] = atof(tok);
    tok = strtok(NULL, ";");
    tab[2] = atof(tok);
    tok = strtok(NULL, ";");
    tab[3] = atof(tok);



    return tab;
}

void loadScene()
{
    FILE* stream = fopen("test.csv", "r");

    char line[1024];
    int i=10;
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        float *ftemp ;
        ftemp= loadRow(tmp,1);
        world_map[i][0]=ftemp[0];
        world_map[i][1]=ftemp[1];
        world_map[i][2]=ftemp[2];
        world_map[i][3]=ftemp[3];
        free(tmp);
        if(i++ > 15384)break;
    }
}