#define TOC ( 0x0072DCE8 )//1.13 actually 0xB576E8 as defined in TOC2
#define TOC2 ( 0xB576E8 )

struct Font_s
{
	int fontName;
	float pixelHeight;
	int glyphCount;
	int material;
	int glowMaterial;
	int glyphs;
};

struct ScreenPlacement
{
	int64_t	 scaleVirtualToReal;
	int64_t scaleVirtualToFull;
	int64_t scaleRealToVirtual;
	int64_t virtualViewableMin;
	int64_t virtualViewableMax;
	int64_t virtualTweakableMin;
	int64_t virtualTweakableMax;
	int64_t realViewportBase;
	int64_t realViewportSize;
	int64_t realViewportMid;
	int64_t realViewableMin;
	//int64_t realViewableMax; you can split any var in here by spliting up the 64 bit value to a 32 bit value for x/y
	int32_t realViewableMaxX;
	int32_t realViewableMaxY;
	int64_t realTweakableMin;
	int64_t realTweakableMax;
	int64_t subScreen;
};

//Draw
opd_s Material_RegisterHandle = { 0x745440, TOC };
opd_s UI_DrawText_p = { 0x42DE98, TOC };
opd_s UI_GetFont = { 0x42DBD8, TOC };
opd_s CL_DrawStr = { 0x1A6D98, TOC };
opd_s R_TextWidth_t = { 0x734570, TOC };

void*(*Material_Register)(const char * font, int imageTrac) = (void*(*)(const char *, int))&Material_RegisterHandle;
void(*UI_DrawText)(ScreenPlacement* scrPlace, const char *text, int maxChars, Font_s* font, float x, float y, int horzAlign, int vertAlign, float scale, const float *color, int style) = (void(*)(ScreenPlacement*, const char*, int, Font_s*, float, float, int, int, float, const float*, int))&UI_DrawText_p;
Font_s*(*UI_GetFontHandle)(ScreenPlacement* scrPlace, int fontEnum, float scale) = (Font_s*(*)(ScreenPlacement*, int, float))&UI_GetFont;
void(*CL_DrawStretchPic)(ScreenPlacement* scrPlace, float x, float y, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const float *color, void *material) = (void(*)(ScreenPlacement*, float, float, float, float, int, int, float, float, float, float, const float *, void *))&CL_DrawStr;
int(*R_TextWidth)(const char *text, int maxChars, Font_s *font) = (int(*)(const char*, int, Font_s*))&R_TextWidth_t;


opd_s cb = { 0x00399CC8, TOC };

void(*cBuf_Addtext)(int client, char* cmd) = (void(*)(int, char*))&cb;


void Menu_PaintAll_Stub(int a, int b) {
	__asm("li %r3, 0x3");
}
