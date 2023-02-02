#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include<string.h>
#include<conio.h>


typedef struct Paciente{
    char nome[50];
    char cpf[50];
    char sexo[20];
    char endereco[300];
    int cep;
    char rua[50];
    int num;
    char bairro[50];
    char cidade[50];
    char estado[50];
    char comorbidades[500];
    char email[300];
    int telefone;
    int dnasc, mnasc, anasc;
    int ddiag, mdiag, adiag;
    int idade;
    int codi;
    int urg;
    struct Paciente *prox;

}paciente;

typedef struct Listas{
    int qnt;
    struct Paciente *head;
}listas;

typedef struct Arvore{
    struct Paciente *No;
    struct Arvore *Esq;
    struct Arvore *Dir;
}arvore;

int pacientes = 0;

void adicionar(arvore **Arv, paciente *tmp);

listas* inicializarLista(){
    listas *tmp = (listas*)malloc(sizeof(listas));
    tmp->qnt = 0;
    tmp->head = NULL;
    return tmp;
}
//Cadastra os pacientes
void cadastrar_paciente(listas *tmp, arvore *Arv){
    int op_cadastro_paciente = 0;

    printf("\t\t-------------------------CADASTRO-------------------------\n\n");
    do{
        system("cls");
        paciente *aux = (paciente *)malloc(sizeof(paciente));
        printf("\tInforme o nome do paciente\n");
        printf("\tNome: ");
        fflush(stdin);
        gets(aux->nome);
        fflush(stdin);

        printf("\n\tInforme o CPF do paciente\n");
        printf("\tCPF: ");
        scanf(" %s", &aux->cpf);

        printf("\n\tInforme o telefone do paciente\n");
        printf("\tTelefone: ");
        scanf(" %d", &aux->telefone);
        fflush(stdin);

        printf("\n\tInforme o E-mail do paciente\n");
        printf("\tEmail: ");
        scanf(" %s", &aux->email);
        fflush(stdin);

        printf("\n\tInforme o dia de nascimento do paciente\n");
        printf("\tDia de Nascimento: ");
        scanf(" %d", &aux->dnasc);

        printf("\n\tInforme o mes de nascimento do paciente\n");
        printf("\tMes de Nascimento: ");
        scanf(" %d", &aux->mnasc);

        printf("\n\tInforme o ano de nascimento do paciente\n");
        printf("\tAno de Nascimento: ");
        scanf(" %d", &aux->anasc);

        printf("\n\tInforme o CEP do paciente\n");
        printf("\tCEP: ");
        scanf(" %d", &aux->cep);
        fflush(stdin);

        printf("\n\tInforme a rua do endereco do paciente\n");
        printf("\tRua: ");
        fgets(aux->rua, 50, stdin);
        fflush(stdin);
        aux->rua[strlen(aux->rua)-1]=0;

        printf("\n\tInforme o numero do endereco do paciente\n");
        printf("\tNumero: ");
        scanf(" %d", &aux->num);
        fflush(stdin);

        printf("\n\tInforme a bairro do endereco do paciente\n");
        printf("\tBairro: ");
        fgets(aux->bairro, 50, stdin);
        fflush(stdin);
        aux->bairro[strlen(aux->bairro)-1]=0;

        printf("\n\tInforme a cidade do endereco do paciente\n");
        printf("\tCidade: ");
        fgets(aux->cidade, 50, stdin);
        fflush(stdin);
        aux->cidade[strlen(aux->cidade)-1]=0;

        printf("\n\tInforme a estado do endereco do paciente\n");
        printf("\tEstado: ");
        fgets(aux->estado, 50, stdin);
        fflush(stdin);
        aux->estado[strlen(aux->estado)-1]=0;

        printf("\n\tInforme o dia do diagnostico do paciente\n");
        printf("\tDia do Diagnostico: ");
        scanf(" %d", &aux->ddiag);

        printf("\n\tInforme o mes do diagnostico do paciente\n");
        printf("\tMes do Diagnostico: ");
        scanf(" %d", &aux->mdiag);

        printf("\n\tInforme o ano do diagnostico do paciente\n");
        printf("\tAno do Diagnostico: ");
        scanf(" %d", &aux->adiag);

        int idade = aux->adiag - aux->anasc;

        aux->idade = idade;

        if(aux->idade >= 65){
            printf("\n\t*** Paciente faz parte do grupo de risco! ***\n");
            printf("\t*** Precisa ter certos cuidados com o Paciente ***\n");
        }
        else{
            printf("\n\tPaciente nao faz parte do Grupo de Risco!\n");
        }

        printf("\n\tInforme as comorbidades do paciente\n");
        printf("\tComorbidades: ");
        fflush(stdin);
        gets(aux->comorbidades);
        fflush(stdin);

        printf("\n\tInforme a urgencia do paciente [de 1 (Mais urgente) a 20 (Menos urgente)]\n");
        printf("\tUrgencia: ");
        scanf("%d", &aux->urg);
        printf("\n\n");

        printf("\n\tInforme o código do paciente\n");
        printf("\tCódigo: ");
        scanf("%d", &aux->codi);
        printf("\n\n");

        //Salva os dados dos Pacientes em TXT
        FILE *paci;
        paci = fopen("Dados_Pacientes.txt", "a+");
        fprintf(paci,"Nome: %s -> CPF: %s -> Idade: %d -> Email: %s -> Telefone: %d -> Data de Nascimento: %d/%d/%d -> CEP: %d -> Rua: %s -> Numero: %d -> Bairro: %s -> Cidade: %s -> Estado: %s -> Comorbidades: %s -> Data do Diagnostico: %d/%d/%d -> Urgencia: %d -> Código: %d\n", aux->nome, aux->cpf, aux->idade, aux->email, aux->telefone, aux->dnasc, aux->mnasc, aux->anasc, aux->cep, aux->rua, aux->num, aux->bairro, aux->cidade, aux->estado, aux->comorbidades, aux->ddiag, aux->mdiag, aux->adiag, aux->urg, aux->codi);
        fclose(paci);

        if (aux->idade >= 65) {
            FILE *sint;
            sint = fopen("Grupo de Risco.txt", "a+");
            fprintf(sint,"CEP: %d\nIdade: %d\n", aux->cep, aux->idade);
            fprintf(sint,"----------------------------------------------------------------\n");
            fclose(sint);
        }

        adicionar(&Arv, aux);

        aux->prox = tmp->head;
        tmp->head = aux;
        tmp->qnt++;


        printf("1-Novo cadastro\n2-Voltar ao Menu\n");
        printf("Opção: ");
        scanf("%d", &op_cadastro_paciente);
    }while(op_cadastro_paciente != 2);
}

//Faz a listagem dos pacientes
void listar_pacientes(listas *tmp){
    int op = 0;
    printf("\t----------------------PACIENTES----------------------\n");

    paciente *aux;
    printf("\n\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for(aux = tmp->head; aux != NULL; aux = aux->prox){
        printf("Nome: %s\n", aux->nome);
        printf("CPF: %s\n", aux->cpf);
        printf("E-mail: %s\n", aux->email);
        printf("Telefone: %d\n", aux->telefone);
        printf("Data de nascimento: %d/%d/%d\n", aux->dnasc,aux->mnasc,aux->anasc);
        printf("CEP: %d\n", aux->cep);
        printf("Rua: %s\n", aux->rua);
        printf("Número: %d\n", aux->num);
        printf("Bairro: %s\n", aux->bairro);
        printf("Cidade: %s\n", aux->cidade);
        printf("Estado: %s\n", aux->estado);
        printf("Comorbidades: %s\n", aux->comorbidades);
        printf("Data do diagnóstico: %d/%d/%d\n", aux->ddiag, aux->mdiag, aux->adiag);
        printf("Idade: %d\n", aux->idade);
        printf("Código do Paciente: %d\n", aux->codi);
        printf("Urgência: %d\n", aux->urg);

        //CPF: %s\nSexo: %s\nEndereco: %s\nEmail: %s\nIdade: %d\nTelefone: %d\nComorbidades: %s\nCódigo: %d\n", aux->nome, aux->cpf, aux->sexo,aux->endereco,aux->email, aux->idade, aux->telefone,aux->comorbidades, aux->codi);
        printf("---------------------------------------------------------------------------------------------------------\n\n\n");
    }


    printf("---------------------------------------------------------------------------------------------------------\n\n\n");
    printf("\t\t\tExistem %d pacientes cadastrados\n", tmp->qnt);
    free(aux);
    printf("\n\n");
    printf("1-Voltar ao menu\n2-Encerrar o programa ");
    scanf("%d", &op);
    if(op == 2){
        exit(0);
    }
}

void adicionar(arvore **Arv, paciente *pac){
    arvore *temp = NULL;
    if (*Arv == NULL){
        temp = (arvore*)malloc(sizeof(arvore));
        temp->Esq = NULL;
        temp->Dir = NULL;
        temp->No = pac;
        *Arv = temp;
    }
    else {
        if (pac->urg < ((*Arv)->No->urg)){
            adicionar(&((*Arv)->Esq), pac);
        }
        else{
            adicionar(&((*Arv)->Dir), pac);
        }
    }
}

// Em Ordem (Do menor pro maior)
void Mostrar(arvore *Arv){
    if(Arv != NULL){
        Mostrar(Arv->Esq);
        printf("Nome: %s\nCPF: %s\nSexo: %s\nEndereco: %s\nIdade: %d\nTelefone: %d\nComorbidades: %s\nCódigo: %d\n", Arv->No->nome, Arv->No->cpf, Arv->No->sexo,Arv->No->endereco,Arv->No->email, Arv->No->idade, Arv->No->telefone, Arv->No->comorbidades, Arv->No->urg, Arv->No->codi);
        Mostrar(Arv->Dir);
    }
}

//Alterando os dados dos pacientes
void alterar_paciente(listas* lista_escolhida){
     char nome_substituto[50];
     char cpf_substituto[50];
     int codigo, idade_substituto, telefone_substituto;
     paciente* atual = lista_escolhida->head;
     system("cls");

     printf("\tCódigo do paciente a ser alterado: ");
     scanf("%d", &codigo);

     //Verificando se o código é válido
     while(atual != NULL && atual->codi != codigo){
        atual = atual->prox;
     }


     if(atual!=NULL){
        printf("\n\tNovo nome: ");
        scanf("%s", nome_substituto);
        strcpy(atual->nome,nome_substituto);//Faz a mudança de nome

        printf("\n\tNova idade: ");
        scanf("%d", &idade_substituto);
        atual->idade = idade_substituto;//Altera a idade

        printf("\n\tNovo CPF: ");
        scanf("%s", cpf_substituto);
        strcpy(atual->cpf,cpf_substituto);//Altera o CPF

        printf("\n\tNovo telefone: ");
        scanf("%d", &telefone_substituto);
        atual->telefone = telefone_substituto;//Altera o Telefone


        printf("\n\tDados alterados com sucesso.\n\tVoltando ao menu...");

     }else{
        printf("\n\tpaciente não encontrado\n\tVoltando ao menu...");
     }
     Sleep(3000);

}

listas* excluir_paciente(listas* lista_escolhida){

    //Ponteiro para saber o elemento anterior ao elemento atual da lista.
    paciente *anterior = NULL;
    //Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
    paciente *atual = lista_escolhida->head;
    int codigo;
    system("cls");
    //Requisitando e lendo o código do paciente a ser excluído.
    printf("\n\nCódigo do paciente a ser excluído: ");
    scanf("%d", &codigo);

    //Procurando o paciente na lista.
    while(atual != NULL && atual->codi != codigo){
       anterior = atual;
       atual = atual->prox;
    }

    //Mensagem caso o paciente não seja encontrado.
    if(atual == NULL){
       printf("\n  Paciente não encontrado.");
       Sleep(1500);
       return lista_escolhida;
    }
    //Excluindo o primeiro paciente da lista.
    if(anterior == NULL){
       printf("\n  Paciente excluído com sucesso.");
       lista_escolhida->head = atual->prox;
       Sleep(1500);
       return lista_escolhida;
    //Excluindo um paciente do meio da lista.
    }else{
       printf("\n  Paciente excluído com sucesso.");
       anterior->prox = atual->prox;
       Sleep(1500);
       return lista_escolhida;
    }
    lista_escolhida->qnt--;
    //Desalocando o espaço da memória.
    free(atual);
    return lista_escolhida;
}

//Faz a animação do "Entrando..."
void entrando(){
    int carregando;
    for(carregando=1;carregando<=3;carregando++){
        printf("\n\n\n\t\t\tCarregando.");
           Sleep(100);
        system("cls");
        printf("\n\n\n\t\t\tCarregando..");
        Sleep(100);
        system("cls");
        printf("\n\n\n\t\t\tCarregando...");
        Sleep(100);
        system("cls");
    }
}

//Menu principal
void menu(){

    int op_menu;
    listas *lista_paciente = inicializarLista();
    arvore *Arv = NULL;

    do{
        printf("\t\t--------------------HOSPITAL UNIP-------------------------\n\n");
        printf("\n\n");
        printf("\tEscolha a opcao desejada\n");
        printf("\t[1] - Adicionar paciente\n");
        printf("\t[2] - Alterar dados do paciente\n");
        printf("\t[3] - Exibir lista de pacientes\n");
        printf("\t[4] - Excluir paciente\n");
        printf("\t[0] - Encerrar o programa\n");
        printf("\n\tOpcao: ");
        scanf("%d", &op_menu);
        switch(op_menu){
            case 1:
                system("cls");
                cadastrar_paciente(lista_paciente, Arv);
                break;
            case 2:
                system("cls");
                alterar_paciente(lista_paciente);
                break;
            case 3:
                system("cls");
                listar_pacientes(lista_paciente);
                break;
            case 4:
                system("cls");
                printf("\tQual paciente deseja excluir?\n");
                lista_paciente = excluir_paciente(lista_paciente);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("\n\n\n\n");
                printf("Opcao invalida\n");
                Sleep(1500);
                printf("\n\n\n\n");
        }
        system("cls");
    }while(op_menu != 0);
}


//Função principal
int main(){

     while(1)
    {

        char string[5];
        char enter[2];
        char usuario[50];

        printf("## SMP-COVID - Sistema de Monitoramento de Pacientes com COVID ## \n\n");
        printf("Efetue a autenticacao de usuario para ter acesso ao sistema. \n");
        printf("\nUsuario: ");
        scanf("%s", usuario);

        printf ("\nDigite a senha : ");
        string[0] = getch();
        printf ("*");
        string[1] = getch();
        printf ("*");
        string[2] = getch();
        printf ("*");
        string[3] = getch();
        printf ("*");
        string[4] = getch();
        printf ("*");

        enter[0] = getch();
        if(enter[0] == 13)
        {
            if((strcmp(usuario,"admin") == 0) && (string[0] == 'C') && (string[1] == 'o') && (string[2] == 'v') && (string[3] == 'i') && (string[4] == 'd')) // usuário é "admin" e senha correta é "Covid".
            {

                system("color F1");
                system("cls"); // limpa a tela.
                printf ("\n\n\t\tAcesso permitido!\n\n\t\tParabens!\n\t\tTecle Enter para Acessar o Sistema!\n\n\n\n\n\n\n");
                getchar(); // quando pressionar o "ENTER" continua o programa.
                system("cls"); // limpa a tela.
            }
            else
            {
                system("color F1");
                system("cls"); // limpa a tela.
                printf ("\n\n\t\tAcesso negado!\n\n\t\tVoce nao tem permissao para acesso! Tecle 'Enter' Para Tentar Novamente!\n\n\n\n\n\n\n\n\n\n\n");
                system("pause>null");
                system("cls"); // limpa a tela.

                return main();
            }


    system("color F1");//Muda a cor do programa
    setlocale(LC_ALL,"Portuguese");
    entrando();//Chama a função responsável por realizar a animação
    menu();//Chama o menu principal
    system("pause>null");
}}}
