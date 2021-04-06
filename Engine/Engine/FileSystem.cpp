#include "FileSystem.h"

void FileSystem::CreateDirectory(const char * directory) {
	if (!std::filesystem::is_directory(directory) || !std::filesystem::exists(directory)) { // Check if src folder exists
		std::filesystem::create_directory(directory); // create src folder
	}
}
