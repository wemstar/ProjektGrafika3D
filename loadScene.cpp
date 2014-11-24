#include "loadScene.hpp"


float* loadRow(char* line, int num)
{
    const char* tok;
    float tab[2];
    tok = strtok(line, ";");
    tab[0] = atof(tok);
    tok = strtok(NULL, ";");
    tab[1] = atof(tok);



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

printf("Field 3 would be %f %f\n",world_map[i][0],world_map[i][1]);
        free(tmp);
        if(i++ > 1000)break;
    }
}