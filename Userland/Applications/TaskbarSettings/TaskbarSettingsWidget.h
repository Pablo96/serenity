/*
 * Copyright (c) 2022, PabloNarvaha <pnarvaja.21@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/SettingsWindow.h>
#include <LibGUI/ComboBox.h>
#include <LibGUI/ValueSlider.h>

class TaskbarSettingsWidget final : public GUI::SettingsWindow::Tab {
    C_OBJECT(TaskbarSettingsWidget)
public:
    virtual ~TaskbarSettingsWidget() override = default;

    virtual void apply_settings() override;
    virtual void reset_default_values() override;

private:
    TaskbarSettingsWidget();

    RefPtr<GUI::ComboBox> m_position_combobox;
    RefPtr<GUI::ValueSlider> m_height_valueslider;
};
