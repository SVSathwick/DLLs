// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        //::MessageBox(NULL, L"StringLibrary_ATTACH", L"", MB_OK);
        //break;
    case DLL_THREAD_ATTACH:
        //::MessageBox(NULL, L"DLL_THREAD_ATTACH", L"StringLibrary", MB_OK);
        //break;
    case DLL_THREAD_DETACH:
        //::MessageBox(NULL, L"DLL_THREAD_DETACH", L"StringLibrary", MB_OK);
        //break;
    case DLL_PROCESS_DETACH:
        //::MessageBox(NULL, L"StringLibrary_DETACH", L"", MB_OK);
        break;
    }
    return TRUE;
}

