# PSX Programs
A collection of programs intended to be run on a PS1 console or emulator, making use of the PsyQ SDK.

Big thanks to the [PSXDEV.NET](http://psxdev.net/) forums and FAQs for providing the SDK, libraries and a plethora of helpful hints.

## Compiling the programs
Each program's folder is standalone, with its own copy of necessary library code and an individual makefile.

[Assuming you've set up PsyQ already](http://www.psxdev.net/help/psyq_install.html), simply run `psymake` in the `<program>/src` folder.

This will package the entire program into a nice, neat .exe file.

## Using the programs
Run an .exe file in your favourite PSX emulator. [Mine is mednafen](https://mednafen.github.io/).

If you want to run any of them on an actual console, [then you probably know how to do that already](http://www.psxdev.net/help/cdrom_mastering.html).

## The programs
### dispctrl
Writes three lines of numbers to the screen. Made to test my rudimentary controller polling code.

The first corresponds to the button presses on the controller at the time of the most recent poll, the second corresponds to the "last pressed" button(s) and the third is how many times `lkp_callback` has been called.
