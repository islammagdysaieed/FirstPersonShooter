#ifndef Renderer_h__
#define Renderer_h__

#include <gl/glew.h>
#include <gl/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>
#include "Shaders/shader.hpp"
#include "ShaderProgram/ShaderProgram.h"
#include"SkyBox/SkyBox.h"
#include "CollisionDetection/CollisionManager.h"
#include "GameComponents/Hero.h"
#include "GameScene/Level1.h"
using namespace std;
class Renderer
{
	std::unique_ptr<CollisionManager> collisionManager;
	unique_ptr<Hero> hero;
	std::unique_ptr<SkyBox> Game_SkyBox;

	unique_ptr<Level1> Firstlevel;


    GLuint programID;
    KeyFrameAnimationShader animatedModelShader;
	ShaderProgram shader;
	// Transformation
	//GLuint MatrixID;
	GLuint ModelMatrixID;
	GLuint AmbientLightID;
	GLuint LightPositionID;
	GLuint EyePositionID;
	//std::unique_ptr<EulerCamera> myCamera;

	glm::vec3 ambientLight;
	glm::vec3 lightPosition;

public:
    Renderer();
    ~Renderer();
    
    void Initialize();
    void Draw();
	void HandleKeyboardInput(int key);
	void HandleMouse(double deltaX,double deltaY);
	void Update(double deltaTime);
    void Cleanup();
};

#endif // Renderer_h__

