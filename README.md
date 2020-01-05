# jogo-da-vida

Introdução

  Em  1970,  o  cientista  John  Conwayinventou  um  jogo  que  simula  o  processo  de nascimento,  sobrevivência,  e  morte.O  jogo  da  vida  é  um  autômato  celular  e  foi  criado  de modo  a  reproduzir,  através  de  regras  simples,  as  alterações  e  mudanças  em  grupos  de  seres vivos, tendo aplicações em diversas áreas da ciência (ver: http://pt.wikipedia.org/wiki/Jogo_da_vida).
  A ideia base é que um ser  vivo necessita de outros seres vivos para sobreviver e procriar, mas um excesso de densidade populacional provoca a morte do ser vivo devido à escassez de comida.  Os  indivíduos  vivem  num  mundo  matricial  e  a  geração  seguinte  é  gerada  a  partir  da geração anterior de acordo com as seguintes regras:
  
  - Reprodução: Um ser vivo nasce numa célula vazia se essa célula vazia tiver exatamente 3 seres vivos vizinhos. 
  - Sobrevivência:  Um  ser  vivo  que  tenha  2  ou  3  vizinhos  sobrevive  para  a  geração seguinte. 
  - Morte por falta de comida: Um ser vivo com 4 ou mais vizinhos morre porque fica sem comida. 
  - Morte por solidão: Um ser vivo com 0 ou 1 vizinhos morre de solidão.
  
  A cada geração, as regras devem ser aplicadas para todos os seres vivos ao mesmo tempo (isto é no mesmo passo) para obtermos o próximo passo ou geração. 
  
Objetivo
  
  O  objetivo  do  projeto  é  criar  um  programa  em C para simular  o  jogo  da  vida.  Os  indivíduos vivem numa matriz e o programa deve gerar a geração seguinte a partir das regra previamente apresentadas. Cada posição da matriz é uma célula que pode ter um “O” (para representar um ser  vivo)  ou  um  espaço  em  branco.  Cada  célula  tem  um  máximo de  8  células  vizinhas.  Fica  a seu  critério  escolher  se  a  última  célula  é  vizinha  da  primeira  (o  mundo  é  esférico)  ou  não  (o mundo é plano).

    
