#include "CommandQueue.hpp"

#include <cassert>

namespace hle
{

	void CommandQueue::push(const Command& command)
	{
		mQueue.push(command);
	}

	Command CommandQueue::pop()
	{
		if (mQueue.empty())
			return Command();
		else
		{
			Command command = mQueue.front();
			mQueue.pop();
			return command;
		}
	}

	const Command& CommandQueue::peek() const
	{
		assert(!mQueue.empty());

		return mQueue.front();
	}

	bool CommandQueue::empty() const
	{
		return mQueue.empty();
	}
}