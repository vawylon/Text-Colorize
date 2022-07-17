# Text Colorize

![image](https://pawn-wiki.ru/uploads/imgs/img_1618408116__sa-mp-004.png)

> > Hello dear forum members!
Yesterday there was an idea to make an inclusion that would allow you to paint the text into a multi-colored text.
It can be used not only in dialogs, but also in Material Text and 3D text.
I didn't get too steamed up and didn't delve into the deep zen of optimization. stupidly on the fan and on the knee.
What is the point, you ask. You won't believe it, but color has many formats and one of them is RGB.
What about HSV?
There is a formula there is HSV in RGB ok here it is:

```C
stock HSVtoRGB(Float:H, Float:S = 100.0, Float:V= 100.0)
H from 0.0 to 360.0!!!
S - tone
V - saturation
returns RGB color
```

```C
stock HSVtoRGBA(Float:H, A = 0xFF, Float:S = 100.0, Float:V= 100.0)
returns RGBA color
```

---

### Coloring the text

### ColorazeText(text[], Float: hstart = 0.0, Float: hend = 360.0, sizet = sizeof(text))

> text - text
hstart - the beginning of the color tone
hend - end of the color tone
size - maximum length

### Please pay attention!

You have created an array of 128 bytes and the text size will be 120, the color will simply be painted over with one color.
You have to take with a margin.

##### Use

---

```C
&c1.Text
&c2.Text
&c3.Text
&c4.Text
&c5.Text
```

&c - will be replaced by the colors "{ff0000}" in the range from "hstart" to "hend"

### Painting the line

ColorizeString(string[], Float: hstart = 0.0, Float: hend = 360.0, ssize = sizeof(string))
Everything is the same, only it will color the string in the color range from hstart to hend

```C
CMD:colorize(playerid)
{
	new string[2048];
 	new line[256] = "\n";
    ColorizeString(line);
    strcat(string, line);
    line = "\n";
    ColorizeString(line, 120.0, 260.0);
    strcat(string, line);
    line = "&c1. List\n&c2. List\n&c3. List\n&c4. List\n&c5. List\n&c6. List\n&c7. List\n&c8. List\n&c9. List\n&c10. List\n&c11. List\n&c12. List";
    ColorazeText(line, 120.0, 230);
	strcat(string, line, sizeof(string));
	new head[128] = "Text colorize by vawylon";
	ColorizeString(head, 120.0, 290.0);
	new leftbutton[128] = "Выбрать";
	ColorizeString(leftbutton, 90.0, 0);
	new rightbutton[128] = "Закрыть";
	ColorizeString(rightbutton, 0.0, 90);
    ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, head, string, leftbutton, rightbutton);
    return 1;
}
```

* This repository requires the intervention of experienced specialists