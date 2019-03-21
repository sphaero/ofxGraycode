#include "GraycodeMath.h"

namespace ofxGraycode {
	namespace Utils {
		//----------
		int Math::toGraycode(int binary) {
			return binary ^ (binary >> 1);
		}
	}
}
