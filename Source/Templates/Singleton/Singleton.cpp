class Singleton
{
public:
	static Singleton& get()
	{
		static Singleton instance;

		return instance;
	}

	Singleton(const Singleton&) = delete;

	Singleton& operator= (const Singleton&) = delete;

private:
	Singleton() = default;
};
