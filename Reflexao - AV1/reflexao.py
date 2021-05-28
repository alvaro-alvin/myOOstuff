import inspect
from types import FunctionType

def isGetter(f:FunctionType):
    """Detecta se a funcao é um getter se o argumento é (self) e o nome inicia com '    def get_'"""
    return str(inspect.signature(f)) == '(self)' and str(inspect.getsource(f)).startswith("    def get_")

def GetterToPropiety(f:FunctionType):
    """Utilza o nome da funcao para obter um atributo da classe"""
    aux = ""
    #vai até o '(' e armazena em uma variave auxiliar
    for x in str(inspect.getsource(f)):
        if(x == "("):
            break
        aux = aux + x
    #corta fora o 'def get_' para obter o nome do atributo
    aux = aux[12:]
    return aux

class PessoaMeta(type):                              #name = nome da classe
    def __new__(cls, name, bases, dct):              #bases = a tupla de classes base
        x = super().__new__(cls, name, bases, dct)   #dict = dicionario de keys(atributos) e seus valores(*implementacoes)
        aux = "atributos:"
        #passa pelos item da classe referida e para toda funçao identificada como getter obtem o seu atributo
        for key, val in dct.items():
            if(type(val) == FunctionType):
                if(isGetter(val)):
                    aux = aux + " " + GetterToPropiety(val)
        x.proprieties = aux
        return x 


class Pessoa(metaclass=PessoaMeta):

    def __init__(self, nome, idade, profissao) -> None:
        self.nome = nome
        self.idade = idade
        self.profissao = profissao
        pass
    
    def get_nome(self):
        """return the name """
        return self.nome

    def get_idade(self):
        """return the age"""
        return self.idade

    def get_profissao(self):
        """return the job """
        return self.profissao

    def print(self):
        print("Nome:", self.nome, "idade:",  self.idade, "profissao:", self.profissao, '\n')
        pass

pessoa1 = Pessoa("Alvaro", 19, "estudante")
print("Atributos obtidos por meio de reflexao e metaprogramacao com as funcoes getters:")
print(pessoa1.proprieties)


