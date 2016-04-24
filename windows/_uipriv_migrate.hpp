
// menu.c
extern HMENU makeMenubar(void);
extern const uiMenuItem *menuIDToItem(UINT_PTR);
extern void runMenuEvent(WORD, uiWindow *);
extern void freeMenubar(HMENU);
extern void uninitMenus(void);

// tabpage.c
extern void tabPageMargins(HWND, intmax_t *, intmax_t *, intmax_t *, intmax_t *);
extern HWND newTabPage(void);

// draw.c
extern HRESULT initDraw(void);
extern void uninitDraw(void);
extern ID2D1HwndRenderTarget *makeHWNDRenderTarget(HWND hwnd);
extern uiDrawContext *newContext(ID2D1RenderTarget *);
extern void freeContext(uiDrawContext *);
extern ID2D1Brush *createSolidColorBrushInternal(ID2D1RenderTarget *rt, double r, double g, double b, double a);

// dwrite.cpp
#ifdef __cplusplus
extern IDWriteFactory *dwfactory;
#endif
extern HRESULT initDrawText(void);
extern void uninitDrawText(void);
#ifdef __cplusplus
struct fontCollection {
	IDWriteFontCollection *fonts;
	WCHAR userLocale[LOCALE_NAME_MAX_LENGTH];
	int userLocaleSuccess;
};
extern fontCollection *loadFontCollection(void);
extern WCHAR *fontCollectionFamilyName(fontCollection *fc, IDWriteFontFamily *family);
extern void fontCollectionFree(fontCollection *fc);
extern WCHAR *fontCollectionCorrectString(fontCollection *fc, IDWriteLocalizedStrings *names);
#endif

// drawtext.cpp
#ifdef __cplusplus
extern uiDrawTextFont *mkTextFont(IDWriteFont *df, BOOL addRef, WCHAR *family, BOOL copyFamily, double size);
struct dwriteAttr {
	uiDrawTextWeight weight;
	uiDrawTextItalic italic;
	uiDrawTextStretch stretch;
	DWRITE_FONT_WEIGHT dweight;
	DWRITE_FONT_STYLE ditalic;
	DWRITE_FONT_STRETCH dstretch;
};
extern void attrToDWriteAttr(struct dwriteAttr *attr);
extern void dwriteAttrToAttr(struct dwriteAttr *attr);
#endif
extern void doDrawText(ID2D1RenderTarget *rt, ID2D1Brush *black, double x, double y, uiDrawTextLayout *layout);

// fontdialog.cpp
#ifdef __cplusplus
struct fontDialogParams {
	IDWriteFont *font;
	double size;
	WCHAR *familyName;
	WCHAR *styleName;
};
extern BOOL showFontDialog(HWND parent, struct fontDialogParams *params);
extern void loadInitialFontDialogParams(struct fontDialogParams *params);
extern void destroyFontDialogParams(struct fontDialogParams *params);
extern WCHAR *fontDialogParamsToString(struct fontDialogParams *params);
#endif