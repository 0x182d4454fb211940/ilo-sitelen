# ilo sitelen

To read in toki pona, see [`README.md`](https://github.com/0x182d4454fb211940/ilo-sitelen/blob/master/README.md).

This is an IME for typing sitelen pona characters using FCITX.

The following example uses [linja nanpa](https://github.com/ETBCOR/nasin-nanpa) as a font:

![Example input](https://raw.githubusercontent.com/0x182d4454fb211940/ilo-sitelen/master/example.gif)

To install:

## Arch

An [AUR](https://wiki.archlinux.org/title/Arch_User_Repository) package exists: [https://aur.archlinux.org/packages/ilo-sitelen-git](https://aur.archlinux.org/packages/ilo-sitelen-git).

## Other Linux

Build and install with CMake:

```bash
$ git clone https://github.com/0x182d4454fb211940/ilo-sitelen.git
$ cd ilo-sitelen
$ cmake -B build -S . -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release
$ cmake --build build
$ sudo cmake --install build
```


# TODO

- User preferences
- Long "pi"
- Combined glyphs
