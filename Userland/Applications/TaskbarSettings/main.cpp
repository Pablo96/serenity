/*
 * Copyright (c) 2022, PabloNarvaha <pnarvaja.21@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "TaskbarSettingsWidget.h"
#include <LibCore/ArgsParser.h>
#include <LibCore/System.h>
#include <LibGUI/Application.h>
#include <LibGUI/Icon.h>
#include <LibGUI/SettingsWindow.h>
#include <LibMain/Main.h>

ErrorOr<int> serenity_main(Main::Arguments arguments)
{
    TRY(Core::System::pledge("stdio cpath rpath recvfd sendfd unix"));

    auto app = TRY(GUI::Application::try_create(arguments));

    TRY(Core::System::pledge("stdio cpath rpath recvfd sendfd"));

    // StringView selected_tab;
    // Core::ArgsParser args_parser;
    // args_parser.add_option(selected_tab, "Tab, one of 'cursor-theme', 'cursor-highlight',  or 'mouse'", "open-tab", 't', "tab");
    // args_parser.parse(arguments);
    
    auto app_icon = GUI::Icon::default_icon("app-mouse");

    auto window = TRY(GUI::SettingsWindow::create("Taskbar Settings", GUI::SettingsWindow::ShowDefaultsButton::Yes));
    (void)TRY(window->add_tab<TaskbarSettingsWidget>("Taskbar", "Taskbar"));

    window->set_icon(app_icon.bitmap_for_size(16));
    //window->set_active_tab(selected_tab);

    window->show();
    return app->exec();
}
