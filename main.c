#include<stdio.h>
#include <stdbool.h>
#include <string.h>

// IGNORAR OUTROS DÍGITOS ALÉM DE NÚMERO
void entrada(int cpf[20])
{
    char entrada[50];
    int i, j=0, tam;
    printf("Entre com o CPF: ");
    fgets(entrada, 20, stdin);
    tam = strlen(entrada);
    
    for(i=0; i<tam; i++)
    {
        if(entrada[i]>=48 && entrada[i]<=57)
        {  
            cpf[j] = entrada[i]-48;
            
            j++;
        }
    }
}
// FIM IGNORAR OUTROS DÍGITOS ALÉM DE NÚMERO


// VERIFICAR DE QUAL ESTADO É
void estado(int digito)
{
    switch(digito)
    {
        case 0: printf("\nCPF de Rio Grande do Sul"); break;
        case 1: printf("\nCPF de Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul ou Tocantins"); break;
        case 2: printf("\nCPF de Amazonas, Pará, Roraima, Amapá, Acre ou Rondônia"); break;
        case 3: printf("\nCPF de Ceará, Maranhão ou Piauí"); break;
        case 4: printf("\nCPF de Paraíba, Pernambuco, Alagoas ou Rio Grande do Norte"); break;
        case 5: printf("\nCPF de Bahia ou Sergipe"); break;
        case 6: printf("\nCPF de Minas Gerais"); break;
        case 7: printf("\nCPF de Rio de Janeiro ou Espírito Santo"); break;
        case 8: printf("\nCPF de São Paulo"); break;
        case 9: printf("\nCPF de Paraná ou Santa Catarina"); break;
    }
}
// FIM VERIFICAR DE QUAL ESTADO É


// FUNÇÃO VERIFICAR DÍGITO REPETIDO
bool todosRepetidos(int vet[], int N)
{
    int i;
    
    for(N=0; N<=9; N++)
    {
        if(vet[N] != vet[N + 1])
        {
            return false;
        }
    }
    
    return true;
}
// FIM FUNÇÃO VERIFICAR DÍGITO REPETIDO


// FUNÇÃO CALCULAR CPF
int calculoDigitoVerificador(int cpf[], int m[], int N)
{
    int soma = 0;
    int i;
    
    for(i=0; i<N; i++)
	{	
	    soma = soma + cpf[i] * m[i];
	}
	
	return ((soma*10) % 11)%10;
}
// FIM FUNÇÃO CALCULAR CPF


int main()
{
	int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i;
	
	entrada(cpf);
	
	//Cálculo do primeiro dígito verificador
	int soma=0;
	
	/* FAZENDO COM FOR
	for(i=0; i<9; i++)
	{	
	    soma = soma + cpf[i]*m1[i];
	}
	
	int resto = ((soma*10) % 11)%10;
  	*/
  	
  	
  	// MANEIRA REDUZIDA
	if(calculoDigitoVerificador(cpf, m1, 9) == cpf[9] && calculoDigitoVerificador(cpf, m2, 10) == cpf[10] 
	&& todosRepetidos(cpf, 11) == false)
	{
	    printf("\nCPF VÁLIDO!");
		//printf("\nPrimeiro verificador valitrue;
		
		estado(cpf[8]);
	}
	// FIM MANEIRA REDUZIDA
	
	
	else
	{
	    printf("\nCPF INVÁLIDO!");
		//printf("\nErro no primeiro verificador.");
	}
	//Fim Cálculo do primeiro dígito verificador
	
	
	
	
	//Cálculo do segundo dígito verificador
	//soma=0;
	
	/* FAZENDO COM FOR
	for(i=0; i<10; i++)
	{	
	    soma = soma + cpf[i]*m2[i];
	}
	
	resto = ((soma*10) % 11)%10;
  	*/
	
	/*
	if(calculoDigitoVerificador(cpf, m2, 10) == cpf[10])
	{
	    printf("\nSegundo verificado valido.");
	}
	
	else
	{
	    printf("\nErro no segundo veriricador");
	}
	//Fim Cálculo do segundo dígito verificador
	*/
	
	return 0;
}


