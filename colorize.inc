/*

	Colorize text by pawlo/vawylon
	Ñâÿçü Telegram: @vawylon
	Èñïîëüçîâàë pawn 3.10.0
*/

stock Float:floatmod(Float:oper1, Float:oper2)
{
    while (oper1 >= oper2) oper1 -= oper2;
    while (oper1 < 0.0) oper1 += oper2;
    return oper1;
}


stock torgbacolor(r, g, b, a) return ((r << 24) | (g << 16) | (b << 8) | a);
stock HSVtoRGB(Float:H, Float:S = 100.0, Float:V= 100.0){
    if(H>360.0 || H<0.0 || S>100.0 || S<0.0 || V>100.0 || V<0.0) return 0;

    S = S/100.0;
    V = V/100.0;
    new Float:C = S*V;
    new Float:hh = H/60.0;
	new Float:X = C*(1-floatabs(floatmod(hh,2)-1));
    new Float:m = V-C;
    if( hh>=0 && hh<1.0 ) 			return ((floatround((C + m) * 255.0) << 16) | (floatround((X + m) * 255.0) << 8) | floatround((0.0 + m) * 255.0));
	else if( hh>=1.0 && hh<2.0 )	return ((floatround((X + m) * 255.0) << 16) | (floatround((C + m) * 255.0) << 8) | floatround((0.0 + m) * 255.0));
	else if( hh>=2.0 && hh<3.0 )	return ((floatround((0.0 + m) * 255.0) << 16) | (floatround((C + m) * 255.0) << 8) | floatround((X + m) * 255.0));
	else if( hh>=3.0 && hh<4.0 )	return ((floatround((0.0 + m) * 255.0) << 16) | (floatround((X + m) * 255.0) << 8) | floatround((C + m) * 255.0));
	else if( hh>=4.0 && hh<5.0 )	return ((floatround((X + m) * 255.0) << 16) | (floatround((0.0 + m) * 255.0) << 8) | floatround((C + m) * 255.0));
	else 							return ((floatround((C + m) * 255.0) << 16) | (floatround((0.0 + m) * 255.0) << 8) | floatround((X + m) * 255.0));
}
stock HSVtoRGBA(Float:H, A = 0xFF, Float:S = 100.0, Float:V= 100.0) return ((A >> 32) | (HSVtoRGB(H, S, V)<< 8));
stock HSVtoARGB(Float:H, A = 0xFF, Float:S = 100.0, Float:V= 100.0) return ((A << 24) | (HSVtoRGB(H, S, V)));
stock ColorazeText(text[], Float: hstart = 0.0, Float: hend = 360.0, sizet = sizeof(text))
{
	new pos[64] = {-1, ...};
	new res;
	new count;
	new color[9];
	for(new i; i<sizet; i++)
	{
		res = strfind(text, "&c", false, res);
		if(res == -1) break;
		pos[count] = res;
		res += 2;
		count ++;
	}
	new Float:sect = (hend-hstart)/count, step;
	for(new i = sizeof(pos)-1; i!= -1; i--) // ðàáîòàåò. Â ïðèíöèïå è òàê ïîéä¸ò
	{
	    if(pos[i] == -1) continue;
	    strdel(text, pos[i], pos[i]+2);
	    format(color, 9, "{%06x}", HSVtoRGB(step*sect + hstart));
     	strins(text, color, pos[i], sizet);
     	step++;

	}
	return 1;
}

stock ColorizeString(string[], Float: hstart = 0.0, Float: hend = 360.0, ssize = sizeof(string))
{
	new length = strlen(string);
	new free = ssize - length;
	new color[9];
	free = floatround(free/8.0, floatround_ceil);
	free = floatround(((1.0 * length) / (1.0 * free)), floatround_ceil); // õðåíü êàêàÿòî öåëûå ÷èñëà íå ïîëó÷èëîñü ðàçäåëèòü. ïîòîì èñïðàâëþ ïîêà òàê
	if(length < free) free = length;
	new step = floatround(length / free);
	new Float:roat = (hstart-hend)/step;
	for(new i; i<step; i++)
	{
	    printf("roat: %0.2f", roat * i);
	    format(color, 9, "{%06x}", HSVtoRGB(i * roat + hend));
        strins(string, color, length - free * i - free, ssize);
	}
	format(color, 9, "{%06x}", HSVtoRGB(hstart));
 	strins(string, color, 0, ssize);
 	return 1;
}


