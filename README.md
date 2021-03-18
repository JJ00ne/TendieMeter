Hi fellow apes! I decided to create this project to keep track of my GME tendies
without searching the quotes everytime. Anyway, you can adapt the code for every ticker.
PS. sorry if my english is not perfect



=================  HOW IT WORKS  ===================

This contraption is made up of two parts: first we have a PHP script that you
need to upload somewhere (you can easily find free hosting somewhere, i used Altervista).
This script looks to the CNBC website, parsing its HTML to retrieve the price, which is
contained in a <span> with a specific class. The second part is the Arduino, connected to
ethernet with a ENC28J60 module. There are many variations of the module, but they all
works in the same way. The Arduino browser the PHP page retrieving the price from it,
showing it on the LCD. Due to the dimension of the 16x2 LCD, the maximum gain you can write
is 9999.99$. When the squeeze will squoze, you could either rewrite the code or buy a bigger LCD. 
Let's jump in the project.



=================  THE PHP  ===================
You don't need to change anything, unless the CNBC changes their HTML system.
Just upload on a hosting that let you run PHP. There are many services that
offer you a third level domain for free. If you want to check quotes for another
ticker, you can change it here.


=================  THE LCD  ===================
You can configure the LCD just how it's showed in the pic attached, and the
configuration is the same for both UNO and MEGA.
If you want to change the pin layout, remember to change it also in the code.


=================  THE ETHERNET MODULE  ===================
As stated above, you don't need exactly a ENC28J60 module, there are many models very
similar to each other. If it have this shape (check the photo) and ten pins, it's ok.
You can do this also with an ethernet shield, but i don't know if you need to change the code.
This sketch requires ethercard.h library, which require the module on some default pins,
different if you use a UNO or a MEGA:
|==============|=========|==========|
|   ENC28J60   |   UNO   |   MEGA   |
|==============|=========|==========|
|   VCC        |   3.3v  |   3.3V   |
|   GND        |   GND   |   GND    |
|==============|=========|==========|
|   SCK         |   13    |   52     |
|   MISO       |   12    |   50     |
|==============|=========|==========|
|   MOSI       |   11    |   51     |
|   CS         |   10    |   53     |
|==============|=========|==========|



=================  THE CODE  ===================
I modified a little bit some example sketches for the module found on the internet.
Before the use, remember to read all the comments in the initial part of the code, 
adjusting all the variables shown. 
You can figure all the section by yourself, if you really want to breakdown the code.



=================  IT'S DONE!  ===================
Probably someone will have trouble connecting the module to the LAN, due to the use of
DHCP or static IP or MAC conflict. Sorry, but i'm just an ape, i don't know how to help you.
Much of the code was written by someone else and i really don't understand much of it.
Just google it, and you will find a solution.



====================================
If you want to get in touch, DM me on reddit: JJ_00ne
And always, GME to the moon!
====================================
