#pragma once

#include <queue>

#include "Command.hpp"

namespace hle
{
	class CommandQueue
	{
	public:
		void push(const Command& command);
		Command pop();
		const Command& peek() const;
		bool empty() const;
	private:
		std::queue<Command> mQueue;
	};
}
