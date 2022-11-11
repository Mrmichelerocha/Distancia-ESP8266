#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "memoria.h"
#include "digital.h"
#include "i2c.h"
#include "serial.h"
#include <inttypes.h> 

#define DEVICE_I2C 0x50

//Estrutura do registro
typedef struct {
    char nome[20];
    char telefone[14];
    char endereco[30];
}registro;

extern "C" void app_main() ;
int v=0;
void app_main()
{
    serial.begin(9600);

    printf("Funcionando...\n");
    printf("Para iniciar a lista primeiro pressione [7]\n");
    
    char buffer[100];
    char leitura[100];
    
    // pinos de dados eh o 16 e pino de clock eh o 5
    Memoria memoria_i2c = Memoria();

    //Loop menu
    while(1)
    {
        printf("\tMENU\n");
        printf("[1] - Inserir dados\n");
        printf("[2] - Lista todos os registros\n");
        printf("[3] - Pesquisa registro por nome\n");
        printf("[4] - Pesquisa registro por telefone\n");
        printf("[5] - Remove registro baseado no telefone\n");
        printf("[6] - Mostra a quantidade de registros atualmente armazenados\n");
        printf("[7] - Inicializa o banco de dados (todas as informacoes armazenadas serao perdidas)\n");

        char ch;
        printf("Escolha uma opcao: ");
        ch = serial.readChar();

        switch(ch)
        {
            case '1':
                // char x = getchar();
                printf("[1]\n");
                printf("Digite o nome: ");
                // strcpy(buffer, x);
                serial.readString((uint8_t *)buffer,100);
                // strcpy(registro.nome, leitura);
                memoria_i2c.escreve(100, (uint8_t *)buffer,strlen(buffer)+1);

                // printf("Digite o telefone: ");
                // buffer = serial.readString((uint8_t *)leitura,100);
                // strcpy(tipo_registro.telefone, buffer);
                // memoria_i2c.escreve(100, (uint8_t *)tipo_registro.telefone,strlen(buffer)+1);

                // printf("Digite o endereco: ");
                // buffer = serial.readString((uint8_t *)leitura,100);
                // strcpy(tipo_registro.endereco, buffer);
                // memoria_i2c.escreve(100, (uint8_t *)tipo_registro.endereco,strlen(buffer)+1);

                printf("Salvos na memoria !!\n");
                break;
            case '2':
                printf("[2]\n");
                memoria_i2c.le(100,(uint8_t *)leitura,25);
                printf("Nome: %s\n",leitura);

                // memoria_i2c.le(100,(uint8_t *)leitura,25);
                // printf("Telefone: %c\n",leitura);
                
                // memoria_i2c.le(100,(uint8_t *)leitura,25);
                // printf("Endereco: %c\n",leitura);  
                break;
            case '3':
                // printf("Digite o nome a ser pesquisado na lista\n")
                // printf("Nome: ");
                // serial.readString((uint8_t *)tipo_registro.nome, 10);

                // memoria_i2c.le(100,(uint8_t *)tipo_registro.nome, 25);
                // memoria_i2c.le(100,(uint8_t *)tipo_registro.telefone, 25);
                // printf("Nome encontrado: %c, com telefone: %c\n", tipo_registro.nome, tipo_registro.telefone);
                break;
            case '4':
                // char tel = getchar();
                // memoria_i2c.le(100,(uint8_t *)leitura, 25);
                // printf("Valor lido %c, com telefone: %c\n", leitura, tel);
                break;
            case '5':
                // remove_registro();
                break;
            case '6':
                // qnt_registro();
                break;
            case '7':
                memoria_i2c.init(0);
                printf("Memoria foi inicializada!!!\n");
                break;
    };
    
};


