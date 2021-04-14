

https://pawn-wiki.ru/uploads/imgs/img_1618408116__sa-mp-004.png


Здраствуйте дорогие форумчане!
Вчера появилась идея сделать инклуйд который позволил бы красить текст в разноцветный текст.
Его можно использовать не только в диалогах, но и в MaterialText так и 3D текст.
Я сильно не запаривался и не углублялся в глупокий дзен оптимизации. тупа по фану и на коленке.
В чём суть спросите вы. Не поверите но у цвета есть множество форматов и одно из них RGB. Ок, но как на счёт HSV?
Тем кто вообще только что познакомился с HSL.
Читаем эту тему
%D1%86%D0%B2%D0%B5%D1%82%D0%BE%D0%B2%D0%B0%D1%8F_%D0%BC%D0%BE%D0%B4%D0%B5%D0%BB%D1%8C

Там формула есть HSV в RGB ок вот она:

stock HSVtoRGB(Float:H, Float:S = 100.0, Float:V= 100.0)
H от 0.0 до 360.0!!!
S - тон
V - насыщенность
возвращает RGB цвет

stock HSVtoRGBA(Float:H, A = 0xFF, Float:S = 100.0, Float:V= 100.0)
возвращает RGBA цвет


Красим текст::

ColorazeText(text[], Float: hstart = 0.0, Float: hend = 360.0, sizet = sizeof(text))
text - текст
hstar - начало цветового тона
hend - конец цветового тона
sizet - максимальная длинна


Прошу обратить внимание!!!!!!!!!
Вы создали массив 128 байт и размер текста будет 120 цвет просто на просто закрасится одним цветом.
Вы должны брать с запасом. 

Использование 
&c1.Text
&c2.Text
&c3.Text
&c4.Text
&c5.Text

&c - заменится на цвета "{ff0000}" в диапазоне от "hstart" до "hend"

Красим строку:

ColorizeString(string[], Float: hstart = 0.0, Float: hend = 360.0, ssize = sizeof(string))
Всё тоже самое только закрасит строку в диапазон цветов он hstart до hend


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

Автор Я. vawylon/pawlo
