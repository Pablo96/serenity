serenity_component(
    TaskbarSettings
    REQUIRED
    TARGETS TaskbarSettings
)

set(SOURCES
    main.cpp
    TaskbarSettingsWidget.cpp
)

serenity_app(TaskbarSettings ICON app-mouse)
target_link_libraries(TaskbarSettings LibGUI LibMain)
