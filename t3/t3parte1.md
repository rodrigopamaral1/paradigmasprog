---------------------------------------PARTE 1-----------------------------------------------------------------------</p>
[trace]  ?- avo(joao,Y). </p>
   Call: (8) avo(joao, _5448) ? creep // CHAMADA DA FUNÇÃO AVO</p>
   Call: (9) pai(joao, _5666) ? creep // CHAMADA DA PRIMEIRA FUNçÃO DE AVO</p>
   Exit: (9) pai(joao, jose) ? creep //  RETORNO COM SUCESSO, JOAO POSSUI UM FILHO JOSE</p>
   Call: (9) pai(jose, _5448) ? creep // CHAMADA DA SEGUNDA FUNÇÂO DE AVO, AGORA PRA PROCURAR FILHOS DE JOSE, NETOS DE JOAO</p>
   Fail: (9) pai(jose, _5448) ? creep// FALHOU, NAO ENCONTRA NENHUM FILHO DE JOSE, LOGO NAO A NETOS DE JOAO</p>
   Fail: (8) avo(joao, _5448) ? creep// FAHOU, PROCURA POR MAIS FILHOS E NAO ACHA, ENTAO RETORNA FALSE</p>
false.</p>
</p>
</p>
[trace]  ?- avo(roberto,Y).</p>
   Call: (8) avo(roberto, _5110) ? creep // CHAMADA A FUNÇÂO AVO</p>
   Call: (9) pai(roberto, _5324) ? creep // CHAMADA DA FUNÇAO DE AVO PROCURANDO POR FILHOS DE ROBERTO</p>
   Exit: (9) pai(roberto, joao) ? creep // RETORNO COM SUCESSO, ENCONTROU UM FILHO DE ROBERTO, VOLTA PARA A FUNCAO AVO</p>
   Call: (9) pai(joao, _5110) ? creep // CHAMADA DA SEGUNDA FUNÇAO DE AVO, PROCURANDO PELO NETO DE ROBERTO, FILHO DE JOAO</p>
   Exit: (9) pai(joao, jose) ? creep // RETONO COM SUCESSO ENCONTROU JOSE FILHO DE JOAO E NETO DE ROBERTO</p>
   Exit: (8) avo(roberto, jose) ? creep // FUNÇAO RETORNA COM SUCESSO, Y = JOSE</p>
Y = jose ;</p>
   Redo: (9) pai(roberto, _5324) ? creep // VOLTANDO A PROCURAR FILHOS DE ROBERTO</p>
   Exit: (9) pai(roberto, julio) ? creep // RETORNO COM SUCESSO JULIO</p>
   Call: (9) pai(julio, _5110) ? creep // CHAMADA DA SEGUNDA FUNÇAO DE AVO </p>
   Exit: (9) pai(julio, marcos) ? creep // RETORNA MARCOS NETO DE ROBERTO E FILHO DE JULIO</p>
   Exit: (8) avo(roberto, marcos) ? creep // RETORNA COM SUCESSO Y = MARCOS</p>
Y = marcos ;</p>
   Redo: (9) pai(julio, _5110) ? creep // VOLTANDO A PROCURAR POR FILHOS DE JULIO</p>
   Exit: (9) pai(julio, mario) ? creep // RETORNA MARIO</p>
   Exit: (8) avo(roberto, mario) ? creep// RETONA Y = MARIO</p>
Y = mario.</p>
-----------------------------------------------PARTE 2---------------------------------------------------------</p>
[trace]  ?- azulejos(120,A). </p>
   Call: (8) azulejos(120, _5110) ? creep // CHAMADA DA FUNCAO </p>
   Call: (9) 120>0 ? creep // VERIFICA SE NA > 0, no caso 120</p>
   Exit: (9) 120>0 ? creep // SAIDA POIS E VERDADEIRO</p>
   Call: (9) _5336 is floor(sqrt(120)) ? creep // TIRA RAIZ DE 120 E AREDONDA</p>
   Exit: (9) 10 is floor(sqrt(120)) ? creep //  RESULTADO = 10</p>
   Call: (9) _5348 is 120-10*10 ? creep // CALCULA NA - 10 * 10 E ARMAZENA EM R</p>
   Exit: (9) 20 is 120-10*10 ? creep //  R = 20</p>
   Call: (9) azulejos(20, _5350) ? creep // CHAMA FUNÇAO MANDA R COMO NUMEROS DE AZULEIJOS</p>
   Call: (10) 20>0 ? creep // VERICA SE NA, no caso 20 e maior que 0</p>
   Exit: (10) 20>0 ? creep // RECEBE O VALOR DE SAIDA, TRUE</p>
   Call: (10) _5356 is floor(sqrt(20)) ? creep // CALCULA RAIZ NOVAMENTE COMO ACIMA</p>
   Exit: (10) 4 is floor(sqrt(20)) ? creep // 4 </p>
   Call: (10) _5368 is 20-4*4 ? creep // FAZ NA - 10*10 E ARMAZENA EM R</p>
   Exit: (10) 4 is 20-4*4 ? creep //</p>
   Call: (10) azulejos(4, _5370) ? creep // CHAMA A PROXIMA RECURSAO ASSIM SUCESSIVAMENTE</p>
   Call: (11) 4>0 ? creep // </p>
   Exit: (11) 4>0 ? creep  //</p>
   Call: (11) _5376 is floor(sqrt(4)) ? creep //</p>
   Exit: (11) 2 is floor(sqrt(4)) ? creep//</p>
   Call: (11) _5388 is 4-2*2 ? creep//</p>
   Exit: (11) 0 is 4-2*2 ? creep //</p>
   Call: (11) azulejos(0, _5390) ? creep // AQUI </p>
   Exit: (11) azulejos(0, 0) ? creep// CHAMA A PROXIMA RECURSAO PASSANDO VALOR 0, para NA, COMO ESSA E A CONDIÇAO DE PARA COMEÇA RETORNAR</p>
   Call: (11) _5394 is 1+0 ? creep // AGORA COMEÇAM AS COMPARAÇOES DE RETORNO </p>
   Exit: (11) 1 is 1+0 ? creep   // NQ is 1 + C</p>
   Exit: (10) azulejos(4, 1) ? creep</p>
   Call: (10) _5400 is 1+1 ? creep</p>
   Exit: (10) 2 is 1+1 ? creep</p>
   Exit: (9) azulejos(20, 2) ? creep</p>
   Call: (9) _5110 is 1+2 ? creep</p>
   Exit: (9) 3 is 1+2 ? creep</p>
   Exit: (8) azulejos(120, 3) ? creep</p>
A = 3 ;                                   // TEMOS A RESPOTA AQUI</p>
   Redo: (11) azulejos(0, _5390) ? creep  //</p>
   Call: (12) 0>0 ? creep  // APOS OS CALULOS  A CONDIÇAO DENTRO NA RECURSAO DA FALSE EM TODAS AS OUTRAS FUNÇOES.</p>
   Fail: (12) 0>0 ? creep</p>
   Fail: (11) azulejos(0, _5390) ? creep</p>
   Fail: (10) azulejos(4, _5370) ? creep</p>
   Fail: (9) azulejos(20, _5350) ? creep</p>
   Fail: (8) azulejos(120, _5110) ? creep</p>
false.</p>

