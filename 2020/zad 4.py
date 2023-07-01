def binarnie(x):
    wynik = ""
    while x > 0:
        wynik = str(x % 2) + wynik
        x = x // 2
        # x //= 2
    return wynik


def czy_pierwsza(x):
    if x < 2:
        return False
    for i in range(2, x//2 + 1):
        if x % i == 0:
            return False
    return True


f = open("dane.txt", "r")
liczby = []
for i in range(5000):
    liczby.append(int(f.readline()))

f.close()

pierwsze = []
palindromiczne = 0



for liczba in liczby:
    if czy_pierwsza(liczba):
        pierwsze.append(liczba)
    zapis_bin = binarnie(liczba)
    if zapis_bin == zapis_bin[::-1]:
        palindromiczne += 1

    zapis_bin_kopia = zapis_bin
    for i in range(len(zapis_bin)):
        zapis_bin_kopia = "0" + zapis_bin_kopia
        if zapis_bin_kopia == zapis_bin_kopia[::-1]:
            palindromiczne += 1
            break


print(len(pierwsze))
print(min(pierwsze))
print(max(pierwsze))
print()
print(palindromiczne)
