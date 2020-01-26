#pragma once
#ifndef OFXSOIL_HPP
#define OFXSOIL_HPP
#include <string>
#include <vector>
#include <stdexcept>

namespace ofxSOIL {
using LoadMode = enum : unsigned int {
	AUTO = 0,
	L,
	LA,
	RGB,
	RGBA
};
using SaveMode = enum : unsigned int {
	TYPE_TGA = 0,
	TYPE_BMP,
	TYPE_DDS
};
using Flag = enum : unsigned int {
	POWER_OF_TWO = 1,
	MIPMAPS = 2,
	TEXTURE_REPEATS = 4,
	MULTIPLY_ALPHA = 8,
	INVERT_Y = 16,
	COMPRESS_TO_DXT = 32,
	DDS_LOAD_DIRECT = 64,
	NTSC_SAFE_RGB = 128,
	CoCg_Y = 256,
	TEXTURE_RECTANGLE = 512
};
using Direction = enum {
	North,
	South,
	East,
	West,
	Up,
	Down
};
struct CubeMap {
	explicit CubeMap() = default;
	std::string xPos;
	std::string xNeg;
	std::string yPos;
	std::string yNeg;
	std::string zPos;
	std::string zNeg;
};
struct Image {
	explicit Image() = default;
	unsigned char* data;
	int width;
	int height;
	int channel;
};
/**
 * IOError is exception a mean of failed texture save or load.
 */
class IOError : public std::runtime_error {
public:
	explicit IOError(const std::string& msg) : std::runtime_error(msg) {}
};
/**
 * @param file
 * @param mode
 * @param textureName
 * @param flag
 * @return
 */
unsigned int loadOGLTexture(const std::string& file, LoadMode mode, unsigned int textureName, Flag flag);

/**
 * @param cubeMap
 * @param mode
 * @param textureName
 * @param flag
 * @return
 */
unsigned int loadOGLCubeMap(const CubeMap& cubeMap, LoadMode mode, unsigned int textureName, Flag flag);

/**
 * @param file
 * @param directions
 * @param mode
 * @param textureName
 * @param flag
 * @return
 */
unsigned int loadOGLSingleCubeMap(const std::string& file, std::vector<Direction> directions, LoadMode mode, unsigned int textureName, Flag flag);

/**
 * @param file
 * @param mode
 * @return
 */
Image loadImage(const std::string& file, LoadMode mode);

/**
 * @param file
 * @param mode
 * @param x
 * @param y
 * @param w
 * @param h
 */
void saveScreenshot(const std::string& file, SaveMode mode, int x, int y, int w, int h);

/**
 * @param mem
 * @param bytes
 * @param mode
 * @param textureName
 * @param flag
 * @return
 */
unsigned int loadOGLTextureFromMemory(unsigned char* mem, int bytes, LoadMode mode, unsigned int textureName, Flag flag);

/**
 * @param file
 * @param mode
 * @param mode
 * @param height
 * @param channels
 * @param data
 */
void saveImage(const std::string& file, SaveMode mode, int width, int height, int channels, const unsigned char* data);
}
#endif