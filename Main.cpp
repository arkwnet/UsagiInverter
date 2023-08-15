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
	SetMainWindowText(TITLE);
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	if (DxLib_Init() == -1) {
		return -1;
	}
	
	Fps fps;
	int voiceHandle[4];
	int count = -10;
	int mode = 0;
	int freq = 100;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		if (count < 0) {
			voiceHandle[0] = LoadSoundMem(L"Assets\\Voice\\Usagi.wav");
			count = 0;
		} else {
			fps.Update();
			if (count == 0) {
				PlaySoundMem(voiceHandle[0], DX_PLAYTYPE_LOOP);
				ChangeFont(L"ＭＳ ゴシック");
				SetFontSize(24);
				ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
			}
			DrawBox(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_WHITE, TRUE);
			DrawString(30, 30, TITLE, COLOR_BLACK);
			DrawString(30, 70, VERSION, COLOR_BLACK);
			if (mode == 0) {
				DrawString(30, 130, L"モード: マニュアル", COLOR_BLACK);
			}
			DrawFormatString(30, 170, COLOR_BLACK, L"周波数: %d Hz", freq);
			SetFrequencySoundMem(freq, voiceHandle[0]);
			if (CheckHitKey(KEY_INPUT_LEFT) == 1 && freq > 100) {
				freq -= 20;
			}
			if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
				freq += 20;
			}
			count++;
			fps.Wait();
		}
	}

	DxLib_End();
	return 0;
}
