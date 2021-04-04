#pragma once
#include <cstddef>

class FileSystem {
	const char* ReadTextFile	(const char* path);
	bool		WriteTextFile	(const char* path, const char* text);

	std::byte * ReadBinaryFile	(const char* path);
	bool		WriteBinaryFile	(const char* path, unsigned char* bytes, size_t size);
};