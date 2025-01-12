#include "Timer.h"

namespace thegrill
{
	Timer::Timer()
	{
		m_start = std::chrono::high_resolution_clock::now();
	}

	float Timer::elapsed()
	{
		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> time = std::chrono::duration_cast<std::chrono::duration<float>>(now - m_start);
		return time.count();
	}

	void Timer::reset()
	{
		m_start = std::chrono::high_resolution_clock::now();
	}

}