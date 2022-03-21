#pragma once
#include "KeyboardEvent.h"
#include <queue>
#include <memory>
#include<d3d9.h>

using namespace::std;

class KeyboardClass
{
public:
	KeyboardClass(KeyboardClass&) = delete;
	void operator=(KeyboardClass&) = delete;
	static shared_ptr<KeyboardClass> GetInstance();

	bool KeyIsPressed(const unsigned char keycode);
	bool KeyBufferIsEmpty();
	bool CharBufferIsEmpty();
	KeyboardEvent ReadKey();
	unsigned char ReadChar();
	void OnKeyPressed(const unsigned char key);
	void OnKeyReleased(const unsigned char key);
	void OnChar(const unsigned char key);
	void EnableAutoRepeatKeys();
	void DisableAutoRepeatKeys();
	void EnableAutoRepeatChars();
	void DisableAutoRepeatChars();
	bool IsKeysAutoRepeat();
	bool IsCharsAutoRepeat();
private:
	KeyboardClass();
	bool autoRepeatKeys = false;
	bool autoRepeatChars = false;
	bool keyStates[256];
	std::queue<KeyboardEvent> keyBuffer;
	std::queue<unsigned char> charBuffer;

	static shared_ptr<KeyboardClass> instance;
};

