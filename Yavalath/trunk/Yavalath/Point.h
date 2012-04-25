#pragma once

class NewPoint 
{
	private:
			float xval, yval;
	public:
		 // Constructor uses default arguments to allow calling with zero, one,
        // or two values.
        void CreatePoint(float x, float y);

		// Extractors.
        float x();
        float y();

		//Set


};