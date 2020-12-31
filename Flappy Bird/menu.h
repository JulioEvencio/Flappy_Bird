#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//  Bibliotecas
#include "cabecalho.h"

/*  Constantes */
//  Botao jogar
#define MENU_BOTAO_JOGAR_MENSAGEM "Jogar"
#define MENU_BOTAO_JOGAR_X 150
#define MENU_BOTAO_JOGAR_Y 200
#define MENU_BOTAO_JOGAR_LARGURA 100
#define MENU_BOTAO_JOGAR_ALTURA 50
#define MENU_BOTAO_JOGAR_COR SDL2_PRETO
#define MENU_BOTAO_JOGAR_COR_FUNDO SDL2_BRANCO
//  Botao sair
#define MENU_BOTAO_SAIR_MENSAGEM "Sair"
#define MENU_BOTAO_SAIR_X 150
#define MENU_BOTAO_SAIR_Y 260
#define MENU_BOTAO_SAIR_LARGURA 100
#define MENU_BOTAO_SAIR_ALTURA 50
#define MENU_BOTAO_SAIR_COR SDL2_PRETO
#define MENU_BOTAO_SAIR_COR_FUNDO SDL2_BRANCO

/* Variaveis */
//  SDL Menu
SDL_Rect fundo_botao_jogar;
SDL_Rect fundo_botao_sair;

/*  Estruturas */

/*  Funcoes */
void funcao_menu(void);
void click_menu(void);

#endif // MENU_H_INCLUDED