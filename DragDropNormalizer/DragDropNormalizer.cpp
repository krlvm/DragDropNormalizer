#include <Windows.h>
#include <Uxtheme.h>
#include <vsstyle.h>
#include <vssym32.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "uxtheme.lib")

#include "BitmapBits.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    HBITMAP hbm;

    HTHEME hTheme = OpenThemeData(GetForegroundWindow(), L"DragDrop");
    GetThemeBitmap(hTheme, 7, 0, TMT_DIBDATA, GBF_DIRECT, &hbm);

    BITMAP bm;
    GetObject(hbm, sizeof(bm), &bm);

    if (!hbm || bm.bmBitsPixel != 32)
    {
        return FALSE;
    }

    BYTE* pBits = new BYTE[bm.bmWidth * bm.bmHeight * 4];
    GetBitmapBits(hbm, bm.bmWidth * bm.bmHeight * 4, pBits);

    for (int i = 0; i < DD_BITMAP_SIZE; i++)
    {
        pBits[i] = DD_BITMAP_BITS[i];
    }

    SetBitmapBits(hbm, bm.bmWidth * bm.bmHeight * 4, pBits);
    delete[] pBits;

    CloseThemeData(hTheme);

    return 0;
}