#pragma once
#include "FileSystem.h"
#include <unordered_map>
#include <vector>

class VFS {
public:
	bool		Mount			(const char* virtualPath, const char* physicpath);
	bool		Unmount			(const char* virtualPath);

	const char*	ReadFile		(const char* path);
	bool		WriteFile		(const char* path, const char* text);

	bool		ReadFile		(const char* path, char* bytes, size size);
	bool		WriteFile		(const char* path, char* bytes, size size);

	bool		FileExist		(const char* virtualFilePath);
	bool		MountExist		(const char* virtualFilePath);
	String		PhysicalFilePath(const char* virtualFilePath);

private:
	std::unordered_map<String, String> m_MountPoints;
};