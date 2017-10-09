#pragma once


#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform {
	public:

		Transform();

		glm::mat4 GetModelMatrix();
		glm::vec3 GetPosition();
		glm::quat GetRotation();
		glm::vec3 GetScale();

		//cambiar posiscion actual
		void SetPosition(float x, float y, float z);
		void SetRotation(float x, float y, float z);
		void SetScale(float x, float y, float z);

		//Sum a la posicion actual
		void Translate(float x, float y, float z, bool world); 
		void MoveForward(float delta, bool world); 
		void MoveUp(float delta, bool world);
		void MoveRight(float delta, bool world);
		void Rotate(float x, float y, float z, bool world);

		//vectores propios del mundo
		static constexpr glm::vec3 WORLD_FORWARD_VECTOR = glm::vec3(0.0f, 0.0f, 1.0f);
		static constexpr glm::vec3 WORLD_UP_VECTOR = glm::vec3(0.0f, 1.0f, .0f);
		static constexpr glm::vec3 WORLD_RIGHT_VECTOR = glm::vec3(1.0f, 0.0f, 0.0f);

	private:
		//llmar cuando la posicion, rotacion o escala cambie
		void UpdateLocalVectors();
		void UpdateModelMatrixPosition();
		void UpdateModelMatrixRotationScale();

		//resultado de toda la clase
		glm::mat4 _modelMatrix;

		//calcular matriz modelo
		glm::vec3 _position;
		glm::quat _rotation;
		glm::vec3 _scale;
		
		//vectores propios del objeto
		glm::vec3 _forward;	
		glm::vec3 _up;
		glm::vec3 _right;

		
};