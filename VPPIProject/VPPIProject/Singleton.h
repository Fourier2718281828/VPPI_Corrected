#ifndef SINGLETON_
#define SINGLETON_

class NonCopyable
{
public:
	NonCopyable() = default;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator=(const NonCopyable&) = delete;
};

template<typename Derived>
class Singleton : private NonCopyable
{
protected:
	Singleton() = default;
public:
	static Derived& get_instance()
	{
		static Derived instance;
		return instance;
	}
};

#endif // !SINGLETON_
