#include "Command.hpp"

namespace hle
{
	Command::Command()
		:	category(Category::None)
		,	action()
		,	id(-1)
	{
	}
	Command::Command(Category::Type _type, Action _action)
		: category(_type)
		, action(_action)
		, id(-1)
	{
	}
	Command::Command(Category::Type _type, Action _action, Entity::ID _id)
		: category(_type)
		, action(_action)
		, id(_id)
	{
	}
}