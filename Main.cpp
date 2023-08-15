/*
うさぎインバータ
(c) 2023 Sora Arakawa all rights reserved.
*/

#include "DxLib.h"
#include "Common.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);
	ChangeWindowMode(TRUE);
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);
	SetUseDirect3DVersion(DX_DIRECT3D_9);
	SetWindowIconID(813);
	SetMainWindowText(L"うさぎインバータ");
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	if (DxLib_Init() == -1) {
		return -1;
	}
	Fps fps;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		fps.Update();
		DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_WHITE, TRUE);
		fps.Wait();
	}

	DxLib_End();
	return 0;
}
