I had to tweak smartborders a bit, because it kept failing... to make it work, go to dwm.c and find the function:

    1790: void tile(Monitor *m)

and uncomment:

    1801: //m->gappx = 0

    1805: //m->gappx = gappx

recompile and see if your window has no borders when "n = 1", and has borders when "n > 1"!

patches i've added:

    https://dwm.suckless.org/patches/smartborders/

    https://dwm.suckless.org/patches/center/

    https://dwm.suckless.org/patches/focusmonmouse/

    https://dwm.suckless.org/patches/fullgaps/

    https://dwm.suckless.org/patches/fullscreen/

    https://dwm.suckless.org/patches/pertag/

    https://dwm.suckless.org/patches/xrdb/

slstatus stolen from Mental Outlaw's repo >:) -> https://github.com/MentalOutlaw

