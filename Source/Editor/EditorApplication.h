#pragma once

#include "Editor.h"
#include <Urho3D/Engine/Application.h>

using namespace UrhoEditor;

namespace UrhoEditor
{

class EditorApplication : public Application
{
    URHO3D_OBJECT(EditorApplication, Application)

public:
    EditorApplication(Context* context);

    /// Setup before engine initialization. Modifies the engine parameters.
    virtual void Setup();
    /// Setup after engine initialization. Creates the logo, console & debug HUD.
    virtual void Start();
    /// Cleanup after the main loop. Called by Application.
    virtual void Stop();

    String editorTitle_;

private:
    /// Defines the main window title and icon
    void SetWindowTitleAndIcon();
    /// Subscribe to all editor events
    void SubscribeToEvents();

    SharedPtr<Editor> editor_;
};

} // namespace UrhoEditor