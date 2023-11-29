#pragma once
#include <glm/glm.hpp>

using color3_t = glm::vec3;
using color4_t = glm::vec4;
using rgba_t = uint32_t;

inline color4_t RGBAToColor(const rgba_t& rgba)
{
	color4_t color;

	color.r = ((rgba >> 24) & 0xff) / 255.0f;
	color.g = ((rgba >> 16) & 0xff) / 255.0f;
	color.b = ((rgba >> 8) & 0xff) / 255.0f;
	color.a = (rgba & 0xff) / 255.0f;

	return color;
}

inline rgba_t ColorToRGBA(const color4_t& color)
{
	rgba_t rgba;

	glm::clamp(color, 0.0f, 1.0f);

	rgba |= uint8_t(color.r * 255) << 24;
	rgba |= uint8_t(color.g * 255) << 16;
	rgba |= uint8_t(color.b * 255) << 8;
	rgba |= uint8_t(color.a * 255);

	return rgba;
}