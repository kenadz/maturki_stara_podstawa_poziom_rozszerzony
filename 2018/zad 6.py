f = open("slowa.txt", "r")

lista = []

for i in range(1000):
    linia = f.readline()
    linia = linia[:-1]
    linia = linia.split(" ")
    lista.append(linia)
f.close()
litery_A = 0
zawiera = 0
anagramy = 0

for para in lista:
    # 6.1
    if para[0][-1] == 'A':
        litery_A += 1
    if para[1][-1] == 'A':
        litery_A += 1

    # 6.2
    if para[0] in para[1]:
        zawiera += 1

    # 6.3
    if sorted(para[0]) == sorted(para[1]):
        anagramy += 1

f = open("wyniki6.txt", "w")
f.write(f"6.1 {litery_A}\n")
f.write(f"6.2 {zawiera}\n")
f.write(f"6.3 {anagramy}\n")
f.close()
