//
// Radiance entry point
//

#include "Raydiance.h"

// Simple blue and white gradient background
Color ray_color(const Ray& r)
{
	Vec3 unit_dir = unit_vector(r.direction());
	auto t = 0.5 * (unit_dir.y() + 1.0); // Scale y to [0, 1]
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + (t * Color(0.5, 0.7, 1.0));
}

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
			auto pixel_center = pixel00_loc + (pixel_delta_u * x)
				+ (pixel_delta_v * y);

			auto ray_dir = pixel_center - cam_center;
			Ray r(cam_center, ray_dir);

			Color pixel_color = ray_color(r);

			write_color(img_out, pixel_color);
		}
	}
	std::clog << "\nRender complete.\n";

	img_out.close();

	return 0;
}
