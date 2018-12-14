#pragma once

#ifndef INCLUDE_STRUCT_
#define INCLUDE_STRUCT_

typedef struct {

	double x, y;

}sPos;

typedef struct
{
	sPos pos;
	double r, cx, cy;
	int onActive;

}sOBJPos;




/*
typedef struct
{
	double ang;
	double deg;
	double r;
	sPos pos;
	int ActiveFlg;
	int* Graph;
	int width;
	int height;

}sUtility;*/


#endif // INCLUDE_STRUCT_
