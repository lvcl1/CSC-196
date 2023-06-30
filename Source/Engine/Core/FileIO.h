#pragma once
#include <filesystem>
#include <string>

namespace kiko
{
	std::string getFilePath();
	bool setFilePath(const std::filesystem::path& path);
	bool FileExists(const std::filesystem::path& path);
	bool getFileSize(const std::filesystem::path& path, size_t& size);
	bool ReadFile(const std::filesystem::path& path, std::string& buffer);
}