#include "StateStack.hpp"

#include <cassert>

namespace hle
{
	State::Ptr StateStack::createState(States::ID stateID)
	{
		auto found = mFactories.find(stateID);
		if (found != mFactories.end())
		{
			found = mFactories.find(States::ErrorState);
			assert(found != mFactories.end());
		}

		return found->second();
	}
	void StateStack::applyPendingChanges()
	{
		for (auto change : mPendingList)
		{
			switch (change.action)
			{
			case Action::Push: mStack.push_back(createState(change.stateID)); break;
			case Action::Pop: mStack.pop_back(); break;
			case Action::Clear: mStack.clear(); break;
			}
		}
		mPendingList.clear();
	}
	StateStack::StateStack(const State::Context& context)
		: mContext(context)
	{
	}
	void StateStack::update(sf::Time dt)
	{
		for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
			if (!(*itr)->update(dt))
				return;

		applyPendingChanges();
	}
	void StateStack::draw()
	{
		// TODO: add single-layer and deep rendering states option
		for (auto& state : mStack)
			state->draw();
	}
	void StateStack::handleEvent(const sf::Event& event)
	{
		for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
			if (!(*itr)->handleEvent(event))
				return;

		applyPendingChanges();
	}
	void StateStack::pushState(States::ID stateID)
	{
		mPendingList.push_back(PendingChange(Action::Push, stateID));
	}
	void StateStack::popState()
	{
		mPendingList.push_back(PendingChange(Pop));
	}
	void StateStack::clearStates()
	{
		mPendingList.push_back(PendingChange(Clear));
	}

	bool StateStack::empty() const
	{
		return mStack.empty();
	}

	StateStack::PendingChange::PendingChange(Action _action)
		:	action(_action)
		,	stateID(States::ID::ErrorState)
	{
		// TODO: Add errorstate message for failing pending change
	}

	StateStack::PendingChange::PendingChange(Action _action, States::ID _id)
		:	action(_action)
		,	stateID(_id)
	{
	}
}