#pragma once

#include "Output.h"
#include "Color.h"
#include "Ray.h"

#include <iostream>
#include <fstream>

//
// Image
//

inline constexpr auto aspect_ratio{ 16.0 / 9.0 };
inline constexpr int img_w{ 400 };

// Image must be at least 1 pixel tall
inline constexpr int img_h{ (static_cast<int>(img_w / aspect_ratio) < 1) ? 1
	: static_cast<int>(img_w / aspect_ratio) };

//
// Camera
//

inline constexpr auto focal_len{ 1.0 }; // Distance from camera to viewport
inline auto cam_center{ Point3(0.0, 0.0, 0.0) };
inline constexpr auto viewport_h{ 2.0 };

// Aspect ratio must be recalcuated as img_h may be rounded down or floored at
// 1 so actual image dimensions may not perfectly match intended aspect ratio
inline constexpr auto viewport_w{ viewport_h * static_cast<double>(img_w)
	/ img_h };

// Vector across horizontal viewport edge
inline auto viewport_u = Vec3(viewport_w, 0.0, 0.0);

// Vector down vertical viewport edge
inline auto viewport_v = Vec3(0.0, -viewport_h, 0.0);

// Horizontal gap between viewport pixels (center to center)
inline auto pixel_delta_u = viewport_u / img_w;

// Vertical gap between viewport pixels (center to center)
inline auto pixel_delta_v = viewport_v / img_h;

// Viewport center is orthogonal to camera center
inline auto viewport_ulc = cam_center - (viewport_u * 0.5) - (viewport_v * 0.5)
- Vec3(0.0, 0.0, focal_len);

// Pixels are inset from viewport edges by half of their delta
inline auto pixel00_loc = viewport_ulc + (pixel_delta_u + pixel_delta_v) * 0.5;
