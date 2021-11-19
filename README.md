# 700110-2122-ACW

The purpose of this project is to provide students with a foundation to create the coursework. It provides the ability to create graphics in order to demonstrate the physics simulation and AI agent based behaviour for the module. This readme will give you a quick overview of how to interact with the framework.

# GameEntity

It is expected that most of the classes you create will inherit from GameEntity. GameEntity provides every entity with an ID. You may find it useful to use this if you need to send messages from one entity to another by creating message managing functionality. The GameEntity class also includes a glm::mat4 m_Model datamember, which is the model matrix - this is where the game entity is in the world. A limited amount of functionality is provided in the GameEntity object to apply translations and rotations to the m_Model matrix. The GameEntity also uses a glm::vec3 m_Colour to represent the colour of a GameEntity.

The game entity also includes virtual functions Render that Renders the GameEntity using OpenGL and RenderGui that renders the GameEntity to the ImGUI user interface. This can allow for some modification of the values in the game entity.

# Camera

There is a Camera class adapted from https://learnopengl.com/code_viewer_gh.php?code=includes/learnopengl/camera.h. This is also a game entity and so you can render it to the Gui and edit some of it's values there. It is tied in to the main App in the App.cpp file via a keyboard polling method in the update.

``` cpp
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window, Camera& pCamera, float pDeltaTime)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        pCamera.ProcessKeyboard(FORWARD, pDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        pCamera.ProcessKeyboard(BACKWARD, pDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            pCamera.ProcessKeyboard(LEFT, pDeltaTime);
        else
            pCamera.ProcessKeyboard(ROTATE_LEFT, pDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            pCamera.ProcessKeyboard(RIGHT, pDeltaTime);
        else
            pCamera.ProcessKeyboard(ROTATE_RIGHT, pDeltaTime);
}
```

There is also some mouse control, which is included using a callback method. This can be a little annoying when you want to edit values using ImGui so you may want to turn this functionality off.

``` cpp
// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}
```

# Adding your own entities

To get you started here is an overview of how to add your own classes to the project. Suppose you want to add a GameEntity called Agent. 

First you need to create the header, and provide implementations for the Render and RenderGui methods like this.

``` cpp
#pragma once
#include "GameEntity.h"

class Agent : public GameEntity
{
private:

public:
	void Render(const IRenderHelpers&) const;
	void RenderGui(const IGuiHelpers&);
};

```

It is not intended that the GameEntity derived classes will render themselves, but instead they call another method in the RenderHelper and GuiHelper objects that are passed to them. It is inside these objects that you will write the code that is specific to rendering the Agent class.

``` cpp
#include "Agent.h"
#include "helpers/IRenderHelpers.h"
#include "helpers/IGuiHelpers.h"

void Agent::Render(const IRenderHelpers& pHelper) const
{
	pHelper.Render(this);
}

void Agent::RenderGui(const IGuiHelpers& pHelper)
{
	pHelper.RenderGui(this);
}
```

Next you need to create the functionality to render the agent to openGL. First declate a virtual function with an Agent * parameter in the IRenderHelpers.h header file.

``` cpp
	virtual void Render(const Agent*) const = 0;
```

You will also need to forward declare the Agent class at the top of this file.

``` cpp
 class Agent;
```

Next in the RenderHelper.h header file declare the method again to show you will be implementing the method in this concrete class.

``` cpp
	void Render(const Agent*) const;
```

Then in the RenderHelper.cpp file add the code that you would like to be called when your agent is rendered.

``` cpp
void OpenGLRenderHelpers::Render(const Agent* pAgent) const
{
    SetColour(pAgent->GetColour()); // this sets the colour
    SetModel(pAgent->GetModel()); // this sets the model
    
    // this code draws a cube - you may wish to refactor this into a private "drawCube" method (see below)
    glBindBuffer(GL_ARRAY_BUFFER, m_BufferIDs[0]); // this is the ID of the model you want to use. 
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}
```

If you want to refactor the code to make the draw calls easier to manager you might like to add the following methods.

``` cpp
// Draws a 1 x 1 x 1 cube with origin at the centre
// To adjust the position and orientation call SetModel before calling this method
// To adjust the colour call SetColour before calling this method
void OpenGLRenderHelpers::DrawCube() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_BufferIDs[0]); // this is the ID of the model you want to use. 
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

// Draws a sphere with radius 0.5 with origin at the centre
// To adjust the position and orientation call SetModel before calling this method
// To adjust the colour call SetColour before calling this method
void OpenGLRenderHelpers::DrawSphere() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_BufferIDs[1]); // this is the ID of the model you want to use. 
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLES, 0, 960);
}

// Draws a cylinder with radius 0.5 with origin at the centre
// To adjust the position and orientation call SetModel before calling this method
// To adjust the colour call SetColour before calling this method
void OpenGLRenderHelpers::DrawCylinder() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_BufferIDs[2]); // this is the ID of the model you want to use. 
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glDrawArrays(GL_TRIANGLES, 0, 384);
}
```

To test your code create an Agent in App.cpp somewhere appropriate, then in the renderOpenGL method call the Render function on your instance of Agent after the glClear command. You might like to experiment by trying to render an agent as a sphere on top of a cylinder.

``` cpp
Agent agent; // example global agent

static void renderOpenGL()
{
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // other render calls
    agent.Render(*renderHelper);
}
```

You can also add the new Agent to ImGui by adding a calling the default RenderGui method in renderImGui.

``` cpp
void renderImGui()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("Hello, IMGUI!");
    // other gui calls
    agent.RenderGui(*guiHelper);

    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
```

The default behaviour for ImGui will just display that there is an Entity with a particular ID. You can make that more useful by adding some more useful methods.
First declate a virtual function with an Agent * parameter in the IGuiHelpers.h header file. Again, you will also need to forward declare the Agent class.

``` cpp
	virtual void RenderGui(const Agent*) const = 0;
```

Then in the GuiHelpers.h header indicate that you will be providing a concrete implementation of the method.

``` cpp
	void RenderGui(Agent*) const;
```

Then in the GuiHelpers.cpp add an implementation for the method. You should experiment with this and check the ImGui documentation to see what options are available (there are loads!). For now though you can change the colour and position of your Agent with code like this.

``` cpp
void ImGuiHelpers::RenderGui(Agent* pAgent) const
{
	std::string label = "Agent : " + std::to_string(pCube->ID());
	ImGui::Text(label.c_str());
	RenderGuiAsColour("Colour : ", &pAgent->GetColour());
  RenderGui("position : ", &pAgent->Position);
}
```

Hopefully that gives you some insight into how to interact with the framework. If you have any "feature requests" please let me know!
