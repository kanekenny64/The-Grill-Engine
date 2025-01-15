#include "Renderer/Mesh.h"
#include "Renderer/Shader.h"


namespace thegrill {

	struct Core;
	struct Texture;

	/**
	 * @brief The GUI system handles rendering of GUI elements.
	 */
	struct GUI
	{
		/**
		 * @brief Constructs a GUI instance.
		 * @param _core A shared pointer to the core engine instance.
		 */
		GUI(std::shared_ptr<Core> _core);
		~GUI();

		/**
		 * @brief Renders an image on the screen.
		 * @param _tex A shared pointer to the texture to render.
		 * @param _x The x-coordinate of the image.
		 * @param _y The y-coordinate of the image.
		 * @param _w The width of the image.
		 * @param _h The height of the image.
		 */
		void image(std::shared_ptr<Texture> _tex, float _x, float _y, float _w, float _h);

		/**
		 * @brief Renders a button on the screen.
		 * @param _tex A shared pointer to the texture to render.
		 * @param _x The x-coordinate of the button.
		 * @param _y The y-coordinate of the button.
		 * @param _w The width of the button.
		 * @param _h The height of the button.
		 * @return An integer indicating the button state.
		 */
		int button(std::shared_ptr<Texture> _tex, float _x, float _y, float _w, float _h);

	private:
		friend struct thegrill::Core;

		std::weak_ptr<Core> m_core;
		std::shared_ptr<renderer::Shader> mShader;
		std::shared_ptr<renderer::Mesh> mRect;
	};

}