#include "StdAfx.h"
#include "JogoIA.h"
#include <stdio.h>

//***IMPORTANTE
//cor preto = 2
//cor branca = 1
//cor amarela = 0


//***VARIAVEIS GLOBAIS 

short int Tabuleiro[64];
int Turno=1; //marca quem esta jogando,quem come�a o jogo s�o as brancas, isso pode ser mudado com o m�todo SetQmInicia


//***M�TODOS


 //Inicia o tabuleiro totalmente zerado
 void IniciaTabuleiro(){
	 for(int i=0; i<64;i++){
		 Tabuleiro[i]=0;
		 //printf("pos %d = %d",i,Tabuleiro[i]);
	 }
 }

//faz a jogada, retorna 1 para jogada efetuada e 0 para jogada n efetuada, recomendado colocar a var Turno no parametro cor
//Exemplo de chamada: FazJogada(Turno,44);
 bool FazJogada(int cor,int posicao) {
	 if(Tabuleiro[posicao]==0){//se a posi��o esta vaga
		Tabuleiro[posicao]=cor;
		return(1);
	 }
	 else
		 return(0); 

 }

 //Seta quem vai come�ar o jogo 1 para brancas, 2 para pretas.
 void SetQmInicia(int cor){
	 Turno=cor;
 }


 //Muda o turno para o proximo jogador
 void ProximoTurno(){
	 if(Turno==1)
		 Turno=2;
	 else
		Turno=1;

	 }