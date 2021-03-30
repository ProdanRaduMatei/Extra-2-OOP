#pragma once
#include "Image.h"

class ImageProcessing
{
private:
	virtual void process(const Image& src, Image& dst);
};

class Adjustment : public ImageProcessing {
public:
	Adjustment();
	void setContrast(float c);
	void setBrightness(int b);

	void process(const Image& src, Image& dst) override;
private:
	int brightness;
	float contrast;
};

class Gamma : public ImageProcessing {
public:
	Gamma();
	void setTita(float t);

	void process(const Image& src, Image& dst) override;
private:
	float tita;
};
