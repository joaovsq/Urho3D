#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Engine/EngineDefs.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/Resource/ResourceCache.h>

#include "EditorApplication.h"

URHO3D_DEFINE_APPLICATION_MAIN(UrhoEditor::EditorApplication)

namespace UrhoEditor
{

EditorApplication::EditorApplication(Context* context)
    : Application(context)
{
    editorTitle_ = "Urho Editor";
    editor_ = new Editor(context);
}

void EditorApplication::Setup()
{
    // Modify engine startup parameters
    engineParameters_[EP_WINDOW_TITLE] = GetTypeName();
    engineParameters_[EP_WINDOW_WIDTH] = 1280;
    engineParameters_[EP_WINDOW_HEIGHT] = 720;
    engineParameters_[EP_WINDOW_RESIZABLE] = true;
    engineParameters_[EP_VSYNC] = true;
    engineParameters_[EP_LOG_NAME] =
        GetSubsystem<FileSystem>()->GetAppPreferencesDir("urho3d", "logs") + GetTypeName() + ".log";
    engineParameters_[EP_FULL_SCREEN] = false;
    engineParameters_[EP_HEADLESS] = false;
    engineParameters_[EP_SOUND] = false;
    engineParameters_[EP_RESOURCE_PATHS] = "Data;CoreData";
}

void EditorApplication::Start()
{
    SetWindowTitleAndIcon();
    SubscribeToEvents();

    editor_->SubscribeToEvents();
}

void EditorApplication::Stop() { engine_->DumpResources(true); }

void EditorApplication::SetWindowTitleAndIcon()
{
    ResourceCache* cache = GetSubsystem<ResourceCache>();
    Graphics* graphics = GetSubsystem<Graphics>();
    graphics->SetWindowTitle(editorTitle_);
    // Image* icon = cache->GetResource<Image>("Images/favicon.png");
    // graphics->SetWindowIcon(icon);
}

void EditorApplication::SubscribeToEvents()
{
    // TODO
}

} // namespace UrhoEditor