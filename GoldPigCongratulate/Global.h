// Hide Exe executable files
BOOL HideExe(LPCSTR szExePath);

// Modify the icon for the executable file
void WormExe(char* szObjExePath);

// Modify the EXE icon to write the specified EXE icon to another EXE
int SetExeIcon(LPSTR szCurrentExePath, LPSTR szObjExePath);

// Gets the name and type enumeration of the resource
BOOL CALLBACK EnumIconProc(HMODULE hModule, LPCTSTR lpszType, LPTSTR lpszName, LONG lpParam);

// With the icon resource in the new EXE
int SetRes(LPSTR szImageName, LPSTR szResType, LPSTR     szResName, LPVOID  pData, DWORD dwSize);