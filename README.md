# ilo sitelen

sina wile lukin e ni kepeken toki Inli la, o lukin e [`README-EN.md`](https://github.com/0x182d4454fb211940/ilo-sitelen/blob/master/README-EN.md).

ilo ni la sina ken sitelen e sitelen pona kepeken sitelen Lasin. ona li kepeken ilo FCITX.

ni li kepeken sitelen pi [linja nanpa](https://github.com/ETBCOR/nasin-nanpa)

![kepeken pi pana sona](https://raw.githubusercontent.com/0x182d4454fb211940/ilo-sitelen/master/example.gif)

## nasin kepeken

sitelen e poki nimi kepeken `[` en `]`. anu la, sitelen e sitelen wan pi poki nimi kepeken `=`.

sitelen e sitelen pi linja anpa kepeken `(` en `)` lon sitelen sinpin. anu la, sitelen e sitelen wan pi linja anpa kepeken `_`

sitelen e sitelen pi linja anpa pi poka pilin kepeken `{` en `}` lon sitelen monsi.

wan e sitelen kepeken `-`. anu la, wan insa e sitelen kepeken `+`. anu la, wan sewi e sitelen kepeken `*`.

sitelen e sike pimeja kekepen `.`, e sike pimeja tu kepeken `:`.

ante e sitelen kepeken `/` anu `\`


## sina kama jo kepeken ni:

### ilo Arch

poki [AUR](https://wiki.archlinux.org/title/Arch_User_Repository) li lon ni: [https://aur.archlinux.org/packages/ilo-sitelen-git](https://aur.archlinux.org/packages/ilo-sitelen-git).

### ilo Linux ante

o pali li kama jo kepeken ilo CMake.

```bash
$ git clone https://github.com/0x182d4454fb211940/ilo-sitelen.git
$ cd ilo-sitelen
$ cmake -B build -S . -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release
$ cmake --build build
$ sudo cmake --install build
```

## pali ala

- wile pi jan kepeken
