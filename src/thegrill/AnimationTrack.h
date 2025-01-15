#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Component.h"


namespace thegrill {

	struct Model;

	/**
	 * @brief The AnimationTrack class holds data for an animation track, including keyframes.
	 */
	struct AnimationTrack : Component {
		AnimationTrack();
		~AnimationTrack() = default;

		/**
		 * @brief Creates the animation track by loading keyframes from a specified path and continuing for a specified number of frames.
		 * @subsection Uses Blender's naming convention for .obj files outputted from animations.
		 * @param _path The file path to load the animation data from.
		 * @param _numFrames The number of frames to create in the animation track.
		 */
		void create(const std::string& _path, int _numFrames);

		int startFrame; ///< The index of the first frame in the animation.

		/// A vector of shared pointers to the keyframes of the animation track.
		std::vector<std::shared_ptr<Model> > m_keyFrames;
	};
}
		