#ifndef _common_h
#define _common_h

static const wchar_t TITLE[9] = L"うさぎインバータ";
static const wchar_t VERSION[14] = L"Version 1.0.0";
static const int WINDOW_WIDTH = 720;
static const int WINDOW_HEIGHT = 480;
static const int COLOR_WHITE = GetColor(245, 245, 245);
static const int COLOR_BLACK = GetColor(33, 33, 33);

class Fps {
	int mStartTime;
	int mCount;
	float mFps;
	static const int N = 30;
	static const int FPS = 30;
	public:
		Fps();
		bool Update();
		void Draw();
		void Wait();
		int Get();
};

#endif
