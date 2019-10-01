#ifndef KEYBOARDSTATE_H
#define KEYBOARDSTATE_H

#define MAX_KEYSTATE 5
#define MAX_MOUSESTATE 5

namespace K {
	enum KState
	{
		Up,
		Down,
		Left,
		Right,
		Skill1,
		Skill2,
	};
}

namespace M {
	enum class MState
	{
		Left,
		Right,
		Middle
	};
}


extern bool KEYBOARD[MAX_KEYSTATE];
//extern bool MOUSE[MAX_MOUSESTATE];



#endif // !KEYBOARDSTATE_H
