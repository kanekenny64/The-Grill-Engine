#include "AnimationTrack.h"
#include "Model.h"
#include "Core.h"
#include "Resources.h"


namespace thegrill {
	AnimationTrack::AnimationTrack()
	{
		startFrame = 0;
	}

	/**
	 * @brief Creates the animation track by loading keyframes from a specified path.
	 *
	 * This function takes the name of the first .obj file in the animation sequence and looks for the rest of the files
	 * in the sequence based on Blender's default naming convention (e.g., example0001.obj, example0002.obj, etc.).
	 *
	 * @param _path The file path to the first model in the sequence.
	 * @param _numFrames The total number of frames to create in the animation track.
	 */

	void AnimationTrack::create(const std::string& _path, int _numFrames)
	{

		m_keyFrames.push_back(get_core()->get_resources()->load<Model>(_path)); ///< Load the first model.


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

			m_keyFrames.push_back(get_core()->get_resources()->load<Model>(newPath)); ///< Load the subsequent models.
		}
	}

	
}