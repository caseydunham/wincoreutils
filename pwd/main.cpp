/*
 * Copyright (c) 2012 Casey Dunham <casey.dunham@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>

void fatal_error(LPTSTR);

void fatal_error(LPTSTR program_name) 
{ 
    LPTSTR msg = 0;
    DWORD last_error = GetLastError(); 
	DWORD flags = FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS;
	DWORD lang = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT); 
    
	FormatMessage(flags, NULL, last_error, lang, msg, 0, NULL);

    wprintf_s(L"%s: %s\n", program_name, msg);
    
    LocalFree(msg);
}

int wmain(int argc, wchar_t* argv[])
{
	wchar_t path[MAX_PATH];
    
    if (GetCurrentDirectory(MAX_PATH, path) == 0)
	{
        fatal_error(L"pwd");
		return 1;
	}
	
    wprintf_s(L"%s\n", path);
    return 0;
}
