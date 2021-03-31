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

class Convolution : public ImageProcessing {
private:
	unsigned int kernel[4][4];

public:
	void process(const Image& src, Image& dst) override;
	void setKernelIdentity();
	void setKernelBlur();
	void setKernelGaussian();
	void setKernelHorizontal();
	void setKernelVertical();
	int csp(const Image& src, unsigned int x, unsigned int y);
};
