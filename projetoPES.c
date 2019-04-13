#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<locale.h>

struct Livro{

    int codLivro, edicao, numPaginas;
    float preco;
    char titulo[50], autor[50], categoria[50], status[50];
};

struct Usuario{

    int codUsuario;
    char cpf[11], nome[50], telefone[20];
};

struct EmprestimoLivro{

    char dataEmprestimo[10];
    int codUsuario, codLivro;
};



void inserirDadosUsuario();
void listarDadosUsuarios();
void inserirDadosLivro();
void listarDadosLivros();
void compraLivro();
int verificarCODLIVRO(int cod);
int verificarCODUSUARIO(int cod);
void emprestimoLivro();
void buscarUsuario();
void editarDadosUsuario();
void editarDadosLivro();
void buscarLivro();
void devolverLivro();

int codUsuarioAutomatico = 1;
int codLivroAutomatico = 1;

int main(){

    setlocale(LC_ALL,"");
    int op = 0;

    while(1){

        printf("\t\t -------------- Biblioteca --------------\n\n");
        printf("\n 1 - Cadastrar o Usuario");
        printf("\n 2 - Listar Usuários Cadastrados");
        printf("\n 3 - Cadastrar Livro");
        printf("\n 4 - Listar Livros Cadastrados");
        printf("\n 5 - Comprar Livro");
        printf("\n 6 - Realizar Empréstimo de Livro");
        printf("\n 7 - Editar Dados Usuario");
        printf("\n 8 - Buscar Usuario");
        printf("\n 9 - Editar Dados Livro");
        printf("\n 10 - Buscar Livro");
        printf("\n 11 - Devolução de Livro");
        printf("\n 12 - Sair");

        printf("\n\nDigite um opção : ");
        scanf(" %d", &op);
        printf("\n");

        switch(op){

            case 1:

              inserirDadosUsuario();
                break;

            case 2:
                listarDadosUsuarios();
                break;

            case 3:
                inserirDadosLivro();
                break;

            case 4:
                listarDadosLivros();
                break;

            case 5:
                compraLivro();
                break;

            case 6:
               emprestimoLivro();
                break;

            case 7:
               editarDadosUsuario();
               break;

            case 8:
                buscarUsuario();
                break;

            case 9 :
                editarDadosLivro();
                break;

            case 10 :
                buscarLivro();
                break;

            case 11:
                devolverLivro();
                break;
        }

        if(op == 12){

            printf("\n\nVOCÊ SAIU !!!");
            break;
        }
    }


}

void inserirDadosUsuario(){
    system("cls");

    struct Usuario user[50];

    printf("\t\t --------------- Cadastro de Usuário --------------- \n");
    int qtdUsuario;
    FILE *arquivoUsuario;
    arquivoUsuario = fopen("usuarios.txt","a");

    if(arquivoUsuario == NULL){
        printf("Não foi possível abrir o arquivo");
        return;
    }

        printf("\nDigite a quantidade de usuários a serem cadastrados: ");
        scanf(" %d", &qtdUsuario);

        for(int i = 0; i < qtdUsuario; i ++){

            printf("\nDigite o nome: ");
            scanf(" %s", user[i].nome);

            printf("Digite o CPF: ");
            scanf(" %s", user[i].cpf);

            printf("Digite o Telefone: ");
            scanf(" %s", user[i].telefone);


        if(codUsuarioAutomatico == 1){
             user[i].codUsuario = codUsuarioAutomatico;
             codUsuarioAutomatico++;
        }else {
            user[i].codUsuario = codUsuarioAutomatico;
            codUsuarioAutomatico++;
        }

        fprintf(arquivoUsuario, "%d \t %s \t %s \t %s \n",user[i].codUsuario, user[i].nome, user[i].cpf, user[i].telefone );
        printf("\nUsuário cadastrado com sucesso !!\n");


    }

  fclose(arquivoUsuario);
  system("pause");
  system("cls");
}

void listarDadosUsuarios(){
    system("cls");

    struct Usuario user[50];
    FILE *arquivoUsuario;
    int i = 0;

    arquivoUsuario = fopen("usuarios.txt","r");

    if(arquivoUsuario == NULL){
        printf("Não existe nenhum usuário cadastrado !!\n");
        system("pause");
        system("cls");
        return;
    }

     printf("\t\t --------------- Usuários --------------- \n\n");
    while(!feof(arquivoUsuario)){
        fscanf(arquivoUsuario, "%d \t %s \t %s \t %s \n",&user[i].codUsuario, user[i].nome, user[i].cpf, user[i].telefone);
        printf("Código: %d \t Nome: %s \t CPF: %s \t Telefone: %s \n", user[i].codUsuario, user[i].nome, user[i].cpf, user[i].telefone);
        i++;
    }

    fclose(arquivoUsuario);
    printf("\n\n");
    system("pause");
    system("cls");

}

void inserirDadosLivro(){

    system("cls");

    struct Livro livro[50];
    FILE *arquivoLivro;
    arquivoLivro = fopen("livros.txt","a");

    if(arquivoLivro == NULL){
        printf("Não foi possível abrir o arquivo !!\n");
        system("pause");
        system("cls");
        return;
    }

    printf("\t\t -------------- Cadastro de Livro --------------\n\n");

    int qtdLivro;

    printf("Digite a quantidade de Livros a serem cadastrados: ");
    scanf(" %d", &qtdLivro);

    for(int i = 0; i < qtdLivro; i++){

        printf("Digite o nome do Livro: ");
        scanf(" %s", livro[i].titulo);

        printf("Digite o autor do Livro: ");
        scanf(" %s", livro[i].autor);

        printf("Digite a edição do Livro: ");
        scanf(" %d", &livro[i].edicao);

        printf("Digite o número de páginas do Livro: ");
        scanf(" %d", &livro[i].numPaginas);

        printf("Digite o Preço do Livro: ");
        scanf(" %f", &livro[i].preco);

     //   strcpy(livro[i].status, "Disponivel");

        if(codLivroAutomatico == 1){
            livro[i].codLivro = codLivroAutomatico;
            codLivroAutomatico++;
        }
        else {
            livro[i].codLivro = codLivroAutomatico;
            codLivroAutomatico++;
        }
        fprintf(arquivoLivro, "%d \t %s \t %s \t %d \t %d \t %f \n", livro[i].codLivro, livro[i].titulo, livro[i].autor, livro[i].edicao, livro[i].numPaginas, livro[i].preco);
        printf("\nLivro cadastrado com sucesso !!\n\n");
    }

   fclose(arquivoLivro);
   system("pause");
   system("cls");
}


void listarDadosLivros(){

    system("cls");
    struct Livro livro[50];
    FILE *arquivoLivro;
    int i = 0;

    arquivoLivro = fopen("livros.txt","r");

    if(arquivoLivro == NULL){
        printf("Não existe nenhum Livro cadastrado\n");

        system("pause");
        system("cls");
        return;
    }
    printf("\t\t --------------- Livros  --------------- \n\n");
    while(!feof(arquivoLivro)){
        fscanf(arquivoLivro, "%d \t %s \t %s \t %d \t %d \t %f \n", &livro[i].codLivro, livro[i].titulo, livro[i].autor, &livro[i].edicao, &livro[i].numPaginas, &livro[i].preco);
       printf("Código: %d \t Titulo: %s \t Autor: %s \t Edição: %d \t NumPáginas: %d \t Preço: %.2f \n", livro[i].codLivro, livro[i].titulo, livro[i].autor, livro[i].edicao, livro[i].numPaginas, livro[i].preco);
        i++;
    }

  fclose(arquivoLivro);
  system("pause");
  system("cls");

}

void compraLivro(){

    system("cls");
    printf("\t\t ------------- Venda de Livro ------------- \n\n");

    FILE *arquivoCompraLivro;
    FILE *arquivoLivro;

    int  codLivro, i = 0;
    float valorLivro, valorUsuario, valorRetornar;
    struct Livro livro[50];

    arquivoLivro = fopen("livros.txt","r");

    if(arquivoLivro == NULL){
        printf("Não foi possível está opção !!\n");
        system("pause");
        system("cls");
        return;
    }

    arquivoCompraLivro = fopen("compralivros.txt","w");

     if(arquivoCompraLivro == NULL){
        printf("Não foi possível está opção !!\n");
        system("pause");
        system("cls");
        return;
    }


     while(!feof(arquivoLivro)){
        fscanf(arquivoLivro, "%d \t %s \t %s \t %d \t %d \t %f \n", &livro[i].codLivro, livro[i].titulo, livro[i].autor, &livro[i].edicao, &livro[i].numPaginas, &livro[i].preco);
        i++;
    }




    printf("\n\nDigite o Código do Livro: ");
    scanf(" %d", &codLivro);



    if(codLivro != verificarCODLIVRO(codLivro)){
        printf("\n\nNão existe existe este COD de Livro !!!\n\n");
          system("pause");
          system("cls");
    }
    else {

            printf("Valor do livro : %.2f", livro[codLivro - 1].preco);
            printf("\n\n");
            printf("Digite o valor a ser pago: ");
            scanf(" %f", &valorUsuario);

            valorRetornar = valorUsuario - livro[codLivro - 1].preco;

            printf("\nO valor a retornar é : %.2f ", valorRetornar);

            char lerCaracter[1001] ;
            int linhaInicialLivro = 1;

            while(fgets(lerCaracter, 1001, arquivoLivro) != NULL ){

                    if( linhaInicialLivro != codLivro ){

                            fputs(lerCaracter, arquivoCompraLivro);

                    }

                linhaInicialLivro += 1;

            }
            fclose(arquivoLivro);
            fclose(arquivoCompraLivro);

            remove("livros.txt");
            rename("compralivros.txt","livros.txt");

            printf("\n\nCompra Realizada com Sucesso !!\n\n");

          system("pause");
          system("cls");
    }

}

int verificarCODLIVRO(int cod){

    struct Livro livro[50];
    FILE *arquivoLivro;
    int i  = 0, codLivroTESTE = 0;

    arquivoLivro = fopen("livros.txt","r");

    if(arquivoLivro == NULL){
        printf("Não existe nenhum Livro cadastrado\n");

        system("pause");
        system("cls");
        return 0;
    }
   while(!feof(arquivoLivro)){
        fscanf(arquivoLivro, "%d \t %s \t %s \t %d \t %d \t %f \n", &livro[i].codLivro, livro[i].titulo, livro[i].autor, &livro[i].edicao, &livro[i].numPaginas, &livro[i].preco);
        if(cod == livro[i].codLivro){
           codLivroTESTE = livro[i].codLivro;
        }
        i++;
    }

    fclose(arquivoLivro);

    if(codLivroTESTE == cod){
        return cod;
    }
}


int verificarCODUSUARIO(int cod){

    struct Usuario user[50];
    FILE *arquivoUsuario;
    int i = 0,  codUsuarioTESTE = 0;

    arquivoUsuario = fopen("usuarios.txt","r");

    if(arquivoUsuario == NULL){
        printf("Não existe nenhum usuário cadastrado !!\n");
        system("pause");
        system("cls");
       return 1;
    }

    while(!feof(arquivoUsuario)){

        fscanf(arquivoUsuario, "%d \t %s \t %s \t %s \n",&user[i].codUsuario, user[i].nome, user[i].cpf, user[i].telefone);
        if(cod == user[i].codUsuario){
            codUsuarioTESTE = user[i].codUsuario;
        }
    i++;
    }

    fclose(arquivoUsuario);

    if(codUsuarioTESTE == cod){

        return cod;
    }
}

void emprestimoLivro(){

    system("cls");

    FILE *arquivoEmprestimo;
    arquivoEmprestimo = fopen("emprestimo.txt","a");

    struct EmprestimoLivro empLivro[50];

    int qtdEmprestimos, codUsuarioTESTE, codLivroTESTE;


    if(arquivoEmprestimo == NULL){
        printf("Não é possível realizar o emprestimo !!");
        return;
    }
    printf("\t\t ----------------- Emprestimo de Livro ----------------- \n\n");

    printf("Quantos Emprestimos deseja realizar: ");
    scanf(" %d", &qtdEmprestimos);

    for(int i = 0; i < qtdEmprestimos; i++){

      printf("Digite o código do Usuário: ");
      scanf(" %d", &codUsuarioTESTE);

        if(codUsuarioTESTE != verificarCODUSUARIO(codUsuarioTESTE)){
           printf("\n\nNão existe existe este COD de usuário !!!\n\n");
            system("pause");
            system("cls");
            return;
        }
       else {

            empLivro[i].codUsuario = codUsuarioTESTE;

                printf("Digite o código do Livro: ");
                scanf(" %d", &codLivroTESTE);


                if(codLivroTESTE != verificarCODLIVRO(codLivroTESTE)){
                        printf("\n\nNão existe existe este COD de Livro !!!\n\n");
                        system("pause");
                        system("cls");
                        return;
                }
                else{

                        printf("Digite a Data da Devolucao, no seguinte formato dd/mm/yyyy: ");
                        scanf(" %s", empLivro[i].dataEmprestimo);

                        empLivro[i].codLivro = codLivroTESTE;

                        fprintf(arquivoEmprestimo,"%d \t %d \t %s \n", empLivro[i].codUsuario, empLivro[i].codLivro, empLivro[i].dataEmprestimo);
                        printf("\n\nEmprestimo realizado com Sucesso\n\n");
                }

        }

    }
    fclose(arquivoEmprestimo);

    system("pause");
    system("cls");

}

void buscarUsuario(){

    system("cls");

    struct Usuario user[50];
    FILE *arquivoUsuario;
    int i = 0,  codUsuarioTESTE = 0, contUsuNULL = 0, contUSUNOTNULL = 0;

    arquivoUsuario = fopen("usuarios.txt","r");

    printf("\t\t --------------- BUSCA DE USUARIOS  ---------------\n\n");

    if(arquivoUsuario == NULL){
        printf("Não existe nenhum usuário cadastrado !!\n");
        system("pause");
        system("cls");
       return;
    }

    printf("Digite o cod do Usuario: ");
    scanf(" %d", &codUsuarioTESTE);

    while(!feof(arquivoUsuario)){

        fscanf(arquivoUsuario, "%d \t %s \t %s \t %s \n",&user[i].codUsuario, user[i].nome, user[i].cpf, user[i].telefone);

        if(codUsuarioTESTE == user[i].codUsuario){
            printf("Código: %d \t Nome: %s \t CPF: %s \t Telefone: %s \n",user[i].codUsuario, user[i].nome, user[i].cpf, user[i].telefone);
            printf("\n");
            system("pause");
            system("cls");
            contUSUNOTNULL++;
            return;
        }
        else {
            contUsuNULL++;
        }
        i++;
    }


    if(contUsuNULL != contUSUNOTNULL){
        printf("\n\nO Usuario não existe !!! \n\n");
        system("pause");
        system("cls");

    }

    fclose(arquivoUsuario);


}

void editarDadosUsuario(){


    system("cls");

    struct Usuario user[50];
    FILE *arquivoUsuario;
    FILE *arquivoTEMPUSU;
    int i = 0, opcao = 0, codUsuarioTESTE;




     printf("\t\t --------------- Editar Dados Usuario --------------- \n\n");

    arquivoUsuario = fopen("usuarios.txt","r");

    if(arquivoUsuario == NULL){
        printf("Não existe nenhum usuário cadastrado !!\n");
        system("pause");
        system("cls");
        return;
    }

    arquivoTEMPUSU = fopen("tempUsuarios.txt","w");

    if(arquivoTEMPUSU == NULL){
        printf("Não é possivel abrir o arquivo");
        system("pause");
        system("cls");
        return;
    }


      while(!feof(arquivoUsuario)){

        fscanf(arquivoUsuario, "%d \t %s \t %s \t %s \n",&user[i].codUsuario, user[i].nome, user[i].cpf, user[i].telefone);

       i++;
      }


    printf("Digite o cod do Usuário: ");
    scanf(" %d", &codUsuarioTESTE);

     if(codUsuarioTESTE != verificarCODUSUARIO(codUsuarioTESTE)){
           printf("\n\nNão existe existe este COD de usuário !!!\n\n");
            system("pause");
            system("cls");
            return;
    }
    else {
            for(int j = 0; j < i; j ++){

                    if(codUsuarioTESTE == user[j].codUsuario){
                        printf("\n\nNome: %s", user[j].nome);
                        printf("\nCPF: %s", user[j].cpf);
                        printf("\nTelefone: %s",user[j].telefone);

                        printf("\n\nO que voce deseja alterar ? \n\n 1 - Nome \n 2 - CPF \n 3 - Telefone\n");
                        printf("\nDigite a opção: ");
                        scanf(" %d", &opcao);

                        if(opcao == 1){
                             printf("Digite o nome: ");
                             scanf(" %s",user[j].nome);
                        }
                        else if(opcao == 2){
                             printf("Digite o CPF: ");
                             scanf(" %s", user[j].cpf);
                        }
                       else if(opcao == 3){
                             printf("Digite o telefone: ");
                            scanf(" %s", user[j].telefone);
                       }

                       fprintf(arquivoTEMPUSU,"%d \t %s \t %s \t %s\n",user[j].codUsuario , user[j].nome, user[j].cpf,  user[j].telefone);
                    }
                    else {
                        fprintf(arquivoTEMPUSU,"%d \t %s \t %s \t %s\n", user[j].codUsuario, user[j].nome, user[j].cpf,  user[j].telefone);
                    }
            }



           fclose(arquivoUsuario);
           fclose(arquivoTEMPUSU);

           remove("usuarios.txt");
           rename("tempUsuarios.txt","usuarios.txt");

           printf("\nUsuario Editado com Sucesso !!\n\n");

        system("pause");
        system("cls");
    }
}
void editarDadosLivro(){

    system("cls");
    struct Livro livro[50];
    FILE *arquivoLivro;
    FILE *arquivoLivroTEMP;
    int i = 0, codLivro, opcao;

    arquivoLivro = fopen("livros.txt","r");

    if(arquivoLivro == NULL){
        printf("Não existe nenhum Livro cadastrado\n");

        system("pause");
        system("cls");
        return;
    }

    arquivoLivroTEMP = fopen("livroTEMP.txt","w");

    if(arquivoLivroTEMP == NULL){
        printf("Não existe nenhum Livro cadastrado\n");

        system("pause");
        system("cls");
        return;

    }

    printf("\t\t --------------- Editar Livros  --------------- \n\n");

    while(!feof(arquivoLivro)){
        fscanf(arquivoLivro, "%d \t %s \t %s \t %d \t %d \t %f \n", &livro[i].codLivro, livro[i].titulo, livro[i].autor, &livro[i].edicao, &livro[i].numPaginas, &livro[i].preco);

        i++;
    }

    printf("Digite o codigo do Livro: ");
    scanf("%d", &codLivro);

    if(codLivro != verificarCODLIVRO(codLivro)){
        printf("O codigo do livro não existe\n\n");
        system("pause");
        system("cls");
    }
        else {

            for(int k = 0; k < i ; k++){

                if(codLivro == livro[k].codLivro){
                        printf("\n\n");
                        printf("Titulo: %s", livro[k].titulo);
                        printf("\nAutor: %s", livro[k].autor);
                        printf("\nEdição: %d", livro[k].edicao);
                        printf("\nNumPaginas: %d", livro[k].numPaginas);
                        printf("\nPreço: %.2f", livro[k].preco);

                        printf("\n\nO que voce deseja alterar ? \n 1 - Titulo \n 2 - Autor\n 3 - Edição\n 4 - NumPaginas\n 5 - Preço\n");
                        printf("Digite uma opção: ");
                        scanf("%d", &opcao);

                        if(opcao == 1){
                            printf("Digite o nome do Livro: ");
                            scanf(" %s", livro[k].titulo);
                        }
                        else if(opcao == 2){
                            printf("Digite o autor do Livro: ");
                            scanf(" %s", livro[k].autor);
                        }
                        else if(opcao == 3){
                            printf("Digite a edição do Livro: ");
                            scanf(" %d", &livro[k].edicao);
                        }
                        else if(opcao == 4){
                            printf("Digite o número de páginas do Livro: ");
                            scanf(" %d", &livro[k].numPaginas);
                        }
                        else if(opcao == 5){
                            printf("Digite o Preço do Livro: ");
                            scanf(" %f", &livro[k].preco);

                        }
                          fprintf(arquivoLivroTEMP, "%d \t %s \t %s \t %d \t %d \t %f \n", codLivro , livro[k].titulo, livro[k].autor, livro[k].edicao, livro[k].numPaginas, livro[k].preco);
            }
            else {

                    fprintf(arquivoLivroTEMP, "%d \t %s \t %s \t %d \t %d \t %f \n", livro[k].codLivro, livro[k].titulo, livro[k].autor, livro[k].edicao, livro[k].numPaginas, livro[k].preco);

            }
        }
    printf("\n\nLivro Editado com Sucesso !!!\n");
    }



      fclose(arquivoLivro);
      fclose(arquivoLivroTEMP);
      remove("livros.txt");
      rename("livroTEMP.txt","livros.txt");
      system("pause");
      system("cls");

}

void buscarLivro(){

    system("cls");
    printf("\t\t ----------------- Busca de Livro -----------------\n\n");


    FILE *arquivoLivro;
    arquivoLivro = fopen("livros.txt","r");
    int codLivro, contLivroNOTNULL = 0, contLivroNULL = 0, i = 0;
    struct Livro livro[50];

    if(arquivoLivro == NULL){
        printf("Não foi possível abrir o arquivo !!\n\n");
        system("pause");
        system("cls");
        return;
    }

    printf("Digite o código do Livro: ");
    scanf(" %d", &codLivro);

     while(!feof(arquivoLivro)){
        fscanf(arquivoLivro, "%d \t %s \t %s \t %d \t %d \t %f \n", &livro[i].codLivro, livro[i].titulo, livro[i].autor, &livro[i].edicao, &livro[i].numPaginas, &livro[i].preco);
        if(codLivro == livro[i].codLivro){
            printf("Código: %d \t Titulo: %s \t Autor: %s \t Edição: %d \t NumPáginas: %d \t Preço: %.2f \n", livro[i].codLivro, livro[i].titulo, livro[i].autor, livro[i].edicao, livro[i].numPaginas, livro[i].preco);
            printf("\n");
            system("pause");
            system("cls");
            contLivroNOTNULL++;
            return;
        }
        i++;
        contLivroNULL++;

    }

    if(contLivroNULL != contLivroNOTNULL){
        printf("\n\nO código do livro não existe !!");
        printf("\n");
        system("pause");
        system("cls");
    }

}



// Rever Funcao
void devolverLivro(){
    system("cls");
    printf("\t\t ------------------- DEVOLUÇÃO DO LIVRO  -------------------\n\n");

    FILE *arquivoEMPLIVRO;
    arquivoEMPLIVRO = fopen("emprestimo.txt","r");

    if(arquivoEMPLIVRO == NULL){
        printf("Não foi possível abrir o arquivo\n\n");
        system("pause");
        system("cls");
        return;
    }

    struct EmprestimoLivro empLivro[50];


    int i = 0, codLivroTESTE, codUsuarioTESTE;
    float multa;
    char dataDevolucao[10];


   while(feof(arquivoEMPLIVRO)){
        fscanf(arquivoEMPLIVRO,"%d \t %d \t %s \n", &empLivro[i].codUsuario, &empLivro[i].codLivro, empLivro[i].dataEmprestimo);
        printf("%d \t %d \t %s ",empLivro[i].codUsuario, empLivro[i].codLivro, empLivro[i].dataEmprestimo);
        i++;
   }

    printf("Digite o código do Livro: ");
    scanf(" %d", &codLivroTESTE);
    printf("Digite o código do Usuário: ");
    scanf(" %d", &codUsuarioTESTE);



    if(codLivroTESTE != verificarCODLIVRO(codLivroTESTE)){
        printf("O código do livro não existe !!!\n\n");
        system("pause");
        system("cls");
        return;
    }
    else {

        if(codUsuarioTESTE != verificarCODUSUARIO(codUsuarioTESTE)){
            printf("O código do usuário não existe !!!\n\n");
            system("pause");
            system("cls");
            return;
        }
        else {

            for(int j = 0; j < i; j ++){

                if(codUsuarioTESTE == empLivro[j].codUsuario){
                    if(codLivroTESTE == empLivro[j].codLivro){
                            printf("\n\nData de emprestimo: %s", empLivro[j].dataEmprestimo);

                            printf("Digite a data de Devolução, FORMATO: dd/mm/yyyy: ");
                            scanf(" %s", dataDevolucao);

                            if(strcmp(empLivro[j].dataEmprestimo, dataDevolucao) == 0){
                                printf("SEM MULTA");
                            }
                            else {
                                printf("MULTA DE R$ 10");
                            }
                    }
                }
            }

        }
    }

      fclose(arquivoEMPLIVRO);
      printf("\n\n");
      system("pause");
      system("cls");

}
