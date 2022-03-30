# ilo sitelen

To read in toki pona, see [`README.md`](https://github.com/0x182d4454fb211940/ilo-sitelen/blob/master/README.md).

This is an IME for typing sitelen pona characters using FCITX.

To install:

```bash
$ git clone https://github.com/0x182d4454fb211940/ilo-sitelen.git
$ cd ilo-sitelen
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release
$ sudo make install
```

The following example uses [linja nanpa](https://github.com/ETBCOR/nasin-nanpa) as a font:

![Example input](https://raw.githubusercontent.com/0x182d4454fb211940/ilo-sitelen/master/example.gif)

# TODO

- AUR package
