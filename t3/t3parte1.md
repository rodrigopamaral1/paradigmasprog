[trace]  ?- avo(joao,Y). 
   Call: (8) avo(joao, _5448) ? creep // CHAMADA DA FUNÇÃO AVO
   Call: (9) pai(joao, _5666) ? creep // CHAMADA DA PRIMEIRA FUNçÃO DE AVO
   Exit: (9) pai(joao, jose) ? creep //  RETORNO COM SUCESSO, JOAO POSSUI UM FILHO JOSE
   Call: (9) pai(jose, _5448) ? creep // CHAMADA DA SEGUNDA FUNÇÂO DE AVO, AGORA PRA PROCURAR FILHOS DE JOSE, NETOS DE JOAO
   Fail: (9) pai(jose, _5448) ? creep// FALHOU, NAO ENCONTRA NENHUM FILHO DE JOSE, LOGO NAO A NETOS DE JOAO
   Fail: (8) avo(joao, _5448) ? creep// FAHOU, PROCURA POR MAIS FILHOS E NAO ACHA, ENTAO RETORNA FALSE
false.


[trace]  ?- avo(roberto,Y).
   Call: (8) avo(roberto, _5110) ? creep // CHAMADA A FUNÇÂO AVO
   Call: (9) pai(roberto, _5324) ? creep // CHAMADA DA FUNÇAO DE AVO PROCURANDO POR FILHOS DE ROBERTO
   Exit: (9) pai(roberto, joao) ? creep // RETORNO COM SUCESSO, ENCONTROU UM FILHO DE ROBERTO, VOLTA PARA A FUNCAO AVO
   Call: (9) pai(joao, _5110) ? creep // CHAMADA DA SEGUNDA FUNÇAO DE AVO, PROCURANDO PELO NETO DE ROBERTO, FILHO DE JOAO
   Exit: (9) pai(joao, jose) ? creep // RETONO COM SUCESSO ENCONTROU JOSE FILHO DE JOAO E NETO DE ROBERTO
   Exit: (8) avo(roberto, jose) ? creep // FUNÇAO RETORNA COM SUCESSO, Y = JOSE
Y = jose ;
   Redo: (9) pai(roberto, _5324) ? creep // VOLTANDO A PROCURAR FILHOS DE ROBERTO
   Exit: (9) pai(roberto, julio) ? creep // RETORNO COM SUCESSO JULIO
   Call: (9) pai(julio, _5110) ? creep // CHAMADA DA SEGUNDA FUNÇAO DE AVO 
   Exit: (9) pai(julio, marcos) ? creep // RETORNA MARCOS NETO DE ROBERTO E FILHO DE JULIO
   Exit: (8) avo(roberto, marcos) ? creep // RETORNA COM SUCESSO Y = MARCOS
Y = marcos ;
   Redo: (9) pai(julio, _5110) ? creep // VOLTANDO A PROCURAR POR FILHOS DE JULIO
   Exit: (9) pai(julio, mario) ? creep // RETORNA MARIO
   Exit: (8) avo(roberto, mario) ? creep// RETONA Y = MARIO
Y = mario.
