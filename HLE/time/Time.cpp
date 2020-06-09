#include "Time.hpp"

#include <iomanip>
#include <sstream>

namespace hle
{
	namespace time
	{
		sf::Time minutes(float mins)
		{
			return sf::seconds(Minute.asSeconds() * mins);
		}
		sf::Time hours(float hours)
		{
			return sf::seconds(Hour.asSeconds() * hours);
		}
		sf::Time days(float days)
		{
			return sf::seconds(Day.asSeconds() * days);
		}
		std::string to_string(const sf::Time time)
		{
			return format_time(time, TimeFormat::BySize);
		}
		std::string format_time(const sf::Time time, TimeFormat format)
		{
			std::ostringstream oss;

			switch (format)
			{
			case TimeFormat::Microseconds:	oss << time.asMicroseconds() << " us"; break;
			case TimeFormat::Milliseconds:	oss << time.asMilliseconds() << " ms"; break;
			case TimeFormat::Seconds:
			{
				const auto sec = time.asSeconds();
				oss << sec << (sec == 1.f ? " second" : " seconds"); 
				break; 
			}
			case TimeFormat::Minutes:
			{
				const auto min = time.asSeconds() / Minute.asSeconds();
				oss << min << (min == 1.f ? " minute" : " minutes");
				break;
			}
			case TimeFormat::Hours:
			{
				const auto hour = time.asSeconds() / Hour.asSeconds();
				oss << hour << (hour == 1.f ? " hour" : " hours");
				break;
			}
			case TimeFormat::Days:
			{
				const auto day = time.asSeconds() / Day.asSeconds();
				oss << day << (day == 1.f ? " day" : " days");
				break;
			}
			case TimeFormat::Clock:
				{
					sf::Time buff = time;
					while (buff >= Day)
					{
						buff -= Day;
					}
					uint32_t hours = 0;
					while (buff >= Hour)
					{
						buff -= Hour;
						++hours;
					}
					uint32_t minutes = 0;
					while (buff >= Minute)
					{
						buff -= Minute;
						++minutes;
					}
					oss << std::setfill('0') << std::setw(2) << hours << ":" << std::setfill('0') << std::setw(2) << minutes;
				break;
				}
			case TimeFormat::BySize:
				if (time >= sf::microseconds(1) && time < sf::milliseconds(1))
					return format_time(time, TimeFormat::Microseconds);
				else if (time >= sf::milliseconds(1) && time < sf::seconds(1.f))
					return format_time(time, TimeFormat::Milliseconds);
				else if (time >= sf::seconds(1.f) && time < time::minutes(1.f))
					return format_time(time, TimeFormat::Seconds);
				else if (time >= time::minutes(1.f) && time < time::hours(1.f))
					return format_time(time, TimeFormat::Minutes);
				else if (time >= time::hours(1.f) && time < time::days(1.f))
					return format_time(time, TimeFormat::Hours);
				else if (time >= time::days(1.f))
					return format_time(time, TimeFormat::Days);
				else // reasonable default
					return format_time(time, TimeFormat::Seconds);
				break;
			}
			return oss.str();
		}
	}
}