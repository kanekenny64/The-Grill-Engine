#include <chrono>

namespace thegrill {
	struct Timer
	{
	public:
		Timer();

		float elapsed();

		void reset();

	private:
		std::chrono::high_resolution_clock::time_point m_start;
	};
}
