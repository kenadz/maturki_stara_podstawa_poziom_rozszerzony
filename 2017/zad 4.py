def dec(bin):
    wynik = 0
    potega = 1 #1 2 4 8 16
    for znak in bin[::-1]:
        if znak == '1':
            wynik += potega
        potega *= 2
    return wynik

def czy_bcd(napis):
    i = 0
    while i < len(napis):
        if dec(napis[i: i+4]) > 9:
            return False
        i += 4
    return True


f = open("binarne.txt", "r")
lista = []

for i in range(500):
    lista.append(f.readline()[:-1])

f.close()
dwucykliczne = 0
najdluzszy_dwucykliczny = ""
niepoprawne_bcd = 0
najwieksza = 0
najwieksza_bin = ""

for napis in lista:
    if len(napis) % 2 == 0:
        if napis[0:len(napis)//2] == napis[len(napis)//2: len(napis)]:
            dwucykliczne += 1
            if len(napis) > len(najdluzszy_dwucykliczny):
                najdluzszy_dwucykliczny = napis

    if not czy_bcd(napis):
        niepoprawne_bcd += 1

    dziesietnie = dec(napis)
    if dziesietnie < 65535 and dziesietnie > najwieksza:
        najwieksza = dziesietnie
        najwieksza_bin = napis

f = open("zadanie4.txt", "w")
f.write(f"4.1 ilosc: {dwucykliczne} \nnajdluzszy: {najdluzszy_dwucykliczny} {len(najdluzszy_dwucykliczny)}\n")
f.write(f"4.2 {niepoprawne_bcd}\n")
f.write(f"4.3 {najwieksza} {najwieksza_bin}\n")
f.close()





