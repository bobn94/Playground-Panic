// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <sdkddkver.h>

#include <stdio.h>
#include <tchar.h>
#pragma warning(disable:4099)
#define SFML_STATIC
#if defined(_DEBUG)
#pragma comment(lib, "sfml-window-s-d.lib")
#pragma comment(lib, "sfml-graphics-s-d.lib")
#pragma comment(lib, "sfml-system-s-d.lib")
#pragma comment(lib, "sfml-audio-s-d.lib")
#else
#pragma comment(lib, "sfml-window-s.lib")
#pragma comment(lib, "sfml-window-s.lib")
#pragma comment(lib, "sfml-window-s.lib")
#pragma comment(lib, "sfml-window-s.lib")
#endif
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

// TODO: reference additional headers your program requires here
