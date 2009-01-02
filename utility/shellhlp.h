//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// This is a part of the Litestep Shell source code.
//
// Copyright (C) 1997-2007  Litestep Development Team
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#if !defined(SHELLHLP_H)
#define SHELLHLP_H

#include "common.h"
#include <ShellAPI.h>


//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Shell Helpers
//
// These are mostly small wrappers that work around inconveniences or even bugs
// in some Windows APIs
//
#define LS_CSIDL_QUICKLAUNCH   0x00FF
HRESULT GetShellFolderPath(int nFolder, LPTSTR ptzPath, size_t cchPath);

bool GetSystemString(DWORD dwCode, LPTSTR ptzBuffer, DWORD cchBuffer);
HRESULT PathAddBackslashEx(LPTSTR ptzPath, size_t cchPath);
HRESULT CLSIDToString(REFCLSID rclsid, LPTSTR ptzBuffer, size_t cchBuffer);
bool LSGetModuleFileName(HINSTANCE hInst, LPTSTR pszBuffer, DWORD cchBuffer);
HRESULT TryAllowSetForegroundWindow(HWND hWnd);
bool IsVistaOrAbove();
void LSShutdownDialog(HWND hWnd);
BOOL LSPlaySystemSound(LPCTSTR pszSoundAlias);
HANDLE LSCreateThread(LPCSTR pszName, LPTHREAD_START_ROUTINE fnStartAddres,
                      LPVOID lpParameter, LPDWORD pdwThreadId);


//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// WOW64 Wrappers
//
BOOL LSDisableWow64FsRedirection(PVOID* ppvOldValue);
BOOL LSRevertWow64FsRedirection(PVOID pvOldValue);

BOOL LSShellExecuteEx(LPSHELLEXECUTEINFO lpExecInfo);
HINSTANCE LSShellExecute(HWND hwnd, LPCTSTR lpOperation, LPCTSTR lpFile,
                         LPCTSTR lpParameters, LPCTSTR lpDirectory, INT nShow);


//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// HrGetLastError
// Convert GetLastError to HRESULT without an ugly macro
//
inline HRESULT HrGetLastError()
{
    return HRESULT_FROM_WIN32(GetLastError());
}

#endif // SHELLHLP_H
