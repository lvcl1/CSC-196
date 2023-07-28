#include "FileIO.h"
#include <fstream>


namespace kiko
{
	std::string getFilePath()
	{
		return std::filesystem::current_path().string();
	}
	bool setFilePath(const std::filesystem::path& path)
	{
		std::error_code ec;
		std::filesystem::current_path(path, ec);
		return ec.value()==0;
	}

	bool FileExists(const std::filesystem::path& path)
	{
		return std::filesystem::exists(path);
	}

	bool getFileSize(const std::filesystem::path& path, size_t& size)
	{
		std::error_code ec;
		size = std::filesystem::file_size(path, ec);
		return ec.value() == 0;
	}

	bool ReadFile(const std::filesystem::path& path, std::string& buffer)
	{
		if (!FileExists(path)) return false;
		size_t size;
		if (!getFileSize(path, size)) return false;
		buffer.resize(size);
		std::ifstream stream(path);
		stream.read(buffer.data(), size);
		stream.close();

		return true;
	}
}
