#pragma once

#include "../Common.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace hle
{
	namespace time
	{
		class FramerateClock
		{
		private:
			uint32_t mFrames;
			uint32_t mFramesPerSec;
			sf::Time mTime;
			sf::Clock mClock;
		public:

			FramerateClock();

			const uint32_t getFramerate();
			bool update();
		};
	}
}
