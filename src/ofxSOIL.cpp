#include "ofxSOIL.h"
#include <SOIL.h>

namespace ofxSOIL {
unsigned int loadOGLTexture(const std::string & file, LoadMode mode, unsigned int textureName, Flag flag) {
	unsigned int status = SOIL_load_OGL_texture(file.c_str(), mode, textureName, flag);
	if (status == 0) {
		throw IOError("failed SOIL_load_OGL_texture()");
	}
	return status;
}
unsigned int loadOGLCubeMap(const CubeMap & cubeMap, LoadMode mode, unsigned int textureName, Flag flag) {
	unsigned int status = SOIL_load_OGL_cubemap(
		cubeMap.xPos.c_str(),
		cubeMap.xNeg.c_str(),
		cubeMap.yPos.c_str(),
		cubeMap.yNeg.c_str(),
		cubeMap.zPos.c_str(),
		cubeMap.zNeg.c_str(),
		mode,
		textureName,
		flag
	);
	if (status == 0) {
		throw IOError("failed SOIL_load_OGL_cubemap()");
	}
	return status;
}
unsigned int loadOGLSingleCubeMap(const std::string & file, std::vector<Direction> directions, LoadMode mode, unsigned int textureName, Flag flag){
	std::string buf;
	for (auto dir : directions) {
		if (dir == Direction::North) {
			buf += "N";
		} else if (dir == Direction::South) {
			buf += "S";
		} else if (dir == Direction::East) {
			buf += "E";
		} else if (dir == Direction::West) {
			buf += "W";
		} else if (dir == Direction::Up) {
			buf += "U";
		} else if (dir == Direction::Down) {
			buf += "D";
		}
	}
	unsigned int status = SOIL_load_OGL_single_cubemap(file.c_str(), buf.c_str(), mode, textureName, flag);
	if (status == 0) {
		throw IOError("failed SOIL_load_OGL_single_cubemap()");
	}
	return status;
}
Image loadImage(const std::string & file, LoadMode mode) {
	Image img;
	img.data = SOIL_load_image(file.c_str(), &img.width, &img.height, &img.channel, mode);
	if (img.data == nullptr) {
		throw IOError("failed SOIL_load_image()");
	}
	return img;
}
void saveScreenshot(const std::string & file, SaveMode mode, int x, int y, int w, int h) {
	int status = SOIL_save_screenshot(file.c_str(), mode, x, y, w, h);
	if (status == 0) {
		throw IOError("failed SOIL_save_screenshot()");
	}
}
unsigned int loadOGLTextureFromMemory(unsigned char * mem, int bytes, LoadMode mode, unsigned int textureName, Flag flag) {
	unsigned int status = SOIL_load_OGL_texture_from_memory(mem, bytes, mode, textureName, flag);
	if (status == 0) {
		throw IOError("failed SOIL_save_screenshot()");
	}
	return status;
}

void saveImage(const std::string & file, SaveMode mode, int width, int height, int channels, const unsigned char * data) {
	int status = SOIL_save_image(file.c_str(), mode, width, height, channels, data);
	if (status == 0) {
		throw IOError("failed SOIL_save_screenshot()");
	}
}
}