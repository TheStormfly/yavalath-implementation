// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

// TODO: reference additional headers your program requires here
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Drawing;

using namespace std;


typedef struct {
	unsigned char b[61];
}structBoard;

#include <time.h>
#include <iostream>
#include <math.h>
#include <vector>


#include "Hexagon.h"
#include "Board.h"
#include "Minimax.h"
#include "Form1.h"
