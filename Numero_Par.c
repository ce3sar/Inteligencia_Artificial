#include<stdio.h> // libreria basica para entrada y salida
#include<stdlib.h>//Libreria utilizada para usar la funcion rand() para generar numeros aleatorios

int rdtsc()
{
    __asm__ __volatile__("rdtsc");
}

int main()
{
	int tamano_arreglo=12000;
	int arreglo[tamano_arreglo];//={1,133,500,367,250,831,1000,167,267,2000,1733,1000};
	int aleatorio=0;
	int ciclo=0;
	int mayor=0;
	int divisible=0;
	
	while(ciclo<tamano_arreglo)
	{
		srand(rdtsc());
		aleatorio=rand()%tamano_arreglo+1;
		arreglo[ciclo]=aleatorio;
		printf("%d\n",aleatorio);
		ciclo++;
	}
	ciclo=1;
	while(ciclo<tamano_arreglo-2)
	{
		if(arreglo[ciclo]/2==arreglo[ciclo+2] && arreglo[ciclo-1]+arreglo[ciclo+1]==arreglo[ciclo] && arreglo[ciclo+1]%2!=0 && arreglo[ciclo]%2==0)
		{
			if(arreglo[ciclo]>mayor)
			{
				mayor=arreglo[ciclo];
			}
		}
		ciclo++;
	}
	divisible=mayor/2;
	printf("Par mayor en el arreglo es %d y es divisible %d veces.",mayor,divisible);
	scanf("%d");
	return 0;
}
