#ifndef TSINGELTON
#define TSINGLETON

template <class T>
class TSingleton
{
protected:
	static T *m_pSingleton;

public:
	virtual ~TSingleton()
	{
	}

	inline static T* Get()
	{
		if (!m_pSingleton)
			m_pSingleton = new T;

		return (m_pSingleton);
	}

	static void Del()
	{
		if (m_pSingleton)
		{
			delete (m_pSingleton);
			m_pSingleton = NULL;
		}
	}
};

template <class T>
T* TSingleton<T>::m_pSingleton = 0;

#endif