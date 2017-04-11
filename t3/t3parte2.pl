% 1) Defina um predicado somaQuad(X,Y,Q) que seja verdadeiro se Q for a soma dos quadrados de X e Y. Exemplos de uso:
somaQuad(X,Y,Q) :- Q is X*X + Y*Y.

% 2) Defina um predicado zeroInit(L) que é verdadeiro se L for uma lista que inicia com o número 0 (zero). Exemplo de uso:

zeroInit(L) :- L = [H|_], H = 0.

% 3) Defina um predicado hasEqHeads(L1,L2) que seja verdadeiro se as listas L1 e L2 possuírem o mesmo primeiro elemento. Exemplos de uso:

hasEqHeads(L1, L2) :- L1 = [H|_] , L2 = [I|_], H = I.

% 4) Defina um predicado has5(L) que seja verdadeiro se L for uma lista de 5 elementos. Lembre de como funciona a unificação em Prolog e resolva este exercício sem usar o predicado pré-definido length. Exemplos de uso:

has5(L) :- L = [_,_,_,_,_].

% 5) Defina um predicado hasN(L,N) que seja verdadeiro se L for uma lista de N elementos. Agora você pode usar um predicado pré-definido.

hasN(L,N) :- length(L, X), X =:= N.

% 6) Defina um predicado isBin(L) que seja verdadeiro se L for uma lista contendo somente elementos 0 e 1. Use recursão. Exemplo:

isBin([1]).
isBin([0]).
isBin(L) :- L = [H|T],
	    isBin(T),
	    (H = 0;
	     H = 1).

% 7) Defina um predicado mesmaPosicao(A,L1,L2) para verificar se um elemento A está na mesma posição nas listas L1 e L2. Assuma que L1 e L2 sejam permutações de uma lista de elementos distintos, sem repetições. Dica: procure auxílio em predicados pré-definidos. Exemplo de uso:

mesmaPosicao(A,L1,L2) :- nth0(X, L1, A), nth0(Y, L2, A), X = Y.

% 8) Defina um predicado repete5(E,L) que seja verdadeiro se a lista L for composta por exatamente 5 repetições do elemento E. Não use recursão. Exemplos:

repete5(E,L) :- L = [E,E,E,E,E].

% 9) Defina um predicado recursivo sumQuads(L,S) que seja verdadeiro se S for o somatório dos quadrados dos elementos da lista L.

sumQuads([], 0).
sumQuads(L, S) :- L = [H|T],
		 sumQuads(T, S1),
	         S is H*H + S1.


% 10) Defina um predicado recursivo repete(N,E,L) que seja verdadeiro se a lista L for composta por exatamente N repetições do elemento E.

repete(0, _, []).
repete(N, E, L) :- L = [H|T],
                   Na is N-1,
                   repete(Na, E, T),
                   Na > -1,
                   H = E.
% 11) Defina um predicado recursivo mapop(L1,L2) que seja verdadeiro se a lista L2 for formada aplicando-se a operação 2*x+1 a cada elemento x da lista L1.

mapop([], []).
mapop(L1,L2) :- L1 = [H|T],
                L2 = [U|I],
                mapop(T, I),
                U is H * 2 + 1.
