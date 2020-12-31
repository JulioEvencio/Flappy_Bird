//  Bibliotecas
#include "jogo.h"

/*  Funcoes */
//  Funcao do jogo
void funcao_jogo(void)
{
    /*  Logica */
    sdl2_limpar_tela(tela, SDL2_CIANO);

    //  Movimentando cenario
    movimentar_cenario();

    //  Gravidade
    ativar_gravidade();
    
    //  Fundo
    sdl2_desenhar_textura(tela, textura[fundo_textura], JANELA_X, JANELA_Y, JANELA_LARGURA, JANELA_ALTURA);
    //  Personagem
    animar_personagem();
    //  Cano
    desenhar_cano();
    //  Base/chao
    sdl2_desenhar_textura(tela, textura[base], cenario.base[base1_x], BASE_Y, BASE_LARGURA, BASE_ALTURA);
    sdl2_desenhar_textura(tela, textura[base], cenario.base[base2_x], BASE_Y, BASE_LARGURA, BASE_ALTURA);

    //  Atualizando tela
    sdl2_atualizar_tela(tela);

    //  Verificando se o usuario morreu
    verificar_morte(verificar_colisao());
}

//  Verificando click do mouse no jogo
void click_jogo(void)
{
    //  Pulo do personagem
    pular_personagem();
}

//  Funcao que reseta os dados do personagem
void resetar_jogo(void)
{
    //  Personagem
    personagem.x = PERSONAGEM_X;
    personagem.y = PERSONAGEM_Y;
    personagem.largura = PERSONAGEM_LARGURA;
    personagem.altura = PERSONAGEM_ALTURA;
    //  Base
    cenario.base[base1_x] = BASE_X;
    cenario.base[base2_x] = BASE_LARGURA;
    //  Cano
    resetar_cano();
}

//  Funcao que faz as animacoes dos sprites
void animar_personagem(void)
{
    //  Personagem
    static int sprites = ANIMACAO_INICIO;
    if(ANIMACAO_QUADRO1(sprites))
    {
        sdl2_desenhar_textura(tela, textura[personagem_textura_sprite1], personagem.x, personagem.y, personagem.largura, personagem.altura);
    }
    if(ANIMACAO_QUADRO2(sprites))
    {
        sdl2_desenhar_textura(tela, textura[personagem_textura_sprite2], personagem.x, personagem.y, personagem.largura, personagem.altura);
    }
    if(ANIMACAO_QUADRO3(sprites))
    {
        sdl2_desenhar_textura(tela, textura[personagem_textura_sprite3], personagem.x, personagem.y, personagem.largura, personagem.altura);
    }
    sprites++;
    if(sprites > ANIMACAO_FINAL)
    {
        sprites = ANIMACAO_INICIO;
    }
}

//  Funcao responsavel pela gravidade do jogo
void ativar_gravidade(void)
{
    //  Gravidade no personagem
    personagem.y += gravidade;
    gravidade++;
}

//  Funcao que verifica a morte do personagem
void verificar_morte(int colisao)
{
    if((personagem.y + personagem.altura) > BASE_Y || colisao)
    {
        loop = menu;
        gravidade = GRAVIDADE;
        resetar_jogo();
    }
}

//  Funcao responsavel pelo pulo do personagem
void pular_personagem(void)
{
    gravidade = -GRAVIDADE;
}


//  Funcao responsavel pela movimentacao do cenario
void movimentar_cenario(void)
{
    //  Movimentando base
    for(int incremento = 0; incremento < BASE_NUMERO; incremento++)
    {
        cenario.base[incremento] -= CENARIO_MOVIMENTO;
    }
    //  Resetando a posicao da base quando a ela sair do cenario
    for(int incremento = 0; incremento < BASE_NUMERO; incremento++)
    {
        if((cenario.base[incremento] + BASE_LARGURA) < JANELA_X)
        {
            cenario.base[incremento] = BASE_LARGURA - BASE_CORRECAO_MOVIMENTO;
        }
        if((cano[incremento].x + CANO_BAIXO_LARGURA) < JANELA_X)
        {
            cano[incremento].x = CANO_CIMA_X + JANELA_LARGURA;
        }
    }

    //  Movimentando cano
    for(int incremento = 0; incremento < CANO_NUMERO; incremento++)
    {
        cano[incremento].x -= CENARIO_MOVIMENTO;
    }
    //  Resetando a posicao do cano quando a ela sair do cenario
    for(int incremento = 0; incremento < CANO_NUMERO; incremento++)
    {
        if((cano[incremento].x + CANO_BAIXO_LARGURA) < JANELA_X)
        {
            cano[incremento].x = CANO_CIMA_X + JANELA_LARGURA;
        }
    }
}

//  Funcao que desenha todos os canos
void desenhar_cano(void)
{
    for(int incremento = 0; incremento < CANO_NUMERO; incremento++)
    {
        //  Cano virado para cima
        if(cano[incremento].tipo == cano_virado_cima)
        {
            sdl2_desenhar_textura(tela, textura[cano_cima], cano[incremento].x, cano[incremento].y, cano[incremento].largura, cano[incremento].altura);
        }
        //  Cano virado para baixo
        if(cano[incremento].tipo == cano_virado_baixo)
        {
            sdl2_desenhar_textura(tela, textura[cano_baixo], cano[incremento].x, cano[incremento].y, cano[incremento].largura, cano[incremento].altura);
        }
    }
}

//  Funcao que reseta as posicoes dos canos
void resetar_cano(void)
{
    for(int incremento = 0; incremento < CANO_NUMERO; incremento++)
    {
        if((incremento % 2) == 0)
        {
            cano[incremento].tipo = cano_virado_baixo;
        }
        else
        {
            cano[incremento].tipo = cano_virado_cima;
        }
        if(cano[incremento].tipo == cano_virado_cima)
        {
            cano[incremento].x = CANO_CIMA_X;
            cano[incremento].y = CANO_CIMA_Y;
            cano[incremento].largura = CANO_CIMA_LARGURA;
            cano[incremento].altura = CANO_CIMA_ALTURA;
        }
        else
        {
            cano[incremento].x = CANO_BAIXO_X;
            cano[incremento].y = CANO_BAIXO_Y;
            cano[incremento].largura = CANO_BAIXO_LARGURA;
            cano[incremento].altura = CANO_BAIXO_ALTURA;
        }
    }
}

//  Funcao que verifica colisao do personagem com o cano 1
int verificar_colisao_cano1(void)
{
    //  Cano 1
    if((personagem.y + personagem.altura) < cano[cano_virado_baixo].y)
    {
        return 0;
    }
    if(personagem.y > (cano[cano_virado_baixo].y + cano[cano_virado_baixo].altura))
    {
        return 0;
    }
    if((personagem.x + personagem.largura) < cano[cano_virado_baixo].x)
    {
        return 0;
    }
    if(personagem.x > (cano[cano_virado_baixo].x + cano[cano_virado_baixo].largura))
    {
        return 0;
    }

    return 1;
}

//  Funcao que verifica colisao do personagem com o cano 2
int verificar_colisao_cano2(void)
{
    //  Cano 1
    if((personagem.y + personagem.altura) < cano[cano_virado_cima].y)
    {
        return 0;
    }
    if(personagem.y > (cano[cano_virado_cima].y + cano[cano_virado_cima].altura))
    {
        return 0;
    }
    if((personagem.x + personagem.largura) < cano[cano_virado_cima].x)
    {
        return 0;
    }
    if(personagem.x > (cano[cano_virado_cima].x + cano[cano_virado_cima].largura))
    {
        return 0;
    }

    return 1;
}

int verificar_colisao(void)
{
    if(verificar_colisao_cano1() || verificar_colisao_cano2())
    {
        return 1;
    }
    return 0;
}