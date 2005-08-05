#ifndef _MODELS_H_
#define _MODELS_H_

/**> Model Loading <**/
//
// Model Maximums
//
#include "gl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "Constants.h"
#include "Terrain.h"
#include "binio.h"
#include "Quaternions.h"

//
// Textures List
//
typedef struct		{
	long			xsz,ysz;
	GLubyte				*txt;
} ModelTexture;

//
// Model Structures
//

class TexturedTriangle{
public:
	short			vertex[3];
	float gx[3],gy[3];
};

#define max_model_decals 300

#define nothing 0
#define normaltype 4
#define notextype 1
#define rawtype 2
#define decalstype 3

class Model{
public:
	short	vertexNum,TriangleNum;
	bool hastexture;

	int type,oldtype;

	int* possible;
	int* owner;
	XYZ* vertex;
	XYZ* normals;
	XYZ* facenormals;
	TexturedTriangle* Triangles;
	GLfloat* vArray;

	/*int possible[max_model_vertex];
	int owner[max_textured_triangle];
	XYZ vertex[max_model_vertex];
	XYZ normals[max_model_vertex];
	XYZ facenormals[max_textured_triangle];
	TexturedTriangle Triangles[max_textured_triangle];
	GLfloat vArray[max_textured_triangle*24];*/

	GLuint 				textureptr;
	ModelTexture		Texture;
	int numpossible;
	bool color;

	XYZ boundingspherecenter;
	float boundingsphereradius;

	float*** decaltexcoords;
	XYZ** decalvertex;
	int* decaltype;
	float* decalopacity;
	float* decalrotation;
	float* decalalivetime;
	XYZ* decalposition;

	/*float decaltexcoords[max_model_decals][3][2];
	XYZ decalvertex[max_model_decals][3];
	int decaltype[max_model_decals];
	float decalopacity[max_model_decals];
	float decalrotation[max_model_decals];
	float decalalivetime[max_model_decals];
	XYZ decalposition[max_model_decals];*/

	int numdecals;

	bool flat;

	void DeleteDecal(int which);
	void MakeDecal(int atype, XYZ *where, float *size, float *opacity, float *rotation);
	void MakeDecal(int atype, XYZ where, float size, float opacity, float rotation);
	void drawdecals(GLuint shadowtexture,GLuint bloodtexture,GLuint bloodtexture2,GLuint breaktexture);
	int SphereCheck(XYZ *p1,float radius, XYZ *p, XYZ *move, float *rotate);
	int SphereCheckPossible(XYZ *p1,float radius, XYZ *move, float *rotate);
	int LineCheck(XYZ *p1,XYZ *p2, XYZ *p, XYZ *move, float *rotate);
	int LineCheckSlide(XYZ *p1,XYZ *p2, XYZ *p, XYZ *move, float *rotate);
	int LineCheckPossible(XYZ *p1,XYZ *p2, XYZ *p, XYZ *move, float *rotate);
	int LineCheckSlidePossible(XYZ *p1,XYZ *p2, XYZ *p, XYZ *move, float *rotate);
	void UpdateVertexArray();
	void UpdateVertexArrayNoTex();
	void UpdateVertexArrayNoTexNoNorm();
	bool loadnotex(char *filename);
	bool loadraw(char *filename);
	bool load(char *filename,bool texture);
	bool loaddecal(char *filename,bool texture);
	void Scale(float xscale,float yscale,float zscale);
	void FlipTexCoords();
	void UniformTexCoords();
	void ScaleTexCoords(float howmuch);
	void ScaleNormals(float xscale,float yscale,float zscale);
	void Translate(float xtrans,float ytrans,float ztrans);
	void CalculateNormals(bool facenormalise);
	void draw();
	void drawdifftex(GLuint texture);
	void drawimmediate();
	void drawdiffteximmediate(GLuint texture);
	void Rotate(float xang,float yang,float zang);
	~Model();
	void deallocate();
	Model();
};

#endif