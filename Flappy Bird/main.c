/*
    Flappy Bird - versao 1.0
*/

//  Bibliotecas
#include "cabecalho.h"
#include "funcoes.c"
#include "menu.c"
#include "jogo.c"

int main(void)
{
    //  Gerando semente para a funcao rand
    srand(time(NULL));
    
    //  Iniciando SDL, IMG e TTF
    sdl2_iniciar_SDL2();

    //  Criando janela do jogo
    if((janela = sdl2_criar_janela(JANELA_NOME, JANELA_LARGURA, JANELA_ALTURA)) == NULL)
    {
        return 1;
    }

    //  Criando tela do jogo
    if((tela = sdl2_criar_tela(janela)) == NULL)
    {
        return 1;
    }

    //  Carregando fonte
    if((fonte = sdl2_carregar_fonte(FONTE_ARQUIVO, FONTE_TAMANHO)) == NULL)
    {
        return 1;
    }

    //  Carregando texturas
    carregar_textura();

    //  Resetando jogo antes de iniciar
    resetar_jogo();

    //  Loop do jogo
    loop = menu;
    while(loop != fechar_jogo)
    {
        //  Verificando se algum evento ocorreu
        while(SDL_PollEvent(&evento) != 0)
        {
            /*  Verificando qual evento ocorreu */
            //  Verificando se o usuario clicou no 'X' da janela
            if(evento.type == SDL_QUIT)
            {
                loop = fechar_jogo;
            }
            //  Verificnado se o usuario clicou
            if(evento.type == SDL_MOUSEBUTTONDOWN)
            {
                click_usuario();
            }
        }

        //  Verificando em qual tela o jogador esta
        switch(loop)
        {
            case(menu):
                funcao_menu();
                break;
            case(jogo):
                funcao_jogo();
                break;
        }

        //  Delay
        SDL_Delay(DELAY);
    }

    //  Finalizando SDL, IMG e TTF
    sdl2_fechar_fonte(fonte);
    sdl2_fechar_tela(tela);
    sdl2_fechar_janela(janela);
    sdl2_finalizar_SDL2();

    return 0;
}