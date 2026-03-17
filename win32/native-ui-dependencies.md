# Native UI Dependencies

ZoiteChat Windows frontend links against native UI/runtime libraries from the Windows SDK and system runtime:

- user32.lib
- comctl32.lib
- uxtheme.lib
- dwmapi.lib
- d2d1.lib
- dwrite.lib
- ole32.lib
- shell32.lib
- wininet.lib
- winmm.lib
- ws2_32.lib

Additional non-UI runtime dependencies remain:

- libarchive import library from the CI dependency bundle
- OpenSSL import libraries resolved from `DepsRoot`
