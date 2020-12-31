//  Bibliotecas
#include "cabecalho.h"

/*  Funcoes */
/*  Mouse */
//  Funcao responsavel por verificar onde o personagem clicou
void click_usuario(void)
{
    coluna_mouse = evento.motion.x;
    linha_mouse = evento.motion.y;

    switch(loop)
    {
        case(menu):
            //  Verificando clicks do mouse no menu
            click_menu();
            break;
        case(jogo):
            //  Verificando clicks do mouse no jogo
            click_jogo();
            break;
    }
}

//  Funcao que verifica a area onde o click foi feito
int verificar_click_local(int x, int y, int largura, int altura)
{
    if(linha_mouse > y && linha_mouse < (y + altura))
    {
        if(coluna_mouse > x && coluna_mouse < (x + largura))
        {
            return 1;
        }
    }
    return 0;
}

/*  SDL */
//  Funcao que carrega as imagens nas texturas
void carregar_textura(void)
{
    for(int incremento = 0; incremento < JOGO_TEXTURA_NUMERO; incremento++)
    {
        textura[incremento] = sdl2_carregar_textura(tela, texturas_arquivos[incremento]);
    }
}