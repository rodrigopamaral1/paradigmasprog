# -----------------------Parte 1----------------------------
# 1.Defina uma funcao somaQuad(x,y) que calcule a soma dos quadrados de dois números x e y.
def somaQuad(x,y): return pow(x,2) + pow(y,2)

# 2.Crie uma função hasEqHeads(l1,l2) que verifique se as listas l1 e l2 possuem o mesmo primeiro elemento.
def hasEqHeads(l1,l2): return l1[0] == l2[0]

# 3.Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome. Defina uma função auxiliar para ajudar neste exercício.
def ConSrAux(strings): return "Sr." + strings

list(map(ConSrAux, ["oi", "ola", "alguem"]))

# 4.Crie uma função que receba uma string e retorne o número de espaços nela contidos. Defina uma função auxiliar para ajudar neste exercício.
def CountSpaceAux(c): return c == " "

len(str(filter(CountSpaceAux, "Quantos espacos tem isto?")))

# 5.Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista. Defina uma função auxiliar para ajudar neste exercício.
def MatFuncAux(n): return 3*n*2 + 2/n + 1

list(map(MatFuncAux, [1,2,3,4]))

# 6.Escreva uma função que, dada uma lista de números, retorne uma lista com apenas os que forem negativos. Defina uma função auxiliar para ajudar neste exercício.
def ReturnNegAux(num): return num < 0

list(filter(ReturnNegAux, [-1,0,1]))

# 7.Escreva uma função que receba uma lista de números e retorne somente os que estiverem entre 1 e 100, inclusive. Defina uma função auxiliar para ajudar neste exercício.
def Return0_100aux(num): return num > 0 and num < 101

list(filter(Return0_100aux, [-1,0,1,99,100,101]))

# 8.Escreva uma função que receba uma lista de números e retorne somente aqueles que forem pares. Defina uma função auxiliar para ajudar neste exercício.
def RetParAux(x): return x%2 == 0

list(filter(RetParAux, [1,2,3,4]))

# 9.Crie uma função charFound(c,s) que verifique se o caracter c está contido na string. O resultado deve ser True ou False. Você não deve usar o operador in. Defina uma função auxiliar para ajudar neste exercício.
def charFound(c,s):
    def aux(x): return x == c
    return len(str(filter(aux, s))) > 0

# 10.Escreva uma função que receba uma lista de strings e retorne uma nova lista com adição de marcações HTML (p.ex.: <B> e </B>) antes e depois de cada string.
def html_aux(string): return "<B>" + string + "</B>"

list(map(html_aux, ["oi", "ola"]))
