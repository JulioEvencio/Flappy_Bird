/*
    Flappy Bird - versao 1.0
*/

//  Bibliotecas
#include "cabecalho.h"
#include "sdl2/sdl2.c"
#include "funcoes.c"

int main(int argc, char *args[])
{
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
        }

        //  Verificando em qual tela o jogador esta
        switch(loop)
        {
            case(menu):
                //  Code
                break;
            case(jogo):
                //  Code
                break;
        }

        //  Delay
        SDL_Delay(DELAY);
    }


    //  Finalizando SDL, IMG e TTF
    sdl2_finalizar_SDL2();

    return 0;
}