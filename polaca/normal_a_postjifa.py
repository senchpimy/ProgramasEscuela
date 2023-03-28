def polaca_postfija(expresion):
    operadores = ["+","-","*","/"]
    pila = []
    salida = []
    tokens = expresion.split()
    for token in tokens:
        if token.isnumeric():
            salida.append(token)
        elif token in operadores:
            pila.append(token)
        elif token == '(':
            pila.append(token)
        elif token == ')':
            while pila and pila[-1] != '(':
                salida.append(pila.pop())
            if pila and pila[-1] == '(':
                pila.pop()
    while pila:
        print(salida)
        salida.append(pila.pop())
    return ' '.join(salida)

expresion = "( 6 + 2 / 5 ) / ( 12 - ( 4 * 5 ) )"
pantalla=polaca_postfija(expresion)
print(pantalla)
