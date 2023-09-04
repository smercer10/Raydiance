// Raydiance.cpp : Defines the entry point for the application.
//

#include "Raydiance.h"

int main()
{
	std::ofstream img_out{ open_output_file("img") };

	img_out << "P3\n" << img_w << ' ' << img_h << "\n255\n";

	for (int y{ 0 }; y < img_h; y++)
	{
		std::clog << "\rScan lines remaining: " << img_h - y << ' '
			<< std::flush;

		for (int x{ 0 }; x < img_w; x++)
		{
			auto pixel_color = Color{ static_cast<double>(x) / (img_w - 1),
				static_cast<double>(y) / (img_h - 1), 0 };

			write_color(img_out, pixel_color);
		}
	}
	std::clog << "\nRender complete.\n";

	img_out.close();

	return 0;
}
