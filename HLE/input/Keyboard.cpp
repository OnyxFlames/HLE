#include "Keyboard.hpp"

#include <SFML/Window/VideoMode.hpp>

std::string hle::to_string(sf::Keyboard::Key key)
{
#define sfml_key_string_case(k) case sf::Keyboard::k: return #k

	switch (key)
	{
		case sf::Keyboard::Unknown: return "Unknown Key";

		sfml_key_string_case(A);
		sfml_key_string_case(B);
		sfml_key_string_case(C);
		sfml_key_string_case(D);
		sfml_key_string_case(E);
		sfml_key_string_case(F);
		sfml_key_string_case(G);
		sfml_key_string_case(H);
		sfml_key_string_case(I);
		sfml_key_string_case(J);
		sfml_key_string_case(K);
		sfml_key_string_case(L);
		sfml_key_string_case(M);
		sfml_key_string_case(N);
		sfml_key_string_case(O);
		sfml_key_string_case(P);
		sfml_key_string_case(Q);
		sfml_key_string_case(R);
		sfml_key_string_case(S);
		sfml_key_string_case(T);
		sfml_key_string_case(U);
		sfml_key_string_case(V);
		sfml_key_string_case(W);
		sfml_key_string_case(X);
		sfml_key_string_case(Y);
		sfml_key_string_case(Z);

		sfml_key_string_case(Num0);
		sfml_key_string_case(Num1);
		sfml_key_string_case(Num2);
		sfml_key_string_case(Num3);
		sfml_key_string_case(Num4);
		sfml_key_string_case(Num5);
		sfml_key_string_case(Num6);
		sfml_key_string_case(Num7);
		sfml_key_string_case(Num8);
		sfml_key_string_case(Num9);

		sfml_key_string_case(Escape);
		sfml_key_string_case(LControl);
		sfml_key_string_case(LShift);
		sfml_key_string_case(LAlt);
		sfml_key_string_case(LSystem);
		sfml_key_string_case(RControl);
		sfml_key_string_case(RShift);
		sfml_key_string_case(RAlt);
		sfml_key_string_case(RSystem);
		sfml_key_string_case(Menu);
		sfml_key_string_case(LBracket);
		sfml_key_string_case(RBracket);
		sfml_key_string_case(Semicolon);
		sfml_key_string_case(Comma);
		sfml_key_string_case(Period);
		sfml_key_string_case(Quote);
		sfml_key_string_case(Slash);
		sfml_key_string_case(Backslash);
		sfml_key_string_case(Tilde);
		sfml_key_string_case(Equal);
		sfml_key_string_case(Hyphen);
		sfml_key_string_case(Space);
		sfml_key_string_case(Enter);
		sfml_key_string_case(Backspace);
		sfml_key_string_case(Tab);
		sfml_key_string_case(PageUp);
		sfml_key_string_case(PageDown);
		sfml_key_string_case(End);
		sfml_key_string_case(Home);
		sfml_key_string_case(Insert);
		sfml_key_string_case(Delete);

		sfml_key_string_case(Add);
		sfml_key_string_case(Subtract);
		sfml_key_string_case(Multiply);
		sfml_key_string_case(Divide);

		sfml_key_string_case(Left);
		sfml_key_string_case(Right);
		sfml_key_string_case(Up);
		sfml_key_string_case(Down);

		sfml_key_string_case(Numpad0);
		sfml_key_string_case(Numpad1);
		sfml_key_string_case(Numpad2);
		sfml_key_string_case(Numpad3);
		sfml_key_string_case(Numpad4);
		sfml_key_string_case(Numpad5);
		sfml_key_string_case(Numpad6);
		sfml_key_string_case(Numpad7);
		sfml_key_string_case(Numpad8);
		sfml_key_string_case(Numpad9);

		sfml_key_string_case(F1);
		sfml_key_string_case(F2);
		sfml_key_string_case(F3);
		sfml_key_string_case(F4);
		sfml_key_string_case(F5);
		sfml_key_string_case(F6);
		sfml_key_string_case(F7);
		sfml_key_string_case(F8);
		sfml_key_string_case(F9);
		sfml_key_string_case(F10);
		sfml_key_string_case(F11);
		sfml_key_string_case(F12);

		sfml_key_string_case(Pause);

		// special case to get total keys supported
		case sf::Keyboard::KeyCount: return std::to_string(static_cast<int>(sf::Keyboard::KeyCount));

		default: return "Invalid Key";
	}

#undef sfml_key_string_case
}
