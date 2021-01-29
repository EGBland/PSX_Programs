# PSX Programs
A collection of programs intended to be run on a PS1 console or emulator, making use of the PsyQ SDK.

Big thanks to the [PSXDEV.NET](http://psxdev.net/) forums and FAQs for providing the SDK, libraries and a plethora of helpful hints.

## Compiling the programs
It's a bit of a finicky process that I intend to make easier once I learn how to properly use `ccpsx` and makefiles.

To compile a program, the libraries in `/mylib` should first be compiled. Then, in the program root folder, make a `lib` and an `include` folder. Copy the `.obj` files from `/mylib/src` to the `lib` folder, and the `.h` files from `/mylib/src` to the `include` folder. Then, do `psymake` in the project root. This will place a `MAIN.EXE` file in the project's `build` folder.

## Using the programs
Run an .exe file in your favourite PSX emulator. [Mine is mednafen](https://mednafen.github.io/).

If you want to run any of them on an actual console, [then you probably know how to do that already](http://www.psxdev.net/help/cdrom_mastering.html).

## The programs
### dispctrl
Writes three lines of numbers to the screen. Made to test my rudimentary controller polling code.

The first corresponds to the button presses on the controller at the time of the most recent poll, the second corresponds to the "last pressed" button(s) and the third is how many times `lkp_callback` has been called.
