#ifndef APPLICATION_
#define APPLICATION_

class Application
{
public:
	virtual ~Application() = default;
public:
	virtual int execute() const noexcept = 0;
};

#endif // !APPLICATION_
