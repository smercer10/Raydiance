#include "Output.h"

using namespace std;
namespace fs = std::filesystem;

string get_timestamp()
{
	const time_t t{std::time(nullptr)};
	tm tm{};

	if (localtime_s(&tm, &t))
		return "";

	ostringstream oss{};
	oss << put_time(&tm, "%d-%m-%Y-%H-%M-%S");

	return oss.str();
}

ofstream open_output_file(const string& id)
{
	if (!fs::exists(id))
		fs::create_directory(id);

	const string filename{id + "-" + get_timestamp() + ".ppm"};

	ofstream out(id + "/" + filename);

	return out;
}
