//Aluno: Rafael Bauer Sampaio
//Curso: Ciencia da computacao | 7 periodo | noite

#include "FreeRTOS.h"
#include "task.h"
#include "basic_io.h"
#include <time.h>
#include <stdlib.h>

void taskBatimentos(void *pvParameters);
void taskSaturacao(void* pvParameters);
void taskTemperatura(void* pvParameters);
const TickType_t delay = 1000;  //cria uma variavel com valor 1000 para ser usada
							   //como parametro para o vTaskDelay das tarefas

void taskBatimentos(void *pvParameters)
{
	srand(time(NULL)); //cria numero aleatorio
	int upper = 140;	 //define limite maximo
	int lower = 20;	    //define limite minimo
	for (;; )
	{
		int batimento = (rand() % (upper - lower + 1)) + lower; //gera um numero aleatorio entre 20 e 140
		if (batimento < 50) {
			vPrintStringAndNumber("Batimento cardiaco baixo - ", batimento); //exibe batimento baixo caso seja < 50
		}
		else if (batimento > 90) {
			vPrintStringAndNumber("Batimento cardiaco alto - ", batimento); //exibe batimento alto caso > 90
		}

		vTaskDelay(delay); //delay de 1s
		
	}

	vTaskDelete(NULL); //exclui a tarefa
}

void taskSaturacao(void* pvParameters)
{
	srand(time(NULL)); //cria numero aleatorio
	int upper = 100;     //define limite maximo
	int lower = 80;		//define limite minimo
	for (;; )
	{
		int saturacao = (rand() % (upper - lower + 1)) + lower; //gera um numero aleatorio entre 80 e 100
		if (saturacao < 90) {
			vPrintStringAndNumber("Saturacao baixa - ", saturacao); //exibe saturacao baixa caso seja < 90
		}

		vTaskDelay(delay); //delay de 1s

	}

	vTaskDelete(NULL); //exclui a tarefa
}

void taskTemperatura(void* pvParameters)
{
	srand(time(NULL)); //cria numero aleatorio
	int upper = 41;      //define limite maximo
	int lower = 34;     //define limite minimo
	for (;; )
	{
		float temperatura = (rand() % (upper - lower + 1)) + lower; //gera um numero float aleatorio entre 34 e 41
		if (temperatura < 35) {
			vPrintStringAndNumber("Hipotermia - ", temperatura); //exibe hipotermia caso seja < 35
		}
		else if (temperatura > 37.5) {
			vPrintStringAndNumber("Febre - ", temperatura); //exibe febre caso seja > 37.5
		}

		vTaskDelay(delay); //delay de 1s

	}

	vTaskDelete(NULL); //exclui a tarefa
}

int main_(void)
{

	xTaskCreate(taskBatimentos, "task batimentos", 1000, "Batimentos:", 1, NULL);
	xTaskCreate(taskSaturacao, "task saturacao", 1000, "Saturacao:", 1, NULL);
	xTaskCreate(taskTemperatura, "task temperatura", 1000, "Temperatura:", 1, NULL);


	vTaskStartScheduler();

	for (;; );
	return 0;
}
