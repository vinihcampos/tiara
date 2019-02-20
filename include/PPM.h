#ifndef _PPM_
#define _PPM_

#include "Canvas.h"
#include <string>

namespace tiara{
	class PPM{
		public:
			static std::string generator(const Canvas & canvas);
	};
}

#endif