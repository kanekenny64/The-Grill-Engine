#pragma once

#include <vector>
#include <memory>
#include <string>
#include "Component.h"

namespace thegrill {

	struct Model;

	struct AnimationTrack : Component {
		//This is a struct that holds the data for an animation track
		//It holds the keyframes for the track
		int startFrame;
		
		std::vector<std::shared_ptr<Model> > m_keyFrames;

		//AnimationTrack() = default;

		AnimationTrack();
		~AnimationTrack() = default;

		void create(const std::string& _path, int _numFrames);


	};
}
		