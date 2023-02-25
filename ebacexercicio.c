#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsavel por cuidar dos string

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
    //Inicio da criação de variável/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação das variáveis/string
    
    printf("Digite o CPF a ser cadastrado:  ");//Coletando informações do usuário
    scanf("%s", cpf);//%s refere-se a string
    
    strcpy(arquivo, cpf);//responsavel por copiar os valores dos string
    
    FILE *file;//cria o arquivo
    file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
    fprintf(file,cpf);//salva o valor da variavel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//abre o arquivo e o "a" altera as informações
    fprintf(file,",");//salva o valor da variavel
    fclose(file);//fecha o arquivo
    
    printf("Digite o nome a ser cadastrado:  ");//Coleta as informações de usuarios
    scanf("%s", nome);//Busca a string
    
    file = fopen(arquivo, "a");//Abre o arquivo e altera
    fprintf(file,nome);//salva o valor da variável
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//Abre o arquivo e altera
    fprintf(file,",");//salva o valor da variável
    fclose(file);//fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado:  ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:  ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta()//Função responsavel por consultar dados salvos
{
    setlocale(LC_ALL,"portuguese");//Definindo a Linguagem
    
    //Inicio da criação da variável/string
    char cpf[40];
    char conteudo[200];
    //fim da criação da variável/string
    
    printf("Digite o CPF a ser consultado: ");//coleta informações
    scanf("%s", cpf);//busca a string
    
    FILE *file;//consulta o arquivo
    file = fopen(cpf, "r");//abre o arquivo e o "r" é para ler
    
    if(file == NULL)//Se a informações for "==" igual ou igual a "NULL" nulo
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }
    
    while(fgets(conteudo, 200, file) != NULL);//enquanto, buscar, conteudo, 200 vezes, arquivo. interrompe !=NULL
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);//salva o valor da string
        printf("\n\n");//pula linha, uma para cada \n
    }
    
    system("pause");
} 

int deletar()//Função responsavel por deletar
{
    //inicio da criação da variavel
    char cpf[40];
    //fim fa criação da variavel
    
    printf("Digite o CPF a ser deletado: ");//coleta informações
    scanf("%s",cpf);//buscar a string
    
    remove(cpf);
    
    FILE *file;//consulta o arquivo
    file = fopen(cpf,"r");//abre e lê o arquivo
    
    if(file == NULL)//se não achar
    {
        printf("O usuário não se encontra no sistema.\n");
        system("pause");
    }


int main()
{
    int opcao=0;
    int laco=1;
    char senhadigitada[10]="a";
    int comparacao;
    
    printf("### Cartório da Ebac ###\n\n");
    printf("login de administrador!\n\nDigite sua senha: ");
    scanf("%s",senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    
    If(comparacao == 0);
    {
        
        system("cls");
        for(laco*1;laco*1;)//laço de repetição
        {
            system("cls");
        
            setlocale(LC_ALL, "portuguese");
            printf("###Cartório da Ebac###\n\n");
            printf("Escolha a opção desejada no menu:\n\n");
            printf("\t1-Registrar nomes\n");
            printf("\t2-Consultar nomes\n");
            printf("\t3-Deletar nomes\n\n");
            printf("\t4-Sair do sistema\n\n");
            printf("opcao: ");
        
            scanf("%d", &opcao);
        
            system("cls");//responsavel por limpar a tela
        
            switch(opcao)//inicio da seleção do menu
            {
                case 1:
                registro();//chamada de funções
                break;
            
                case 2:
                consulta();
                break;
            
                case 3:
                deletar();
                break;
                
                case 4:
                printf("Obrigado por usar o sistema!\n");
                return 0;
                break;
            
                default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
            }//fim da seleção
        }
    }
    
    else
        printf("Senha incorreta!");
        
}