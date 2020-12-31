#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

//  Bibliotecas
#include "cabecalho.h"

/*  Constantes */
//  Personagem
#define PERSONAGEM_X 100
#define PERSONAGEM_Y 200
#define PERSONAGEM_LARGURA 30
#define PERSONAGEM_ALTURA 30
//  Cenario
#define CENARIO_MOVIMENTO 10
#define BASE_NUMERO 2
#define BASE_X 0
#define BASE_Y 550
#define BASE_LARGURA JANELA_LARGURA * 2
#define BASE_ALTURA 50
#define BASE_CORRECAO_MOVIMENTO 10
//  Cano
#define CANO_NUMERO 2
//  Cano virado para cima
#define CANO_CIMA_X 130
#define CANO_CIMA_Y JANELA_ALTURA - CANO_CIMA_ALTURA
#define CANO_CIMA_LARGURA 50
#define CANO_CIMA_ALTURA 250 + (rand() % 50)
//  Cano virado para baixo
#define CANO_BAIXO_X 380
#define CANO_BAIXO_Y 0
#define CANO_BAIXO_LARGURA 50
#define CANO_BAIXO_ALTURA 250 + (rand() % 50)
//  Animacao do personagem
#define ANIMACAO_INICIO 1
#define ANIMACAO_FINAL 3
#define ANIMACAO_QUADRO1(x) x == 1
#define ANIMACAO_QUADRO2(x) x == 2
#define ANIMACAO_QUADRO3(x) x == 3
//  Texturas
#define JOGO_TEXTURA_NUMERO 7
//  Geral
#define GRAVIDADE 10

/*  Variaveis */
//  Gravidade do jogo
int gravidade = GRAVIDADE;
//  Vetor de string dos arquivos
static char *texturas_arquivos[JOGO_TEXTURA_NUMERO] = 
{
    "imagens/passaro_sprite_1.png",
    "imagens/passaro_sprite_3.png",
    "imagens/passaro_sprite_2.png",
    "imagens/fundo.png",
    "sprites/base.png",
    "imagens/cano_cima.png",
    "imagens/cano_baixo.png",
};
//  SDL Jogo
SDL_Texture *textura[JOGO_TEXTURA_NUMERO];

/*  Estruturas */
//  Struct do personagem
struct tipo_personagem
{
    int x;
    int y;
    int largura;
    int altura;
};
typedef struct tipo_personagem Personagem;
Personagem personagem;
//  Struct do cano
struct tipo_cano
{
    int x;
    int y;
    int largura;
    int altura;
    int tipo;
};
typedef struct tipo_cano Cano;
Cano cano[CANO_NUMERO];
//  Struct do cenario
struct tipo_cenario
{
    int base[BASE_NUMERO];
};
typedef struct tipo_cenario Cenario;
Cenario cenario;
//  Enum da base
enum enum_base
{
    base1_x,
    base2_x
};
//  Enum do cano
enum enum_cano
{
    cano_virado_cima,
    cano_virado_baixo
};
//  Enum das texturas
enum enum_textura
{
    personagem_textura_sprite1,
    personagem_textura_sprite2,
    personagem_textura_sprite3,
    fundo_textura,
    base,
    cano_cima,
    cano_baixo
};

/*  Funcoes */
void funcao_jogo(void);
void click_jogo(void);
void resetar_jogo(void);
void animar_personagem(void);
void ativar_gravidade(void);
void verificar_morte(int colisao);
void pular_personagem(void);
void movimentar_cenario(void);
void desenhar_cano(void);
void resetar_cano(void);
int verificar_colisao_cano1(void);
int verificar_colisao_cano2(void);
int verificar_colisao(void);

#endif // JOGO_H_INCLUDED