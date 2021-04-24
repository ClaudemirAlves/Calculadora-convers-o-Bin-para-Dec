//Aqui importamos as bibliotecas necessárias para a execução do programa.
//stdio é necessária para realizar os input e output durante o programa.
//math é necessária para realizar algumas operações matemáticas, tais como pow(a, b).
#include<stdio.h>
#include<math.h>

//Aqui temos a "função main()", 
//que serve como "menu principal" da calculadora e fornece ao usuário as opções de conversão.
//Com uma série de condicionais "if",
//é possível "encaminhar" o usuário para uma parte específica do programa, 
//de acordo com a opção escolhida por ele.
//Também através do condicional "if", o usuário pode encerrar a calculadora.
//A condição "if (opcao < 1 or opcao > 3) " garante que qualquer número digitado 
//além das opções propostas será dado como "opção inválida".
//Além disso, nos "ifs" (exceto aquele que encerra o programa), 
//temos a função "main()" para garantir o retorno do usuário ao "menu principal".
int main(){ //função "main()" sempre recebe tipo int.
    int opcao; //"opcao" também recebe tipo "int", pois serão aceitos números inteiros apenas.
    printf("Bem vindo a calculadora de conversao de binario para decimal e vice-versa!");
    printf("Se voce quer transformar binario para decimal, digite 1. Se quer o contrario, digite 2. Se quer sair, digite 3");
    scanf("%d", &opcao);
    //Funções "printf", e "scanf" servem para, respectivamente, "imprimir" mensagens na tela 
    //e permitir inputs do usuário do programa.
    
    if (opcao == 1){
        int DecFinal = 0; int expoente = 0; int Potencia = 0; int Bin = 0; int resto = 0; int Dec = 0;
        //Acima foram declaradas as variáveis utilizadas, além da atribuição de seus tipos e valores.
        printf("Digite um numero binario.");
        scanf("%i", &Bin);
        while (Bin != 0){ //Estrutura de repetição "while", que faz o compilador percorrer uma parte
        //                  do programa enquanto uma condição for atendida.
            resto = Bin % 10; //"Bin % 10" divide o Bin por 10 e guarda o resto da divisão na variável "resto".
            Bin = Bin /= 10; //"Bin /= 10" divide o Bin por 10 e guarda a parte inteira da divisão nele mesmo.
            //                 Isso permite modificar constantemente o Bin, retirando partes dele.
            Potencia = pow(2, expoente); //"Potencia" recebe as potências de base 2 elevadas ao expoente "expoente".
            //                             A base 2 é usada porque a conversão de binário para decimal envolve a base binária no processo.
            //                             Aqui destaco também a função "pow(x, y)", que realiza o cálculo de potência.
            Dec = resto * Potencia; //"Dec" recebe a multiplicação do resto pela "Potencia", 
            //                        iniciando a construção do número em decimal.
            expoente = expoente + 1; //Incremento da variável "expoente", necessário para o cálculo do número decimal.
            DecFinal = DecFinal + Dec; //Número decimal construído a partir da adição sucessiva dos valores
            //                           presentes em "Dec".
            }
        printf("Numero em decimal: %d\n", DecFinal); //"Impressão" do resultado.
        main(); //Chama "main()", garantindo que o usuário não tenha que reiniciar o programa após cada conversão.
    }

    if (opcao == 2){ //Para a parte do código que converte decimal para binário, servem os mesmo comentários acima,
    //                 guardadas as devidas modificações óbvias.
        int BinFinal = 0; int expoente = 0; int Potencia = 0; int Dec = 0; int resto = 0; int Bin = 0;
        printf("Digite um numero decimal.");
        scanf("%i", &Dec);
        while (Dec != 0){
            resto = Dec % 2;
            Dec = Dec /= 2;
            Potencia = pow(10, expoente); //Aqui, por motivos óbvios, utiliza-se a base 10, já que os números a serem convertidos
            //                              estão na base decimal. 
            Bin = resto * Potencia;
            expoente = expoente + 1;
            BinFinal = BinFinal + Bin;
            }
        printf("Numero em binario: %d\n", BinFinal);
        main();
    }
    if (opcao == 3){ //Opção utilizada para encerrar o programa corretamente.
        printf("A calculadora sera encerrada"); 
    }
    if (opcao < 1 or opcao > 3){ //Estrutura que garante a utilização apenas dos números propostos no menu principal.
        printf("Opcao invalida!\n");
        main();
    }
}