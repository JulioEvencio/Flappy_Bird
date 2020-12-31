//  Bibliotecas
#include "menu.h"

/*  Funcoes */
//  Funcao do menu do jogo
void funcao_menu(void)
{
    /*  Logica */
    sdl2_limpar_tela(tela, SDL2_VERDE);

    //  Botao jogar
    sdl2_desenhar_retangulo(tela, fundo_botao_jogar, MENU_BOTAO_JOGAR_X, MENU_BOTAO_JOGAR_Y, MENU_BOTAO_JOGAR_LARGURA, MENU_BOTAO_JOGAR_ALTURA, MENU_BOTAO_JOGAR_COR_FUNDO);
    sdl2_exibir_texto_solid(tela, fonte, MENU_BOTAO_JOGAR_MENSAGEM, MENU_BOTAO_JOGAR_X, MENU_BOTAO_JOGAR_Y, MENU_BOTAO_JOGAR_LARGURA, MENU_BOTAO_JOGAR_ALTURA, MENU_BOTAO_JOGAR_COR);
    //  Bottao sair
    sdl2_desenhar_retangulo(tela, fundo_botao_sair, MENU_BOTAO_SAIR_X, MENU_BOTAO_SAIR_Y, MENU_BOTAO_SAIR_LARGURA, MENU_BOTAO_SAIR_ALTURA, MENU_BOTAO_SAIR_COR_FUNDO);
    sdl2_exibir_texto_solid(tela, fonte, MENU_BOTAO_SAIR_MENSAGEM, MENU_BOTAO_SAIR_X, MENU_BOTAO_SAIR_Y, MENU_BOTAO_SAIR_LARGURA, MENU_BOTAO_SAIR_ALTURA, MENU_BOTAO_SAIR_COR);

    //  Atualizando a tela
    sdl2_atualizar_tela(tela);
}

//  Verificando click do mouse no menu
void click_menu(void)
{
    //  Usuario clicou no botao de jogar
    if(verificar_click_local(MENU_BOTAO_JOGAR_X, MENU_BOTAO_JOGAR_Y, MENU_BOTAO_JOGAR_LARGURA, MENU_BOTAO_JOGAR_ALTURA))
    {
        loop = jogo;
    }

    //  Usuario clicou no botao de sair
    if(verificar_click_local(MENU_BOTAO_SAIR_X, MENU_BOTAO_SAIR_Y, MENU_BOTAO_SAIR_LARGURA, MENU_BOTAO_SAIR_ALTURA))
    {
        loop = fechar_jogo;
    }
}