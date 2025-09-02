# CRIANDO-UM-PORTSCAN-EM-C
O código abaixo mostra como criar um programa em C que varre portas de um host utilizando sockets TCP.

⚠️ Uso exclusivo para fins educacionais • Desenvolvido por M!ss s3c

1. Criar o arquivo do programa

No terminal, digite:

nano portscan.c


Adicione o seguinte código:

#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if(argc < 2){
        printf("Uso: ./portscan <IP-alvo>\n");
        return 0;
    }

    int meusocket; 
    int conecta;
    int porta;
    int inicio = 0;
    int final = 65535;
    char *destino = argv[1];

    struct sockaddr_in alvo;

    for(porta = inicio; porta <= final; porta++) {

        meusocket = socket(AF_INET, SOCK_STREAM, 0);
        if(meusocket < 0) continue;

        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(porta);
        alvo.sin_addr.s_addr = inet_addr(destino);

        conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof(alvo));
        if(conecta == 0){
            printf("Porta %d - status [aberta]\n", porta);
        }

        close(meusocket);
    }

    return 0;
}

2. Compilar o programa

No terminal, digite:

gcc portscan.c -o portscan


gcc → compilador C

-o portscan → nome do executável gerado

3. Executar o programa
./portscan 192.168.0.1


192.168.0.1 → substitua pelo IP alvo que deseja varrer.

O programa tentará conectar a todas as portas de 0 a 65535 e exibirá somente as abertas.

4. Observações importantes

Usar esse tipo de scanner em redes sem permissão é ilegal. Apenas use em ambientes autorizados ou para aprendizado.

Para melhorar a performance, você pode:

Reduzir o intervalo de portas (ex: 1 a 1024).

Utilizar threads ou forks para varredura paralela.

Sempre feche os sockets após o uso com close().

👉 O que você aprendeu aqui

Criar sockets TCP em C para testar portas (socket(), connect()).

Laço for para varredura de portas sequencial.

htons() e inet_addr() para trabalhar com IP e portas.

close() para liberar recursos do sistema.
