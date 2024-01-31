#pragma once

String::String()
{
	_text = new char[_capacity];
	_text[0] = '\0';
}
String::String(const char* const text) : String()
{
	SetText(text);
}
String::String(const size_t count, const char symbol) : String()
{
	char* newString = new char[count + 1];

	for (size_t i = 0; i < count; i++)
		newString[i] = symbol;

	newString[count] = '\0';
	SetText(newString);

	delete[] newString;
}
String::String(String&& other) noexcept
{
	this->_capacity = other._capacity;
	other._capacity = 0;

	this->_length = other._length;
	other._length = 0;

	this->_text = other._text;
	other._text = nullptr;
}
String::String(const String& other) : String(other._text) {}
String::String(const char* const text, const size_t Count) : String()
{
	char* txt = new char[Count];

	for (int i = 0; i < Count; i++) txt[i] = text[i];

	SetText(txt);
	delete[] txt;
}
String::String(const String& text, const size_t Count) : String()
{
	char* txt = new char[Count];

	for (int i = 0; i < Count; i++) txt[i] = text._text[i];

	SetText(txt);
	delete[] txt;
}

void String::SetText(const char* text)
{
	size_t len = strlen(text);

	if (len + _length >= _capacity)
	{
		while (len + _length >= _capacity)
			_capacity += 16;

		char* newText = new char[_capacity];

		int index = 0;
		for (size_t i = 0; i < _length; i++)
			newText[index++] = _text[i];

		for (size_t i = 0; i < len; i++)
			newText[index++] = text[i];

		newText[index] = '\0';
		_length = _length + len;

		delete[] _text;
		_text = newText;
	}
	else
	{
		int index = _length;
		for (size_t i = 0; i < len; i++)
			_text[index++] = text[i];

		_text[index] = '\0';
		_length = index;
	}
}

String& String::operator=(const String& other)
{
	this->_length = 0;
	this->SetText(other._text);
	return *this;
}
String& String::operator=(const char* other)
{
	this->SetText(other); return *this;
}
String& String::operator=(const char& other)
{
	this->_length = 0;
	SetText(&other);
	return *this;
}
String& String::operator=(const int number)
{
	this->_length = 0;
	SetText(NumToStr(number));
	return *this;
}
String& String::operator=(const bool cond)
{
	if (!cond)
	{
		delete[] _text;
		_text = new char[1] {""};
	}

	this->shrink_to_fit();

	return (*this);
}

String& String::operator+(const String& other)
{
	String* conStr = new String(this->_text);

	conStr->SetText(other._text);

	return *conStr;
}
String& String::operator+(const char* other)
{
	String* conStr = new String(this->_text);

	conStr->SetText(other);

	return *conStr;
}
String& String::operator+(const char& other)
{
	String* conStr = new String(this->_text);

	conStr->SetText(&other);

	return *conStr;
}
String& String::operator+(const int number)
{
	String* conStr = new String(this->_text);

	conStr->SetText(NumToStr(number));

	return *conStr;
}
String& String::operator+(const bool cond)
{
	String* str = new String(this->_text);

	if (cond) str->SetText("-true");
	else str->SetText("-false");

	return *str;
}

String& String::operator*(const int count)
{
	String* newStr = new String("");

	for (size_t t = 0; t < count; t++)
		newStr->SetText(this->_text);

	return *newStr;
}
String& String::operator*(const String& other)
{
	String* newStr = new String("");

	for (size_t t = 0; t < other._length; t++)
		newStr->SetText(this->_text);

	return *newStr;
}
String& String::operator*(const char* other)
{
	String* newStr = new String("");

	for (size_t t = 0; t < strlen(other); t++)
		newStr->SetText(this->_text);

	return *newStr;
}
String& String::operator*(const bool cond)
{
	String* str = new String("");

	if (cond) str->SetText(this->_text);

	str->shrink_to_fit();

	return *str;
}

String& String::operator+=(const String& other)
{
	this->SetText(other._text);

	return (*this);
}
String& String::operator+=(const char* other)
{
	this->SetText(other);

	return (*this);
}
String& String::operator+=(const char& other)
{
	this->SetText(&other);

	return (*this);
}
String& String::operator+=(const int number)
{
	this->SetText(NumToStr(number));

	return (*this);
}
String& String::operator+=(const bool cond)
{
	if (cond) this->SetText("-true");
	else this->SetText("-false");

	return (*this);
}

String& String::operator*=(const String& other)
{
	for (size_t t = 0; t < other._length; t++)
		this->SetText(this->_text);

	return (*this);
}
String& String::operator*=(const char* other)
{
	for (size_t t = 0; t < strlen(other); t++)
		this->SetText(this->_text);

	return (*this);
}
String& String::operator*=(const int count)
{
	for (size_t t = 0; t < count; t++)
		this->SetText(this->_text);

	return (*this);
}
String& String::operator*=(const bool cond)
{
	if (cond) this->SetText(this->_text);

	this->shrink_to_fit();

	return (*this);
}

bool String::operator==(const String& other)
{
	if (strcmp(this->_text, other._text) == 0) return true;
	else return false;
}
bool String::operator==(const char* other)
{
	if (strcmp(this->_text, other) == 0) return true;
	else return false;
}
bool String::operator==(const int count)
{
	if (_length == count) return true;
	else return false;
}

char& String::operator[](const size_t index)const
{
	if (_length != 0)
		if (index >= 0 && index < _length)
			return _text[index];

	assert(!"Index Out of Range !!!");
}
char& String::operator()(const size_t index)const
{
	if (_length != 0)
		if (index >= 0 && index < _length)
			return _text[_length - index];

	assert(!"Index Out of Range !!!");
}

ostream& operator<<(ostream& print, const String& other)
{
	print << other._text; return print;
}

istream& operator>>(istream& input, String& other)
{
	int len = other._capacity;
	char* Text = new char[500];

	input.getline(Text, 500);

	other.SetText(Text);

	return input;
}

char& String::front()
{
	if (_length > 0) return _text[0];
	else assert(!"String is Free");
}
char& String::back()
{
	if (_length > 0) return _text[_length - 1];
	else assert(!"String is Free");
}
char& String::at(size_t index)
{
	if (_length > 0)
	{
		if (index < _length)
			return this->_text[index];
		else assert(!"-->  Index Out Of Range ! ");
	}
	else assert(!"String is Free");
}

size_t String::capacity() const { return (_capacity - 1); }
size_t String::size() const { return _length; }
size_t String::find(char chr) const
{
	for (size_t a = 0; a < _length; a++)
		if (_text[a] == chr)
			return a;

	assert(!"-->  Char Not Found ! ");
}
size_t String::rfind(char chr) const
{
	for (size_t a = _length - 1;; a--)
	{
		if (a > _length) break;

		if (_text[a] == chr) return a;
	}

	assert(!"-->  Char Not Found ! ");
}

void String::clear()
{
	delete[] _text;
	_capacity = 16;
	_length = 0;
	_text = new char[_capacity];
	_text[0] = '\0';
}
void String::reserve(size_t newCapacity)
{
	if (newCapacity > _capacity)
	{
		int tam = newCapacity / 16;
		short int kesr = newCapacity % 16;

		this->_capacity = (tam * 16) + (kesr > 0 ? 16 : 0);

		char* newStr = new char[_capacity];

		this->_length = 0;
		this->SetText(_text);

		delete[] _text;
		_text = newStr;

	}
}
void String::resize(size_t newSize)
{
	if (newSize <= _length)
	{
		_length = newSize;
		_text[_length] = '\0';
	}
	else
	{
		reserve(newSize);
		while (_length < newSize) {
			_text[_length] = '\0';
			this->_length += 1;
		}
	}
}
void String::shrink_to_fit()
{
	if (_length < _capacity)
	{
		int tam = _length / 16;
		short int kesr = _length % 16;

		this->_capacity = (tam * 16) + (kesr > 0 ? 16 : 0);

		char* newStr = new char[_capacity];

		this->_length = 0;
		this->SetText(_text);

		delete[] _text;
		_text = newStr;
	}
}
bool String::empty() const
{
	return (_length == 0);
}

size_t String::length() const { return _length; }
void String::push_back(const char& chr)
{
	SetText(&chr);
}
void String::pop_back()
{
	if (_length > 0) this->_text[--_length] = '\0';
}
void String::assign(const char* const string)
{
	_length = 0;
	SetText(string);
}
void String::insert(size_t LocIndex, const char* const text)
{
	if (LocIndex > _length) this->append(text);
	else
	{
		size_t len = strlen(text);

		while (len + _length >= _capacity)
			_capacity += 16;

		char* newText = new char[_capacity];

		int index = 0;

		for (size_t i = 0; i < LocIndex; i++) // yrtb   0, mvc
			newText[index++] = _text[i];

		for (size_t i = 0; i < len; i++)
			newText[index++] = text[i]; // mvc

		for (size_t i = 0; i < _length; i++)
			newText[index++] = _text[i];

		newText[index] = '\0';
		_length = _length + len;

		delete[] _text;
		_text = newText;
	}
}
void String::swap(String& other)
{
	if (other._text != nullptr)
	{
		char* temp = this->_text;

		this->_text = other._text;

		other._text = temp;

		size_t sTemp = _length;
		_length = other._length;
		other._length = sTemp;

		size_t cTemp = _capacity;
		_capacity = other._capacity;
		other._capacity = cTemp;

		return;
	}
	assert(!"Gonderilen string nullptr -dir !!!");
}
const char* String::c_str() const noexcept { return _text; }
void String::copy(char* destination, size_t count, size_t index) const
{
	if (index > _length) assert(!"Index Out Of Range !!!");

	for (int k = 0; k < count; k++)
		destination[k] = _text[index++];

	destination[count] = '\0';
}

String& String::append(const char* const text)
{
	SetText(text);
	return *this;
}
int String::compare(const String& right)
{
	return strcmp(this->_text, right._text);
}

String::~String() noexcept
{
	if (_text != nullptr)
	{
		delete[] _text;
		_text = nullptr;
	}
}