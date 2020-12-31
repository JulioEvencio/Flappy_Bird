#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

//  Bibliotecas
#include "sdl2/sdl2.h"

/*  Constantes */
//  Janela
#define JANELA_NOME "Flappy Bird"
#define JANELA_X 0
#define JANELA_Y 0
#define JANELA_LARGURA 400
#define JANELA_ALTURA 600
//  Fonte
#define FONTE_ARQUIVO "lazy.ttf"
#define FONTE_TAMANHO 20
//  Geral
#define DELAY 30

/*  Variaveis */
/*  SDL */
//  Janela e tela
SDL_Window *janela = NULL;
SDL_Renderer *tela = NULL;
//  Texto
TTF_Font *fonte = NULL;
//  Evento
SDL_Event evento;

/*  Estruturas */

/*  Funcoes */

#endif // CABECALHO_H_INCLUDED