#include <string>
#pragma once

namespace thegrill {
	struct Resources;
	struct Resource	
	{
		std::string getPath() const;
	private:
		friend struct thegrill::Resources;
		virtual void onLoad() = 0;
		virtual void onUnload() = 0;

		void load();
		void unload();

		std::string m_path;

	protected:
		float m_timeout;
	};


	
}

