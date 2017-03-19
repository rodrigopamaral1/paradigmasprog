#--------------------------PARTE 2----------------------------

# 1.Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.
def ConcatenaSr(lista): return list(map(lambda x:"Sr." + x, lista))

# 2.Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.

def func_mat(lista): return list(map(lambda x:3*x*2 + 2/x + 1, lista))

# 3.Crie uma função que receba uma lista de nomes e retorne outra lista com somente aqueles nomes que terminarem com a letra 'a'.
def termina_com_a(lista): return list(filter(lambda x:x[len(x)-1] == "a", lista))

# 4.Escreva uma função que, dada uma lista de idades de pessoas no ano atual, retorne uma lista somente com as idades de quem nasceu depois de 1970. Para testar a condição, sua função deverá subtrair a idade do ano atual.
# >>> idades([20,30,51,57])
# [20, 30]

def func_1970(lista): return list(filter(lambda x:2017-x > 1970, lista))

# 5. O código abaixo é escrito em Python imperativo. Escreva um código equivalente usando programação funcional.

#numbers = [1, 2, 3, 4]
#new_numbers = []
#for number in numbers:
# new_numbers.append(number * 2)
#print(new_numbers)

def func_numbers(lista): return list(map(lambda x:x*2, lista))
