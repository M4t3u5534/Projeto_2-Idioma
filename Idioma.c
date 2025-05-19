// Mateus Ribeiro Cerqueira - 10443901
// Pedro Henrique Carvalho Pereira - 10418861

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // toupper()

int main(){
    // Criação do vetor para contar a quantidade de letras e para input da frase digitada
    int letras[26] = {0};
    char frase[200] = {' '};
    printf("Digite uma frase: ");
    fgets(frase, 200, stdin);

    int i = 0;
    int tamanho = 0;
    int letra;

    // loop para ler a frase e incrementar a quantidade de letras no vetor
    while(frase[i] != '\0'){
        letra = toupper(frase[i]);
        if(letra >= 65 && letra <= 90){
            letras[letra - 65]++;
            tamanho++;
        }
        i++;
    }

    float f_portugues[26] = {14.63, 1.04, 3.88, 4.99, 12.57, 1.02, 1.30, 1.28, 6.18, 0.40, 0.02, 2.78, 4.74, 5.05, 10.73, 2.52, 1.20, 6.53, 7.81, 4.34, 4.63, 1.67, 0.01, 0.21, 0.01, 0.47};
    float f_ingles[26] =   {8.17,  1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07};
    float porx_port = 0, porx_ingl = 0;
    float porc;

    // loop para calcular a proximidade da frase com o português e com o inglês 
    for (int i = 0; i < 26; i++)
    {
        if (tamanho > 0)
            porc = letras[i] * 100.0 / tamanho;
        else
            porc = 0;

        // cálculo da diferença absoluta 
        if (porc - f_portugues[i] >= 0)
            porx_port += (porc - f_portugues[i]);
        else
            porx_port += -(porc - f_portugues[i]);

        if (porc - f_ingles[i] >= 0)
            porx_ingl += (porc - f_ingles[i]);
        else
            porx_ingl += -(porc - f_ingles[i]);
    }

    // garante que diferênça de proximidade entre os idiomas não seja muito pequena
    if ((porx_port - porx_ingl >= -1.0) && (porx_port - porx_ingl <= 1.0))
    {
        printf("As porcentagens das letras nas frases estão muito proximas em ambos os idiomas, não é possivel concluir com precisão\n");
        printf("Uma frase maior é recomendada para melhor avaliação do idioma!");
    }
    else
    {
        // comparação das proximidades 
        if(porx_port < porx_ingl)
            printf("O idioma da frase e o portugues");
        else
            printf("O idioma da frase e o ingles");
    }

    return 0;
}