#include <stdio.h>
#include <stdlib.h>

int main(){
    int letras[26] = {0};
    char frase[200] = {' '};
    printf("Digite uma frase: ");
    fgets(frase, 200, stdin);

    int i = 0;
    int tamanho = 0;
    int letra;
    while(frase[i] != '\0'){
        letra = toupper(frase[i]);
        if(65<=letra<=90){
            letras[letra-65]++;
        }
        i++;
        tamanho++;
    }

    float f_portugues[26] = {14.63, 1.04, 3.88, 4.99, 12.57, 1.02, 1.30, 1.28, 6.18, 0.40, 0.02, 2.78, 4.74, 5.05, 10.73, 2.52, 1.20, 6.53, 7.81, 4.34, 4.63, 1.67, 0.01, 0.21, 0.01, 0.47};
    float f_ingles[26] = {8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07};
    float erro_port, erro_ingl, erro_port1, erro_ingl1;
    float aux_port, aux_ingl;
    for(int i=0;i<26;i+=2){
        float porc1 = letras[i]/tamanho;
        erro_port1 = abs(porc1 - (f_portugues[i]-0.27));
        erro_ingl1 = abs(porc1 - f_ingles[i]);
        float porc2 = letras[i+1]/tamanho;
        aux_port = abs(porc2 - f_portugues[i+1]-0.27);
        aux_ingl = abs(porc2 - f_ingles[i+1]);
        erro_port = (((erro_port1 + aux_port)/2) + erro_port)/2;
        erro_ingl = (((erro_ingl1 + aux_ingl)/2) + erro_ingl)/2;
    }

    if(erro_port<erro_ingl){
        printf("O idioma da frase é o portugues");
    }else{
        printf("O idioma da frase é o ingles");
    }
    return 0;
}