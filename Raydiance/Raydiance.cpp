// Raydiance.cpp : Defines the entry point for the application.
//

#include "Raydiance.h"

using namespace std;
namespace fs = std::filesystem;

int main()
{
	const string img_dir{"img"};

	if (!fs::exists(img_dir))
		fs::create_directory(img_dir);

	ofstream img_out(img_dir + "/img.ppm");

	constexpr int img_w{256};
	constexpr int img_h{256};

	img_out << "P3\n" << img_w << ' ' << img_h << "\n255\n";

	for (int y{0}; y < img_h; y++)
	{
		for (int x{0}; x < img_w; x++)
		{
			auto r{static_cast<double>(x) / (img_w - 1)};
			auto g{static_cast<double>(y) / (img_h - 1)};
			auto b{0.25};

			int ir{static_cast<int>(255.999 * r)};
			int ig{static_cast<int>(255.999 * g)};
			int ib{static_cast<int>(255.999 * b)};

			img_out << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}

	img_out.close();

	return 0;
}
