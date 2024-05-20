#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h> 

void RotationN(char *vet, int n);
void notRotationN(char *vet, int n);
void makeChord(char *chord, char *scale, int note, char fundamental);

char notes[] = {'C', 'c', 'D', 'd', 'E', 'F', 'f', 'G', 'g', 'A', 'b', 'B'};
int scaleM[] = {0, 2, 4, 5, 7, 9, 11};
int scalem[] = {0, 2, 3, 5, 7, 8, 10};

int main(int argc, char **argv){

    srand(time(NULL));
    
    char *scale = malloc(7*sizeof(char));

    if(argc < 2){
        printf("correct usage: fundamental, min(1)/maj(0)");
    }

    int flag = 1;

    while(flag){
        if(notes[0] != *argv[1]){
            RotationN(notes, 12);
        }else{
            flag = 0;
        }     
    }

    if(*argv[2] == '0'){
        for (int j = 0; j < 7; j++)
        {
            scale[j] = notes[scaleM[j]];
        }
    }else{
        for (int j = 0; j < 7; j++)
        {
            scale[j] = notes[scalem[j]];
        }
    }

    char *chord = malloc(7*sizeof(char));
    int othersO[] = {1, 2, 3, 5, 6};
    int size = 5;
    int others[size];

    for (int i = 0; i < 4; i++)
    {
        if(i==0){
            for (int j = 0; j < size; j++)
            {
                others[j] = othersO[j];
            }
            
            makeChord(chord, scale, 0, *argv[1]);
            printf("%s\n", chord);
        }else if(i==3){
            makeChord(chord, scale, 4, *argv[1]);
            printf("%s\n", chord);
        }else{
            int p = (rand() % size+1) - 1;
            makeChord(chord, scale, others[p], *argv[1]);
            printf("%s\n", chord);
            for (int k = p; k < size - 1; k++)  
            {  
                others[k] = others[k + 1];  
            }  
            size--;
        }
    }
    
    
    return 0;
}

void RotationN(char *vet, int n){
    char tmp = vet[0];
    int i = 0;
    while(i<n-1){
        vet[i] = vet[i+1];
        i++;
    }
    vet[n-1] = tmp;
}

void notRotationN(char *vet, int n){
    char tmp = vet[n-1];
    int i = n-1;
    while(i>0){
        vet[i] = vet[i-1];
        i--;
    }
    vet[0] = tmp;
}

void makeChord(char *chord, char *scale, int note, char fundamental){
    
    for (int i = 0; i < note; i++)
    {
        RotationN(scale, strlen(scale));
    }

    chord[0] = scale[0];
    chord[2] = scale[4];
    
    //3rd or 4th
    int p = rand() % 100;
    if(p > 10){
        chord[1] = scale[2];
    }else{
        chord[1] = scale[3];
    }

    //7th or not
    p = rand() % 100;
    if(p > 80){
        chord[3] = scale[6];
    }else if(p > 90){
        //9th
        chord[4] = scale[1];
        p = rand() % 100;
        //11th
        if(p > 80){
            chord[5] = scale[3];
        }
        //13th
        if(p > 90){
            chord[6] = scale[5];
        }
    }

    for (int i = 0; i < note; i++)
    {
        notRotationN(scale, strlen(scale));
    }

}