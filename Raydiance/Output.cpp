#include "Output.h"

namespace fs = std::filesystem;

std::string get_timestamp()
{
	const time_t t{ time(nullptr) }; // Current time
	tm tm{}; // Struct to store time components

	// Unable to get time
	if (localtime_s(&tm, &t))
		return "";

	std::ostringstream oss{};
	oss << std::put_time(&tm, "%d-%m-%Y-%H-%M-%S");

	return oss.str();
}

std::ofstream open_output_file(const std::string& id)
{
	if (!fs::exists(id))
		fs::create_directory(id);

	const std::string filename{ id + "-" + get_timestamp() + ".ppm" };

	std::ofstream out(id + "/" + filename);

	return out;
}
