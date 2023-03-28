#include <stdio.h>
#include <stdlib.h>

int primo(int num){
    int p = 0;
    for (int i = 2; i < num ; i++){
        if(num % i == 0){
            p++;
            
            break;
        }
    }
    
    if(p == 0){
        return 1;
    }
    
    return 0;
}

int Arqui(){
    FILE *file;
    
    file = fopen("TURMAII10D.txt", "w");
    if(!file){
        printf("Erro ao abrir o ficheiro!");
        exit(1);
    }
    int numero = 2;
    fprintf(file, "%d", numero);
    fclose(file);
    return 0;
}

int Rand(int start, int max){
    int value = (rand()%max)+start;
    return value;
}

int main (){
    int i;    
    i = primo(103);
    int b[4];
    /*
    for(int z = 0; z < 4; z++){
        b[z] = Rand(1, 10);
    }
    
    for(int z = 0; z < 4; z++){
        printf("%d \n", b[z]);
    }
    Arqui();

    printf("\n \n %d", i);
    
    */    
    int mat[4][4];
    
    for(int y = 0; y < 4; y++){
        for(int w = 0; w < 4; w++){
            mat[y][w] = Rand(1,5);
        }
    }
    int maior = 0;
    for (int y = 4-1; y >= 0; y--){
        if(mat[y][(4-1)-y] > maior){
            maior = mat[y][(4-1)-y]; 
        }
    }
    printf("%d o maior \n", maior);
    
    for(int y = 0; y < 4; y++){
        for(int w = 0; w < 4; w++){
            printf("%d", mat[y][w]); 
        }
        printf("\n");
    }
    int aux[4];
    for(int y = 0; y < 4; y++){
        aux[y] = mat[3][y];
        mat[3][y] = mat[0][y]; 
        mat[0][y] = aux[y];
    }
    
    for(int y = 0; y < 4; y++){
        for(int w = 0; w < 4; w++){
            printf("%d", mat[y][w]);   
        }
        printf("\n");
    }
    
    return 0;
}
