#‎include‬ <windows.h>
#include <stdio.h>

void clip(LPCTSTR title)
{
int a;

RECT _clip;
HWND _window;

_window = FindWindow(NULL, title);

GetWindowRect(_window, &_clip);

// data border dari window yang mau di lock
_clip.left += 8;
_clip.top += 30;
_clip.right -= 8;
_clip.bottom -= 8;

ClipCursor(&_clip);
}

void unclip()
{
int a;

RECT _screen;

_screen.left = 0;
_screen.top = 0;
_screen.right = GetSystemMetrics(SM_CXSCREEN);
_screen.bottom = GetSystemMetrics(SM_CYSCREEN);

ClipCursor(&_screen);
}

int main()
{
char title[100];
char i=0;
// tolong lah,source udah aku buka,masak mau ambil hak cipta juga
smile emotikon
respect brada
printf("###################################\n");
printf("###### Window Cursor Kuncier ######\n");
printf("##### 2013 Mathew Sanders #####\n");
printf("##### farewell thank you #####\n");
printf("###################################\n\n");

printf("Masukkan nama / title window yang mau di lock : ");

fgets(title, sizeof(title), stdin);

int len = strlen(title);
title[len-1] = '\0';

printf("Memulai mengunci window \"%s\"\n", title);

printf("Tutup window ini buat exit.\n");

while(1)
{
HWND _active = GetForegroundWindow();
HWND _window = FindWindow(NULL, (LPCTSTR)title);

if(_active == _window)
{
if(i == 0)
{
printf("Window aktif - Locked\n");
clip((LPCTSTR)title);
i = 1;
}
else { Sleep(500); }
}
else
{
if(i == 1)
{
printf("Window tidak aktif - Unlocked\n");
unclip();
i = 0;
}
else { Sleep(500); }
}
}
return 0;
}