#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

//  Bibliotecas
#include "sdl2/sdl2.h"
#include "menu.h"

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
//  Jogo
int loop;
//  Mouse
int linha_mouse;
int coluna_mouse;
/*  SDL */
//  Janela e tela
SDL_Window *janela = NULL;
SDL_Renderer *tela = NULL;
//  Texto
TTF_Font *fonte = NULL;
//  Evento
SDL_Event evento;

/*  Estruturas */
enum enum_jogo
{
    fechar_jogo,
    menu,
    jogo
};

/*  Funcoes */
//  Mouse
void click_usuario(void);
int verificar_click_local(int x, int y, int largura, int altura);
void carregar_textura(void);

#endif // CABECALHO_H_INCLUDED