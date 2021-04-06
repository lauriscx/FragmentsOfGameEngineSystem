#include "VFS.h"

bool		VFS::Mount		(const char * virtualPath, const char * physicpath) {
	if (strcmp(virtualPath, "") == 0 || strcmp(physicpath, "") == 0 || MountExist(virtualPath)) {
		return false;
	}
	m_MountPoints[virtualPath] = physicpath;
	return true;
}
bool		VFS::Unmount	(const char * virtualPath) {
	if (strcmp(virtualPath, "") == 0 || !MountExist(virtualPath)) {
		return false;
	}
	m_MountPoints[virtualPath].clear();
	return true;
}

const char* VFS::ReadFile	(const char * path) {
	return FileSystem::ReadTextFile(PhysicalFilePath(path).c_str());
}
bool		VFS::WriteFile	(const char * path, const char * text) {
	return FileSystem::WriteTextFile(PhysicalFilePath(path).c_str(), text);
}

bool		VFS::ReadFile	(const char * path, char * bytes, size size) {
	return FileSystem::ReadBinaryFile(PhysicalFilePath(path).c_str(), bytes, size);
}
bool		VFS::WriteFile	(const char * path, char * bytes, size size) {
	return FileSystem::WriteBinaryFile(PhysicalFilePath(path).c_str(), bytes, size);
}

bool		VFS::FileExist	(const char * virtualFilePath) {
	return FileSystem::FileExist(virtualFilePath);
}
bool		VFS::MountExist	(const char * key) {
	return m_MountPoints.find(key) != m_MountPoints.end();
}

/*
 * If file path stars with / then
 * file will be searched using VFS.
*/
String VFS::PhysicalFilePath(const char * virtualFilePath) {
	/*
	 * VFS path start with '/' physical without '/'.
	 */
	if (virtualFilePath[0] != '/') {
		return virtualFilePath;
	}
	/*
	 * Get VFS path without first slash.
	*/
	String virtualPath = &virtualFilePath[1];
	/*
	 * Get VFS file path key.
	 */
	String directory = virtualPath.substr(0, virtualPath.find('/'));

	/*
	 * Check is VFS file path key exist.
	 */
	if (MountExist(directory.c_str())) {
		/*
		 * Add physical path and file name.
		 */
		FileSystem::CreateDirectory(m_MountPoints[directory].c_str());
		return m_MountPoints[directory] + virtualPath.substr(directory.size(), directory.size() - virtualPath.size());
	}
	return nullptr;
}
