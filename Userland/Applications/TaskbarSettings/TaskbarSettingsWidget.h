/*
 * Copyright (c) 2022, MacDue <macdue@dueutil.tech>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/ColorInput.h>
#include <LibGUI/SettingsWindow.h>
#include <LibGUI/Slider.h>
#include <LibGUI/Window.h>

class TaskbarSettingsWidget final : public GUI::SettingsWindow::Tab {
    C_OBJECT(TaskbarSettingsWidget)
public:
    virtual ~TaskbarSettingsWidget() override = default;

    virtual void apply_settings() override;
    virtual void reset_default_values() override;

private:
    TaskbarSettingsWidget();
};
