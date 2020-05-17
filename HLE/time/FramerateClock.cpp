#include "FramerateClock.hpp"

hle::time::FramerateClock::FramerateClock()
	:	mFrames(0)
	,	mFramesPerSec(0)
	,	mTime(sf::Time::Zero)
	,	mClock()
{
}

const uint32_t hle::time::FramerateClock::getFramerate()
{
	return mFramesPerSec;
}

bool hle::time::FramerateClock::update()
{
	mTime += mClock.restart();
	++mFrames;

	if (mTime >= sf::seconds(1.0f))
	{
		mFramesPerSec = mFrames;
		mFrames = 0;
		mTime -= sf::seconds(1.0f);
		return true;
	}
	return false;
}
