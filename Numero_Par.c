#include<stdio.h> // libreria basica para entrada y salida
#include<stdlib.h>//Libreria utilizada para usar la funcion rand() para generar numeros aleatorios

int rdtsc()//funcion para sacar el numero de ciclos del procesador
{
    __asm__ __volatile__("rdtsc");
}

int main()
{
	int tamano_arreglo=12000;//tamano del arreglo
	int arreglo[tamano_arreglo];//creacion del arreglo  ={1,133,500,367,250,831,1000,167,267,2000,1733,1000};
	int aleatorio=0;//variable que guardara los numeros aleatorios generalos
	int ciclo=0;//variable para controlar los ciclos
	int mayor=0;//guarda el par mayor del arreglo
	int divisible=0;//guarda el  numero de veces divisible de mayor
	
	while(ciclo<tamano_arreglo)//ciclo para llenar el arreglo
	{
		srand(rdtsc());//semilla para generar diferente numeros aleaatorios
		aleatorio=rand()%tamano_arreglo+1;//genera un numero aleatorio entre 0 y el tamano del arreglo
		arreglo[ciclo]=aleatorio;//asigna a la posicion del arreglo el numero aleatorio
		//printf("%d\n",aleatorio);
		ciclo++;//aumenta la variable ciclo
	}//fin del ciclo while 
	ciclo=1;//igualas ciclo a uno
	while(ciclo<tamano_arreglo-2)//ciclo para la comparacion del especificaciones
	{
		if(arreglo[ciclo]/2==arreglo[ciclo+2] && arreglo[ciclo-1]+arreglo[ciclo+1]==arreglo[ciclo] && arreglo[ciclo+1]%2!=0 && arreglo[ciclo]%2==0)//condifiones para ver si hay un par valida en la posicion del arreglo
		{
			if(arreglo[ciclo]>mayor)//condicion para ver si la posicion del arreglo es mayor al par anterior
			{
				mayor=arreglo[ciclo];//asignacion del nuevo par mayor
			}//fin del if
		}//fin del if
		ciclo++;//aumenta la variable ciclo
	}//fin del ciclo while
	divisible=mayor/2;//cuantas veces es divisible entre 2 el par mayor encontrado
	printf("Par mayor en el arreglo es %d y es divisible %d veces.",mayor,divisible);//mostrar en pantalla el par mayor y cuantas veces es divisible
	return 0;
}
