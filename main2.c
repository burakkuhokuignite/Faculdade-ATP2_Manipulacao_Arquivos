

//TRABALHO POR: LUCIANO CARLOS SIME�O JUNIOR E MATHEUS HENRIQUE PATRIZI
		
		
#include "main.h"
#include "func_aux.h"
#include "func_txt.h"
#include "func_bin.h"



int main(int argc, char *argv[]){
	int ctrl_input = -1;
	char op, name1[21], name2[21], name3[21];
	int n = 0, operation;
	switch (argc) {
        case 1:
            
            printf("    BEM-VINDO AO SOFTWARE DE MANIPULAÇÃO DE ARQUIVOS !\n"
                   "Software desenvolvido por Luciano Carlos Simeao Jr\n"
                   "e Matheus Henrique Patrizi\n");
                   Sleep(2);

                   system("cls");
            puts("==============================================================");
          printf("Instrucoes de uso:\n"
                 "1 - Digite somente o nome do programa -\"tpp04\"- para exibir\n"
                 "as informacoes de uso \n\n"
                 "2 - Digite tpp04 seguido do tipo de abertura do arquivo ('t'\n"
                 "para arquivos do tipo texto e 'b' para arquivos do tipo\n"
                 " binario, seguido do nome que deseja dar ao arquivo e um numero\n"
                 "inteiro que ira representar a quantidade de valores que serao\n"
                 "armazenados no arquivo criado \n\n"
                 "3 - Digite tpp04, seguido do tipo de abertura do arquivo e o nome\n"
                 "dele, para exibir na tela os valores armazenados no arquivo \n\n"
                 "4 - Digite tpp04, o tipo de abertura, um numero de 1 a 4 sendo:\n"
                 " 1 - Intersecao 2 - Uniao 3 - Diferenca (1o - 2o) 4 - Diferenca\n"
                 "(2o - 1o)\n");
            puts("==============================================================");
            break;
        case 3:

            if(!(strcmp(argv[1],"t"))){
         		FILE *f3t;
         		f3t = fopen(argv[2],"r");
                printTxtFile(f3t);
                fclose(f3t);
            }

            else if(!(strcmp(argv[1],"b"))){
            	FILE *f3b;
            	f3b = fopen(argv[2],"r");
                printBinFile(f3b);
                fclose(f3b);
            }

            else ctrl_input = 0;

            break;
        case 4:

            if(isNumber(argv[3])){
                    n  = atoi(argv[3]);

                    if(!(strcmp(argv[1],"t"))){

                       // createTxtFile(argv[2]);
                        int vvv[n];
                        giveRandom(vvv,n);
                        SelectionSort(n,vvv);
                        FILE *fff;
                        fff = fopen(argv[2],"a");
                        fclose(fff);
                        fff= fopen(argv[2],"w");
                        PreencheArquivo(fff,n,vvv);
                        fclose(fff);
                    }

                    else if(!(strcmp(argv[1],"b"))){
                        
						createBinFile(argv[2]);
						FILE *f1 = NULL;
						f1 = fopen(argv[2],"a");
						randNumArq(f1,n);
						fclose(f1);
						f1 = fopen(argv[2],"rb+");
						BubbleSort(f1);
						fclose(f1);
						
                    }

                    else ctrl_input  = 0;

            }//if(isNumber)

            else{
                ctrl_input = 0;
            }

            break;
        case 6:
			
            if(isNumber(argv[2])){
                op = *argv[1];
                operation = atoi(argv[2]);

                strcpy(name3,argv[5]);
                strcpy(name2,argv[4]);
                strcpy(name1,argv[3]);
                createBinFile(name3);
                switch(operation){
                	case 1:
                    	if(op == 'b'){
                    		FILE *f61b1,*f61b2,*f61b3;
                			f61b1 = fopen(name1,"rb+");
                			f61b2 = fopen(name2,"rb+");
                			f61b3 = fopen(name3,"wb");
                			IntersecaoBin(f61b1,f61b2,f61b3);
                			fclose(f61b1);
                			fclose(f61b2);
                			fclose(f61b3);
                		}
                		
                		else if(op == 't'){
                			FILE *f6t1,*f6t2;
                			f6t1 = fopen(name1,"r");
                			f6t2 = fopen(name2,"r");
                			int tt1=0,tt2=0;
                			ContaArq(f6t1,&tt1);
                			ContaArq(f6t2,&tt2);
                			int va1[tt1],va2[tt2];
                			ArqVet(f6t1,tt1,va1);
                			ArqVet(f6t2,tt2,va2);
                			fclose(f6t1);
                			fclose(f6t2);
                			int tamn = tt1+tt2, vint[tamn];
                			IntersecaoTxt(va1,va2,vint,tt1,tt2,&tamn);
                			SelectionSort(tamn,vint);
                			FILE *f61t;
                			f61t = fopen(name3,"w");
                			PreencheArquivo(f61t,tamn,vint);
                			fclose(f61t);
                		}
                		
                	break;

                	case 2:
                		
                	if(op == 'b'){
                			FILE *f62b1,*f62b2,*f62b3;
                			f62b1 = fopen(name1,"rb+");
                			f62b2 = fopen(name2,"rb+");
                			f62b3 = fopen(name3,"wb");
                			UniaoBin(f62b1,f62b2,f62b3);
                			fclose(f62b1);
                			fclose(f62b2);
                			fclose(f62b3);
                		}

                		else if(op == 't'){
                			FILE *f6t1,*f6t2;
                			f6t1 = fopen(name1,"r");
                			f6t2 = fopen(name2,"r");
                			int tt1=0,tt2=0;
                			ContaArq(f6t1,&tt1);
                			ContaArq(f6t2,&tt2);
                			int va1[tt1],va2[tt2];
                			ArqVet(f6t1,tt1,va1);
                			ArqVet(f6t2,tt2,va2);
                			fclose(f6t1);
                			fclose(f6t2);
                			int tamn2 = tt1+tt2,vuni[tamn2];
                			UniaoTxt(va1,va2,vuni,tt1,tt2,&tamn2);
                			SelectionSort(tamn2,vuni);
                			FILE *f62t;
                			f62t = fopen(name3,"w");
                			PreencheArquivo(f62t,tamn2,vuni);
                			fclose(f62t);
                		}

                	break;

                	case 3:
                	
                    	if(op == 'b'){
                    		FILE *f63b1,*f63b2,*f63b3;
                			f63b1 = fopen(name1,"rb+");
                			f63b2 = fopen(name2,"rb+");
                			f63b3 = fopen(name3,"wb");
                			DiferencaBin(f63b1,f63b2,f63b3);
                			fclose(f63b1);
                			fclose(f63b2);
                			fclose(f63b3);
                		}
                		
                		else if(op == 't'){
                			FILE *f6t1,*f6t2;
                			f6t1 = fopen(name1,"r");
                			f6t2 = fopen(name2,"r");
                			int tt1=0,tt2=0;
                			ContaArq(f6t1,&tt1);
                			ContaArq(f6t2,&tt2);
                			int va1[tt1],va2[tt2];
                			ArqVet(f6t1,tt1,va1);
                			ArqVet(f6t2,tt2,va2);
                			fclose(f6t1);
                			fclose(f6t2);
                			int tamn3 = tt1+tt2,vdif1[tamn3];
                			DiferencaTxt(va1,va2,vdif1,tt1,tt2,&tamn3);
                			SelectionSort(tamn3,vdif1);
                			FILE *f63t;
                			f63t = fopen(name3,"w");
                			PreencheArquivo(f63t,tamn3,vdif1);
                			fclose(f63t);
                		}
                	break;

                	case 4:

                		if(op == 'b'){
                			FILE *f63b11,*f63b22,*f63b33;
                			f63b11 = fopen(name1,"rb+");
                			f63b22 = fopen(name2,"rb+");
                			f63b33 = fopen(name3,"wb");
                			DiferencaBin(f63b22,f63b11,f63b33);
                			fclose(f63b11);
                			fclose(f63b22);
                			fclose(f63b33);
                		}
                		
                		else if(op == 't'){
                			FILE *f6t1,*f6t2;
                			f6t1 = fopen(name1,"r");
                			f6t2 = fopen(name2,"r");
                			int tt1=0,tt2=0;
                			ContaArq(f6t1,&tt1);
                			ContaArq(f6t2,&tt2);
                			int va1[tt1],va2[tt2];
                			ArqVet(f6t1,tt1,va1);
                			ArqVet(f6t2,tt2,va2);
                			fclose(f6t1);
                			fclose(f6t2);
                			int tamn4 = tt1+tt2,vdif2[tamn4];
                			DiferencaTxt(va2,va1,vdif2,tt2,tt1,&tamn4);
                			SelectionSort(tamn4,vdif2);
                			FILE *f64t;
                			f64t = fopen(name3,"w");
                			PreencheArquivo(f64t,tamn4,vdif2);
                			fclose(f64t);
                		}
                	break;
                }
                
            }
            else{
                ctrl_input = 0;
            }

            break;

        default:

            ctrl_input = 0;
            break;
    }

    if(!ctrl_input)	fputs("Erro na entrada de dados!!!",stderr);

    system("pause");
    return 0;

}
