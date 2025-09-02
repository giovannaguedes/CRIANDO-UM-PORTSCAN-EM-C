#include<stdio.h>

#include<sys/socket.h>

#include<netdb.h>

int main (int argc, char *argv[]){

	int meusocket; 
	int conecta;
	//declarando porta e o destino ip e dando inicio ao teste de portas começando de 0 indo até 65535.
	int porta;
	int inicio = 0;
	int final = 65535;
	char *destino;
	destino = argv[1];
	
	struct sockaddr_in alvo;
	
	for(porta=inicio;porta<final;porta++){
	
	meusocket = socket (AF_INET, SOCK_STREAM, 0) ;
	alvo.sin_family = AF_INET;
	alvo.sin_port = htons (porta) ;
	alvo.sin_addr.s_addr = inet_addr(destino);

	conect = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);
	if(conecta == 0){
		printf("porta %d - status [aberta] \n");
		close(meusocket);
		close(conecta);
	}else{
		close(meusocket);
		close(conecta);
	}
	}
}
