numero = input("inserisci numero: ")
numero = float(numero)

numero *= 10

if(numero%10 > 5):
    numero = int(numero/10) + 1
else:
    numero = int(numero/10)

print(numero)
