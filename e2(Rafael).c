Código da 2

#include <stdio.h>
#include <string.h>
struct cad_dados{
	float s, sn, p;
	char n[80];
};
struct cad_dados x;
void scan(){
	printf ("Digite o Nome do Funcionario: ");
	fgets (x.n, 80, stdin);
	printf ("Digite o Salario atual do Funcionario: ");
	scanf ("%f", &x.s);
}
void calc_aumento(){
	if (x.s>0 && x.s<=400){
		x.p=0.15;
		x.sn=x.p*x.s+x.s;
	}
	else{
		if (x.s>400 && x.s<=700){
			x.p=0.12;
			x.sn=x.p*x.s+x.s;
		}
		else{
			if (x.s>700 && x.s<=1000){
				x.p=0.10;
				x.sn=x.p*x.s+x.s;
			}
			else{
				if (x.s>1000 && x.s<=1800){
					x.p=0.07;
					x.sn=x.p*x.s+x.s;
				}
				else{
					if (x.s>1800 && x.s<=2500){
						x.p=0.04;
						x.sn=x.p*x.s+x.s;
					}
					else{
						x.p=0;
						x.sn=x.s;
					}
				}
			}
		}
	}
}
void resultado(){
	printf ("%s", x.n);
	if(x.p==0){
		printf("SEM AUMENTO");
	}
	else{
		printf ("Porcentagem do aumento: %.0f\n", x.p*100);
	}
	printf ("Salario Atual: RS%.2f\n", x.s);
	printf ("Novo Salario: RS%.2f", x.sn);
}
int main(){
	scan();
	calc_aumento();
	resultado();
}