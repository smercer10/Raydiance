// Raydiance.cpp : Defines the entry point for the application.
//

#include "Raydiance.h"

using namespace std;

int main()
{
	ofstream img_out{open_output_file("img")};

	img_out << "P3\n" << img_w << ' ' << img_h << "\n255\n";

	for (int y{0}; y < img_h; y++)
	{
		for (int x{0}; x < img_w; x++)
		{
			const auto r{static_cast<double>(x) / (img_w - 1)};
			const auto g{static_cast<double>(y) / (img_h - 1)};
			constexpr auto b{0.25};

			const int ir{static_cast<int>(255.999 * r)};
			const int ig{static_cast<int>(255.999 * g)};
			constexpr int ib{static_cast<int>(255.999 * b)};

			img_out << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}

	img_out.close();

	return 0;
}
