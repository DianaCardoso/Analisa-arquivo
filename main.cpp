#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//função Conta Letra
int funcaoCl(FILE &fp){
    //Pego a bibliota std e usa as funçoes como padrao.
    using namespace std;
	char ch;
	int contaletra = 0;

	//garante que estará no começo do arquivo
	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, então
	while( (ch = fgetc(&fp)) != EOF ){
		int charascii = (int) ch;
		if(((charascii >= 65) && (charascii <= 90)) || ((charascii >= 97) && (charascii <= 122)) ){
            contaletra++;
		}
    }
	return contaletra;
}

int funcaoCc(FILE &fp){
    using namespace std;
	char ch;
	int contachar = 0;

	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, então
	while( (ch = fgetc(&fp)) != EOF ){
		int charascii = (int) ch;
		contachar ++;
    }
	return contachar;

}
int funcaoCd(FILE &fp){
    //Pego a bibliota std e usa as funçoes como padrao.
    using namespace std;
	char ch;
	int contadigito = 0;

	//garante que estará no começo do arquivo
	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, então
	while( (ch = fgetc(&fp)) != EOF ){
		int charascii = (int) ch;
		if((charascii >= 48) && (charascii <= 57)){
            contadigito++;
		}
    }
	return contadigito;

}

int funcaoCn(FILE &fp){
    //Pego a bibliota std e usa as funçoes como padrao.
    using namespace std;
	char ch;
	int contalinha = 1;

	//garante que estará no começo do arquivo
	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, então
	while( (ch = fgetc(&fp)) != EOF ){
		int charascii = (int) ch;
		if(charascii == 10){
            contalinha++;
		}
    }
	return contalinha;

}
int funcaoCt(FILE &fp, char letra){
    //Pego a bibliota std e usa as funçoes como padrao.
    using namespace std;
	char ch;
	int contaespecifico = 0;

	//garante que estará no começo do arquivo
	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, então
	while( (ch = fgetc(&fp)) != EOF ){
        if(ch == letra){
            contaespecifico++;
		}
    }
	return contaespecifico;

}

/*void funcaoCo(string velho, string novo){

    FILE* batman;
    //Declarando uma string contendo o comando de copia que precisará executar
    string comando = "copy " + velho + " " + novo;
    //Converte a string de c++ para string de c e executa o comando no prompt
    system(comando.c_str());

    batman = fopen(novo.c_str(), "rb");
    fr



    fclose(batman);
}
int funcaoDo(FILE &fp){

}*/

int trocachar(string opcoes){

    return (int)opcoes.at(1);

}



int main(int argc, char** argv) {
    using namespace std;
	setlocale(LC_ALL, "portuguese");

	FILE *fp; //abre arquivo
	string opcao = argv[1];
	char leitura;

    //se a pessoa digitar um desses comandos, então ele precisa passar 3 parâmetros
	if((opcao == "CL") || (opcao == "CC") || (opcao == "CD") || (opcao == "CN")){
		if(argc != 3){
            printf("Você precisa passar 3 parâmetros");
            exit(1);
		}
    //se a pessoa digitar uma dessas opções, então ele precisa passar 4 parâmetros
	}else if((opcao == "CT") || (opcao == "CO") || (opcao == "DO")){
			if(argc != 4){
                printf("Você precisa passar 4 parâmetros");
                exit(2);
			}
    //se ele digitar qualquer coisa fora das opções então é inválido
	}else{
		printf("%s", argv[1]);
		exit(3);
	}

	if ((opcao == "CO") || (opcao == "DO")){
        leitura = 'b';
	}else{
        leitura = 't';
	}

    //abre o arquivo e verifica se ele existe.
    if(leitura == 'b'){
        if((fp = fopen(argv[2], "rb")) == NULL){
		printf("Arquivo não pode ser aberto\n");
		exit(1);
        }
    }else{
        if((fp = fopen(argv[2], "rt")) == NULL){
		printf("Arquivo não pode ser aberto\n");
		exit(1);
        }
    }



    /*printf("%d\n", funcaoCl(*fp));
    printf("%d\n", funcaoCc(*fp));
    printf("%d\n", funcaoCd(*fp));
    printf("%d\n", funcaoCn(*fp));
    printf("%d\n", funcaoCt(*fp, *argv[3]));
    funcaoCo(argv[2], argv[3]);*/




    //Caso a pessoa digite qualquer opção válida, então ele vai para a funçao chamada.
	switch ((int) trocachar(opcao)){
		case 76: printf("%d\n", funcaoCl(*fp)); break;
		case 67: printf("%d\n", funcaoCc(*fp)); break;
		case 68: printf("%d\n", funcaoCd(*fp)); break;
		case 78: printf("%d\n", funcaoCn(*fp)); break;
		case 84: printf("%d\n", funcaoCt(*fp, *argv[3])); break;
		/*case "CO" : funcaoCo(fp); break;
		case "DO" : funcaoDo(fp); break;
		default : printf("Opção inválida!");*/
	}
    fclose(fp);
	return 0;
}
