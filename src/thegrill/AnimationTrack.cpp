#include "AnimationTrack.h"
#include "Model.h"
#include "Core.h"
#include "Resources.h"


namespace thegrill {
	AnimationTrack::AnimationTrack()
	{
		startFrame = 0;
	}

	void AnimationTrack::create(const std::string& _path, int _numFrames)
	{
		//Takes in the name of the first .obj file in the animation then looks for the rest of the files in the sequence
		//Naming convention uses Blender's default of example0001.obj, example0002.obj, example0003.obj, etc.

		m_keyFrames.push_back(get_core()->get_resources()->load<Model>(_path));


		//find the first part of the file name without the number
		std::string oldPath = _path.substr(0, _path.size() - 4);
		std::string newPath;

		for (int i = 2; i < _numFrames; i++)
		{
			if (i > 999)
			{
				newPath = oldPath + std::to_string(i);
			}
			else if (i > 99)
			{
				newPath = oldPath + "0" + std::to_string(i);
			}
			else if (i > 9)
			{
				newPath = oldPath + "00" + std::to_string(i);
			}
			else
			{
				newPath = oldPath + "000" + std::to_string(i);
			}

			std::cout << newPath << std::endl;

			m_keyFrames.push_back(get_core()->get_resources()->load<Model>(newPath));
		}
	}

	
}