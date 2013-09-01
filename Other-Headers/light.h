#ifndef LIGHT_H
#define LIGHT_H

#include "enumerations.h"
#include "GL/gl.h"
#include "model.h"

class Light : public Model
{
public:
	Light(LightType lightType);
	void setType(LightType lightType);
	void setAmbientColor(float red, float green, float blue, float alpha);
	void setDiffuseColor(float red, float green, float blue, float alpha);
	void setSpecularColor(float red, float green, float blue, float alpha);
	void setPosition(float x, float y, float z, float w);
	void setSpotLightDirection(float x, float y, float z, float w);
	void setSpotLightRange(float innerAngle, float outerAngle, float falloff);
	void enable(int lightNumber);
	void disable(int lightNumber);

	void drawObjectMode ();
	void drawVertexMode (){};
	void drawFaceMode (){};
	void drawEdgeMode (){};
	void drawObjectModeSelect ();
	void drawVertexModeSelect (int /*index*/){};
	void drawFaceModeSelect (){};
	void drawEdgeModeSelect (){};
	void showAttribute ();
	void save (QDataStream *out);
	void changeAttributes ();
	bool completeModel () {}
	void setHeight (float){};
	void setWidth (float){};
	void setLength (float){};

private:
	LightType lightType;
	float ambient[4];
	float diffuse[4];
	float specular[4];
	float modelAmbient[4];
	bool localViewer;
	bool modelTwoSided;
	float position[4];  // if position[3] == 0 light in directional else light is point light

	float spotExponent;
	float spotCutoff;
	float constantAttenuation;
	float linearAttenuation;
	float quadraticAttenuation;
};

#endif // LIGHT_H
