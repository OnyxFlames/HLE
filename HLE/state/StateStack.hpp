#pragma once

#include <map>
#include <vector>

#include <functional>

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "State.hpp"

#include "StateIdentifiers.hpp"

namespace hle
{
	class StateStack
	{
	public:
		enum Action
		{
			Unknown = -1,
			Push,
			Pop,
			Clear,
			ActionCount,
		};
	public:
		explicit StateStack(const State::Context& context);

		template <typename T>
		void registerState(States::ID stateID);

		void update(sf::Time dt);
		void draw();
		void handleEvent(const sf::Event& event);

		void pushState(States::ID stateID);
		void popState();
		void clearStates();

		bool empty() const;

	private:
		State::Ptr createState(States::ID stateID);
		void applyPendingChanges();

	private:
		struct PendingChange
		{
			Action action;
			States::ID stateID;
			PendingChange(Action _action);
			PendingChange(Action _action, States::ID _id);
		};
	private:
		std::vector<State::Ptr> mStack;
		std::vector<PendingChange> mPendingList;
		State::Context mContext;
		std::map<States::ID, std::function<State::Ptr()>> mFactories;
	};
	template<typename T>
	inline void StateStack::registerState(States::ID stateID)
	{
		mFactories[stateID] = [this]()
		{
			return State::Ptr(new T(*this, mContext));
		};
	}
}
