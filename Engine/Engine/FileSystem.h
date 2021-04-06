#pragma once

#include <cstddef>
#include <fstream>
#include <filesystem>
#include <sstream>
#include "DataTypes.h"

class FileSystem {
public:
	static bool			FileExist		(const char* path) {
		std::ifstream file(path);
		bool status = file.good();
		file.close();
		return status;
	}
	static int64		FileSize		(const char* path) {
		return std::filesystem::file_size(path);
	}

	static const char*	ReadTextFile	(const char* path) {
		std::ifstream file(path);
		std::stringstream data;
		data << file.rdbuf();
		file.close();
		return data.str().c_str();
	}
	static bool			WriteTextFile	(const char* path, const char* text) {
		std::ofstream file;
		file.open(path, std::ios::trunc);
		if (file.good()) {
			file << text << std::endl;
			file.close();
			return true;
		}
		else {
			file.close();
			return false;
		}
	}

	static void			CreateDirectory(const char* directory);

	static bool			ReadBinaryFile	(const char* path, byte* bytes, size_t size) {
		std::ifstream file(path, std::ios::binary);

		if (file.good()) {
			file.seekg(0);
			file.read((char*)bytes, size);
			file.close();
			return true;
		} else {
			file.close();
			return false;
		}
	}
	static bool			WriteBinaryFile	(const char* path, byte* bytes, size_t size) {
		std::ofstream file(path, std::ios::binary | std::ios::trunc);

		if (file.is_open()) {
			file.seekp(0);
			file.write((char*)bytes, size);

			file.close();
			return true;
		}
		return false;
	}

};