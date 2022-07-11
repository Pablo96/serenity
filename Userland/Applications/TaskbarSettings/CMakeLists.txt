serenity_component(
    TaskbarSettings
    REQUIRED
    TARGETS TaskbarSettings
)

compile_gml(TaskbarSettings.gml TaskbarSettingsGML.h taskbar_settings_gml)

set(SOURCES
    main.cpp
    TaskbarSettingsWidget.cpp
    TaskbarSettingsGML.h
)

serenity_app(TaskbarSettings ICON app-mouse)
target_link_libraries(TaskbarSettings LibGUI LibMain)
