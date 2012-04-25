#pragma once
#include "stdafx.h"
#include <math.h>

	void NewPoint::CreatePoint(float x , float y ) 
	{
		xval = x;
		yval = y;
	}

	 float NewPoint::x() { return xval; }
	 float NewPoint::y() { return yval; }

