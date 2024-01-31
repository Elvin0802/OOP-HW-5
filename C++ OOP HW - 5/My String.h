#pragma once

class String {
private:

	size_t _length = 0;
	size_t _capacity = 16;
	char* _text = nullptr;

	void SetText(const char* text);

public:

	String();
	String(const char* const text);
	String(const size_t count, const char symbol);
	String(const String& other);
	String(String&& other)noexcept;
	String(const char* const text, const size_t Count);
	String(const String& text, const size_t Count);

	String& operator=(const String& other);
	String& operator=(const char* other);
	String& operator=(const char& other);
	String& operator=(const int number);
	String& operator=(const bool cond);

	String& operator+(const String& other);
	String& operator+(const char* other);
	String& operator+(const char& other);
	String& operator+(const int number);
	String& operator+(const bool cond);

	String& operator*(const String& other);
	String& operator*(const char* other);
	String& operator*(const int number);
	String& operator*(const bool cond);

	String& operator+=(const String& other);
	String& operator+=(const char* other);
	String& operator+=(const char& other);
	String& operator+=(const int number);
	String& operator+=(const bool cond);

	String& operator*=(const String& other);
	String& operator*=(const char* other);
	String& operator*=(const int count);
	String& operator*=(const bool cond);

	bool operator==(const String& other);
	bool operator==(const char* other);
	bool operator==(const int count);

	char& operator[](const size_t index)const;
	char& operator()(const size_t index)const;

	char& front();
	char& back();
	char& at(size_t index);

	size_t capacity() const;
	size_t size() const;
	size_t find(char chr) const;
	size_t rfind(char chr) const;

	void clear();
	void resize(size_t newSize);
	void reserve(size_t newCapacity);
	void shrink_to_fit();
	bool empty() const;

	size_t length() const;
	void push_back(const char& chr);
	void pop_back();
	void assign(const char* const string);
	void insert(size_t index, const char* const str);
	void swap(String& other);
	const char* c_str() const noexcept;
	void copy(char* dest, size_t count, size_t offer) const;

	String& append(const char* const text); // "a".append("b") => "ab"

	int compare(const String& right); // -1, 0, 1

	const char* print() const { return _text; }

	~String()noexcept;
};