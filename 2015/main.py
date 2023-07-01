def najdluzszy_blok_zer(slowo):
    dl_bloku = 0
    dl_najdl_bloku = 0

    for litera in slowo:
        if litera == '0':
             dl_bloku += 1
             if dl_bloku > dl_najdl_bloku:
                 dl_najdl_bloku = dl_bloku
        else:
            dl_bloku = 0

    return dl_najdl_bloku

f = open('slowa.txt', 'r')
slowa = []
for i in range(1000):
    slowa.append(f.readline()[:-1])

wiecej_zer = 0
ma_dwa_bloki = 0
najdl_blok = 0
slowa_najdl_blok = []

for slowo in slowa:
    if slowo.count('0') > slowo.count('1'):
        wiecej_zer += 1

    if list(slowo) == sorted(slowo) and slowo.count('1') > 0 and slowo.count('0') > 0:
        ma_dwa_bloki += 1

    if najdluzszy_blok_zer(slowo) > najdl_blok:
        najdl_blok = najdluzszy_blok_zer(slowo)


for slowo in slowa:
    if najdluzszy_blok_zer(slowo) == najdl_blok:
        slowa_najdl_blok.append(slowo)


f = open('wynik4.txt', 'w')

f.write(f'4.1 {wiecej_zer}\n')
f.write(f'4.2 {ma_dwa_bloki}\n')
f.write('4.3 \n')
f.write(f'najdłuższy blok: {najdl_blok}\n')
f.write("\n".join(slowa_najdl_blok))


# "separator".join(lista)